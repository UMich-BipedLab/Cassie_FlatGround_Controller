% Main_patternsearch

fun = @OptSimulation;
% Set options to give iterative display and to plot the objective function at each iteration.

options = optimoptions('patternsearch','Display','iter','PlotFcn',@psplotbestf);
% Find the unconstrained minimum of the objective starting from the point [0,0].

% x0 = [0.35,0.35,0.2,0.4,-0.01,0.035];
x0 = [ 0.15    0.4500    0.55    0.6500];

A = [];
b = [];
Aeq = [];
beq = [];
lb = [0 0 0 0];
ub = [1 1 1 1];
nonlcon = [];
x = patternsearch(fun,x0,A,b,Aeq,beq,lb,ub,nonlcon,options);