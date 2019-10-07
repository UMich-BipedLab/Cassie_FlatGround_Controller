function Data = Construt_Data()


% walking
Data.hd = zeros(10,1);
Data.dhd = zeros(10,1);
Data.h0 = zeros(10,1);
Data.dh0 = zeros(10,1);
Data.hd_fix = zeros(10,1);
Data.dhd_fix = zeros(10,1);
Data.h0_fix = zeros(10,1);
Data.dh0_fix = zeros(10,1);

Data.hd_joint = zeros(10,1);
Data.dhd_joint = zeros(10,1);
Data.h0_joint = zeros(10,1);
Data.dh0_joint = zeros(10,1);

Data.y = zeros(10,1);
Data.dy = zeros(10,1);
Data.y_joint = zeros(10,1);
Data.dy_joint = zeros(10,1);

Data.y1_joint = 0;
Data.y2_joint = 0;
Data.y3_joint = 0;
Data.y4_joint = 0;
Data.y5_joint = 0;
Data.y6_joint = 0;
Data.y7_joint = 0;
Data.y8_joint = 0;
Data.y9_joint = 0;
Data.y10_joint = 0;

% standing up
Data.y_knee = zeros(2,1);
Data.dy_knee = zeros(2,1);
Data.LLd = 0;
Data.dLLd = 0;
Data.qKnee_d = 0;
Data.dqKnee_d = 0;
Data.qknee_d_L = 0;
Data.qknee_d_R = 0;
Data.left_tune = 0;
Data.right_tune = 0;

Data.LL0_R = 0;
Data.LL0_L = 0;
Data.y_output = zeros(4,1);
Data.dy_output = zeros(4,1);
Data.u_output = zeros(4,1);
Data.lateral_mid_p = 0;
Data.lateral_mid_v = 0;
Data.LL_des_fil = 0;

% temp
Data.test = 0;

% general
Data.task = 0;
Data.t = 0;
Data.q = zeros(26,1);
Data.dq = zeros(26,1);
Data.u = zeros(10,1);
Data.u_sat = zeros(10,1);
Data.u_fil = zeros(10,1);
Data.stanceLeg = 0;
Data.s_sw = 0;
Data.s_st = 0;
Data.s = 0;
Data.ds = 0;
Data.encoder_fil = zeros(14,1);
Data.d_torso_angle_fil = zeros(3,1);



Data.tp_last = 0;
Data.avg_v_last_1 = 0;
Data.avg_v_last_2 = 0;

Data.theta = 0;
Data.dtheta = 0;
Data.theta_d = 0;
Data.dtheta_d = 0;

Data.GRF = zeros(2,1);
Data.t0 = 0;
Data.Switch = 0;
Data.spring_force_R = zeros(2,1);
Data.spring_force_L = zeros(2,1);

Data.torso_angle = zeros(3,1);
Data.d_torso_angle = zeros(3,1);
Data.id_torso_angle = zeros(3,1);
Data.dd_torso_angle = zeros(3,1);
Data.d_torso_angle_fil = zeros(3,1);
Data.torso_position = zeros(3,1);
Data.torso_velocity = zeros(3,1);
Data.torso_velocity_fil = zeros(3,1);
Data.torso_vx = 0;
Data.torso_vy = 0;
Data.torso_vz = 0;
Data.torso_vx_fil = 0;
Data.torso_vy_fil = 0;
Data.torso_vz_fil = 0;

Data.torso_vx_b = 0;
Data.torso_vy_b = 0;
Data.torso_vz_b = 0;
Data.torso_vx_b_fil = 0;
Data.torso_vy_b_fil = 0;
Data.torso_vz_b_fil = 0;

Data.tg_velocity_x = 0;

Data.com_pos = zeros(3,1);
Data.com_vel = zeros(3,1);
Data.com_vel_x = 0;
Data.com_vel_y = 0;
Data.com_vel_z = 0;
Data.com_vel_x_fil = 0;
Data.com_vel_y_fil = 0;
Data.com_vel_z_fil = 0;
Data.com_pos_x_fil = 0;
Data.com_pos_y_fil = 0;
Data.com_pos_z_fil = 0;
Data.com_pos_fil = zeros(3,1);

