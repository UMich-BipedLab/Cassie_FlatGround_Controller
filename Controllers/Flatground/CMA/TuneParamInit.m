% PD gain on Joints (walk)
% c_Kp_pitch = 100;
% c_Kd_pitch = 20;
% c_Kp_roll = 100;
% c_Kd_roll = 20;
% c_Kp_yaw = 200;
% c_Kd_yaw = 4;
c_Kp_pitch = 100;
c_Kd_pitch = 20;
c_Kp_roll = 100;
c_Kd_roll = 20;
c_Kp_yaw = 200;
c_Kd_yaw = 4;


c_Kp_abduction = 400;
c_Kp_rotation = 200;
c_Kp_thigh = 500;
c_Kp_knee = 500;
c_Kp_toe = 10;

c_Kd_abduction = 10;
c_Kd_rotation = 4;
c_Kd_thigh = 15;
c_Kd_knee = 15;
c_Kd_toe = 2;

% PD gain on Joints (stand)
c_Kp_abduction_stand = 400;
c_Kp_thigh_stand = 200;
c_Kp_knee_stand = 500;
c_Kp_rotation_stand = 200;
c_Kp_toe_stand = 600;

c_Kd_abduction_stand = 4;
c_Kd_thigh_stand = 10;
c_Kd_knee_stand = 20;
c_Kd_rotation_stand = 4;
c_Kd_toe_stand = 80;

c_Kp_lateral_stand = 2;
c_Kd_lateral_stand = 0.025;

% filters
c_fil_para_x = 0.002;
c_fil_para_y = 0.002;
c_fil_para_2 = 0.02;
c_fil_para_3 = 0.02;
c_fil_para_4 = 0.001;
c_fil_para_5 = 0.02;

% gravity compensation
c_u_abduction_swing_cp = 14;
c_u_abduction_cp = +YToolkits.ifelse(isSim,40,40);
c_u_thigh_cp = +YToolkits.ifelse(isSim,-10,-15);
c_u_knee_cp = +YToolkits.ifelse(isSim,120,120);

% footplacment
c_Kfs_p = 0.05;
c_Kfs_d = 0.15;

c_Kfl_p = +YToolkits.ifelse(isSim,0.10,0.15);
c_Kfl_d = 0.10;
% offset
c_sagittal_offset_exp = -0.0;
c_lateral_offset_exp = 0.000;
c_turning_offset_exp = 0;
c_stand_offset_exp = 0.01;

% Switch from stand to walk
c_shift_time = +YToolkits.ifelse(isSim,0.3,0.4);
c_shift_distance = +YToolkits.ifelse(isSim,0.030,0.045);

% Switch from walk to stand
c_final_sw_abduction = 0.15;
c_final_st_abduction = 0.05;
c_pre_final_sw_abduction = -0.01;

c_stance_thre_ub = 200;
c_stance_thre_lb = 100;
c_lateral_velocity_weight = 1;
c_init_lateral_velocity = 0.1;
c_abduction_inward_gain = 1;
c_joint_filter_choice = 1; % Mikhail's filter is 0
c_standing_switch_time = 0.4;

c_toe_tilt_angle = 0.3;  % [rad] ~ 17.2 deg
c_force_step_end_s = 1.0;

