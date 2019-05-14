rng default % For reproducibility
fun = @OptSimulation;


lb = [0,0,0,0, -1];
ub = [1,1,1,1, +1];

options = optimoptions('surrogateopt','PlotFcn','surrogateoptplot',...
    'InitialPoints',[0.2 0.35 0.2 0.4],'MaxFunctionEvaluations',120);

xSout = surrogateopt(fun,lb,ub,options);