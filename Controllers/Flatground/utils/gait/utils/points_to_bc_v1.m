function [ alpha ] = points_to_bc_v1( points,dpoints,tp,M )
% one row in the points matrix represent a trajectory
% dpoints is the changing rates of points
% use matlab built-in function
n = size(points,1); % how many trajectory
m = size(points,2); % how many points in one trajectory
s = linspace(0,1,m);
alpha = zeros(n,M+1);
alpha(:,1) = points(:,1);
alpha(:,end) = points(:,end);
alpha(:,2) = alpha(:,1) + dpoints(:,1)*tp/M;
alpha(:,end-1) = alpha(:,end) - dpoints(:,end)*tp/M;

[alpha_sym,b_sym,s_sym]=bc_curve_symbolic(M);
alpha_str=arrayfun(@char,alpha_sym,'UniformOutput', false);

p_a=alpha_str([1,2,end-1,end]);
c_a=alpha_str(3:end-2);
g=matlabFunction(b_sym,'Vars',[ alpha_sym(3:end-2) alpha_sym([1,2,end-1,end]) s_sym]);
bcft=fittype(g,'independent','s','coefficients',c_a,'problem',p_a);
for k=1:n
    result=fit(s',points(k,:)',bcft,'problem',num2cell(alpha(k,[1,2,end-1,end])),'StartPoint',zeros(1,M-3));
    mid_index=3:M-1;
    alpha(k,mid_index)=coeffvalues(result);
end

end

