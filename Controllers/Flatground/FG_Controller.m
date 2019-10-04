%Yukai controller.

classdef FG_Controller <matlab.System & matlab.system.mixin.Propagates & matlab.system.mixin.SampleTime %#codegen
    
    properties
        Kp_pitch;
        Kd_pitch;
        Kp_roll;
        Kd_roll;
        Kp_yaw;
        Kd_yaw;
        
        Kp_abduction;
        Kp_rotation;
        Kp_thigh;
        Kp_knee;
        Kp_toe;
        
        Kd_abduction;
        Kd_rotation;
        Kd_thigh;
        Kd_knee;
        Kd_toe;
        
        Kfs_p;
        Kfl_p;
        Kfs_d;
        Kfl_d;
        
        Kp_toe_stand;
        Kd_toe_stand;
        Kp_lateral_stand;
        Kd_lateral_stand;
        Kp_abduction_stand;
        Kd_abduction_stand;
        Kp_thigh_stand;
        Kd_thigh_stand;
        Kp_knee_stand;
        Kd_knee_stand;
        Kp_rotation_stand;
        Kd_rotation_stand;
        
        fil_para_x;
        fil_para_y;
        
        stance_thre_ub;
        stance_thre_lb;
        
        lateral_velocity_weight;
        init_lateral_velocity;
        
        abduction_inward_gain; 
        
        joint_filter_choice;
        
        shift_time;
        shift_distance;
        standing_switch_time;

        toe_tilt_angle;
        
        final_sw_abduction;
        final_st_abduction;
        pre_final_sw_abduction;
        
        sagittal_offset_exp;
        lateral_offset_exp;
        turning_offset_exp;
        stand_offset_exp;

        u_abduction_cp;
        u_abduction_swing_cp;
        u_thigh_cp;
        u_knee_cp;
        
        fil_para_2;
        fil_para_3;
        fil_para_4;
        fil_para_5;
        
        force_step_end_s;
        
        fil_vel_offset;
        
        CP_StanceKnee;
        CP_SwingKnee;
        CP_StanceAbdu;
        CP_SwingAbdu;
        
 
        Gamma_st_abu;
        Gamma_sw_abu;
        
        Gamma_st_hip;
        Gamma_sw_hip;
        
        Gamma_st_knee;
        Gamma_sw_knee;
        
        
        
        com_bp;
        
        sagittal_speed;

    end
    % PROTECTED PROPERTIES ====================================================
    properties (Access = protected)
 
        sagittal_offset = -0.01;
        lateral_offset = 0;
        turning_offset = 0;
        stand_offset = -0.01;

        Toe_thigh_offset = 1.0996;
        safe_TorqueLimits = repmat([100;60;80;190;45],[2,1]);
        %safe_TorqueLimits = repmat([80;60;80;190;45],[2,1]);
        standing_abduction_offset = 0.08;
        
        bezier_degree = 5;
    end
    % PRIVATE PROPERTIES ====================================================
    properties (Access = private)
        

        Kp = zeros(10,1);
        Kd = zeros(10,1);
        stanceLeg = 1;
        begin = 0;
        Switch = 0; % if switching stance leg
        walking_ini = 0;
        step_end = 0;
        task = 2; % 0 is do nothing; 1 is walking; 2 is standing up; 3 is test
        task_prev = 0;
        task_next = 0;
        t0 = 0; % the time when starting a step
        t_prev = 0;
        t1 = 0;
        s1 = 0; % transition time for stand to walk
        t2 = 0;
        s2 = 0; % transition time for walk to stand
        u_prev = zeros(10,1); % u in previous iteration
        u_last = zeros(10,1); % u in last step 
        u_fil  = zeros(10,1); % u filtered 
        
        s_prev = 0;
        s_unsat_prev = 0;
        dqy_b_start = 0;
        gaitparams = struct( 'HAlpha',zeros(10,6),'ct',0);
        
        gaitparams_fil = struct( 'HAlpha',zeros(10,6),'ct',0);
        
        foot_placement = 1;
        pitch_torso_control = 1;
        roll_torso_control = 1;
        stance_passive = 1;
        knee_com = 1;
        abduction_com = 1;
        thigh_compensation = 1;
        abduction_swing_com = 0;
        reduce_impact = 1;
        keep_direction = 1;
        
        to_turn = 0;
        to_turn_prev = 1;
        tg_yaw = 0;
        
        tg_velocity_x = 0;
        
        uHip_gravity_2 = 1.2; % for swing leg
        dqx_b_fil = 0;
        dqy_b_fil = 0;
        dqz_b_fil = 0;
        dqx_fil = 0;
        dqy_fil = 0;
        dqz_fil = 0;
        com_vel_x_fil = 0;
        com_vel_y_fil = 0;
        com_vel_z_fil = 0;
        com_pos_x_fil = 0;
        com_pos_y_fil = 0;
        com_pos_z_fil = 0;
        
        com_roll_fil = 0;
        com_roll_cur = 0;
        
        
        pitch_des_fil = 0;
        tg_velocity_x_fil = 0;
        lateral_move_fil = 0;
        
        LL_des_fil = 0.7;
        roll_des_fil = 0;
        LL_des = 0.7;
        dLL_des_fil = 0;
        P_feedback_toe_fil = 0;
        
        hd = zeros(10,1);
        dhd = zeros(10,1);
        hd_joint = zeros(10,1);
        dhd_joint = zeros(10,1);
        h0 = zeros(10,1);
        dh0 = zeros(10,1);
        h0_joint = zeros(10,1);
        dh0_joint = zeros(10,1);
        y = zeros(10,1);
        dy = zeros(10,1);
        y_joint = zeros(10,1);
        dy_joint = zeros(10,1);
        
        hd_prev = zeros(10,1);
        dhd_prev = zeros(10,1);
        h0_prev = zeros(10,1);
        dh0_prev = zeros(10,1);
        y_prev = zeros(10,1);
        dy_prev = zeros(10,1);
        hd_joint_prev = zeros(10,1);
        dhd_joint_prev = zeros(10,1);
        h0_joint_prev = zeros(10,1);
        dh0_joint_prev = zeros(10,1);
        y_joint_prev = zeros(10,1);
        dy_joint_prev = zeros(10,1);

        hd_last = zeros(10,1);
        dhd_last = zeros(10,1);
        
        v_final = zeros(2,1);
        v_final_avgy = 0;
        tp_last = 0; % how long does last step take
        step_height = 0;
        
        sagittal_move = 0;
        lateral_move = 0;
        rotation_move = 0;
        
        to_stand_step_count = 0;
        
        dqy_b_avg_1 = 0;
        %% iterative learning control
        % phase variables
        s_previous_step = linspace(0,1,100);
        s_current_step = zeros(1,2000);
        kstep = 1;
 
        % Error in the current step (this is recorded in every time step)
        Error_CurrentStep = zeros(10,2000); % we should at most have 0.4/0.0005 = 800 data points
        
        % Error in the previous step (this is interpolated into 100 data points)
        Error_PreviousStep = zeros(10,100); % we should at most have 100 data points        

        % Torques in the current step (this is recorded in every time step)
        Torque_CurrentStep = zeros(10,2000); % we should at most have 0.4/0.0005 = 800 data points    
        
        % Torque in the previous step (this is interpolated into 100 data points)
        Torque_PreviousStep = zeros(10,100); % we should at most have 100 data points  
            
