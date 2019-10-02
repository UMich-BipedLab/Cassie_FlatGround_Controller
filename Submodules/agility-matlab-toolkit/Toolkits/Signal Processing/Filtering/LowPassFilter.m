% LOWPASSFILTER Implements a low pass filter object
% 
%  Syntax:
%    filter = LowPassFilter
%    filter.setSmoothingFactor(alpha)
%    filter.setTimeConstant(tau, dt)
%    filter.setCutoffFrequency(f_c, dt)
% 
%    where,
%      alpha = Smoothing factor between 0 and 1
%      tau = Time constant
%      f_c = Cutoff frequency
%      dt = Sample time
% 
%  Description:
%    Implements a low-pass filter object and provides methods for setting
%    the smoothing factor, time constant, or cutoff frequency of the filter.
%
%    Reference page in Doc Center
%       doc LowPassFilter
%
%