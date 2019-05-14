% PD gain on Joints (walk)
% c_Kp_pitch = 100;
% c_Kd_pitch = 20;
% c_Kp_roll = 100;
% c_Kd_roll = 20;
% c_Kp_yaw = 200;
% c_Kd_yaw = 4;

% c_Kp_pitch = 100;
% c_Kd_pitch = 20;
% c_Kp_roll = 100;
% c_Kd_roll = 20;
% c_Kp_yaw = 100;
% c_Kd_yaw = 20;


% c_Kp_abduction = 400;
% c_Kp_rotation = 200;
% c_Kp_thigh = 500;
% c_Kp_knee = 500;
% c_Kp_toe = 10;%60;

% c_Kd_abduction = 10;
% c_Kd_rotation = 4;
% c_Kd_thigh = 15;
% c_Kd_knee = 15;
% c_Kd_toe = 2;



% gravity compensation
% c_u_abduction_swing_cp = 14;
% c_u_abduction_cp = 40;
% c_u_thigh_cp = -15;
% c_u_knee_cp = 120;

% footplacment
c_Kfs_p = 0.60;
c_Kfs_d = 0.35;

c_Kfl_p = 0.35;
c_Kfl_d = 0.45;


c_fil_vel_offset  = -0.1;%-0.28;
% offset
c_sagittal_offset_exp = -0.000;
c_lateral_offset_exp = 0.0;
c_turning_offset_exp = 0;
c_stand_offset_exp = 0;

% Switch from stand to walk
c_shift_time = 0.4;
c_shift_distance = 0.045;


% c_stance_thre_ub = 200;
% c_stance_thre_lb = 100;
% c_lateral_velocity_weight = .5;
% c_init_lateral_velocity = 0.1;
% c_abduction_inward_gain = 1;
% c_joint_filter_choice = 1; % Mikhail's filter is 0
% c_standing_switch_time = 0.4;

% c_toe_tilt_angle = 0;  % [rad] ~ 17.2 deg
% c_force_step_end_s = 1;


simOut = sim('FG_Simulator.slx'); 