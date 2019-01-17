% State Estimator
classdef ExtractJointPosition < matlab.System & matlab.system.mixin.Propagates %#codegen
    
    % PROTECTED PROPERTIES ==================================================
    properties (Access = protected)
    end % properties
    
    % Private variables
    properties(Access = private)
    end
    
    % Pre-computed constants
    properties(Access = private, Constant)
    end
    
    % PROTECTED METHODS =====================================================
    methods (Access = protected)
        
        function setupImpl(obj)
            %SETUPIMPL Initialize System object.
        end % setupImpl
        
        function [JointPosition]= stepImpl(obj, cassieOutputs)
            qa = CassieModule.getDriveProperty(cassieOutputs,'position');
            dqa = CassieModule.getDriveProperty(cassieOutputs,'velocity');
            qj = CassieModule.getJointProperty(cassieOutputs,'position');
            dqj = CassieModule.getJointProperty(cassieOutputs,'velocity');
            qq = cassieOutputs.pelvis.vectorNav.orientation;
            qaL = qa(1:5);
            qjL =  qj(1:2);
            qaR = qa(6:10);
            qjR =  qj(4:5);
            qsL = getSpringDeflectionAngle(qaL(4),qjL(1),qjL(2));
            qsR = getSpringDeflectionAngle(qaR(4),qjR(1),qjR(2));
            
            JointPosition = [qaL;qaR;qjL;qjR];

        end % stepImpl
        
        %% Define Outputs
        function resetImpl(~)
            %RESETIMPL Reset System object states.
        end % resetImpl
        
        function [q_fil, AngularVelocity_fil] = getOutputSizeImpl(~)
            %GETOUTPUTSIZEIMPL Get sizes of output ports.
            q_fil = [14, 1];
            AngularVelocity_fil = [3, 1];
            
        end % getOutputSizeImpl
        
        function [q_fil, AngularVelocity_fil] = getOutputDataTypeImpl(~)
            %GETOUTPUTDATATYPEIMPL Get data types of output ports.
            q_fil = 'double';
            AngularVelocity_fil = 'double';
        end % getOutputDataTypeImpl
        
        function [q_fil, AngularVelocity_fil] = isOutputComplexImpl(~)
            %ISOUTPUTCOMPLEXIMPL Complexity of output ports.
            q_fil = false;
            AngularVelocity_fil = false;
        end % isOutputComplexImpl
        
        function [q_fil, AngularVelocity_fil]= isOutputFixedSizeImpl(~)
            %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports.
            q_fil = true;
            AngularVelocity_fil = true;
        end % isOutputFixedSizeImpl
    end % methods
end % classdef