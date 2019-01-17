%CASSIELOG Interface class for handling Cassie real-time log files
%
% Syntax:
%   log = CassieLog
%   log.load

% Copyright 2017-2018 Agility Robotics

classdef CassieLog < handle
  
  % PROTECTED PROPERTIES =======================================================
  properties (Access = protected)
    % Timestamp for each log entry
    time
    % Byte array of log data
    logBytes
    % Function used to unpack a row of log data into a struct
    unpackfun
    % Nested name of each field
    fieldNames
    % Starting index of each field
    startInds
    % Ending index of each field
    endInds
    % Numeric type of each field
    numTypes
    % Pelvis pose matrices from vive log data
    vivePelvisPose
    % Size of each row of log data in bytes
    logEntrySize
    % Size of each row of log data in bytes after packing into doubles
    packedLogEntrySize
  end % protected properties
  
  % PUBLIC METHODS =============================================================
  methods (Access = public)
    function obj = CassieLog(varargin)
      %CASSIELOG Construct interface object for Cassie real-time log files
      
      % Create structure representing binary log data
      logStruct.out = CassieModule.getOutStruct;
      logStruct.userIn = CassieModule.getUserInStruct;
      
      % Get log entry size in bytes
      % File scopes only log doubles, so for storage efficiency buses are packed
      % as bytes and typecast to a double array
      obj.logEntrySize = sum(BusModule.getPackingInfo(logStruct.out, 'singlefloats')) + ...
        sum(BusModule.getPackingInfo(logStruct.userIn, 'singlefloats'));
      obj.packedLogEntrySize = 8 * ceil(obj.logEntrySize / 8);
      
      % Get bus unpacking function
      obj.unpackfun = BusModule.getUnpackingFunction(logStruct, 'singlefloats');
      
      % Get bus unpacking data
      [bytes, fields, ~, obj.numTypes] = ...
        BusModule.getPackingInfo(logStruct, 'singlefloats');
      obj.fieldNames = cellfun(@(s)s.join('.'), fields);
      obj.endInds = cumsum(bytes);
      obj.startInds = obj.endInds - bytes + 1;
      
      % If arguments were provided to constructor, pass them to the load method
      if nargin
        obj.load(varargin{:});
      end % if
    end % CassieLog
    
    function load(obj, filePath, logType)
      %LOAD Load any compatible log file
      
      % If no file path is provided, prompt for a file
      if nargin < 2
        [fileName, dirPath] = uigetfile({'*.dat', 'Real-time Cassie log';
          '*.mat', 'Simulation log'; '*.*', 'All files'}, 'Multiselect', 'on');
        if ~fileName
          % No file selected
          return
        end % end
        filePath = string(dirPath) + string(fileName)';
      else
        % Make sure filepath is a string array instead of a character array
        filePath = string(filePath);
      end % if
      
      % Determine log type if not specified
      if nargin < 3 || isempty(logType)
        % Check which file extension was selected
        [~, ~, ext] = fileparts(filePath(1));
        
        % Choose log type based on extension
        switch lower(ext)
          case '.dat'
            logType = 'realtime';
            
          case '.mat'
            % Check contents of mat file to differentiate between simulation log
            % and vive log
            if ~isempty(whos(matfile(filePath), 'data'))
              logType = 'simulation';
            else
              logType = 'vive';
            end % if
            
          case '.bin'
            logType = 'binary';
            
          otherwise
            error('Could not determine log file type from extension.');
        end % switch
      end % if
      
      % Concatenating multiple files is only supported for real-time logs
      if logType ~= "realtime"
          if numel(filePath) > 1
            error('Opening multiple log files together is not supported for this log type.');
          end % if
      end % if
      
      % Load file data
      switch lower(logType)
        case 'realtime'
          % Load real-time log
          
          % Read contents of multiple files into cell arrays
          timeCell = cell(numel(filePath), 1);
          logBytesPaddedCell = cell(numel(filePath), 1);
          for i = 1:numel(filePath)
            fileScopeData = SimulinkRealTime.utils.getFileScopeData(char(filePath(i)));
            timeCell{i} = fileScopeData.data(:, end)';
            doubles = fileScopeData.data(:, 1:end-1)';
            logBytesPaddedCell{i} = typecast(doubles(:), 'uint8');
          end % for
          
          % Concatenate data from multiple files
          startTimes = cellfun(@(x) x(1), timeCell);
          [~, order] = sort(startTimes);
          obj.time = horzcat(timeCell{order});
          logBytesPadded = vertcat(logBytesPaddedCell{order});
          
          % Clear any existing vive pelvis pose data
          obj.vivePelvisPose = [];
          
          % Cast doubles -> bytes, then reshape byte array and remove padding
          numEntries = numel(obj.time);
          logBytesPadded = reshape(logBytesPadded, obj.packedLogEntrySize, numEntries);
          obj.logBytes = logBytesPadded(1:obj.logEntrySize, :);
          
        case 'simulation'
          % Load simulation log
          matFile = load(filePath);
          obj.time = matFile.data(1, :)';
          doubles = matFile.data(2:end, :);
          logBytesPadded = typecast(doubles(:), 'uint8');
          
          % Clear any existing vive pelvis pose data
          obj.vivePelvisPose = [];
          
          % Cast doubles -> bytes, then reshape byte array and remove padding
          numEntries = numel(obj.time);
          logBytesPadded = reshape(logBytesPadded, obj.packedLogEntrySize, numEntries);
          obj.logBytes = logBytesPadded(1:obj.logEntrySize, :);
          
        case 'vive'
          % Load vive log
          matFile = load(filePath);
          obj.time = matFile.time;
          obj.logBytes = matFile.logBytes;
          obj.vivePelvisPose = matFile.vivePelvisPose;
          
        case 'binary'
          % Binary dump of CassieOutBus and CassieUserInBus without padding
          
          % Load raw data
          f = fopen(filePath);
          bytes = fread(f, '*uint8');
          fclose(f);
          
          % Trim and reshape
          numEntries = floor(numel(bytes) / obj.logEntrySize);
          bytes = bytes(1:obj.logEntrySize*numEntries);
          obj.logBytes = reshape(bytes, obj.logEntrySize, numEntries);
          
          % Construct time vector
          obj.time = (0:numEntries-1) * 5e-4;
          
        otherwise
          error('Invalid log file type specified.');
      end % switch
      
      % If logBytes was not already set, create it using logBytesPadded
      if isempty(obj.logBytes)
        % Cast doubles -> bytes, then reshape byte array and remove padding
        numEntries = numel(obj.time);
        logBytesPadded = reshape(logBytesPadded, obj.packedLogEntrySize, numEntries);
        obj.logBytes = logBytesPadded(1:obj.logEntrySize, :);
      end % if
    end % load
    
    function plotImuState(obj)
      %PLOTIMUSTATE
      
      % Get the IMU data
      t = obj.getTime;
      pressure = obj.getField('out.pelvis.vectorNav.pressure');
      temperature = obj.getField('out.pelvis.vectorNav.temperature');
      magneticField = obj.getField('out.pelvis.vectorNav.magneticField');
      angularVelocity = obj.getField('out.pelvis.vectorNav.angularVelocity');
      linearAcceleration = obj.getField('out.pelvis.vectorNav.linearAcceleration');
      orientation = obj.getField('out.pelvis.vectorNav.orientation');
      
      % Plot
      subplot(3, 2, 1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Pressure (kPa)');
      plot(t, pressure);
      
      subplot(3, 2, 3);
      hold on; grid on; xlabel('Time (s)'); ylabel('Temperature (C)');
      plot(t, temperature);
      
      subplot(3, 2, 5);
      hold on; grid on; xlabel('Time (s)'); ylabel('Magnetic Field (Gauss)');
      plot(t, magneticField);
      
      subplot(3, 2, 2);
      hold on; grid on; xlabel('Time (s)'); ylabel('Angular Velocity (rad/s)');
      plot(t, angularVelocity);
      
      subplot(3, 2, 4);
      hold on; grid on; xlabel('Time (s)'); ylabel('Linear Acceleration (m/s/s)');
      plot(t, linearAcceleration);
      
      subplot(3, 2, 6);
      hold on; grid on; xlabel('Time (s)'); ylabel('Orientation (quaternion)');
      plot(t, orientation);
    end % plotImuState
    
    function displayMessageSummary(obj)
      %DISPLAYMESSAGESUMMARY Display a summary of the diagnostics codes
      
      % Define message scope data
      t = obj.getTime;
      message = obj.getMessage;
      
      % Bin and count diagnostic messages
      msg = double(message);
      edges = unique(msg);
      num = histc(msg(:), edges);
      
      % Summarize results
      for i = 2:numel(edges)
        fprintf('  %s (%d) (%2.2f%%) \n', ...
          DiagnosticCodes(edges(i)).char, ...
          num(i), ...
          100*num(i)/numel(t));
      end % for
    end % displayMessageSummary
    
    function displayMessages(obj)
      %DISPLAYMESSAGES Display messages and time stamps
      %
      % TODO: Add filters to search messages
      
      % Define message scope data
      t = obj.getTime;
      message = obj.getMessage;
      
      % Find all error messages
      [r, c] = find(message);
      
      % Loop through found message
      for j = 1:length(r)
        % Get current message properties
        tmsg = t(r(j));
        msg = char(DiagnosticCodes(message(r(j), c(j))));
        
        % Display time and error message
        fprintf('(%0.4f) %s\n', tmsg, msg);
      end % for
    end % displayMessages
    
    function plotMessageScope(obj)
      %PLOTMESSAGESCOPE Plot diagnostic messages over time
      
      % Define message scope data
      t = obj.getTime;
      message = obj.getMessage;
      
      % Plot message codes
      figure; hold on; grid on;
      xlabel('Time (s)');
      ylabel('Message Code');
      stem(t, message);
    end % plotMessageScope
    
    function plotEnergyScope(obj)
      %PLOTENERGYSCOPE Plot voltage and current over time
      
      % Define energy scope data
      t = obj.getTime;
      voltage = obj.getVoltage;
      current = obj.getCurrent;
      
      % Compute power draw
      P = voltage.*current;
      
      % Initialize figure
      figure;
      
      % Plot voltage
      voltagePlotHandle = subplot(3, 1, 1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Voltage (V)');
      plot(t, voltage);
      
      % Plot current
      currentPlotHandle = subplot(3, 1, 2);
      hold on; grid on; xlabel('Time (s)'); ylabel('Current (A)');
      plot(t, current);
      
      % Plot power
      powerPlotHandle = subplot(3, 1, 3);
      hold on; grid on; xlabel('Time (s)'); ylabel('Power (W)');
      plot(t, P);
    end % plotEnergyScope
    
    function plotOutputsScope(obj)
      %PLOTOUTPUTSSCOPE Plot motor and joint states over time
      
      % Define outputs scope data
      t = obj.getTime;
      motorPosition = obj.getMotorPosition;
      motorVelocity = obj.getMotorVelocity;
      jointPosition = obj.getJointPosition;
      jointVelocity = obj.getJointVelocity;
      
      % Initialize figure
      figure;
      
      % Plot motor position
      motorPositionPlotHandle = subplot(2,1,1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Motor Position (rad)');
      plot(t, motorPosition);
      
      % Plot motor velocity
      motorVelocityPlotHandle = subplot(2,1,2);
      hold on; grid on; xlabel('Time (s)'); ylabel('Motor Velocity (rad/s)');
      plot(t, motorVelocity);
      
      % Initialize figure
      figure;
      
      % Plot joint position
      jointPositionPlotHandle = subplot(2,1,1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Joint Position (rad)');
      plot(t, jointPosition);
      
      % Plot joint velocity
      jointVelocityPlotHandle = subplot(2,1,2);
      hold on; grid on; xlabel('Time (s)'); ylabel('Joint Velocity (rad/s)');
      plot(t, jointVelocity);
    end % plotOutputsScope
    
    function plotMotorTorques(obj)
      %PLOTMOTORTORQUES Plot actual versus commanded motor torque
      
      % Define inputs scope data
      t = obj.getTime;
      commandedMotorTorque = obj.getCommandedMotorTorque;
      actualMotorTorque = obj.getActualMotorTorque;
      
      % Initialize figure
      figure;
      
      % Plot  data
      motorTorquePlotHandle = subplot(1,1,1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Motor Torque (N*m)');
      plot(t, commandedMotorTorque, '-');
      plot(t, actualMotorTorque, '--');
    end % plotMotorTorques
    
    function plotInputsScope(obj)
      %PLOTINPUTSSCOPE Plot commanded motor torques
      
      % Define inputs scope data
      t = obj.getTime;
      motorTorque = obj.getCommandedMotorTorque;
      
      % Initialize figure
      figure;
      
      % Plot  data
      motorTorquePlotHandle = subplot(1,1,1);
      hold on; grid on; xlabel('Time (s)'); ylabel('Motor Torque (N*m)');
      plot(t, motorTorque);
    end % plotInputsScope
    
    function plotTorqueSpeedCurve(obj, startTime, endTime)
      %PLOTTORQUESPEEDCURVE Plot the torque speed curve of each motor
      
      % Define maximum motor velocity
      % dq_max = CassieParameters.motorMaximumSpeed./...
      %   CassieParameters.motorGearRatio*2*pi/60;
      dq_max = [2.618;2.618;1.676;1.676;5.236;2.618;2.618;1.676;1.676;5.236];
      
      % Define maximum motor torque
      % u_max = CassieParameters.motorMaximumTorque.*...
      %   CassieParameters.motorGearRatio;
      u_max = [112.5;112.5;195.2;195.2;45;112.5;112.5;195.2;195.2;45];
      
      % Get outputs scope data
      t = obj.getTime';
      dq = obj.getMotorVelocity';
      
      % Check if optional arguments were specified
      if nargin ~= 3
        % Define default optional arguments
        startIndex = 1;
        endIndex = numel(t);
      else
        % Convert specified time range into indexes
        startIndex  = find(t <= startTime, 1, 'last');
        endIndex = find(t >= endTime, 1, 'first');
      end % if
      
      % Specify range
      ind = startIndex:endIndex;
      
      % Resample outputs data
      t = t(ind);
      dq = dq(ind,:);
      
      % Resample inputs data to match outputs
      u = interp1(t, obj.getActualMotorTorque', t);
      
      % Define motor names
      motorNames = {'Abduction', 'Yaw', 'Hip', 'Knee', 'Foot'};
      
      % Plot torque speed curves
      figure;
      for i = 1:5
        subplot(2,3,i); hold on; grid on; box on;
        title(motorNames{i});
        xlabel('Motor Output Velocity (rad/s)');
        ylabel('Motor Output Torque (N*m)');
        plot(dq(:,i), u(:,i));
        plot(dq(:,i + 5), u(:,i + 5));
        plot(...
          [-dq_max(i) 0 dq_max(i) 0 -dq_max(i)], ...
          [0 u_max(i) 0 -u_max(i) 0], '--r');
      end % for
    end % plotTorqueSpeedCurve
    
    function rmsPower = getRmsPower(obj, startTime, endTime)
      %GETRMSPOWER Get the RMS power
      
      % Define energy scope data
      t = obj.getTime;
      voltage = obj.getVoltage;
      current = obj.getCurrent;
      
      % Compute power draw
      P = voltage.*current;
      
      % Check if optional arguments were specified
      if nargin ~= 3
        % Define default optional arguments
        startIndex = 1;
        endIndex = numel(t);
      else
        % Convert specified time range into indexes
        startIndex  = find(t <= startTime, 1, 'last');
        endIndex = find(t >= endTime, 1, 'first');
      end % if
      
      % Specify range
      ind = startIndex:endIndex;
      
      % Resample outputs data
      t = t(ind);
      P = P(:, ind);
      
      % Compute RMS power
      rmsPower = sqrt(mean(P.^2));
      
      % Display mean power
      disp(rmsPower);
    end % getRmsPower
    
    function plotPower(obj, startTime, endTime)
      %PLOTPOWER Plot the power draw over time
      
      % Define energy scope data
      t = obj.getTime;
      voltage = obj.getVoltage;
      current = obj.getCurrent;
      
      % Compute power draw
      P = voltage.*current;
      
      % Check if optional arguments were specified
      if nargin ~= 3
        % Define default optional arguments
        startIndex = 1;
        endIndex = numel(t);
      else
        % Convert specified time range into indexes
        startIndex  = find(t <= startTime, 1, 'last');
        endIndex = find(t >= endTime, 1, 'first');
      end % if
      
      % Specify range
      ind = startIndex:endIndex;
      
      % Resample outputs data
      t = t(ind);
      P = P(:, ind);
      
      % Display mean power
      disp(mean(P));
      
      % Plot power
      figure;
      hold on; grid on; box on;
      title('Power')
      xlabel('Time (s)');
      ylabel('Power (W)');
      plot(t, P);
    end % plotPower
    
    function visualize(obj)
      %VISUALIZE Visualize and playback animation of the log
      
      % Define time vector
      t = obj.getTime;
      
      % Define state vector
      state = [...
        obj.getVectorNavOrientation
        zeros(3, numel(t))
        obj.getMotorPosition
        obj.getJointPosition];
      
      % Determine first and last good data frame
      first = find(any(state, 1), 1);
      last = find(diff(t) < 0, 1, 'first');
      if isempty(last)
        last = numel(t);
      end % if
      t = t(first:last);
      state = state(:, first:last);
      
      if ~isempty(obj.vivePelvisPose)
        % Send time, state, and vive pose data to the visualizer
        pose = obj.vivePelvisPose(:, :, first:last);
        CassieVisualizer(t, state, pose);
      else
        % Send just time and state to the visualizer
        CassieVisualizer(t, state);
      end % if
    end % visualize
  end % public methods
  
  % GET/SET METHODS ============================================================
  methods
    function logBytes = getLogBytes(obj)
      %GETLOGBYTES Get the log bytes
      logBytes = obj.logBytes;
    end % getLogBytes
    
    function log = getStruct(obj, inds)
      %GETSTRUCT Get the log struct for specified indices
      
      % Unpack each specified row
      for i = 1:numel(inds)
        log(i) = obj.unpackfun(obj.logBytes(:, inds(i)));
      end % while
    end % getLogStruct
    
    function out = getField(obj, field)
      %GETFIELD Get values of the specified field
      
      % Find field index
      i = find(obj.fieldNames == field, 1);
      if isempty(i)
        error('Invalid field name: %s', field);
      end
      
      % Typecast data
      inds = obj.startInds(i):obj.endInds(i);
      bytes = obj.logBytes(inds, :);
      out = typecast(bytes(:), char(obj.numTypes(i)));
      
      % Reshape data
      ncols = size(obj.logBytes, 2);
      nrows = numel(out) / ncols;
      out = reshape(out, nrows, ncols);
    end
    
    function time = getTime(obj)
      time = obj.time;
    end % getTime
    
    function message = getMessage(obj)
      message = DiagnosticCodes(obj.getField('out.messages')');
    end % getMessage
    
    function voltage = getVoltage(obj)
      voltage = double(sum(obj.getField('out.pelvis.battery.voltage'), 1));
    end % getVoltage
    
    function current = getCurrent(obj)
      current = double(obj.getField('out.pelvis.battery.current'));
    end % getCurrent
    
    function vectorNavOrientation = getVectorNavOrientation(obj)
      vectorNavOrientation = ...
        double(obj.getField('out.pelvis.vectorNav.orientation'));
    end % getVectorNavOrientation
    
    function vectorNavVelocity = getVectorNavVelocity(obj)
      vectorNavVelocity = ...
        double(obj.getField('out.pelvis.vectorNav.angularVelocity'));
    end % getVectorNavVelocity
    
    function motorPosition = getMotorPosition(obj)
      motorPosition = double([...
        obj.getField('out.leftLeg.hipRollDrive.position')
        obj.getField('out.leftLeg.hipYawDrive.position')
        obj.getField('out.leftLeg.hipPitchDrive.position')
        obj.getField('out.leftLeg.kneeDrive.position')
        obj.getField('out.leftLeg.footDrive.position')
        obj.getField('out.rightLeg.hipRollDrive.position')
        obj.getField('out.rightLeg.hipYawDrive.position')
        obj.getField('out.rightLeg.hipPitchDrive.position')
        obj.getField('out.rightLeg.kneeDrive.position')
        obj.getField('out.rightLeg.footDrive.position')]);
    end % getMotorPosition
    
    function motorVelocity = getMotorVelocity(obj)
      motorVelocity = double([...
        obj.getField('out.leftLeg.hipRollDrive.velocity')
        obj.getField('out.leftLeg.hipYawDrive.velocity')
        obj.getField('out.leftLeg.hipPitchDrive.velocity')
        obj.getField('out.leftLeg.kneeDrive.velocity')
        obj.getField('out.leftLeg.footDrive.velocity')
        obj.getField('out.rightLeg.hipRollDrive.velocity')
        obj.getField('out.rightLeg.hipYawDrive.velocity')
        obj.getField('out.rightLeg.hipPitchDrive.velocity')
        obj.getField('out.rightLeg.kneeDrive.velocity')
        obj.getField('out.rightLeg.footDrive.velocity')]);
    end % getMotorVelocity
    
    function jointPosition = getJointPosition(obj)
      jointPosition = double([...
        obj.getField('out.leftLeg.shinJoint.position')
        obj.getField('out.leftLeg.tarsusJoint.position')
        obj.getField('out.leftLeg.footJoint.position')
        obj.getField('out.rightLeg.shinJoint.position')
        obj.getField('out.rightLeg.tarsusJoint.position')
        obj.getField('out.rightLeg.footJoint.position')]);
    end % getJointPosition
    
    function jointVelocity = getJointVelocity(obj)
      jointVelocity = double([...
        obj.getField('out.leftLeg.shinJoint.velocity')
        obj.getField('out.leftLeg.tarsusJoint.velocity')
        obj.getField('out.leftLeg.footJoint.velocity')
        obj.getField('out.rightLeg.shinJoint.velocity')
        obj.getField('out.rightLeg.tarsusJoint.velocity')
        obj.getField('out.rightLeg.footJoint.velocity')]);
    end % getJointVelocity
    
    function motorTorque = getCommandedMotorTorque(obj)
      motorTorque = double(obj.getField('userIn.torque'));
    end % getCommandedMotorTorque
    
    function motorTorque = getActualMotorTorque(obj)
      motorTorque = double([...
        obj.getField('out.leftLeg.hipRollDrive.torque')
        obj.getField('out.leftLeg.hipYawDrive.torque')
        obj.getField('out.leftLeg.hipPitchDrive.torque')
        obj.getField('out.leftLeg.kneeDrive.torque')
        obj.getField('out.leftLeg.footDrive.torque')
        obj.getField('out.rightLeg.hipRollDrive.torque')
        obj.getField('out.rightLeg.hipYawDrive.torque')
        obj.getField('out.rightLeg.hipPitchDrive.torque')
        obj.getField('out.rightLeg.kneeDrive.torque')
        obj.getField('out.rightLeg.footDrive.torque')]);
    end % getActualMotorTorque
  end % get/set methods
end % classdef
