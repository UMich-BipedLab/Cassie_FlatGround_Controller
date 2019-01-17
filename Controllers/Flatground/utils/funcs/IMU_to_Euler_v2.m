function [yaw, pitch, roll, dyaw, dpitch, droll] = IMU_to_Euler_v1( q,w )
% convert the quaternion angle and angular velocity to euler and euler
% rates

% need further refined for different quadrant

R_fix = [1 0 0; 0 cos(pi) -sin(pi); 0 sin(pi) cos(pi)]; % q is measured when z is pointing down. Move it back




R = YToolkits.Angles.Quaternion_to_Matrix(q);

dR = YToolkits.Angles.AngularVelocity_to_dMatrix(w,R);

% R = R_fix * R * R_fix';
% dR = R_fix * dR * R_fix';

[yaw,pitch,roll] = YToolkits.Angles.Matrix_to_Euler(R);
[dyaw,dpitch,droll] = YToolkits.Angles.dMatrix_to_dEuler(R,dR);
end

