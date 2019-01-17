% BUTTERWORTHFILTER Implements a Butterworth filter object
% 
%  Syntax:
%    filter = ButterworthFilter(order)
%    filter.setTimeConstant(tau, dt)
% 
%    where,
%      order = The order of the butterworth filter
%      tau = Time constant
%      dt = Sample time
% 
%  Description:
%    Implements a Butterworth low-pass filter of arbitrary order with a
%    s-domain transfer function defined as:
%      H(s) = G_0/Bn(a)
%    where a = s/w_c, w_c is cutoff frequency, and G_0 is steady-state gain
%    Bn(s) is a Butterworth polynomial. A polynomial of order n has the
%    form:
%      Bn(s) = product(from k=1 to n/2) of
%          (s^2 - 2*s*cos((2*k + n - 1)*pi/2*n + 1) if n = even
%      Bn(s) = (s+1)*product(from k=1 to (n-1)/2) of
%          (s^2 - 2*s*cos((2*k + n - 1)*pi/2*n + 1) if n = odd
% 
%  TODO:
%    - Use prototype filters to implement different types of butterworth
%      filters, e.g. high-pass
%
%    Reference page in Doc Center
%       doc ButterworthFilter
%
%