%         % Error in the current step (this is recorded in every time step)
%         Error_CurrentStep % we should at most have 0.4/0.0005 = 800 data points
%         
%         % Error in the previous step (this is interpolated into 100 data points)
%         Error_PreviousStep % we should at most have 100 data points        
% 
%         % Torques in the current step (this is recorded in every time step)
%         Torque_CurrentStep % we should at most have 0.4/0.0005 = 800 data points    
%         
%         % Torque in the previous step (this is interpolated into 100 data points)
%         Torque_PreviousStep % we should at most have 100 data points          
    end % properties
    properties (Access = private, Constant)
        TorqueLimits = repmat([112.5;112.5;195.2;195.2;45],[2,1]);
        ActuatorLimits = [-0.2618, 0.3927;    -0.3927, 0.3927;    -0.8727, 1.3963;    -2.8623, -0.7330;   -2.4435, -0.5236; ...
            -0.3927, 0.2618;    -0.3927, 0.3927;    -0.8727, 1.3963;    -2.8623, -0.7330;   -2.4435, -0.5236];
        Ks1 = 1800;
        Ks2 = 1600;
    end
    
    % PROTECTED METHODS =====================================================
    methods (Access = protected)
        
        function [userInputs, Data] = stepImpl(obj, t, cassieOutputs, isSim, GaitLibrary, GaitLibrary_Ori, encoder_fil, LinuxData)
            %STEPIMPL System output and state update equations.
            
            %% Initialize --------------------------------------------------------
            Data = PreFunctions.Construct_Data;
            % Reset the desired motor torques to zero in case they aren't defined
            userInputs = CassieModule.getUserInStruct;
            u = zeros(10,1);
            % Update the Cassie outputs data structure
            RadioButton = RadioChannelToButton(cassieOutputs.pelvis.radio.channel);
            obj.Kp = repmat([obj.Kp_abduction;obj.Kp_rotation;obj.Kp_thigh;obj.Kp_knee; obj.Kp_toe],[2,1]);
            obj.Kd = repmat([obj.Kd_abduction;obj.Kd_rotation;obj.Kd_thigh;obj.Kd_knee; obj.Kd_toe],[2,1]);
            
            if (isSim == 0 && t>10) || (isSim == 1 && t>0.1)
                obj.begin = 1;
            end
            
            %% Read Commands
            % In experiment some settings are different from simulation
            if isSim == 0
                obj.pitch_torso_control = 1;
                obj.knee_com = 1;
                obj.abduction_com = 1;
                obj.foot_placement = 1;
                obj.lateral_offset = obj.lateral_offset_exp;
                obj.sagittal_offset = obj.sagittal_offset_exp - 0.02 * RadioButton.S1A;
                obj.turning_offset = obj.turning_offset_exp;
                obj.stand_offset = obj.stand_offset_exp + RadioButton.S2A*0.1;
            else    
                
                obj.sagittal_offset = obj.sagittal_offset_exp;
                
            end 
            % Receive command signal from RC radio
            if RadioButton.LVA < 0 % To prevent walking backward too fast
                p = 0.5;
            else
                p = 1;
            end
            
            % overwrite velocity command from the slrtexplr
            if RadioButton.SEA == +1
              obj.tg_velocity_x = obj.sagittal_speed;
            else
              obj.tg_velocity_x = p* RadioButton.LVA;
            end
            obj.tg_velocity_x_fil = YToolkits.first_order_filter(obj.tg_velocity_x_fil, obj.tg_velocity_x, 0.0003);
            obj.lateral_move = 0.015*RadioButton.LHA;
            obj.lateral_move_fil = YToolkits.first_order_filter(obj.lateral_move_fil, obj.lateral_move, 0.003);
            obj.rotation_move = -0.2*RadioButton.RHA;
            if abs(RadioButton.RHA)<0.1
                obj.to_turn = -1;
            else
                obj.to_turn = 1;
            end
            pitch_des = median([RadioButton.RVA,-0.5,0.5]);
            obj.pitch_des_fil = YToolkits.first_order_filter(obj.pitch_des_fil, pitch_des, 0.0005);
            obj.LL_des = 0.68+RadioButton.LSA*0.2;
            obj.LL_des_fil = YToolkits.first_order_filter(obj.LL_des_fil,obj.LL_des,obj.fil_para_4);            
            roll_des = RadioButton.RHA*0.1;
            obj.roll_des_fil = YToolkits.first_order_filter(obj.roll_des_fil,roll_des,0.0003); % cutoff frequency 0.1 Hz;
            
            %% state machine ( walk or stand )
            if RadioButton.SBA == 1
                obj.task_next = 1;
            else
                obj.task_next = 2;
            end      
            if obj.task_next == 2
                obj.t1 = 0;
                obj.s1 = 0;
            end    
            
            % finish shifting the COM to the left leg, set the current task to walking
            if obj.task_next ==1 && obj.s1 > 1
                obj.task = obj.task_next;
                obj.P_feedback_toe_fil = 0;
            end
            
            if obj.task_next == 2 && obj.step_end
                obj.task =2;
                obj.step_end = 0;
                obj.t2 = 0;
                obj.u_last = obj.u_prev;
            end
            
            %% begin calculation
            if    t > 0.1 && obj.begin ==1
                
                
                %% Add EKF information to the system
                % x y z yaw pitch roll
                % process data from ekf:
%                 R = YukaiToolkits.Angles.Quaternion_to_Matrix(cassieOutputs.pelvis.vectorNav.orientation);
%                 Rz = YukaiToolkits.Angles.Rz(LinuxData.state.q(4)); % yaw angle
%                 % torso velocity in the body frame -> world frame -> yaw
%                 % frame
%                 I_Vel =  R * LinuxData.inekf.velocity;
%                 BI_Vel = Rz' * I_Vel;
                
                
                %% get values
                [qyaw, qpitch, qroll, dqyaw, dqpitch, dqroll] = IMU_to_Euler_v2(cassieOutputs.pelvis.vectorNav.orientation, cassieOutputs.pelvis.vectorNav.angularVelocity);
                qa  = CassieModule.getDriveProperty(cassieOutputs,'position');
                dqa = CassieModule.getDriveProperty(cassieOutputs,'velocity');
                qj  = CassieModule.getJointProperty(cassieOutputs,'position');
                dqj = CassieModule.getJointProperty(cassieOutputs,'velocity');
                qq  = cassieOutputs.pelvis.vectorNav.orientation;
                qaL = qa(1:5);
                qaR = qa(6:10);
                qjL =  qj(1:2);
                qjR =  qj(4:5);
                qsL = getSpringDeflectionAngle(qaL(4),qjL(1),qjL(2));
                qsR = getSpringDeflectionAngle(qaR(4),qjR(1),qjR(2));
                    
                % Get current velocities
                dqaL =  dqa(1:5);
                dqaR =  dqa(6:10);
                dqjL =  dqj(1:2);
                dqjR =  dqj(4:5);
                dqsL = getSpringDeflectionRate(dqaL(4),dqjL(1),dqjL(2));
                dqsR = getSpringDeflectionRate(dqaR(4),dqjR(1),dqjR(2));
                
                % assign the value
                q_abduction_R = qaR(1);
                q_rotation_R = qaR(2);
                q_thigh_R = qaR(3);
                q_thigh_knee_R = qaR(4);
                q_knee_shin_R = qjR(1);
                q_thigh_shin_R = q_thigh_knee_R+q_knee_shin_R;
                q_shin_tarsus_R = qjR(2);
                q_toe_R = qaR(5);
                
                q_abduction_L = qaL(1);
                q_rotation_L = qaL(2);
                q_thigh_L = qaL(3);
                q_thigh_knee_L = qaL(4);
                q_knee_shin_L = qjL(1);
                q_thigh_shin_L = q_thigh_knee_L+q_knee_shin_L;
                q_shin_tarsus_L = qjL(2);
                q_toe_L = qaL(5);
                
                
                dq_abduction_R = dqaR(1);
                dq_rotation_R = dqaR(2);
                dq_thigh_R = dqaR(3);
                dq_thigh_knee_R = dqaR(4);
                dq_knee_shin_R = dqjR(1);
                dq_thigh_shin_R = dq_thigh_knee_R+dq_knee_shin_R;
                dq_shin_tarsus_R = dqjR(2);
                dq_toe_R = dqaR(5);
                
                dq_abduction_L = dqaL(1);
                dq_rotation_L = dqaL(2);
                dq_thigh_L = dqaL(3);
                dq_thigh_knee_L = dqaL(4);
                dq_knee_shin_L = dqjL(1);
                dq_thigh_shin_L = dq_thigh_knee_L+dq_knee_shin_L;
                dq_shin_tarsus_L = dqjL(2);
                dq_toe_L = dqaL(5);
                
                qall = [  0;  0;              0;              qyaw;           qpitch;              qroll;
                      q_abduction_L;	q_rotation_L;	q_thigh_L;      q_thigh_knee_L;     q_knee_shin_L;      q_shin_tarsus_L;    q_toe_L;
                      q_abduction_R;	q_rotation_R;	q_thigh_R;      q_thigh_knee_R;     q_knee_shin_R;      q_shin_tarsus_R;    q_toe_R];
                
                dqall = [ 0;  0;              0;              dqyaw;         dqpitch;            dqroll;
                      dq_abduction_L;	dq_rotation_L;	dq_thigh_L;     dq_thigh_knee_L;    dq_knee_shin_L;     dq_shin_tarsus_L;   dq_toe_L;
                      dq_abduction_R;	dq_rotation_R;	dq_thigh_R;     dq_thigh_knee_R;    dq_knee_shin_R;     dq_shin_tarsus_R;   dq_toe_R];
                
                %% process Data
                
                % get current h0_joint and h0
                obj.h0_joint=[qaL; qaR];
                obj.dh0_joint = [dqaL; dqaR];
                if obj.joint_filter_choice == 1 % Use AR joint filter or custom filter.
                    obj.dh0_joint([3,4,5,8,9,10]) = encoder_fil([3,4,5,8,9,10]);
                end
                [ obj.h0, obj.dh0] = get_FK(obj, obj.h0_joint,obj.dh0_joint);

                % get GRF and s
                if cassieOutputs.isCalibrated == 1
                    [ GRF_L, GRF_R ] = get_GRF(obj,qall,qsR,qsL,0);
                else
                    GRF_L = [0;0];
                    GRF_R = [0;0];
                end
                GRF_v = [GRF_L(2) GRF_R(2) ];
                [ s_L, s_R ] = obj.get_s_LR(GRF_v); % s is normalized between 0 and 1, 0 means the leg is in air and 1 means leg is on ground.
                s_LR = [s_L; s_R];

                if obj.stanceLeg == 1
                    swing_grf = GRF_L(2);
                    stance_grf = GRF_R(2); %#ok<*NASGU>
                else
                    swing_grf = GRF_R(2);
                    stance_grf = GRF_L(2);
                end
                
                %% if not walking in previous moment, reset the current hd
                % to smooth the torque
                if obj.task == 1 && obj.task_prev~=1
                    obj.hd_joint =obj.h0_joint + obj.u_prev./obj.Kp;
                    obj.dhd_joint = obj.dh0_joint;
                    [obj.hd, obj.dhd] = get_FK(obj, obj.hd_joint, obj.dhd_joint);
                end
                
                % If Cassie is standing or turning, swing leg is NOT commanded to maintain the direction of the robot.
                if (obj.to_turn ~=1 && obj.to_turn_prev == 1) || obj.task == 2
                    obj.tg_yaw = qyaw;
                end
                
                
                
                
                
                
                
                
                % || obj.walking_ini == 0
                % what happens when a step end and a new step begin.
                if (obj.s_prev >=0.5 && swing_grf >obj.stance_thre_ub && obj.task == 1) || ...
                   (obj.s_unsat_prev > obj.force_step_end_s && obj.task == 1) || ...
                   (obj.walking_ini == 0 && obj.task_next == 1) % initial step
                    
               
                qall_withoutyaw = qall;
                qall_withoutyaw(4) = 0;
                feetDistance = abs(RightToeBottomBack(qall_withoutyaw) - LeftToeBottomBack(qall_withoutyaw));
                obj.step_height = feetDistance(3); % current set it to be positive; however, based on which leg 
                % is switched to we should figure out the correct direction. 
               
               
                    if obj.walking_ini == 1 % when a step is finished during walking
                        obj.stanceLeg = - obj.stanceLeg;
                    else % initial step when the walking switch is triggered
                        obj.stanceLeg = +1; % At the beginning of a step. 
                        % StanceLeg is always left leg, this value will be
                        % set to -1 at the beginning of the first step
                        % since walking_ini == 1.
                    end    
                        
                    % Copy the data from current step to the previous step;
                    % and reset the current step data structure.
                    if obj.task == 1   
                        %%%%%%%
                        %=====
                        % check initialization:

                        % These signals can be very noisy, apply zero phase
                        % filter                  

