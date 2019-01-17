function [ alpha ] = points_to_bc_v3( points,dpoints,tp,M )
% one row in the points matrix represent a trajectory
% dpoints is the changing rates of points
% use least square
M = 5;
n = size(points,1); % how many trajectory
m = size(points,2); % how many points in one trajectory
s = linspace(0,1,m);
alpha = zeros(n,M+1);
alpha(:,1) = points(:,1);
alpha(:,end) = points(:,end);
alpha(:,2) = alpha(:,1) + dpoints(:,1)*tp/M;
alpha(:,end-1) = alpha(:,end) - dpoints(:,end)*tp/M;

polyterm = zeros(m,M+1);
for i = 1:m
    for k = 0:M
        polyterm(i,k+1) = (factorial(M)/(factorial(k)*factorial(M-k))) * s(i)^k * (1-s(i))^(M-k);
    end
end

for i = 1:n
    A = polyterm(:,3:end-2);
    b = (points(i,:)'-polyterm(:,[1,2,end-1,end])*alpha(i,[1,2,end-1,end])');
    x = (A'*A)^-1*A'*b;
    alpha(i,3:end-2) = x';
end

