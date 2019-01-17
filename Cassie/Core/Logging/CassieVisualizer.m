%CASSIEVISUALIZER System for real-time and log visualization
%
% Syntax:
%   viz = CassieVisualizer

% Copyright 2017-2018 Agility Robotics

classdef CassieVisualizer < handle
  
  % PRIVATE PROPERTIES =========================================================
  properties (Access = private)
    % Figure handle
    figure
    % Timer object for updating graphics
    timer
    % Multi body tree structure
    tree
    % Simulink Real-Time target PC
    target
    % Visualization signal name
    signalNames
    % Time vector
    time
    % State vector
    state
    % Pose matrices from external position sensor
    pose
    % Current time in the visualization
    currentTime = 0
    % Current playback speed of the visualization
    playbackSpeed = 1
  end % private properties
  
  % PUBLIC METHODS =============================================================
  methods (Access = public)
    function obj = CassieVisualizer(time, state, pose)
      %CASSIEVISUALIZER System for real-time and log visualization
      
      % If called with no arguments, act as a real-time visualizer using the
      % host-target link
      if nargin == 0
        % Get signal names for state data
        obj.signalNames = CassieVisualizer.getSignalNames();
        
        % Get handle to target PC
        obj.target = SimulinkRealTime.target;
        assert(strcmp(obj.target.Connected, 'Yes'), ...
          'CassieVisualizer started in real-time mode but target computer is not connected.');
      else
        % Log data provided, act as a log visualizer
        obj.time = time;
        obj.state = state;
        if nargin >= 3
          obj.pose = pose;
        end % if
      end % if
      
      % Intialize timer object
      obj.timer = timer(...
        'TimerFcn', @(src, event) obj.timerFcn(src, event), ...
        'ExecutionMode', 'fixedRate', ...
        'Period', 1/20, ...
        'TasksToExecute', Inf);

      % Initialize object properties
      obj.tree = MultiBodyTree.fromDescriptor(CassieDescriptor);
      
      % Remove connecting rods from visualization
      obj.tree.getBodyByName('left-achilles-rod').isVisible = false;
      obj.tree.getEndEffectorByName('left-achilles-rod-end').isVisible = false;
      obj.tree.getBodyByName('left-plantar-rod').isVisible = false;
      obj.tree.getEndEffectorByName('left-plantar-rod-end').isVisible = false;
      obj.tree.getBodyByName('right-achilles-rod').isVisible = false;
      obj.tree.getEndEffectorByName('right-achilles-rod-end').isVisible = false;
      obj.tree.getBodyByName('right-plantar-rod').isVisible = false;
      obj.tree.getEndEffectorByName('right-plantar-rod-end').isVisible = false;
      
      % Initialize figure
      obj.figure = figure(...
        'Color', [1 1 1], ...
        'CreateFcn', 'movegui west', ...
        'CloseRequestFcn', @obj.closeRequestCallback, ...
        'DeleteFcn', @obj.deleteCallback, ...
        'KeyPressFcn', @obj.keyPressCallback, ...
        'Name', 'Visualizer', ...
        'PaperPositionMode', 'auto', ...
        'Position', [0 0 1280 720] + [0 0 100 100], ...
        'Units', 'pixels');
      
      % Initialize tree visualization
      obj.tree.draw;
      
      % Set axes properties
      if ~isempty(obj.pose)
        ax = gca;
        ax.XLim = [-0.6 0.6];
        ax.YLim = [-0.6 0.6];
        ax.ZLim = [0 1];
        axis on;
        grid on;
      end % if

      % Start the timer object that controls graphic frame updates
      start(obj.timer);
    end % CassieVisualizer
    
    function play(obj)
      %PLAY Play the visualization
      
      % Start the timer object that controls graphic frame updates
      start(obj.timer);
    end % play
    
    function pause(obj)
      %PAUSE Pause the visualization
      
      % Reset window title
      set(obj.figure, 'Name', 'Cassie Visualizer');
      
      % Stop the timer object that controls graphic frame updates
      stop(obj.timer);
    end % pause
    
    function timerFcn(obj, src, ~)
      %TIMERFCN Callback function executed when a timer event occurs
      
      % Internal timer used to compute the frame rate
      persistent dt; if isempty(dt); dt = tic; end % if
      
      if ~isempty(obj.target)
        % Real-time viualizer
        
        % Get current robot state
        bytes = uint8(obj.target.getsignal(obj.signalNames)');
        x = double(typecast(bytes, 'single'));
        x = [x(1:4); [0; 0; 1.2]; x(5:20)];
        pelvisPose = [];
      else
        % Log visualizer
        
        % Update the current time of the visualization
        obj.currentTime = obj.currentTime + src.Period*obj.playbackSpeed;
        
        % Check for playback looping and adjust current time
        if obj.currentTime >= obj.time(end)
          obj.currentTime = obj.time(1);
        elseif obj.currentTime <= obj.time(1)
          obj.currentTime = obj.time(end);
        end % if
        
        % Get a state vector close to the display time
        nearInd = find(obj.time > obj.currentTime, 1);
        if isempty(nearInd)
          nearInd = numel(obj.time);
        end % if
        x = obj.state(:, nearInd);
        
        % If a global pose was provided, get that as well
        if ~isempty(obj.pose)
          pelvisPose = obj.pose(:, :, nearInd);
        else
          pelvisPose = [];
        end % if
      end % if
      
      % Parse state vector
      q_pelvis = x(1:4);
      p_pelvis = x(5:7);
      q_m = x(8:17);
      q_j = x(18:23);
      
      if ~isempty(pelvisPose)
        % Use a global pelvis pose if provided
        T = Transform3d(pelvisPose);
      else
        % If valid, construct the root transformation from the state estimator
        if all(q_pelvis == 0)
          T = Transform3d(Rotation3d, Vector3d(p_pelvis));
        else
          Q = Quaternion(q_pelvis).normalize;
          T = Transform3d(Q.getRotation, Vector3d(p_pelvis));
        end % if
      end
      
      % Update multi body tree joint positions
      obj.tree.getBodyByName('cassie-pelvis').setRelativeTransform(T);
      obj.tree.getJointByName('left-hip-roll-joint').setPosition(q_m(1));
      obj.tree.getJointByName('left-hip-yaw-joint').setPosition(q_m(2));
      obj.tree.getJointByName('left-hip-pitch-joint').setPosition(q_m(3));
      obj.tree.getJointByName('left-knee-joint').setPosition(q_m(4));
      obj.tree.getJointByName('left-foot-joint').setPosition(q_m(5));
      obj.tree.getJointByName('left-foot-crank-joint').setPosition(q_m(5));
      obj.tree.getJointByName('left-shin-joint').setPosition(q_j(1));
      obj.tree.getJointByName('left-tarsus-joint').setPosition(q_j(2));
      obj.tree.getJointByName('right-hip-roll-joint').setPosition(q_m(6));
      obj.tree.getJointByName('right-hip-yaw-joint').setPosition(q_m(7));
      obj.tree.getJointByName('right-hip-pitch-joint').setPosition(q_m(8));
      obj.tree.getJointByName('right-knee-joint').setPosition(q_m(9));
      obj.tree.getJointByName('right-foot-joint').setPosition(q_m(10));
      obj.tree.getJointByName('right-foot-crank-joint').setPosition(q_m(10));
      obj.tree.getJointByName('right-shin-joint').setPosition(q_j(4));
      obj.tree.getJointByName('right-tarsus-joint').setPosition(q_j(5));
      
      % Update model visualization
      obj.tree.draw;
      
      % Construct figure name string
      if ~isempty(obj.target)
        figureName = [...
          'Visualizer', ...
          sprintf(' (%0.1ffps)',  1/toc(dt))];
      else
        figureName = [...
          'Cassie Visualizer', ...
          sprintf(' (%0.1ffps)',  1/toc(dt)), ...
          sprintf(' (%0.1fx)',  obj.playbackSpeed), ...
          sprintf(' (%0.1fs)',  obj.currentTime)];
      end % if
      
      % Update frame rate indicator
      set(obj.figure, 'Name', figureName);
      
      % Update clock timer
      dt = tic;
      
      % Flush pending graphics events
      drawnow;
    end % timerFcn
    
    function keyPressCallback(obj, varargin)
      %KEYPRESSCALLBACK Keypress callback function
      
      % Do not respond to keys in real-time vizualizer mode
      if ~isempty(obj.target)
        return
      end % if
      
      % Get the current key pressed and enter state machine
      switch get(obj.figure, 'CurrentKey')
        % Increase playback speed
        case 'uparrow'
          obj.playbackSpeed = obj.playbackSpeed + 0.1;
          
          % Decrease playback speed
        case 'downarrow'
          obj.playbackSpeed = obj.playbackSpeed - 0.1;
          
          % Play/pause
        case 'space'
          % Check if the visualization is currently running
          if strcmp(obj.timer.Running, 'on')
            % Pause the visualization
            obj.pause;
          else
            % Play the visualization
            obj.play;
          end % if
          
        otherwise
          % Do nothing
      end % switch
    end % keyPressCallback
    
    function closeRequestCallback(obj, varargin)
      %CLOSEREQUESTCALLBACK Close request callback function
      
      % Pause visualization
      obj.pause;
      
      % Delete figure
      delete(obj.figure);
    end % closeRequestCallback
    
    function deleteCallback(obj, varargin)
      %DELETECALLBACK Delete callback function
      
      % Close everything before deleting
      obj.closeRequestCallback;
    end % deleteCallback
  end % public methods
  
  % STATIC METHODS =============================================================
  methods (Static)
    function signalNames = getSignalNames()
      %GETSIGNALNAMES Gets signal names used to pull data from real-time system
      
      % Determine which byte signals should be read from the target
      % Get packed log structure and zero all bytes
      s.out = CassieModule.getOutStruct;
      s.userIn = CassieModule.getUserInStruct;
      packfun = BusModule.getPackingFunction(s, 'singlefloats');
      unpackfun = BusModule.getUnpackingFunction(s, 'singlefloats');
      bytes = packfun(s);
      bytes = bytes * 0;
      s = unpackfun(bytes);
      
      % Unpack and set selected values to nonzero bytes
      indicators = double(typecast(uint8(1:80), 'single'));
      s.out.pelvis.vectorNav.orientation(:) = indicators(1:4);
      s.out = CassieModule.setDriveProperty(s.out, 'position', indicators(5:14));
      s.out = CassieModule.setJointProperty(s.out, 'position', indicators(15:20));
      
      % Repack and look for indices of nonzero bytes
      bytes = packfun(s);
      inds = find(bytes);
      [~, sortinds] = sort(bytes(inds));
      inds = inds(sortinds);
      
      % Initialize signal name cell array
      signalNames = cellstr("Cassie/Vector Concatenate/s" + inds);
    end % getSignalNames
  end % static private methods
end % classdef
