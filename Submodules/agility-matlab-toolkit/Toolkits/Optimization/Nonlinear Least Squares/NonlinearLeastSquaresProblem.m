% NONLINEARLEASTSQUARESPROBLEM Nonlinear least squares problem object
% 
%  Syntax:
%    problem = NonlinearLeastSquaresProblem(r, lb, ub)
% 
%  Description:
%    Least squares is the problem of finding a vector x that minimizes the
%    sum of the squares of the error. Typically this is used for regression
%    analysis or for overdetermined systems. Given a vector function r(x),
%    we want to minimize ||r(x)||, or equivalently to find
% 
%      x* = argmin_x{f(x)}, where f(x) = 1/2*r(x)'*r(x)
% 
%    subject to:
% 
%      lb <= x <= ub
%
%    Reference page in Doc Center
%       doc NonlinearLeastSquaresProblem
%
%