function [Data] = getLinuxDataStruct(varargin)
%GETDATASTRUCTURE Summary of this function goes here
%   Detailed explanation goes here

Data = struct;
if nargin > 0
    if ischar(varargin{1}) && strcmp(varargin{1}, 'annotated')
        Data.busname_ = 'CassieLinuxDataBus';
        Data.cstructname_ = 'cassie_linux_data_t';
        Data.userInputs = CassieModule.getUserInStruct('annotated');
    else
        error('Unrecognized input');
    end
else
    Data.userInputs = CassieModule.getUserInStruct();
end

% Data.control.type
% 0 - torque control
% 1 - position control
% 2 - position control with floating base gravity compensation
% 3 - position control with single support gravity compensation
% 4 - position control with feedback linearization (no Coriolis)
% 5 - position control with feedback linearization 
Data.control.type = int32(0); 
Data.control.Kff1 = 0; % Gain for user provided feedforward
Data.control.Kff2 = 0; % Gait for calculated feedforward
Data.control.motorPositionsDesired = zeros(10,1);
Data.control.motorVelocitiesDesired = zeros(10,1);

Data.inekf.enabled = int32(0);
Data.inekf.velocity = zeros(3,1);

Data.state.q = zeros(20,1);
Data.state.dq = zeros(20,1);

end

