%LOWLEVELCONTROLLER Implements a PD + feedforward joint tracker
% Author: Ross Hartley
% Date:   10/24/2018
classdef LowLevelController < ...
        matlab.System & ...
        matlab.system.mixin.Propagates %#codegen
    
    % NONTUNABLE PROPERTIES ======================================================
    properties (Nontunable)
        % Proportional Gains
        Kp = 1*[400;200;500;500;10; 400;200;500;500;10]; % Original
        % Derivative Gains
        Kd = 1*[10;4;15;15;2; 10;4;15;15;2]; % Original
    end % nontunable properties
    
    % PROTECTED METHODS =====================================================
    methods (Access = protected)
    % SYSTEM CLASS METHODS ================================================
    function setupImpl(~)
    %SETUPIMPL Initialize System object.
    end % setupImpl
    
    function userInputs = stepImpl(obj, outputs, data)
    %STEPIMPL System output and state update equations.
    userInputs = CassieModule.getUserInStruct;
    userInputs = data.userInputs;
    
    switch(data.control.type)
        case 0 % Torque Control
            % Already set
            % userInputs.torque = data.userInputs.torque;
            
        case 1 % Position Control: PD + user provided feedforward
            % Extract actual and desired positions and velocities
            [motorPositions, motorVelocities] = obj.getMotors(outputs);
            motorPositionsDesired = data.control.motorPositionsDesired;
            motorVelocitiesDesired = data.control.motorVelocitiesDesired;
                       
            % PD + feedforward
            uff1 = data.control.Kff1 * data.userInputs.torque;
            ufb = -(obj.Kp.*(motorPositions - motorPositionsDesired) + obj.Kd.*(motorVelocities - motorVelocitiesDesired));
            u = uff1 + ufb;
            
            % Set user inputs
            userInputs.torque = u;            
            
        case 2 % Position Control: PD + user provided feedforward + floating base gravity compensation
            % Extract actual and desired positions and velocities
            [motorPositions, motorVelocities] = obj.getMotors(outputs);
            motorPositionsDesired = data.control.motorPositionsDesired;
            motorVelocitiesDesired = data.control.motorVelocitiesDesired;
                       
            % PD + feedforward + floating base gravity compensation
            uff1 = data.control.Kff1 * data.userInputs.torque;
            uff2 = data.control.Kff2 * B\G;
            ufb = -(obj.Kp.*(motorPositions - motorPositionsDesired) + obj.Kd.*(motorVelocities - motorVelocitiesDesired));
            u = uff1 + uff2 + ufb;
            
            % Set user inputs
            userInputs.torque = u;        
            
        otherwise
            return;
    end
    
    
    
    end % stepImpl
    
    function [motorPositions,motorVelocities] = getMotors(~, outputs) 
        % Extract current positions and velocities
        motorPositions = [outputs.leftLeg.hipRollDrive.position;
            outputs.leftLeg.hipYawDrive.position;
            outputs.leftLeg.hipPitchDrive.position;
            outputs.leftLeg.kneeDrive.position;
            outputs.leftLeg.footDrive.position;
            outputs.rightLeg.hipRollDrive.position;
            outputs.rightLeg.hipYawDrive.position;
            outputs.rightLeg.hipPitchDrive.position;
            outputs.rightLeg.kneeDrive.position;
            outputs.rightLeg.footDrive.position];
        
        motorVelocities = [outputs.leftLeg.hipRollDrive.velocity;
            outputs.leftLeg.hipYawDrive.velocity;
            outputs.leftLeg.hipPitchDrive.velocity;
            outputs.leftLeg.kneeDrive.velocity;
            outputs.leftLeg.footDrive.velocity;
            outputs.rightLeg.hipRollDrive.velocity;
            outputs.rightLeg.hipYawDrive.velocity;
            outputs.rightLeg.hipPitchDrive.velocity;
            outputs.rightLeg.kneeDrive.velocity;
            outputs.rightLeg.footDrive.velocity];
    end
    
    function resetImpl(~)
    %RESETIMPL Reset System object states.
    end % resetImpl
    
    function [name_1, name_2] = getInputNamesImpl(~)
    %GETINPUTNAMESIMPL Return input port names for System block.
    name_1 = 'Outputs';
    name_2 = 'LinuxData';
    end % getInputNamesImpl
    
    function name_1 = getOutputNamesImpl(~)
    %GETOUTPUTNAMESIMPL Return output port names for System block.
    name_1 = 'UserInputs';
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