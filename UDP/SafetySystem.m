%SAFETYSYSTEM Overwrites torque values to ensure safety
% Author: Ross Hartley
% Date:   10/23/2018

classdef SafetySystem < ...
        matlab.System & ...
        matlab.system.mixin.Propagates %#codegen
    
    % NONTUNABLE PROPERTIES ======================================================
    properties (Nontunable)
        % Flag indicating if simulation or experiment
        isSim = false;
        % Threshold to trigger torque smoothing
        torque_discontinuity_threshold = 10;
    end % nontunable properties
    
    % Private variables ======================================================
    properties(Access = private)
        safe_inputs_prev = CassieModule.getUserInStruct();
        u_cont_alpha = zeros(10,1); % u continuity sigmoid offset
        u_cont_beta = 50;           % u continuity sigmoid decay rate
        u_cont_t0 = 0;              % u continuity time of recompute
    end
    
    % Pre-computed constants ======================================================
    properties(Access = private, Constant)
        motorMaximumTorque = [16*4.5;16*4.5;25*12.2;25*12.2;50*0.9; ...
                              16*4.5;16*4.5;25*12.2;25*12.2;50*0.9]; 
    end
    
    % PROTECTED METHODS =====================================================
    methods (Access = protected)
        % SYSTEM CLASS METHODS ================================================
        function setupImpl(~)
            %SETUPIMPL Initialize System object.
        end % setupImpl
        
        function safe_inputs = stepImpl(obj, t, inputs, udp_timeout)
            %STEPIMPL System output and state update equations.
            safe_inputs = inputs;
            
            % If inf or nan is detected, zero torques
            if any(abs(safe_inputs.torque)>1e6)
                safe_inputs.torque = zeros(10,1);
                return;
            end            
            
            % If large delay detected in ProcessUdpPacket, zero torques
            if ((udp_timeout > 0) && ~obj.isSim)
                safe_inputs.torque = zeros(10,1);
                return;
            end
            
            % Sigmoid-based torque smoothing
            if any(abs(safe_inputs.torque - obj.safe_inputs_prev.torque)...
                   > obj.torque_discontinuity_threshold)
                % Reset sigmoid parameters
                 obj.u_cont_t0 = t;
                 obj.u_cont_alpha = safe_inputs.torque - obj.safe_inputs_prev.torque;
            end
            u_sig = -(2.*obj.u_cont_alpha - 2.*obj.u_cont_alpha./(1+exp(-obj.u_cont_beta*(t-obj.u_cont_t0))));
            obj.safe_inputs_prev = safe_inputs; % Store previous values before modifying
            safe_inputs.torque = safe_inputs.torque + u_sig;
                      
            % Saturate torques
            safe_inputs.torque = saturate(safe_inputs.torque, -obj.motorMaximumTorque, obj.motorMaximumTorque);
            
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
            dt_1 = 'CassieUserInBus';
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