%                         if RadioButton.SFA ~= 1
%                             figure(1)
%                             hold on
%                             % plot(u_CurrentStep_interp(:,4),'r');
%                             plot(obj.Torque_PreviousStep(4,:),'b')
%                         end    
                        
                        
                        % corp the data to correct sizes (RadioButton.SFA == 1)
                        if (obj.kstep ~= 1) && 0
                            % first step switched from standing & use SF to
                            % stop updating.
                                                
                            % resize the data to a fixed value 1x100
                            s_interp = linspace(0,obj.s_current_step(obj.kstep-1),100);
                            err_incr = linspace(0,1e-9,length(obj.s_current_step(1:obj.kstep-1)));


                            
                            u_CurrentStep_interp = zeros(100,10);
                            e_CurrentStep_interp  = zeros(100,10);
                            % Interpolation of the data structure (different channels of data are stored as coloum vectors)
                            u_CurrentStep_interp = interp1(obj.s_current_step(1:obj.kstep-1) + err_incr, obj.Torque_CurrentStep(:,1:obj.kstep-1)', s_interp); % 100x10
                            e_CurrentStep_interp = interp1(obj.s_current_step(1:obj.kstep-1) + err_incr, obj.Error_CurrentStep(:,1:obj.kstep-1,:)',  s_interp); % 100x10                       

                            obj.s_previous_step = s_interp;     
                            % This makes sure the filter always has the same input size

                            % Moving-Average Zero Filter
                            windowSize = 5; 
                            b = (1/windowSize)*ones(1,windowSize);
                            a = 1;

%                             Torque_PreviousStep_F = zeros(100,10);
%                             Error_PreviousStep_F  = zeros(100,10);
                            
                            Torque_PreviousStep_F = filtfilt(b, a, u_CurrentStep_interp); % 100x10
                            Error_PreviousStep_F  = filtfilt(b, a, e_CurrentStep_interp); % 100x10
                            % The filter will treat each coloum of the data structure as
                            % a different channel of signals
                            
%                             Torque_PreviousStep_FT = zeros(10,100);
%                             Error_PreviousStep_FT = zeros(10,100);       
                            
                            Torque_PreviousStep_FT = reshape(transpose(Torque_PreviousStep_F),10,100);
                            Error_PreviousStep_FT = reshape(transpose(Error_PreviousStep_F),10,100);
                            % Check whether or not the torque and error are
                            % initilized
                            if any(obj.Torque_PreviousStep(:)) 
                                obj.Torque_PreviousStep = obj.Torque_PreviousStep*0.6 + Torque_PreviousStep_FT*0.4; % 10x100
                                obj.Error_PreviousStep  = obj.Error_PreviousStep*0.6  + Error_PreviousStep_FT*0.4; % 10x100;
                            else    
                                obj.Torque_PreviousStep = Torque_PreviousStep_FT; % 10x100
                                obj.Error_PreviousStep  = Error_PreviousStep_FT; % 10x100;
                            end

%                             if t>10
%                                 figure(1)
%                                 hold on
%                                 plot(u_CurrentStep_interp(:,1),'red');
%                                 plot(obj.Torque_PreviousStep(1,:),'red')
%                                 plot(obj.Error_PreviousStep(1,:)*obj.Gamma_st_abu,'black');
%                                 figure(2)
%                                 hold on
%                                 plot(u_CurrentStep_interp(:,6),'red');
%                                 plot(obj.Torque_PreviousStep(6,:),'red')
%                                 plot(obj.Error_PreviousStep(6,:)*obj.Gamma_sw_abu,'black');
%                             end
                        end
                        
                        % clean current step data structure:
                        obj.s_current_step = linspace(0,1,2000);

                        obj.Torque_CurrentStep = zeros(10,2000);
                        obj.Error_CurrentStep  = zeros(10,2000);
                        
                        obj.kstep = 1;
                        
                    end % end of reset walking step for ILC
                    
                    %% state machine updates
                    obj.tp_last = t - obj.t0;
                    obj.t0=t;
                    obj.t_prev = obj.t0;
                    obj.s_prev = 0;
                    obj.s_unsat_prev = 0;
                    % obj.Switch = 1;
                    obj.walking_ini = 1;
                    obj.u_last = obj.u_prev; % u_prev is the torque command in previous iteration, u_last is the torque command at the end of last step
                    % save the velocity data at the end of a step.
                    obj.v_final = [obj.dqx_b_fil; obj.dqy_b_fil];
                    obj.v_final_avgy =  obj.lateral_velocity_weight *obj.dqy_b_fil + ... % filtered lateral velocity at the end of the stride
                                     (1-obj.lateral_velocity_weight)*obj.dqy_b_start;
                    obj.dqy_b_start = obj.dqy_b_fil;

                    obj.hd_last = obj.hd; % save the desired output at the end of a step. It is used to reset the first 2 bezier coefficient in next step to smooth the torque.
                    obj.dhd_last = obj.dhd;
                        
                    % if command to stand, decide if should stand ( stand if the last step is left stance and the command is not made during this step or the previous step) 
                    if obj.task_next == 2 && obj.stanceLeg == 1 && obj.to_stand_step_count >= 1.99
                        obj.step_end = 1; 
                    end
                    % count the steps after command to stand
                    if obj.task_next == 2 && obj.task ~= 2
                        obj.to_stand_step_count = obj.to_stand_step_count + 1;
                    end
                    if obj.step_end == 1
                        obj.to_stand_step_count = 0;
                        % reset for the next walking cycle;
                        obj.walking_ini = 0;
                    end    
                        
                end % end of reset step
                
                
                % order the index of stance leg and swing leg
                if obj.stanceLeg == 1 % right stanceleg
                    st_abduction = 6;
                    st_rotation = 7;
                    st_thigh = 8;
                    st_knee = 9;
                    st_toe = 10;
                    sw_abduction = 1;
                    sw_rotation = 2;
                    sw_thigh = 3;
                    sw_knee = 4;
                    sw_toe =5;
                    GRF_st_index = 2;
                    GRF_sw_index = 1;
                    st_index = 2;
                    sw_index = 1;
                    abduction_direction = -1; % when the hip abduct outside, the sign is negative
                    st_LA = st_thigh;
                    st_LL = st_knee;
                    sw_LA = sw_thigh;
                    sw_LL = sw_knee;
                else % left leg in stance
                    st_abduction = 1;
                    st_rotation = 2;
                    st_thigh = 3;
                    st_knee = 4;
                    st_toe = 5;
                    sw_abduction = 6;
                    sw_rotation = 7;
                    sw_thigh = 8;
                    sw_knee = 9;
                    sw_toe = 10;
                    GRF_st_index = 1;
                    GRF_sw_index = 2;
                    st_index = 1;
                    sw_index = 2;
                    abduction_direction = 1;
                    st_LA = st_thigh;
                    st_LL = st_knee;
                    sw_LA = sw_thigh;
                    sw_LL = sw_knee;
                end           
                
                
                %% Get the phase variables
                s_unsat = obj.s_unsat_prev + (t - obj.t_prev)*obj.gaitparams.ct;
                s = min(s_unsat,1.05); % here s indicates the phase, 0 is the beginning of a step and 1 is the end of a step.
                
                % Generate some bezier curve that can be used later.
                sf_b = [0,0,ones(1,20)];
                s_fast = YToolkits.bezier(sf_b,s);
                ds_fast = YToolkits.dbezier(sf_b,s)*obj.gaitparams.ct;             
                sl_b = [0,0,ones(1,4)];
                s_slow = YToolkits.bezier(sl_b,s);
                ds_slow = YToolkits.dbezier(sl_b,s)*obj.gaitparams.ct;
                
                sendl_b = [ones(1,4),0,0];
                send_slow = YToolkits.bezier(sendl_b,s);
                dsend_slow = YToolkits.dbezier(sendl_b,s)*obj.gaitparams.ct;
                sendf_b = [ones(1,20),0,0];
                send_fast = YToolkits.bezier(sendf_b,s);
                dsend_fast = YToolkits.dbezier(sendf_b,s)*obj.gaitparams.ct;
                
                ssf_b = [0,0,ones(1,50)];
                s_superfast = YToolkits.bezier(ssf_b,s);
                                
                %% Get bezier coefficient for gait from Gaitlibrary obj.dqx_b_fil + obj.fil_vel_offset 
                % For zero speed only obj.dqx_b_fil
                % Get the desire joint values from the gait library. obj, GaitLibrary, phi, T, s
                
                % Send this signal to controller directly obj.v_final_avgy 
                
                obj.gaitparams = ControlPolicy(obj, GaitLibrary, GaitLibrary_Ori, obj.dqx_b_fil, obj.dqy_b_fil, s, t);
                
                % estimating velocity
                [dqx,dqy,dqz] = get_velocity_v3(obj,qall,dqall); % v1 toe joint; v2 toe bottom; v3 toe back; v4 toe front
                % if the stance leg is off ground, set the velocity be 0 and let the velocity filter do the work
                dqx = s_LR(st_index)*dqx;
                dqy = s_LR(st_index)*dqy;
                dqz = s_LR(st_index)*dqz;
                
                % rotate the velocity to the torso frame ( YAW only!!!)
                Rz = YToolkits.Angles.Rz(qyaw);
                dq_b = Rz'*[dqx;dqy;dqz];
                dqx_b = dq_b(1);
                dqy_b = dq_b(2);
                dqz_b = dq_b(3);
                
                
                dqall_g = [ dqx;  dqy;              dqz;              dqyaw;         dqpitch;            dqroll;
                      dq_abduction_L;	dq_rotation_L;	dq_thigh_L;  dq_thigh_knee_L; dq_knee_shin_L;  dq_shin_tarsus_L; dq_toe_L;
                      dq_abduction_R;	dq_rotation_R;	dq_thigh_R;  dq_thigh_knee_R; dq_knee_shin_R;  dq_shin_tarsus_R; dq_toe_R];
                
                % These foot velocitiy and position has the assumption that torso xyz is
                % fixed at [0;0;0](but torso velocity is not 0). foot position is the toe joint position. IN THE BODY FRAME!
                [l_foot_v, r_foot_v] = get_feet_velocity(qall,dqall_g);
                [l_foot_p, r_foot_p] = get_feet_position(qall,dqall_g);
                
                r_foot_v = Rz'*r_foot_v;
                l_foot_v = Rz'*l_foot_v;
                r_foot_p = Rz'*r_foot_p;
                l_foot_p = Rz'*l_foot_p;
                
                foot_px = [l_foot_p(1); r_foot_p(1)];
                foot_py = [l_foot_p(2);r_foot_p(2)];
                foot_pz = [l_foot_p(3); r_foot_p(3)];
                
                % position and velocity of COM has the assumption that
                % torso position is at origion but velocity is not 0.
                com_pos = ComPosition(qall);
                com_pos = com_pos';
                com_vel = ComVelocity(qall,dqall_g);
                com_pos = Rz'*com_pos;
                com_vel = Rz'*com_vel;
                
                % filter the velocity
                obj.dqx_fil   = YToolkits.first_order_filter(obj.dqx_fil,dqx,obj.fil_para_x);
                obj.dqy_fil   = YToolkits.first_order_filter(obj.dqy_fil,dqy,obj.fil_para_y);
                obj.dqz_fil   = YToolkits.first_order_filter(obj.dqz_fil,dqz,obj.fil_para_x);
                obj.dqx_b_fil = YToolkits.first_order_filter(obj.dqx_b_fil,dqx_b,obj.fil_para_x);
                obj.dqy_b_fil = YToolkits.first_order_filter(obj.dqy_b_fil,dqy_b,obj.fil_para_y);
                obj.dqz_b_fil = YToolkits.first_order_filter(obj.dqz_b_fil,dqz_b,obj.fil_para_x);
                obj.com_vel_x_fil = YToolkits.first_order_filter(obj.com_vel_x_fil,com_vel(1),obj.fil_para_2);
                obj.com_vel_y_fil = YToolkits.first_order_filter(obj.com_vel_y_fil,com_vel(2),obj.fil_para_2);
                obj.com_vel_z_fil = YToolkits.first_order_filter(obj.com_vel_z_fil,com_vel(3),obj.fil_para_2);
                obj.com_pos_x_fil = YToolkits.first_order_filter(obj.com_pos_x_fil,com_pos(1),obj.fil_para_3);
                obj.com_pos_y_fil = YToolkits.first_order_filter(obj.com_pos_y_fil,com_pos(2),obj.fil_para_3);
                obj.com_pos_z_fil = YToolkits.first_order_filter(obj.com_pos_z_fil,com_pos(3),obj.fil_para_3);
                
      
                %% 
                u_CP_stance_knee = 0;
                e_CP_stance_knee = 0;
                u_OT_stance_knee = 0;

                u_CP_stance_hip_pitch = 0;
                e_CP_stance_hip_pitch = 0;
                u_OT_stance_hip_pitch = 0;
                
                
                u_CP_stance_abduction = 0;
                e_CP_stance_abduction = 0;
                u_OT_stance_abduction = 0;
                
                u_CP = zeros(10,1);
                e_CP = zeros(10,1);
                %% Walking Controller
                hd_original = zeros(10,1);
                lateral_ftpl = 0;
%                 hd_original_FROST = zeros(10,1);
                % obj.gaitparams_fil.HAlpha = obj.gaitparams_fil.HAlpha*0.5 + obj.gaitparams.HAlpha*0.5;
                if obj.task == 1 % walking
                    % Compute desired outputs ( here the outputs dose not
                    % include torso orientation. the outputs will be
                    % modified later
                    obj.hd = YToolkits.bezier(obj.gaitparams.HAlpha,s);
                    
                    [ hd_original, ~] = get_IK(obj,obj.hd,obj.dhd);
                    obj.dhd = YToolkits.dbezier(obj.gaitparams.HAlpha,s)*obj.gaitparams.ct;
                    
                    %% swing leg foot placement
                    if obj.foot_placement ==1                         
                        
                        % foot placement in saggital plane + add pitch angle in outputs 
                        obj.hd(sw_LA) = obj.hd(sw_LA)   + (obj.Kfs_p*(obj.dqx_b_fil-obj.tg_velocity_x_fil) + obj.sagittal_offset + obj.Kfs_d*(obj.dqx_b_fil - obj.v_final(1)))*s_slow  + qpitch*s_slow;
                        obj.dhd(sw_LA) = obj.dhd(sw_LA) + (obj.Kfs_p*(obj.dqx_b_fil-obj.tg_velocity_x_fil) + obj.sagittal_offset + obj.Kfs_d*(obj.dqx_b_fil - obj.v_final(1)))*ds_slow + qpitch*ds_slow + dqpitch*ds_slow;
                        
                        % Modify the desired stance leg angle (stance hip joint and stance knee joint) to stablize the pitch motion of the torso
                        % obj.hd(st_LA)  = obj.hd(st_LA)   - ( 0.001 * obj.Kp_pitch * qpitch  + 0.002 * obj.Kd_pitch * dqpitch  )*s_fast  ;
                        % obj.dhd(st_LA) = obj.dhd(st_LA)  - ( 0.001 * obj.Kp_pitch * qpitch  + 0.002 * obj.Kd_pitch * dqpitch  )*ds_fast ;                       
                        obj.hd(st_LA)  = obj.hd(st_LA)   - ( qpitch*s_slow  + dqpitch*s_slow );
                        obj.dhd(st_LA) = obj.dhd(st_LA)  - ( qpitch*ds_slow + dqpitch*ds_slow );                            
                           
                        % foot placement in frontal plane + add roll angle in outputs 
                        obj.dqy_b_avg_1  = (obj.lateral_velocity_weight*obj.dqy_b_fil+(1-obj.lateral_velocity_weight)*obj.dqy_b_start);
                        lateral_ftpl = (  obj.Kfl_p*(obj.dqy_b_avg_1 - obj.lateral_move_fil) + ...
                                          obj.Kfl_d*(obj.dqy_b_avg_1 - obj.v_final_avgy)            )*min(1.5*s,1);
                        %+ abduction_direction*obj.init_lateral_velocity*median([0,1,obj.dqx_b_fil]))*min(1.5*s,1);
                        
                        if sign(lateral_ftpl) == abduction_direction
                            p = 1;
                        else
                            p = obj.abduction_inward_gain;
                        end              
                        
                        obj.hd(sw_abduction)  = obj.hd(sw_abduction)  +  p * lateral_ftpl * s_slow  + (obj.lateral_offset)*s_slow  - qroll*s_slow ;
                        obj.dhd(sw_abduction) = obj.dhd(sw_abduction) +  p * lateral_ftpl * ds_slow + (obj.lateral_offset)*ds_slow - qroll*ds_slow - dqroll*s_slow;
                        
%                         obj.hd(st_abduction)  =  obj.hd(st_abduction)   +  0.01*qroll*s_slow ;
%                         obj.dhd(st_abduction) =  obj.dhd(st_abduction)  +  0.01*qroll*s_slow  + 0.2*dqroll*s_slow;    
                        obj.hd(st_abduction)  =  obj.hd(st_abduction)   +  qroll*s_slow ;
                        obj.dhd(st_abduction) =  obj.dhd(st_abduction)  +  qroll*ds_slow  + dqroll*ds_slow;                           
                        
%                         obj.hd(st_abduction)  =  obj.hd(st_abduction)   +  0.5*qroll;
%                         obj.dhd(st_abduction) =  obj.dhd(st_abduction)  +  0.5*qroll + 4.5*dqroll;                            
%                         obj.hd(st_abduction)  =  obj.hd(st_abduction)   +  0.05*qroll*s_slow ;
%                         obj.dhd(st_abduction) =  obj.dhd(st_abduction)  +  0.05*qroll*s_slow  + 0.5*dqroll*s_slow;                         
                        
                        % use hip yaw motor on swing leg to maintain the direction ( or not). 
                        if obj.to_turn ~=1 && obj.keep_direction
                            direction_keep_term  = median([-0.2,0.2,YToolkits.wrap2Pi(obj.tg_yaw - qyaw)]);
                            obj.hd(sw_rotation)  = obj.hd(sw_rotation) + (direction_keep_term+ obj.turning_offset)*s_slow;
                            obj.dhd(sw_rotation) = obj.dhd(sw_rotation) + (direction_keep_term + obj.turning_offset)*ds_slow;                            
                        else
                            obj.hd(sw_rotation)  = obj.hd(sw_rotation) + (obj.rotation_move + obj.turning_offset)*s_slow;
                            obj.dhd(sw_rotation) = obj.dhd(sw_rotation) + (obj.rotation_move + obj.turning_offset)*ds_slow;
                        end
                        

                    end
                    % prevent sw abduction from hitting AR's safety bound
                    obj.hd(sw_abduction) = median([obj.ActuatorLimits(sw_abduction,1) + 0.1,obj.hd(sw_abduction),obj.ActuatorLimits(sw_abduction,2) - 0.1]);
                               
                    %% Preparation for standing
                    if obj.stanceLeg == -1 && obj.to_stand_step_count >= 1.99 % left stance leg (second step) shift the COM to the right
                        obj.hd(sw_abduction) = obj.hd(sw_abduction) - abduction_direction * obj.final_sw_abduction * s_slow;
                        obj.dhd(sw_abduction) = obj.dhd(sw_abduction) - abduction_direction * obj.final_sw_abduction * ds_slow;
                        obj.hd(st_abduction) = obj.hd(st_abduction) + abduction_direction * obj.final_st_abduction * s_slow;
                        obj.dhd(st_abduction) = obj.dhd(st_abduction) + abduction_direction * obj.final_st_abduction * ds_slow;                     
                    end
                    
                    if obj.stanceLeg == 1 && obj.to_stand_step_count >= 0.99 % right stance leg (first step) shift the COM to the left 
                        obj.hd(sw_abduction)  = obj.hd(sw_abduction)  - abduction_direction * obj.pre_final_sw_abduction * s_slow;
                        obj.dhd(sw_abduction) = obj.dhd(sw_abduction) - abduction_direction * obj.pre_final_sw_abduction * ds_slow;
                    end
                    
                    %% compute torque 
                    obj.y  = obj.h0  - obj.hd;
                    obj.dy = obj.dh0 - obj.dhd;
                    
                    [ obj.hd_joint, obj.dhd_joint] = get_IK(obj,obj.hd,obj.dhd);
                    [ obj.h0_joint, obj.dh0_joint] = get_IK(obj,obj.h0,obj.dh0);
                    
                    %% Make the stance leg passive
                    %if obj.stance_passive == 1
                    %    obj.hd_joint(st_LA) = obj.h0_joint(st_LA);
                    %    obj.dhd_joint(st_LA) = 0;
                    %end
                    
                    %% Make the toe joint passive during the stance phase
                    % flat the toe ( tilt a little bit)
                    % obj.hd(sw_toe) = obj.h0_joint(sw_thigh) + deg2rad(13) + deg2rad(50) ; % 13 is the angle between tarsus and thihg, 50 is the angle of transforming frame on foot.
                    % obj.hd(sw_toe) = obj.hd(sw_toe) + obj.toe_tilt_angle*s_fast; % Zhenyu: compensate for jumps observed in the experiments
                    
                    % Make toe passive during stance
                    %obj.dhd(sw_toe) = 0;
                    %obj.hd(st_toe) = obj.h0(st_toe);
                    %obj.dhd(st_toe) = obj.dh0(st_toe);                    

                    %% Save it for resetting bezier ( for the passive stance Leg)
                    [ obj.hd, obj.dhd] = get_FK(obj, obj.hd_joint,obj.dhd_joint);
                    
                    obj.y_joint= obj.h0_joint - obj.hd_joint;
                    obj.dy_joint = obj.dh0_joint - obj.dhd_joint;
                    u = - obj.Kp.*obj.y_joint - obj.Kd.*obj.dy_joint; % not final torque, some compensation for gravity will be added, the torque on stance hip roll and stance hip pitch will be replaced.
                    
                          
                    %% Torso Torque Control
                    
                    if 0
                        
                        % bring them back to test the knee joint tracking only.
                        u_torso_pitch = - obj.Kp_pitch * qpitch - obj.Kd_pitch * dqpitch;
                        u_torso_roll  =   obj.Kp_roll  * qroll  + obj.Kd_roll  * dqroll;

                        %if t < 10
                            if obj.pitch_torso_control == 1
                                u(3) = (1 - s_L)*u(3) + s_L*u_torso_pitch;
                                u(8) = (1 - s_R)*u(8) + s_R*u_torso_pitch;

                            end

                            if obj.roll_torso_control == 1
                                u(1) = (1 - s_L)*u(1) + s_L*u_torso_roll;
                                u(6) = (1 - s_R)*u(6) + s_R*u_torso_roll;
                            end
                        %end 
                    
                    end

                    %% Compensation initial handling
                     s_int = s;
                     if obj.s_previous_step(end) <= s % bound the s in the current compensation step
                       s_int  = obj.s_previous_step(end);
                     end  
                     num_diff = linspace(0,1e-9,size(obj.s_previous_step,2)); % make this increasing       
                     

                     % Interpolate Multiple Sets of Data in One Pass (data must be stored as coloum vectors)
                     u_CP = interp1(obj.s_previous_step + num_diff, obj.Torque_PreviousStep', s_int);
                     u_CP = reshape(u_CP,10,1); % reshape it to 10x1
                     if obj.s_previous_step(end) >= s + 0.02
                       e_CP = interp1(obj.s_previous_step + num_diff, obj.Error_PreviousStep', s_int + 0.02);
                     else
                       e_CP = obj.Error_PreviousStep(:,end);
                     end
                     e_CP = reshape(e_CP,10,1); % reshape it to 10x1
                     
                     
                    
                    %% abduction compensation
                    % when SG button is at -1, use constant compensation
                    % when SG button is at  0, use ILC for stance abduction compensation only
                    % when SG button is at +1, use ILC for both stance and
                    % swing abduction compensation
                    
                    if obj.abduction_com == 1
                        %u(st_abduction) = u(st_abduction) + abduction_direction*obj.u_abduction_cp*s_fast;
                        %u(sw_abduction) = u(sw_abduction) - abduction_direction*obj.u_abduction_cp*(1-s_fast);
                        
                         if RadioButton.SGA == -1  %t < 8
                             
                             % Stance abduction constant compensation
                             s_CP_stance_abduc = YToolkits.bezier(obj.CP_StanceAbdu,s);
                             u(st_abduction) = u(st_abduction) + abduction_direction * s_CP_stance_abduc;% + u_torso_roll;

                         else  
                             
                             % Stance abduction compensation
                             u_CP_stance_abduction = clamp(u_CP(1), -180, 180); % Nm
                             e_CP_stance_abduction = clamp(e_CP(1), -5, 5); % rad
                             u(st_abduction) = u(st_abduction) + abduction_direction * u_CP_stance_abduction*s_fast +  abduction_direction * obj.Gamma_st_abu*e_CP_stance_abduction*s_fast; %  + u_torso_roll

                         end
                         

                         
                        if RadioButton.SGA == +1
                             % Swing abduction compensation              
                             
                             u_CP_swing_abduction = clamp(u_CP(6), -100, 100); % Nm
                             e_CP_swing_abduction = clamp(e_CP(6), -5, 5); % rad
                             u(sw_abduction) = u(sw_abduction) - abduction_direction * u_CP_swing_abduction*(1-s_fast) - abduction_direction * obj.Gamma_sw_abu*e_CP_swing_abduction*(1-s_fast); %  + u_torso_roll
                        
                        else    
                             % Swing abduction constant compensation              
                             s_CP_swing_abduc  = YToolkits.bezier(obj.CP_SwingAbdu ,s);
                             u(sw_abduction) = u(sw_abduction) - abduction_direction * s_CP_swing_abduc;
                        end     
                         
                        
                        %if obj.abduction_swing_com == 1
                        %    u(st_abduction) = u(st_abduction) + abduction_direction*obj.u_abduction_swing_cp*(1-s_fast);
                        %    u(sw_abduction) = u(sw_abduction) - abduction_direction*obj.u_abduction_swing_cp*s_fast;
                        %end
                        %u(sw_abduction) = u(sw_abduction) - abduction_direction*obj.uHip_gravity_2*s_fast;
                        

                    end
                    

 

                    %% thigh (hip pitch) compensation
                    % when SD button is at -1, use constant compensation
                    % when SD button is at  0, use ILC for stance hip compensation only
                    % when SD button is at +1, use ILC for both stance and
                    % swing hip compensation

                    
                    if obj.thigh_compensation == 1
                        
                        % Stance knee compensation
                        if RadioButton.SDA  == -1  %t < 5  % || obj.com_vel_y_fil > 0.2 % currently the com keep drifting to the left
                             % stance thigh compensation using a predefined
                             % fuction:
                             % Constant stance thigh compensation
                             u(st_thigh) = u(st_thigh) + (-15) * s_fast;% + u_torso_roll;
                             % u(st_thigh) = u(st_thigh) + obj.u_thigh_cp*s_fast;
                             
                        else  
                             % ILC stance thigh compensation:
                             u_CP_stance_hip_pitch = clamp(u_CP(3), -150, 150); % Nm
                             e_CP_stance_hip_pitch = clamp(e_CP(3), -1, 1); % rad
                             u(st_thigh) = u(st_thigh) + u_CP_stance_hip_pitch*s_superfast  + obj.Gamma_st_hip*e_CP_stance_hip_pitch;%  + u_torso_pitch;

                        end  
                        
                        % swing thigh compensation
                        if RadioButton.SDA  == +1
                             % ILC swing thigh compensation
                             u_CP_swing_hip_pitch = clamp(u_CP(8), -80, 80); % Nm
                             e_CP_swing_hip_pitch = clamp(e_CP(8), -1, 1); % rad
                             u(sw_thigh) = u(sw_thigh) + u_CP_swing_hip_pitch*s_superfast  + obj.Gamma_sw_hip*e_CP_swing_hip_pitch;%  + u_torso_pitch; 

                        else
                             % Constant swing thigh compensation
                             u(sw_thigh) = u(sw_thigh) + obj.u_thigh_cp*(1-s_fast);
                            
                        end     
                        
                        
                        
                    
                    end
                     
                                     
                    %% knee compensation
                    % when SC button is at  0, use constant compensation
                    % when SC button is at -1, use ILC for stance knee compensation only
                    % when SC button is at +1, use ILC for both stance and
                    % swing knee compensation

                    if obj.knee_com == 1
                               
                         if  RadioButton.SCA == -1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             == 1
                             % Constant stance knee compensation
                             % u(st_knee) = u(st_knee) + (obj.u_knee_cp)*s_fast*cos(obj.h0(st_thigh));
                             % Use a Bezier polynomial for knee precompensation: 
                             s_CP_stance_knee = YToolkits.bezier(obj.CP_StanceKnee,s);
                             u(st_knee) = u(st_knee) + s_CP_stance_knee*s_superfast;      
                        
                         else  
                             % ILC stance knee compensation
                             % these are the st_knee in the previous step
                             u_CP_stance_knee = clamp(u_CP(4), -20, 180); % Nm
                             e_CP_stance_knee = clamp(e_CP(4), -2, 2); % rad

                             u(st_knee) = u(st_knee) + u_CP_stance_knee + obj.Gamma_st_knee*e_CP_stance_knee;
                             
                         end
                         
                         % Swing knee compensation
                         if  RadioButton.SCA == +1 % turn on the swing knee compensation
                             
                             % ILC swing knee compensation
                             u_CP_swing_knee = clamp(u_CP(9), -50, 50); % Nm
                             e_CP_swing_knee = clamp(e_CP(9), -2, 2); % rad
                             u(sw_knee) = u(sw_knee) + u_CP_swing_knee + obj.Gamma_sw_knee*e_CP_swing_knee; 
                        
                         else
                   
                             % Constant swing knee compensation
                             s_CP_swing_knee = YToolkits.bezier(obj.CP_SwingKnee,s); 
                             u(sw_knee) = u(sw_knee) + s_CP_swing_knee;
                         end     
                             

                    end
                    
                    %% Toe compensation
                    toe_com = 1;
                   
                    if toe_com == 1
                       u(st_toe) = u(st_toe) + 5*s_fast;
                       u(sw_toe) = u(sw_toe) + 0;
                    end 
                                                   
                    %% Construct Data
                    Data.hd = obj.hd; 
                    Data.dhd = obj.dhd;
                    Data.hd_joint = obj.hd_joint;
                    Data.dhd_joint = obj.dhd_joint;
                    Data.y_joint = obj.y_joint ;
                    Data.dy_joint   = obj.dy_joint ;
          
                    
                    % in the data structure, stance joints are 1:5 and swing joints are 6:10    
                    if obj.stanceLeg == 1 % right stanceleg
                        % Not only legs are switched, but the direction
                        % of the abuduction motors and yaw motors are
                        % changed.
                        obj.Error_CurrentStep([1,2,  6,7], obj.kstep)  =   obj.y_joint([6, 7, 1, 2]);
                        obj.Error_CurrentStep([3:5, 8:10], obj.kstep)  =   obj.y_joint([8:10, 3:5]);
                        
                        obj.Torque_CurrentStep([1,2,  6,7], obj.kstep)  =  -u([6, 7, 1, 2]);
                        obj.Torque_CurrentStep([3:5, 8:10], obj.kstep)  =   u([8:10, 3:5]);
                        
                        
                    else % left leg in stance
                        obj.Error_CurrentStep(:, obj.kstep)   =   obj.y_joint;
                        obj.Torque_CurrentStep(:, obj.kstep)  =   u;
                    end                         
                    
                    
                    obj.s_current_step(obj.kstep) = s;
                    obj.kstep = obj.kstep + 1;
                end
                
                

                %% stand up
                if obj.task == 2              
                    % If next task is to walk, shift the center of mass to
                    % left
                    if obj.task_next == 1
                        obj.t1 = (obj.t1 + (t - obj.t_prev));
                        obj.s1 = obj.t1/obj.shift_time;
                        lateral_shift = obj.shift_distance * obj.s1;
                    else
                        lateral_shift = 0;
                    end
                    
                    % Based on the commanded roll angle, and lateral_shift,
                    % decide the Leg Length Difference in right and left
                    % leg.
                    left_tune = - obj.s2*max([s_L; s_R]) * (obj.Kp_lateral_stand*(qroll - obj.roll_des_fil - (-lateral_shift))  + obj.Kd_lateral_stand*dqroll);
                    right_tune = obj.s2*max([s_L; s_R]) * (obj.Kp_lateral_stand*(qroll - obj.roll_des_fil - (-lateral_shift)) + obj.Kd_lateral_stand*dqroll);
                    % Inverse kinematics
                    [qthigh_d_L, qknee_d_L ] = Inverse_Kinematics_p(obj.pitch_des_fil, min(obj.LL_des_fil + left_tune, 0.9));
                    [qthigh_d_R, qknee_d_R ] = Inverse_Kinematics_p(obj.pitch_des_fil, min(obj.LL_des_fil + right_tune, 0.9));
                    [dqthigh_d_L, dqknee_d_L] = Inverse_Kinematics_v(obj.pitch_des_fil, min(obj.LL_des_fil + left_tune, 0.9), 0, 0);
                    [dqthigh_d_R, dqknee_d_R] = Inverse_Kinematics_v(obj.pitch_des_fil, min(obj.LL_des_fil + right_tune, 0.9), 0, 0);
                    y_thigh = [obj.h0_joint(3)-qthigh_d_L; obj.h0_joint(8)-qthigh_d_R];
                    dy_thigh = [obj.dh0_joint(3)-dqthigh_d_L; obj.dh0_joint(8)-dqthigh_d_R];
                    y_knee = [obj.h0_joint(4)-qknee_d_L; obj.h0_joint(9)-qknee_d_R];
                    dy_knee = [obj.dh0_joint(4)-dqknee_d_L; obj.dh0_joint(9)-dqknee_d_R];
                    
                    % calculate the torque ( except toe).
                    u([1,6]) = - (obj.Kp_abduction_stand*[obj.h0_joint(1)-obj.standing_abduction_offset; obj.h0_joint(6) - ( - obj.standing_abduction_offset)] + obj.Kd_abduction_stand*[obj.dh0_joint(1); obj.dh0_joint(6)]);
                    u([2,7]) = - (obj.Kp_rotation_stand*[obj.h0_joint(2);obj.h0_joint(7)] + obj.Kd_rotation_stand*[obj.dh0_joint(2);obj.dh0_joint(7)]);
                    u([3,8]) = - (obj.Kp_thigh_stand.*y_thigh + obj.Kd_thigh_stand.*dy_thigh);
                    u([4,9]) = - (obj.Kp_knee_stand*y_knee + obj.Kd_knee_stand*dy_knee);
                    % calculate the toe torque
                    P_feedback_toe = ( com_pos(1) - obj.stand_offset- (r_foot_p(1)+l_foot_p(1))/2);
                    obj.P_feedback_toe_fil = YToolkits.first_order_filter(obj.P_feedback_toe_fil,P_feedback_toe,obj.fil_para_3);
                    u_toe = - (obj.Kp_toe_stand*obj.P_feedback_toe_fil + obj.Kd_toe_stand*( obj.com_vel_x_fil - 0));
                    u([5,10]) = min(s_L,s_R)*u_toe;
                    u([5,10]) = YToolkits.clamp(u([5,10]),-15,15);
                    
                    % from walking to stand ( to make torque smooth in transition)
                    obj.t2 = (obj.t2 + (t - obj.t_prev));
                    obj.s2 = min(obj.t2/obj.standing_switch_time,1);
                    s2_b = [0,0,ones(1,20)];
                    switch_weight  = YToolkits.bezier(s2_b,obj.s2);
                    u = switch_weight*u + (1-switch_weight)*obj.u_last;
                    
                    Data.LL_des_fil = obj.LL_des_fil;
                    Data.y_knee = y_knee;
                    Data.dy_knee = dy_knee;
                    Data.qknee_d_L = qknee_d_L;
                    Data.qknee_d_R = qknee_d_R;
                    Data.left_tune = left_tune;
                    Data.right_tune = right_tune;
                end
          
                %% log object properties
                
                obj.t_prev = t;
                obj.s_prev = s;
                obj.s_unsat_prev = s_unsat;
                obj.task_prev = obj.task;
                obj.u_prev = u;
                obj.hd_prev = obj.hd;
                obj.dhd_prev = obj.dhd;
                obj.h0_prev = obj.h0;
                obj.dh0_prev = obj.dh0;
                obj.y_prev = obj.y;
                obj.dy_prev = obj.dy;
                obj.hd_joint_prev = obj.hd_joint;
                obj.dhd_joint_prev = obj.dhd_joint;
                obj.h0_joint_prev = obj.h0_joint;
                obj.dh0_joint_prev = obj.dh0_joint;
                obj.y_joint_prev = obj.y_joint;
                obj.dy_joint_prev = obj.dy_joint;
                obj.to_turn_prev = obj.to_turn;
                
                %% Return                
                userInputs.telemetry(1) = qsL(1)*1000;
                userInputs.telemetry(2) = qsL(2)*1000;
                userInputs.telemetry(3) = qsR(1)*1000;
                userInputs.telemetry(4) = qsR(2)*1000;
                userInputs.telemetry(5) = dqyaw*180/pi;
                userInputs.telemetry(6) = u(5);
                userInputs.telemetry(7) = u(10);
                userInputs.telemetry(8) = GRF_v(1);
                userInputs.telemetry(9) = GRF_v(2);

                u = YToolkits.vector_saturate(u,obj.safe_TorqueLimits,-obj.safe_TorqueLimits);

                userInputs.torque = u;
                  
                %% log Data
                Data.s = s;
                Data.stanceLeg = obj.stanceLeg;
                Data.task = obj.task;
                Data.GRF = [GRF_L(2); GRF_R(2)];
                Data.s_LR = s_LR;
                Data.tp_last = obj.tp_last;

                
                Data.h0 = obj.h0;
                Data.dh0 = obj.dh0;
                Data.h0_joint = obj.h0_joint;
                Data.dh0_joint = obj.dh0_joint;
                Data.hd = obj.hd;
                Data.dhd = obj.dhd;
                Data.hd_joint = obj.hd_joint;
                Data.dhd_joint = obj.dhd_joint;
                
                Data.u = u;
                Data.torso_angle = [qyaw; qpitch; qroll];
                Data.d_torso_angle = [dqyaw; dqpitch; dqroll];
                Data.torso_vx = dqx;
                Data.torso_vy = dqy;
                Data.torso_vz = dqz;
                Data.torso_vx_b = dqx_b;
                Data.torso_vy_b = dqy_b;
                Data.torso_vz_b = dqz_b;
                Data.torso_vx_fil = obj.dqx_fil;
                Data.torso_vy_fil = obj.dqy_fil;
                Data.torso_vz_fil = obj.dqz_fil;
                Data.torso_vx_b_fil = obj.dqx_b_fil;
                Data.torso_vy_b_fil = obj.dqy_b_fil;
                Data.torso_vz_b_fil = obj.dqz_b_fil;
                
                Data.dqy_b_avg_1 = obj.dqy_b_avg_1;
                Data.com_vel_x_fil = obj.com_vel_x_fil;
                Data.com_vel_y_fil = obj.com_vel_y_fil;
                Data.com_vel_z_fil = obj.com_vel_z_fil;
                Data.com_pos_fil = [obj.com_vel_x_fil;obj.com_vel_y_fil;obj.com_vel_z_fil];
                Data.tg_velocity_x = obj.tg_velocity_x;
                
%                 Data.r_foot_v = r_foot_v;
%                 Data.l_foot_v = l_foot_v;
%                 Data.r_foot_p = r_foot_p;
%                 Data.l_foot_p = l_foot_p;
                
                Data.com_pos = com_pos;
                Data.com_vel = com_vel;

                Data.encoder_fil = encoder_fil;
                
%                 Data.q_abduction_R = q_abduction_R;
%                 Data.q_rotation_R = q_rotation_R;
%                 Data.q_thigh_R = q_thigh_R;
%                 Data.q_thigh_knee_R = q_thigh_knee_R;
%                 Data.q_knee_shin_R = q_knee_shin_R;
%                 Data.q_thigh_shin_R = q_thigh_shin_R;
%                 Data.q_shin_tarsus_R = q_shin_tarsus_R;
%                 Data.q_toe_R = q_toe_R;
%                 
%                 Data.q_abduction_L = q_abduction_L ;
%                 Data.q_rotation_L = q_rotation_L;
%                 Data.q_thigh_L = q_thigh_L;
%                 Data.q_thigh_knee_L = q_thigh_knee_L;
%                 Data.q_knee_shin_L = q_knee_shin_L;
%                 Data.q_thigh_shin_L = q_thigh_shin_L;
%                 Data.q_shin_tarsus_L = q_shin_tarsus_L;
%                 Data.q_toe_L = q_toe_L;
%                 
%                 Data.dq_abduction_R = dq_abduction_R;
%                 Data.dq_rotation_R = dq_rotation_R;
%                 Data.dq_thigh_R = dq_thigh_R;
%                 Data.dq_thigh_knee_R = dq_thigh_knee_R;
%                 Data.dq_knee_shin_R = dq_knee_shin_R;
%                 Data.dq_thigh_shin_R = dq_thigh_shin_R;
%                 Data.dq_shin_tarsus_R = dq_shin_tarsus_R;
%                 Data.dq_toe_R = dq_toe_R;
%                 
%                 Data.dq_abduction_L = dq_abduction_L ;
%                 Data.dq_rotation_L = dq_rotation_L;
%                 Data.dq_thigh_L = dq_thigh_L;
%                 Data.dq_thigh_knee_L = dq_thigh_knee_L;
%                 Data.dq_knee_shin_L = dq_knee_shin_L;
%                 Data.dq_thigh_shin_L = dq_thigh_shin_L;
%                 Data.dq_shin_tarsus_L = dq_shin_tarsus_L;
%                 Data.dq_toe_L = dq_toe_L;
                
%                 Data.qall = qall;
%                 Data.dqall = dqall;
                
%                 Data.qq = qq;
%                 Data.qaR = qaR;
%                 Data.qjR = qjR;
%                 Data.qsR = qsR;
%                 Data.qaL = qaL;
%                 Data.qjL = qjL;
%                 Data.qsL = qsL;
%                 
%                 Data.dqaR = dqaR;
%                 Data.dqjR = dqjR;
%                 Data.dqsR = dqsR;
%                 Data.dqaL = dqaL;
%                 Data.dqjL = dqjL;
%                 Data.dqsL = dqsL;
                
               
                Data.hd_original = hd_original;
                Data.Torque_CP = u_CP;
                Data.Error_CP  = e_CP;
                
                Data.RadioChannel = RadioButtonToChannel(RadioButton); % 16x1
                Data.lateral_ftpl = lateral_ftpl;
%                         obj.Error_CurrentStep(:, obj.kstep)  =  obj.y_joint;
%                         obj.Torque_CurrentStep(:, obj.kstep) =  u;
                
%                         obj.Error_CurrentStep(:, obj.kstep)  =  obj.y_joint;
%                         obj.Torque_CurrentStep(:, obj.kstep) =  u;

                           
            end
            % Return the updated Cassie inputs data structure
            
        end % stepImpl
        
        %% util functions
        function gaitparams = ControlPolicy( obj, GaitLibrary_2D, GaitLibrary_Ori, cur_speed_x , cur_speed_y, s , t)
            
            if obj.stanceLeg == 1 % right stance
               LT_2D = GaitLibrary_2D.LT_2D_Right; % size(21,31,15,2);
            else
               LT_2D = GaitLibrary_2D.LT_2D_Left; % size(21,31,15,2); 
            end    
      
            dxr = GaitLibrary_2D.dxo_range'; %31x1
            dyr = GaitLibrary_2D.dyo_range'; %14x1
            
            Sid = linspace(0,1,21);
            S_cur = clamp(s,0,1);
            LT_2D_s = interp1(Sid, LT_2D, S_cur);  % size(1,31,15,2);
            LT_2D_s = squeeze(LT_2D_s); % size(31,15,2);
            
            LT_2D_s_x = reshape(LT_2D_s(:,7,1),31,1);
            LT_2D_s_y = reshape(LT_2D_s(15,:,2),14,1);

            %%
            vx_cur = clamp(cur_speed_x,min(LT_2D_s_x),max(LT_2D_s_y));
            vy_cur = clamp(cur_speed_y,min(LT_2D_s_y),max(LT_2D_s_y)); % check this and see if I can use larger boundaries;

            Vsp_x  = interp1(LT_2D_s_x,dxr,vx_cur);
            Vsp_y  = interp1(LT_2D_s_y,dyr,vy_cur);
            
                               
            ct_R = 1/0.4;
            ct_L = 1/0.4;
            
            if obj.stanceLeg == 1
                HAlpha_R = GaitLibrary_2D.RightStance.HAlpha;
                HAlpha_R_dx = interp1(dxr,HAlpha_R,Vsp_x); % 31x14x10x6
                HAlpha_R_dx = squeeze(HAlpha_R_dx); %
                HAlpha_R_dx_dy = interp1(dyr,HAlpha_R_dx,Vsp_y); % 31x14x10x6
                HAlpha_R_Cur = squeeze(HAlpha_R_dx_dy); %
                gaitparams.HAlpha = HAlpha_R_Cur;

                gaitparams.HAlpha(:,1) = obj.hd_last;
                gaitparams.HAlpha(:,2) = obj.hd_last + obj.dhd_last/ct_R/obj.bezier_degree;
                gaitparams.ct = ct_R;
            else
                
                HAlpha_L = GaitLibrary_2D.LeftStance.HAlpha;
                HAlpha_L_dx = interp1(dxr,HAlpha_L,Vsp_x); % 31x14x10x6
                HAlpha_L_dx = squeeze(HAlpha_L_dx); %
                HAlpha_L_dx_dy = interp1(dyr,HAlpha_L_dx,Vsp_y); % 31x14x10x6
                HAlpha_L_Cur = squeeze(HAlpha_L_dx_dy); %
                gaitparams.HAlpha = HAlpha_L_Cur;
                gaitparams.HAlpha(:,1) = obj.hd_last;
                gaitparams.HAlpha(:,2) = obj.hd_last + obj.dhd_last/ct_L/obj.bezier_degree;
                gaitparams.ct = ct_L;
            end       
                           
        end
        
        
        function [dqx,dqy,dqz] = get_velocity_v3(obj,q,dq)
            if obj.stanceLeg == 1
                range = 14:20;
                J = J_RightToeBottomBack(q);
            else
                J = J_LeftToeBottomBack(q);
                range = 7:13;
            end
            v_torso = (-J(:,1:3)^-1)*(J(:,4:6)*dq(4:6)+J(:,range)*dq(range));
            dqx = v_torso(1);
            dqy = v_torso(2);
            dqz = v_torso(3);
        end     
        function [ GRF_L, GRF_R  ] = get_GRF(obj,qall,qsR,qsL,u)
            qall(4) = 0;
            JR = J_RightToeJoint(qall);
            JL = J_LeftToeJoint(qall);
            [Fs1R, Fs2R, Fs1L, Fs2L] = get_spring_force(obj,qsR,qsL);
            JR_s = JR([1,3],[18,19]);
            JL_s = JL([1,3],[11,12]);
            GRF_R = (-JR_s')^-1*[Fs1R+Fs2R; Fs2R];
            GRF_L = (-JL_s')^-1*[Fs1L+Fs2L; Fs2L];
        end  
        function [Fs1R, Fs2R, Fs1L, Fs2L] = get_spring_force(obj,qsR,qsL)
            Fs1R =- obj.Ks1 * qsR(1);
            Fs2R =- obj.Ks2 * qsR(2);
            Fs1L =- obj.Ks1 * qsL(1);
            Fs2L =- obj.Ks2 * qsL(2);
        end
        function [s_L, s_R] = get_s_LR(obj, GRF_v)
            s_L = (GRF_v(1)-obj.stance_thre_lb)/(obj.stance_thre_ub-obj.stance_thre_lb);
            s_R = (GRF_v(2)-obj.stance_thre_lb)/(obj.stance_thre_ub-obj.stance_thre_lb);
            s_L = median([0,1,s_L ]);
            s_R = median([0,1,s_R]);
        end
        function [ hd_output, dhd_output] = get_FK(obj, hd_joint,dhd_joint)
            [ hd_output, dhd_output] = get_FK_v2(obj, hd_joint,dhd_joint);
        end
        function [ hd_joint, dhd_joint] = get_IK(obj, hd_output,dhd_output)
            [ hd_joint, dhd_joint] = get_IK_v2(obj, hd_output,dhd_output);
        end
        function [ hd_joint, dhd_joint] = get_IK_v1(obj, hd_output,dhd_output)
            hd_joint = hd_output;
            dhd_joint = dhd_output;
            hd_output(4) = min(hd_output(4),1.02);
            hd_output(9) = min(hd_output(9),1.02);
            [hd_joint(3), hd_joint(4)] = Inverse_Kinematics_p(hd_output(3), hd_output(4));
            [hd_joint(8), hd_joint(9)] = Inverse_Kinematics_p(hd_output(8), hd_output(9));
            [dhd_joint(3), dhd_joint(4)] = Inverse_Kinematics_v(hd_output(3), hd_output(4), dhd_output(3), dhd_output(4));
            [dhd_joint(8), dhd_joint(9)] = Inverse_Kinematics_v(hd_output(8), hd_output(9), dhd_output(8), dhd_output(9));
        end
        
        function [ hd_output, dhd_output] = get_FK_v1(obj, hd_joint,dhd_joint)
            hd_output = hd_joint;
            dhd_output = dhd_joint;
            [hd_output(3), hd_output(4)] = Forward_Kinematics_p(hd_joint(3), hd_joint(4));
            [hd_output(8), hd_output(9)] = Forward_Kinematics_p(hd_joint(8), hd_joint(9));
            [dhd_output(3), dhd_output(4)] = Forward_Kinematics_v(hd_joint(3), hd_joint(4), dhd_joint(3), dhd_joint(4));
            [dhd_output(8), dhd_output(9)] = Forward_Kinematics_v(hd_joint(8), hd_joint(9), dhd_joint(8), dhd_joint(9));
        end
        function [ hd_joint, dhd_joint] = get_IK_v2(obj, hd_output,dhd_output)
            % new leg angle to old leg angle
            [hd_output(3), dhd_output(3)] = LegAngleInverseTransform(obj.com_bp, hd_output(3), hd_output(4), dhd_output(3), dhd_output(4));
            [hd_output(8), dhd_output(8)] = LegAngleInverseTransform(obj.com_bp, hd_output(8), hd_output(9), dhd_output(8), dhd_output(9));
            hd_joint = hd_output;
            dhd_joint = dhd_output;
            hd_output(4) = min(hd_output(4),1.02);
            hd_output(9) = min(hd_output(9),1.02);
            [hd_joint(3), hd_joint(4)] = Inverse_Kinematics_p(hd_output(3), hd_output(4));
            [hd_joint(8), hd_joint(9)] = Inverse_Kinematics_p(hd_output(8), hd_output(9));
            [dhd_joint(3), dhd_joint(4)] = Inverse_Kinematics_v(hd_output(3), hd_output(4), dhd_output(3), dhd_output(4));
            [dhd_joint(8), dhd_joint(9)] = Inverse_Kinematics_v(hd_output(8), hd_output(9), dhd_output(8), dhd_output(9));
        end
        
        function [ hd_output, dhd_output] = get_FK_v2(obj, hd_joint,dhd_joint,com_rp)
            hd_output = hd_joint;
            dhd_output = dhd_joint;
            [hd_output(3), hd_output(4)] = Forward_Kinematics_p(hd_joint(3), hd_joint(4));
            [hd_output(8), hd_output(9)] = Forward_Kinematics_p(hd_joint(8), hd_joint(9));
            [dhd_output(3), dhd_output(4)] = Forward_Kinematics_v(hd_joint(3), hd_joint(4), dhd_joint(3), dhd_joint(4));
            [dhd_output(8), dhd_output(9)] = Forward_Kinematics_v(hd_joint(8), hd_joint(9), dhd_joint(8), dhd_joint(9));
            
            %old leg angle to new leg angle
            [hd_output(3), dhd_output(3)] = LegAngleForwardTransform(obj.com_bp, hd_output(3), hd_output(4), dhd_output(3), dhd_output(4));
            [hd_output(8), dhd_output(8)] = LegAngleForwardTransform(obj.com_bp, hd_output(8), hd_output(9), dhd_output(8), dhd_output(9));

        end
       

             
        %% Default functions
        function setupImpl(obj)
            %SETUPIMPL Initialize System object.
        end % setupImpl
        
        function resetImpl(~)
            %RESETIMPL Reset System object states.
        end % resetImpl
        
        function [name_1, name_2, name_3, name_4, name_5, name_6]  = getInputNamesImpl(~)
            %GETINPUTNAMESIMPL Return input port names for System block
            name_1 = 't';
            name_2 = 'cassieOutputs';
            name_3 = 'isSim';
            name_4 = 'GaitLibrary';
            name_5 = 'GaitLibrary_Ori';
            name_6 = 'encoder_fil';
            name_7 = 'LinuxData';
        end % getInputNamesImpl
        
        function [name_1, name_2] = getOutputNamesImpl(~)
            %GETOUTPUTNAMESIMPL Return output port names for System block
            name_1 = 'userInputs';
            name_2 = 'Data';
        end % getOutputNamesImpl
        
        % PROPAGATES CLASS METHODS ============================================
        function [out, Data] = getOutputSizeImpl(~)
            %GETOUTPUTSIZEIMPL Get sizes of output ports.
            out = [1, 1];
            Data = [1, 1];
        end % getOutputSizeImpl
        
        function [out, Data] = getOutputDataTypeImpl(~)
            %GETOUTPUTDATATYPEIMPL Get data types of output ports.
            out = 'CassieUserInBus';
            Data = 'cassieDataBus';
        end % getOutputDataTypeImpl
        
        function [out, Data] = isOutputComplexImpl(~)
            %ISOUTPUTCOMPLEXIMPL Complexity of output ports.
            out = false;
            Data = false;
        end % isOutputComplexImpl
        
        function [out, Data] = isOutputFixedSizeImpl(~)
            %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports.
            out = true;
            Data = true;
        end % isOutputFixedSizeImpl
    end % methods
end % classdef