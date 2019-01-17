function [ R ] = Rx(theta)
% Rotate theta radians about the x-axis
R = [1,          0,            0; 
     0, cos(theta),  -sin(theta);
     0, sin(theta),   cos(theta)];
end

