% NONLINEARLEASTSQUARESSOLVER Nonlinear least squares solver object
% 
%  Syntax:
%    solver = NonlinearLeastSquaresSolver(problem)
% 
%  Description:
%    The Levenberg-Marquardt algorithm is a damped least squares method used
%    to solve nonlinear least squares problems.
% 
%  Notes:
%    Use small value for tau (1e-6) if x0 is believed to be close
%    to x*, otherwise use something larger (1e-3 < tau < 1).
%
%    Reference page in Doc Center
%       doc NonlinearLeastSquaresSolver
%
%