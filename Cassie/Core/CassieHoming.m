% CASSIEHOMING Cassie homing system
% 
%  Syntax:
%    Implements a MATLAB System block for use in Simulink with inputs:
%      cassieOutputs (CassieOutBus)
%    and outputs:
%      cassieOutputs (CassieOutBus)
% 
%  Description:
%    Implements the homing routine for the Cassie hardware. The basic routine is
%    as follows:
%      - Wait for the EtherCAT system to become fully operational
%      - Check which reed switches have been triggered
%      - Compute the offset required to calibrate and unwrap each degree of
%      freedom based on its home position, calibration position, tick to radian
%      ratio, and current uncalibrated position
%      - Once all degrees of freedom have been calibrated, set the calibration
%      flag in the output structure to be true
% 
%  Notes:
%    The IC-Haus absolute encoders will sometimes initialize 1/32 of
%    revolution off. To account for this, there is some extra unwrapping
%    code to try to catch and adjust for faulty initializations. This is
%    implemented by setting a virtual joint gear ratio of 32:1
%
%    Reference page in Doc Center
%       doc CassieHoming
%
%