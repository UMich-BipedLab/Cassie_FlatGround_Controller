% FILTER Implements a digital filter object
% 
%  Syntax:
%    filter = Filter(b, a, numberOfSignals)
% 
%    where,
%      a = Coefficients for filtered signal
%      b = Coefficients for unfiltered signal
%      numberOfSignals = The number of signals this filter applies too
% 
%  Description:
%    This filter implementation uses the "Direct Form II Transposed"
%    difference equation:
% 
%      a(1)*y(n) = b(1)*x(n) +  ...  + b(nb+1)*x(n-nb) ...
%                - a(2)*y(n-1) - ... - a(na+1)*y(n-na)
% 
%  Notes:
%    - Coefficients are automatically normalized so a(1) is equal to one.
%
%    Reference page in Doc Center
%       doc Filter
%
%