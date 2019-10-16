% PD gain on Joints (walk)
c_Kp_pitch = 200;
c_Kd_pitch = 20;
c_Kp_roll = 100;
c_Kd_roll = 20;
c_Kp_yaw = 200;
c_Kd_yaw = 4;
% c_Kp_pitch = 500;
% c_Kd_pitch = 40;
% c_Kp_roll = 500;
% c_Kd_roll = 30;
% c_Kp_yaw = 200;
% c_Kd_yaw = 4;


c_Kp_abduction = 600;
c_Kp_rotation = 800;
c_Kp_thigh = 500;
c_Kp_knee = 500;
c_Kp_toe = 10;

c_Kd_abduction = 10;
c_Kd_rotation = 10;
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
c_u_thigh_cp = +YToolkits.ifelse(isSim,-20,-15);
c_u_knee_cp = +YToolkits.ifelse(isSim,120,120);

% footplacment
c_Kfs_p = 0.05;
c_Kfs_d = 0.15;

c_Kfl_p = 0.55;
c_Kfl_d = 0.75;

c_fil_vel_offset  = 0;

% offset
c_sagittal_offset_exp = 0.000; %0.04
c_lateral_offset_exp = 0.000;
c_turning_offset_exp = 0;
c_stand_offset_exp = 0.00;

% Switch from stand to walk
c_shift_time     = +YToolkits.ifelse(isSim,0.4,0.4);
c_shift_distance = +YToolkits.ifelse(isSim,0.04,0.04);

% Switch from walk to stand
c_final_sw_abduction = 0.15;
c_final_st_abduction = 0.05;
c_pre_final_sw_abduction = -0.01;

c_stance_thre_ub = 200;
c_stance_thre_lb = 100;
c_lateral_velocity_weight = 1;
c_init_lateral_velocity   = 0.1;
c_abduction_inward_gain   = 0.5;
c_joint_filter_choice     = 1; % Mikhail's filter is 0
c_standing_switch_time    = 0.40;

c_toe_tilt_angle   = 0;  % [rad] ~ 17.2 deg
c_force_step_end_s = 1;


c_CP_StanceKnee = [ 20, 120,  40,  20,  0];
% c_CP_StanceKnee = [ 60, 280,  -40,  -20,  20];
c_CP_SwingKnee  = [  0,   0,    0,    0,   0];
c_CP_StanceHip  = [  0, -20,  -15,  -15,   0];
c_CP_SwingHip   = [  0,   0,    0,    0,   0];
c_CP_StanceAbdu = [ 25,  90,   50,   80,  10];
c_CP_SwingAbdu  = [  15,   18,   20,   25,  -5];


c_Gamma_st_abu  = 120;
c_Gamma_sw_abu  = 120;

c_Gamma_st_hip  = 50*0.01;
c_Gamma_sw_hip  = 10*0.01;

c_Gamma_st_knee = 150;
c_Gamma_sw_knee = 150*0.01;

c_com_bp = 0.05;

c_sagittal_speed = 0;



%% Run only when new tunable parameter is created
if 0
    S = whos('c_*');
    root_block = 'FG_RealTime';
    FG_RealTime;
    % Make the base workspace variables tunable
    NameList = [];
    StorageClassList = [];
    TypeQualifierList = [];
    for i = 1:length(S)
        NameList = [NameList, S(i).name,','];
        StorageClassList = [StorageClassList, 'Auto,'];
        TypeQualifierList = [TypeQualifierList,','];
    end
    NameList = NameList(1:end-1); % Remove the last ','
    StorageClassList = StorageClassList(1:end-1);
    TypeQualifierList = TypeQualifierList(1:end-1);
    
    set_param(root_block,'TunableVars',NameList);
    set_param(root_block,'TunableVarsStorageClass',StorageClassList);
    set_param(root_block, 'TunableVarsTypeQualifier',TypeQualifierList);
    
    % Repeat for simulator
    root_block = 'FG_Simulator';
    FG_Simulator;
    
    NameList = [];
    StorageClassList = [];
    TypeQualifierList = [];
    for i = 1:length(S)
        NameList = [NameList, S(i).name,','];
        StorageClassList = [StorageClassList, 'Auto,'];
        TypeQualifierList = [TypeQualifierList,','];
    end
    NameList = NameList(1:end-1); % Remove the last ','
    StorageClassList = StorageClassList(1:end-1);
    TypeQualifierList = TypeQualifierList(1:end-1);
    
    set_param(root_block,'TunableVars',NameList);
    set_param(root_block,'TunableVarsStorageClass',StorageClassList);
    set_param(root_block, 'TunableVarsTypeQualifier',TypeQualifierList);
    
    % Assign the Model WorkSpace variables of the referenced model to the block parameters
    load_system('FG_Controller_Library');
    set_param('FG_Controller_Library','Lock','off')
    parameters = get_param('FG_Controller_Library/Controller/MATLAB System1','DialogParameters');
    fields = fieldnames(parameters);
    for i = 1:length(fields)-1
        set_param('FG_Controller_Library/Controller/MATLAB System1',fields{i},['c_' fields{i}]);
    end
end