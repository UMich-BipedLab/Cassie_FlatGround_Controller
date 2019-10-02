%CASSIELOG Interface class for handling Cassie log files
%
% Syntax:
%   log = CassieLog(fileName, logType)

% Copyright 2017-2018 Agility Robotics

classdef CassieLog < LogReader
  
  % CONSTANT PROPERTIES ========================================================
  properties (Constant)
    % Motor name list
    motorNameList = {'Hip Roll', 'Hip Yaw', 'Hip Pitch', 'Knee', 'Foot'}
    % Joint name list
    jointNameList = {'Shin', 'Tarsus', 'Foot'}
  end % constant properties
  
  % PUBLIC METHODS =============================================================
  methods (Access = public)
    function obj = CassieLog(varargin)
      %CASSIELOG Construct interface object for Cassie real-time log files
      
      % Create structure representing binary log data
      logStruct.out = CassieModule.getOutStruct;
      logStruct.userIn = CassieModule.getUserInStruct;
      busOptions = 'singlefloats';
      
      % Call superclass constructor
      obj = obj@LogReader(logStruct, busOptions);
      
      % Set default sample rate
      obj.sampleRate = 5e-4;
      
      % If arguments were provided to constructor, pass them to the load method
      if nargin
        obj.load(varargin{:});
      end % if
    end % CassieLog
    
    function load(obj, varargin)
      %LOAD Calls the superclass load function and trims data with no ethercat
      %operation
      
      % Load the data
      load@LogReader(obj, varargin{:});
      
      % Trim the data
      obj.trimNonOperationalTime;
    end % load
    
    function plotEtherCatStatus(obj)
      %PLOTETHERCATSTATUS Plots the EtherCAR Status vector
      
      % Get the log time vector
      time = obj.getTime;
      
      % Get the EtherCAT status vector
      etherCatStatus = obj.getField('out.pelvis.targetPc.etherCatStatus')';
      
      % Define Y labels
      yLabelList = {...
        'Error Status', ...
        'Master State', ...
        'DC Error Status', ...
        'Master To Network Clock Difference (ns)', ...
        'DC Init State', ...
        'Network To Slave Clock Difference (ns)'};
      
      % Initialize figure
      obj.initializeFigure('EtherCAT Status');
      
      % Plot EtherCAT status
      for i = 1:6
        h(i) = subplot(3, 2, i); hold on; grid on; box on;
        ylabel(yLabelList(i));
        xlabel('Time (s)');
        plot(time, etherCatStatus(:, i));
      end % for
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotEtherCatStatus
    
    function displayMessageSummary(obj)
      %DISPLAYMESSAGESUMMARY Display a summary of the diagnostics codes
      
      % Get the log time vector
      t = obj.getTime;
      
      % Bin and count diagnostic messages
      msg = double(obj.getField('out.messages'));
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
    
    function displayMessages(obj, messageName)
      %DISPLAYMESSAGES Display the messages and time stamps
      
      % Get the log time vector
      t = obj.getTime;
      
      % Get the diagnostic codes vector
      message = obj.getField('out.messages');
      
      % Check for optional input argument
      if exist('messageName', 'var')
        % Find filtered messages
        [r, c] = find(message == messageName);
      else
        % Find all error messages
        [r, c] = find(message);
      end % if
      
      % Loop through found message
      for i = 1:length(r)
        % Get current message properties
        tmsg = t(c(i));
        msg = char(DiagnosticCodes(message(r(i), c(i))));
        
        % Display time and error message
        fprintf('(%0.4f) %s\n', tmsg, msg);
      end % for
    end % displayMessages
    
    function plotDiagnosticCodes(obj)
      %PLOTDIAGNOSTICCODES Plot the diagnostic codes
      
      % Initialize the figure
      obj.initializeFigure('Diagnostic Codes');
      
      % Plot diagnostic codes
      hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Diagnostic Code');
      stem(obj.getTime, obj.getField('out.messages')');
    end % plotDiagnosticCodes
    
    function plotBatteryState(obj)
      %PLOTBATTERYSTATE Plot the battery state
      
      % Get the log time vector
      t = obj.getTime;
      
      % Initialize the figure
      obj.initializeFigure('Battery State');
      
      % Plot voltage
      h(1) = subplot(3, 1, 1); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Voltage (V)');
      plot(t, obj.getField('out.pelvis.battery.voltage'));
      
      % Plot current
      h(2) = subplot(3, 1, 2); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Current (A)');
      plot(t, obj.getField('out.pelvis.battery.current'));
      
      % Plot power
      h(3) = subplot(3, 1, 3); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Temperature (C)');
      plot(t, obj.getField('out.pelvis.battery.temperature'));
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotBatteryState
    
    function plotPower(obj)
      %PLOTBATTERYSTATE Plot the battery state
      
      % Get the log time vector
      t = obj.getTime;
      voltage = sum(obj.getField('out.pelvis.battery.voltage'), 1);
      current = obj.getField('out.pelvis.battery.current');
      power = voltage.*current;
      meanPower = mean(power);
      
      % Initialize the figure
      obj.initializeFigure('Power');
      
      % Plot power
      hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Power (W)');
      plot(t, power);
      plot([t(1), t(end)], [meanPower meanPower], '--');
    end % plotPower
    
    function plotImuState(obj)
      %PLOTIMUSTATE Plots the IMU state
      
      % Get the log time vector
      t = obj.getTime;
      
      % Initialize figure
      obj.initializeFigure('IMU State');
      
      % Plot pressure
      h(1) = subplot(3, 2, 1); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Pressure (kPa)');
      plot(t, obj.getField('out.pelvis.vectorNav.pressure'));
      
      % Plot temperature
      h(2)= subplot(3, 2, 3); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Temperature (C)');
      plot(t, obj.getField('out.pelvis.vectorNav.temperature'));
      
      % Plot magnetic field
      h(3)= subplot(3, 2, 5); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Magnetic Field (Gauss)');
      plot(t, obj.getField('out.pelvis.vectorNav.magneticField'));
      legend('x', 'y', 'z');
      
      % Plot angular velocity
      h(4) = subplot(3, 2, 2); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Angular Velocity (rad/s)');
      plot(t, obj.getField('out.pelvis.vectorNav.angularVelocity'));
      legend('x', 'y', 'z');
      
      % Plot linear acceleration
      h(5) = subplot(3, 2, 4); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Linear Acceleration (m/s/s)');
      plot(t, obj.getField('out.pelvis.vectorNav.linearAcceleration'));
      legend('x', 'y', 'z');
      
      % Plot orientation
      h(6) = subplot(3, 2, 6); hold on; grid on; box on;
      xlabel('Time (s)');
      ylabel('Orientation (quaternion)');
      plot(t, obj.getField('out.pelvis.vectorNav.orientation'));
      legend('w', 'x', 'y', 'z');
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotImuState
    
    function plotMotorPosition(obj)
      %PLOTMOTORPOSITION Plot the motor positions
      
      % Initialize the figure
      obj.initializeFigure('Motor Position');
      
      % Plot the data
      obj.plotMotorData(obj.getMotorPosition, 'Position', 'rad');
    end % plotMotorPosition
    
    function plotMotorVelocity(obj)
      %PLOTMOTORVELOCITY Plot the motor velocities
      
      % Initialize the figure
      obj.initializeFigure('Motor Velocity');
      
      % Plot the data
      obj.plotMotorData(obj.getMotorVelocity, 'Velocity', 'rad/s');
    end % plotMotorVelocity
    
    function plotMotorTemperature(obj)
      %PLOTMOTORTEMPERATURE Plot the motor temperatures
      
      % Initialize the figure
      obj.initializeFigure('Motor Temperature');
      
      % Plot the data
      obj.plotMotorData(obj.getMotorTemperature, 'Temperature', 'C');
    end % plotMotorTemperature
    
    function plotMotorTorques(obj)
      %PLOTMOTORTORQUES Plot the actual and commanded motor torques
      
      % TODO: Legend for commanded/actual? Not sure best way to add
      
      % Initialize the figure
      obj.initializeFigure('Motor Torque');
      
      % Plot the data
      obj.plotMotorData(obj.getCommandedMotorTorque, 'Torque', 'Nm');
      obj.plotMotorData(obj.getActualMotorTorque, 'Torque', 'Nm');
      legend('Commanded', 'Actual');
    end % plotMotorTorques
    
    function plotJointPosition(obj)
      %PLOTJOINTPOSITION Plot the joint positions
      
      % Initialize the figure
      obj.initializeFigure('Joint Position');
      
      % Plot the data
      obj.plotJointData(obj.getJointPosition, 'Position', 'rad');
    end % plotJointPosition
    
    function plotJointVelocity(obj)
      %PLOTJOINTVELOCITY Plot the joint velocities
      
      % Initialize the figure
      obj.initializeFigure('Joint Velocity');
      
      % Plot the data
      obj.plotJointData(obj.getJointVelocity, 'Velocity', 'rad/s');
    end % plotJointVelocity
    
    function plotTorqueSpeedCurve(obj)
      %PLOTTORQUESPEEDCURVE Plot the torque speed curve of each motor
      
      % TODO: Legend for left/right? Not sure best way to add
      
      % Define maximum motor velocity
      dq_max = repmat([12.1475; 12.1475; 8.51; 8.51; 11.52], 2, 1);
      
      % Define maximum motor torque
      u_max = repmat([112.5; 112.5; 195.2; 195.2; 45], 2, 1);
      
      % Get the motor velocity and torque
      dq = obj.getMotorVelocity;
      u = obj.getActualMotorTorque;
      
      % Initialize Figure
      obj.initializeFigure('Motor Torque-Speed Curve');
      
      % Plot torque speed curves
      for i = 1:5
        h(i) = subplot(2, 3, i); hold on; grid on; box on; axis tight;
        title(obj.motorNameList{i});
        xlabel('Velocity (rad/s)');
        ylabel('Torque (N*m)');
        plot(dq(i, :), u(i, :));
        plot(dq(i + 5, :), u(i + 5, :));
        plot(...
          [-dq_max(i) 0 dq_max(i) 0 -dq_max(i)], ...
          [0 u_max(i) 0 -u_max(i) 0], '--r');
      end % for
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotTorqueSpeedCurve
    
    function visualize(obj)
      %VISUALIZE Visualize and playback animation of the log
      
      % Get the log time vector
      t = obj.getTime;
      
      % Define state vector
      state = [...
        obj.getField('out.pelvis.vectorNav.orientation')
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
      
      if ~isempty(obj.vivePose)
        % Send time, state, and vive pose data to the visualizer
        pose = obj.vivePose(:, :, first:last);
        CassieVisualizer(t, state, pose);
      else
        % Send just time and state to the visualizer
        CassieVisualizer(t, state);
      end % if
    end % visualize
    
    function exportFigures(obj)
      %EXPORTFIGURES Plot and exports all methods and saves the figures
      
      % Run each plot method and save resulting figure
      obj.plotEtherCatStatus;
      saveas(gcf, 'EtherCatStatus.svg', 'svg');
      obj.plotDiagnosticCodes;
      saveas(gcf, 'MessageScope.svg', 'svg');
      obj.plotBatteryState;
      saveas(gcf, 'BatteryState.svg', 'svg');
      obj.plotImuState;
      saveas(gcf, 'ImuState.svg', 'svg');
      
      obj.plotMotorPosition;
      saveas(gcf, 'MotorPosition.svg', 'svg');
      obj.plotMotorVelocity;
      saveas(gcf, 'MotorVelocity.svg', 'svg');
      obj.plotMotorTorques;
      saveas(gcf, 'MotorTorque.svg', 'svg');
      obj.plotMotorTemperature;
      saveas(gcf, 'MotorTemperature.svg', 'svg');
      obj.plotJointPosition;
      saveas(gcf, 'JointPosition.svg', 'svg');
      obj.plotJointVelocity;
      saveas(gcf, 'JointVelocity.svg', 'svg');
      
      obj.plotPower;
      saveas(gcf, 'Power.svg', 'svg');
      obj.plotTorqueSpeedCurve;
      saveas(gcf, 'TorqueSpeedCurve.svg', 'svg');
    end % exportFigures
    
    function logSummary = getSummary(obj)
      %GETSUMMARY store the summary of log data in a struct
      
      % Call summary function in CassieSummaryModule
      logSummary = CassieSummaryModule.getSummary(obj);
    end % getSummary
  end % public methods
  
  % GET/SET METHODS ============================================================
  methods
    function motorPosition = getMotorPosition(obj)
      motorPosition = [...
        obj.getField('out.leftLeg.hipRollDrive.position')
        obj.getField('out.leftLeg.hipYawDrive.position')
        obj.getField('out.leftLeg.hipPitchDrive.position')
        obj.getField('out.leftLeg.kneeDrive.position')
        obj.getField('out.leftLeg.footDrive.position')
        obj.getField('out.rightLeg.hipRollDrive.position')
        obj.getField('out.rightLeg.hipYawDrive.position')
        obj.getField('out.rightLeg.hipPitchDrive.position')
        obj.getField('out.rightLeg.kneeDrive.position')
        obj.getField('out.rightLeg.footDrive.position')];
    end % getMotorPosition
    
    function motorVelocity = getMotorVelocity(obj)
      motorVelocity = [...
        obj.getField('out.leftLeg.hipRollDrive.velocity')
        obj.getField('out.leftLeg.hipYawDrive.velocity')
        obj.getField('out.leftLeg.hipPitchDrive.velocity')
        obj.getField('out.leftLeg.kneeDrive.velocity')
        obj.getField('out.leftLeg.footDrive.velocity')
        obj.getField('out.rightLeg.hipRollDrive.velocity')
        obj.getField('out.rightLeg.hipYawDrive.velocity')
        obj.getField('out.rightLeg.hipPitchDrive.velocity')
        obj.getField('out.rightLeg.kneeDrive.velocity')
        obj.getField('out.rightLeg.footDrive.velocity')];
    end % getMotorVelocity
    
    function jointPosition = getJointPosition(obj)
      jointPosition = [...
        obj.getField('out.leftLeg.shinJoint.position')
        obj.getField('out.leftLeg.tarsusJoint.position')
        obj.getField('out.leftLeg.footJoint.position')
        obj.getField('out.rightLeg.shinJoint.position')
        obj.getField('out.rightLeg.tarsusJoint.position')
        obj.getField('out.rightLeg.footJoint.position')];
    end % getJointPosition
    
    function jointVelocity = getJointVelocity(obj)
      jointVelocity = [...
        obj.getField('out.leftLeg.shinJoint.velocity')
        obj.getField('out.leftLeg.tarsusJoint.velocity')
        obj.getField('out.leftLeg.footJoint.velocity')
        obj.getField('out.rightLeg.shinJoint.velocity')
        obj.getField('out.rightLeg.tarsusJoint.velocity')
        obj.getField('out.rightLeg.footJoint.velocity')];
    end % getJointVelocity
    
    function motorTorque = getCommandedMotorTorque(obj)
      motorTorque = obj.getField('userIn.torque');
    end % getCommandedMotorTorque
    
    function motorTorque = getActualMotorTorque(obj)
      motorTorque = [...
        obj.getField('out.leftLeg.hipRollDrive.torque')
        obj.getField('out.leftLeg.hipYawDrive.torque')
        obj.getField('out.leftLeg.hipPitchDrive.torque')
        obj.getField('out.leftLeg.kneeDrive.torque')
        obj.getField('out.leftLeg.footDrive.torque')
        obj.getField('out.rightLeg.hipRollDrive.torque')
        obj.getField('out.rightLeg.hipYawDrive.torque')
        obj.getField('out.rightLeg.hipPitchDrive.torque')
        obj.getField('out.rightLeg.kneeDrive.torque')
        obj.getField('out.rightLeg.footDrive.torque')];
    end % getActualMotorTorque
    
    function motorTemperature = getMotorTemperature(obj)
      motorTemperature = [...
        obj.getField('out.leftLeg.hipRollDrive.driveTemperature')
        obj.getField('out.leftLeg.hipYawDrive.driveTemperature')
        obj.getField('out.leftLeg.hipPitchDrive.driveTemperature')
        obj.getField('out.leftLeg.kneeDrive.driveTemperature')
        obj.getField('out.leftLeg.footDrive.driveTemperature')
        obj.getField('out.rightLeg.hipRollDrive.driveTemperature')
        obj.getField('out.rightLeg.hipYawDrive.driveTemperature')
        obj.getField('out.rightLeg.hipPitchDrive.driveTemperature')
        obj.getField('out.rightLeg.kneeDrive.driveTemperature')
        obj.getField('out.rightLeg.footDrive.driveTemperature')];
    end % getMotorTemperature
  end % get/set methods
  
  % PRIVATE METHODS ============================================================
  methods (Access = private)
    function initializeFigure(~, name)
      %INITIALIZEFIGURE Helper method for initializing figure
      figure(...
        'Name', name, ...
        'Units', 'normalized', ...
        'Outerposition', [0 0 1 1]);
      hold on; grid on; box on; axis tight;
    end % initializeFigure
    
    function output = processDataStatistics(~, data)
      %PROCESSDATASTATISTICS Helper method for computing data statistics
      output.max = max(data, [], 2);
      output.min = min(data, [], 2);
      output.mean = mean(data, 2);
      output.rms = sqrt(mean(data.^2, 2));
      output.var = mean((data - output.mean).^2, 2);
      output.std = sqrt(output.var);
    end % processDataStatistics
    
    function plotMotorData(obj, data, param, units)
      %PLOTMOTORDATA Helper method for plotting motor data
      
      % Validate input arguments
      validateattributes(data, {'numeric'}, {'nrows', 10}, '');
      
      % Get the log time vector
      t = obj.getTime;
      
      % Loop through motor indices
      for i = 1:5
        % Plot left leg motor data
        h(i) = subplot(5, 2, 2*i - 1); hold on; grid on; box on; axis tight;
        title(['Left ' obj.motorNameList{i}]);
        xlabel('Time (s)');
        ylabel([param, ' (', units, ')']);
        plot(t, data(i,:));
        
        % Plot right leg motor data
        h(i + 5) = subplot(5, 2, 2*i); hold on; grid on; box on; axis tight;
        title(['Right ' obj.motorNameList{i}]);
        xlabel('Time (s)');
        ylabel([param, ' (', units, ')']);
        plot(t, data(i + 5,:));
      end % for
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotMotorData
    
    function plotJointData(obj, data, param, units)
      %PLOTJOINTDATA Helper method for plotting joint data
      
      % Validate input arguments
      validateattributes(data, {'numeric'}, {'nrows', 6}, '');
      
      % Get the log time vector
      t = obj.getTime;
      
      % Loop through joint indices
      for i = 1:3
        % Plot left leg joint data
        h(i) = subplot(3, 2, 2*i - 1); hold on; grid on; box on; axis tight;
        title(['Left ' obj.jointNameList{i}]);
        xlabel('Time (s)');
        ylabel([param, ' (', units, ')']);
        plot(t, data(i, :));
        
        % Plot right leg joint data
        h(i + 3) = subplot(3, 2, 2*i); hold on; grid on; box on; axis tight;
        title(['Right ' obj.jointNameList{i}]);
        xlabel('Time (s)');
        ylabel([param, ' (', units, ')']);
        plot(t, data(i + 3, :));
      end % for
      
      % Link subplot axes together
      linkaxes(h, 'x');
    end % plotJointData
    
    function trimNonOperationalTime(obj)
      %TRIMNONOPERATIONALTIME trims the time window where EtherCAT is not
      %operational
      
      etherCatData = obj.getField('out.pelvis.targetPc.etherCatStatus');
      timeIndex = find(etherCatData(2,:) == 8, 1, 'first');
      t = obj.getTime();
      
      % If there is any data in the log with EtherCAT in OP state, trim data
      if ~isempty(timeIndex)
        obj.setStartTime(t(timeIndex));
      else
        warning('Log file contains no data with the EtherCAT bus in operational state');
      end % if
    end % trimNonOperationalTime
  end % private methods
end % classdef
