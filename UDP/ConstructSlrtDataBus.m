

classdef ConstructSlrtDataBus < ...
    matlab.System & ...
    matlab.system.mixin.Propagates %#codegen

  % PROTECTED METHODS =====================================================
  methods (Access = protected)
    % SYSTEM CLASS METHODS ================================================
    function setupImpl(~)
      %SETUPIMPL Initialize System object.
    end % setupImpl

    function data = stepImpl(~, t, outputs)
      %STEPIMPL System output and state update equations.
      data = getSlrtDataStruct;
      data.t = t;
      data.outputs = outputs;
      
    end % stepImpl

    function resetImpl(~)
      %RESETIMPL Reset System object states.
    end % resetImpl

    function [name_1, name_2] = getInputNamesImpl(~)
      %GETINPUTNAMESIMPL Return input port names for System block.
      name_1 = 't';
      name_2 = 'outputs';
    end % getInputNamesImpl

    function name_1 = getOutputNamesImpl(~)
      %GETOUTPUTNAMESIMPL Return output port names for System block.
      name_1 = 'data';
    end % getOutputNamesImpl

    % PROPAGATES CLASS METHODS ============================================
    function sz_1 = getOutputSizeImpl(~)
      %GETOUTPUTSIZEIMPL Get sizes of output ports.
      sz_1 = [1, 1];
    end % getOutputSizeImpl

    function dt_1 = getOutputDataTypeImpl(~)
      %GETOUTPUTDATATYPEIMPL Get data types of output ports.
      dt_1 = 'CassieSlrtDataBus';
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