Data.torso_vx_test = 0;
Data.torso_vy_test = 0;
Data.torso_vz_test = 0;
Data.torso_vx_b_test = 0;
Data.torso_vy_b_test = 0;
Data.torso_vz_b_test = 0;
Data.torso_vx_test_2 = 0;
Data.torso_vy_test_2 = 0;
Data.torso_vz_test_2 = 0;
Data.torso_vx_b_test_2 = 0;
Data.torso_vy_b_test_2 = 0;
Data.torso_vz_b_test_2 = 0;
Data.torso_vx_fil_test = 0;
Data.torso_vy_fil_test = 0;
Data.torso_vz_fil_test = 0;
Data.torso_vx_b_fil_test = 0;
Data.torso_vy_b_fil_test = 0;
Data.torso_vz_b_fil_test = 0;
Data.dqy_b_avg_1 = 0;
Data.l_abduction_vx = 0;
Data.l_abduction_vy = 0;
Data.l_abduction_vz = 0;
Data.l_foot_vx = 0;
Data.l_foot_vy = 0;
Data.l_foot_vz = 0;
Data.l_foot_vx_b = 0;
Data.l_foot_vy_b = 0;
Data.l_foot_vz_b = 0;
Data.r_foot_v = zeros(3,1);
Data.l_foot_v = zeros(3,1);
Data.r_foot_p = zeros(3,1);
Data.l_foot_p = zeros(3,1);



Data.s_LR = zeros(2,1);
Data.orient = 0;
Data.d_orient_test = 0;
Data.d_orient = 0;
Data.step_end_dx_fil_seq = zeros(3,1);
Data.step_end_dy_fil_seq = zeros(3,1);
% Data.lateral_mid_p = 0;
% Data.left_tune = 0;

Data.q_abduction_R = 0;
Data.q_rotation_R = 0;
Data.q_thigh_R = 0;
Data.q_thigh_knee_R = 0;
Data.q_knee_shin_R = 0;
Data.q_thigh_shin_R = 0;
Data.q_shin_tarsus_R = 0;
Data.q_toe_R = 0;

Data.q_abduction_L = 0 ;
Data.q_rotation_L = 0;
Data.q_thigh_L = 0;
Data.q_thigh_knee_L = 0;
Data.q_knee_shin_L = 0;
Data.q_thigh_shin_L = 0;
Data.q_shin_tarsus_L = 0;
Data.q_toe_L = 0;



Data.dq_abduction_R = 0;
Data.dq_rotation_R = 0;
Data.dq_thigh_R = 0;
Data.dq_thigh_knee_R = 0;
Data.dq_knee_shin_R = 0;
Data.dq_thigh_shin_R = 0;
Data.dq_shin_tarsus_R = 0;
Data.dq_toe_R = 0;

Data.dq_abduction_L = 0 ;
Data.dq_rotation_L = 0;
Data.dq_thigh_L = 0;
Data.dq_thigh_knee_L = 0;
Data.dq_knee_shin_L = 0;
Data.dq_thigh_shin_L = 0;
Data.dq_shin_tarsus_L = 0;
Data.dq_toe_L = 0;

Data.qall = zeros(20,1);
Data.dqall = zeros(20,1);

Data.qq = zeros(4,1);
Data.qaR = zeros(5,1);
Data.qjR = zeros(2,1);
Data.qsR = zeros(2,1);
Data.qaL = zeros(5,1);
Data.qjL = zeros(2,1);
Data.qsL = zeros(2,1);

Data.dqq = zeros(3,1);
Data.dqaR = zeros(5,1);
Data.dqjR = zeros(2,1);
Data.dqsR = zeros(2,1);
Data.dqaL = zeros(5,1);
Data.dqjL = zeros(2,1);
Data.dqsL = zeros(2,1);

Data.u_P = zeros(10,1);
Data.u_D = zeros(10,1);

Data.hd_original = zeros(10,1);

Data.u_CP_stance_knee = 0;
Data.e_CP_stance_knee = 0;
Data.u_OT_stance_knee = 0;

Data.u_CP_stance_hip_pitch = 0;
Data.e_CP_stance_hip_pitch = 0;
Data.u_OT_stance_hip_pitch = 0;

Data.u_CP_stance_abduction = 0;
Data.e_CP_stance_abduction = 0;
Data.u_OT_stance_abduction = 0;

Data.computer_time = 0;

Data.Torque_CP = zeros(10,1);
Data.Error_CP  = zeros(10,1);
Data.RadioChannel = zeros(16,1);

Data.lateral_ftpl = 0;


Data.I_Vel = zeros(3,1);
Data.EKF_v = zeros(3,1);
Data.EKF_q = zeros(20,1);
Data.EKF_dq = zeros(20,1);
end