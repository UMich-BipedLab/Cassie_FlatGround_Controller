function R = Euler_to_Matrix(yaw,pitch,roll)


R_yaw   = in1(1);
R_pitch = in1(2);
R_roll  = in1(3);

R = R_yaw*R_pitch*R_roll;

end