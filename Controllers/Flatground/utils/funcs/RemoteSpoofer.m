% RemoteSpoofer
classdef RemoteSpoofer < matlab.System & matlab.system.mixin.Propagates %#codegen
    
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
        
        function [cassieOutputs] = stepImpl(obj, cassieOutputs,t)
            
%             RadioButton = RadioChannelToButton(cassieOutputs.pelvis.radio.channel);
%             if t < 5
%                 RadioButton.SBA = 0;
%             end
%             if t > 5
%                 RadioButton.SBA = 1;
%             end
%             if t>8
%                 RadioButton.LVA = 0;
%             end
%             RadioButton.LSA = median([-1,t-0.5-1,1]);
%             cassieOutputs.pelvis.radio.channel = RadioButtonToChannel(RadioButton);


            RadioButton = RadioChannelToButton(cassieOutputs.pelvis.radio.channel);

            if t < 1.5
                RadioButton.SBA = 0;
            end
%             if t > 2 % switch to walking
%                 RadioButton.SBA = 1;
%             end
            
%             if t < 1.5
%                 RadioButton.SBA = 0;
%             end
            RadioButton.SCA = - 1;  % knee compensation on 
            RadioButton.SDA = - 1;  % thigh compensation on
            RadioButton.SGA = - 1; % abduction compensation on 
            RadioButton.LVA = 0;
            if t > 2 % switch to walking
                RadioButton.SBA = 1;
                RadioButton.SFA = 1;  % updating ILC
                
            end
            
            if t > 3
                RadioButton.LVA = 1;
            end    
%             if  t > 10
%                  RadioButton.SCA = 1;  % knee compensation on 
%             end       
%             if  t > 12
%                  RadioButton.SDA = 0; % thigh compensation on
%             end     
%             if  t > 10
% %                 RadioButton.SGA = 0; % abduction compensation on 
%                 RadioButton.SGA = 1;
%             end 
             
            RadioButton.LSA = 1; % full leg length
            
%             if t < 0.5
%                 RadioButton.SFA = 0; % InEKF is off
%             else
%                 RadioButton.SFA = 1; % InEKF is on
%             end    
            cassieOutputs.pelvis.radio.channel = RadioButtonToChannel(RadioButton);


        end % stepImpl
        
        %% Define Outputs
        function resetImpl(~)
            %RESETIMPL Reset System object states.
        end % resetImpl
        
        function out = getOutputSizeImpl(~)
            %GETOUTPUTSIZEIMPL Get sizes of output ports.
            out = [1, 1];           
        end % getOutputSizeImpl
        
        function out = getOutputDataTypeImpl(~)
            %GETOUTPUTDATATYPEIMPL Get data types of output ports.
            out = 'CassieOutBus';
        end % getOutputDataTypeImpl
        
        function out = isOutputComplexImpl(~)
            %ISOUTPUTCOMPLEXIMPL Complexity of output ports.
            out = false;
        end % isOutputComplexImpl
        
        function out= isOutputFixedSizeImpl(~)
            %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports.
            out = true;
        end % isOutputFixedSizeImpl
    end % methods
end % classdef

