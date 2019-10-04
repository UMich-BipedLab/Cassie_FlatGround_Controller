%BYTESTOCASSIELINUXDATABUS Convert a byte array to a CassieLinuxDataBus bus.

% Copyright 2018 Agility Robotics
% Generated automatically by BusModule.generateUnpackingSystem

classdef BytesToCassieLinuxDataBus < ...
    matlab.System & ...
    matlab.system.mixin.Propagates %#codegen

  % PROTECTED METHODS =====================================================
  methods (Access = protected)
    % SYSTEM CLASS METHODS ================================================
    function setupImpl(~)
      %SETUPIMPL Initialize System object.
    end % setupImpl

    function bus = stepImpl(~, bytes)
      %STEPIMPL System output and state update equations.

      bus = struct(...
        'userInputs', struct(...
          'torque', double(typecast(bytes(1:40), 'single')), ...
          'telemetry', typecast(bytes(41:58), 'int16')), ...
        'control', struct(...
          'type', typecast(bytes(59:62), 'int32'), ...
          'Kff1', double(typecast(bytes(63:66), 'single')), ...
          'Kff2', double(typecast(bytes(67:70), 'single')), ...
          'motorPositionsDesired', double(typecast(bytes(71:110), 'single')), ...
          'motorVelocitiesDesired', double(typecast(bytes(111:150), 'single'))), ...
        'inekf', struct(...
          'enabled', typecast(bytes(151:154), 'int32'), ...
          'velocity', double(typecast(bytes(155:166), 'single'))), ...
        'state', struct(...
          'q', double(typecast(bytes(167:246), 'single')), ...
          'dq', double(typecast(bytes(247:326), 'single'))));
    end % stepImpl

    function resetImpl(~)
      %RESETIMPL Reset System object states.
    end % resetImpl

    function name_1 = getInputNamesImpl(~)
      %GETINPUTNAMESIMPL Return input port names for System block.
      name_1 = '';
    end % getInputNamesImpl

    function name_1 = getOutputNamesImpl(~)
      %GETOUTPUTNAMESIMPL Return output port names for System block.
      name_1 = '';
    end % getOutputNamesImpl

    % PROPAGATES CLASS METHODS ============================================
    function sz_1 = getOutputSizeImpl(~)
      %GETOUTPUTSIZEIMPL Get sizes of output ports.
      sz_1 = [1, 1];
    end % getOutputSizeImpl

    function dt_1 = getOutputDataTypeImpl(~)
      %GETOUTPUTDATATYPEIMPL Get data types of output ports.
      dt_1 = 'CassieLinuxDataBus';
    end % getOutputDataTypeImpl

    function cp_1 = isOutputComplexImpl(~)
      %ISOUTPUTCOMPLEXIMPL Complexity of output ports.
      cp_1 = false;
    end % isOutputComplexImpl

    function flag_1 = isOutputFixedSizeImpl(~)
      %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports.
      flag_1 = true;
    end % isOutputFixedSizeImpl
  end % methods
end % classdef