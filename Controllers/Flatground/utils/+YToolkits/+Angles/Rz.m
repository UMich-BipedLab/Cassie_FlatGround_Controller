function [R] = Rz(theta)
% Rotate theta radians about the z-axis
R = [cos(theta), -sin(theta), 0; 
     sin(theta),  cos(theta), 0; 
              0,           0, 1];
end

