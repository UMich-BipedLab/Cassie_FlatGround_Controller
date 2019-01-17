function [R] = Ry(theta)
% Rotate theta radians about the y-axis
R = [cos(theta), 0, sin(theta); 
              0, 1,          0;
    -sin(theta), 0, cos(theta)];
end

