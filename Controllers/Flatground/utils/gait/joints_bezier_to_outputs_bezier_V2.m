
% The order of the Bezier Polynomial
% M = 5;
M = 9;


s = linspace(0,1,30);
check_case = 1; % 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity

% GL = load('GaitLibrary_Omar_3.mat');
% GL = load('GaitLibrary_v1.mat');
GL = load('GL_PD_BO9_COM_v1.mat');

GL = GL.GaitLibrary;
GaitLibrary_joint.RightStance.HAlpha = zeros(length(GL),10,M+1);
GaitLibrary_joint.LeftStance.HAlpha = zeros(length(GL),10,M+1);
GaitLibrary_joint.Desired_Velocity = zeros(2,length(GL));
GaitLibrary_joint.RightStance.ct = zeros(1,length(GL));
GaitLibrary_joint.LeftStance.ct = zeros(1,length(GL));
for i = 1:length(GL)
    GaitLibrary_joint.RightStance.HAlpha(i,:,:) =  reshape(GL{i}.solution.params{1}.atime,10,M+1);
    GaitLibrary_joint.LeftStance.HAlpha(i,:,:) =  reshape(GL{i}.solution.params{3}.atime,10,M+1);
    GaitLibrary_joint.Desired_Velocity(:,i) = GL{i}.velocity;
    GaitLibrary_joint.RightStance.ct(i) = 1/GL{i}.solution.params{1}.ptime(1);
    GaitLibrary_joint.LeftStance.ct(i) = 1/GL{i}.solution.params{3}.ptime(1);
end



GaitLibrary_output.RightStance.HAlpha = zeros(length(GL),10,M+1);
GaitLibrary_output.LeftStance.HAlpha = zeros(length(GL),10,M+1);
GaitLibrary_output.RightStance.TorsoAngleAlpha = zeros(length(GL),3,M+1);
GaitLibrary_output.LeftStance.TorsoAngleAlpha = zeros(length(GL),3,M+1);
GaitLibrary_output.RightStance.ct = zeros(1,length(GL));
GaitLibrary_output.LeftStance.ct = zeros(1,length(GL));
GaitLibrary_output.Velocity = zeros(2,length(GL));

GaitLibrary_output.ct = GaitLibrary_joint.LeftStance.ct;
% Right
for i = 1:length(GL)
    RightStance_Alpha_joint = reshape(GaitLibrary_joint.RightStance.HAlpha(i,:,:),10,M+1);
    
    [ hd_joint,dhd_joint,hd_output,dhd_output,hd_joint_fit,dhd_joint_fit,hd_output_fit,dhd_output_fit,alpha_output ] = Alpha_Joint_to_Alpha_output( RightStance_Alpha_joint,s,1/GaitLibrary_joint.RightStance.ct(i),M );
    
    GaitLibrary_output.RightStance.HAlpha(i,:,:) = alpha_output;
    GaitLibrary_output.RightStance.ct(i) = GaitLibrary_joint.RightStance.ct(i);
    GaitLibrary_output.Velocity(:,i) = GL{i}.velocity;
    
    
% % output level check
% switch check_case
%     case 1
%         figure(i)
%         for j = 1:10
%             subplot(2,5,j)
%             plot(s,hd_output(j,:))
%             hold on
%             plot(s,hd_output_fit(j,:))
%             hold off
%         end
%         title('output position')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 2
%         figure(i+9)
%         for j = 1:10
%             subplot(2,5,j)
%             plot(s,dhd_output(j,:))
%             hold on
%             plot(s,dhd_output_fit(j,:))
%             hold off
%         end
%         title('output velocity')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 3
%         figure(i)
%         for j = 1:10
%             subplot(2,5,j)
%             plot(s,hd_joint(j,:))
%             hold on
%             plot(s,hd_joint_fit(j,:))
%             hold off
%         end
%         title('joint position')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 4
%         figure(i+9)
%         for j = 1:10
%             subplot(2,5,j)
%             plot(s,dhd_joint(j,:))
%             hold on
%             plot(s,dhd_joint_fit(j,:))
%             hold off
%         end
%         title('joint_velocity')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
% end
end
% LeftStance
for i = 1:length(GL)
    LeftStance_Alpha_joint = reshape(GaitLibrary_joint.LeftStance.HAlpha(i,:,:),10,M+1);
    
    [ hd_joint,dhd_joint,hd_output,dhd_output,hd_joint_fit,dhd_joint_fit,hd_output_fit,dhd_output_fit,alpha_output ] = Alpha_Joint_to_Alpha_output( LeftStance_Alpha_joint,s,1/GaitLibrary_joint.LeftStance.ct(i),M );
    
    GaitLibrary_output.LeftStance.HAlpha(i,:,:) = alpha_output;
    GaitLibrary_output.LeftStance.ct(i) = GaitLibrary_joint.LeftStance.ct(i);
    GaitLibrary_output.Velocity(:,i) = GL{i}.velocity;
    
    hd_output = StanceLegSwitch(hd_output);
    dhd_output = StanceLegSwitch(dhd_output);
    hd_output_fit = StanceLegSwitch(hd_output_fit);
    dhd_output_fit = StanceLegSwitch(dhd_output_fit);
    hd_joint = StanceLegSwitch(hd_joint);
    dhd_joint = StanceLegSwitch(dhd_joint);
    hd_joint_fit = StanceLegSwitch(hd_joint_fit);
    dhd_joint_fit = StanceLegSwitch(dhd_joint_fit);
    
    
switch check_case
    case 1
        figure(i)
        for j = 1:10
            subplot(2,5,j)
            hold on
            plot(s,hd_output(j,:))
            plot(s,hd_output_fit(j,:))
            hold off
        end
        title('output position')
        set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
    case 2
        figure(i+9)
        for j = 1:10
            subplot(2,5,j)
            hold on
            plot(s,dhd_output(j,:))
            plot(s,dhd_output_fit(j,:))
            hold off
        end
        title('output velocity')
        set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
    case 3
        figure(i)
        for j = 1:10
            subplot(2,5,j)
            hold on
            plot(s,hd_joint(j,:))
            plot(s,hd_joint_fit(j,:))
            hold off
        end
        title('joint position')
        set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
    case 4
        figure(i+9)
        for j = 1:10
            subplot(2,5,j)
            hold on
            plot(s,dhd_joint(j,:))
            plot(s,dhd_joint_fit(j,:))
            hold off
        end
        title('joint_velocity')
        set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
end


end

%% Get the torso angle
for i = 1:length(GL)
    %Right Stance
    yaw = GL{i}.solution.states{1}.x(4,:);
    pitch = GL{i}.solution.states{1}.x(5,:);
    roll = GL{i}.solution.states{1}.x(6,:);
    dyaw = GL{i}.solution.states{1}.dx(4,:);
    dpitch = GL{i}.solution.states{1}.dx(5,:);
    droll = GL{i}.solution.states{1}.dx(6,:);
    [yaw_fit,dyaw_fit,alpha_yaw_fit ] = points_to_fit_points( yaw,dyaw,1/GaitLibrary_joint.RightStance.ct(i),M );
    [pitch_fit,dpitch_fit,alpha_pitch_fit ] = points_to_fit_points( pitch,dpitch,1/GaitLibrary_joint.RightStance.ct(i),M );
    [roll_fit,droll_fit,alpha_roll_fit ] = points_to_fit_points( roll,droll,1/GaitLibrary_joint.RightStance.ct(i),M );
    s = linspace(0,1,length(yaw));
    GaitLibrary_output.RightStance.TorsoAngleAlpha(i,:,:) = [alpha_yaw_fit;alpha_pitch_fit;alpha_roll_fit];
    % plot
%     switch check_case
%         case {1,3}
%             figure(100+i)
%             subplot(1,3,1)
%             plot(s,yaw)
%             hold on
%             plot(s,yaw_fit)
%             hold off
%             subplot(1,3,2)
%             plot(s,pitch)
%             hold on
%             plot(s,pitch_fit)
%             hold off
%             subplot(1,3,3)
%             plot(s,roll)
%             hold on
%             plot(s,roll_fit)
%             hold off
%         case{2,4}
%             figure(109+i)
%             subplot(1,3,1)
%             plot(s,dyaw)
%             hold on
%             plot(s,dyaw_fit)
%             hold off
%             subplot(1,3,2)
%             plot(s,dpitch)
%             hold on
%             plot(s,dpitch_fit)
%             hold off
%             subplot(1,3,3)
%             plot(s,droll)
%             hold on
%             plot(s,droll_fit)
%             hold off
%     end
    % Left Stance
    yaw = GL{i}.solution.states{3}.x(4,:);
    pitch = GL{i}.solution.states{3}.x(5,:);
    roll = GL{i}.solution.states{3}.x(6,:);
    dyaw = GL{i}.solution.states{3}.dx(4,:);
    dpitch = GL{i}.solution.states{3}.dx(5,:);
    droll = GL{i}.solution.states{3}.dx(6,:);
    [yaw_fit,dyaw_fit,alpha_yaw_fit ] = points_to_fit_points( yaw,dyaw,1/GaitLibrary_joint.LeftStance.ct(i),M );
    [pitch_fit,dpitch_fit,alpha_pitch_fit ] = points_to_fit_points( pitch,dpitch,1/GaitLibrary_joint.LeftStance.ct(i),M );
    [roll_fit,droll_fit,alpha_roll_fit ] = points_to_fit_points( roll,droll,1/GaitLibrary_joint.LeftStance.ct(i),M );
    
    GaitLibrary_output.RightStance.TorsoAngleAlpha(i,:,:) = [alpha_yaw_fit;alpha_pitch_fit;alpha_roll_fit];
    
    yaw = -yaw;
    dyaw = -dyaw;
    yaw_fit = -yaw_fit;
    dyaw_fit = -dyaw_fit;
    roll = -roll;
    droll = -droll;
    roll_fit = -roll_fit;
    droll_fit = -droll_fit;
    
    s = linspace(0,1,length(yaw));
    % plot
    switch check_case
        case {1,3}
            figure(100+i)
            subplot(1,3,1)
            hold on
            plot(s,yaw)
            plot(s,yaw_fit)
            hold off
            subplot(1,3,2)
            hold on
            plot(s,pitch)
            plot(s,pitch_fit)
            hold off
            subplot(1,3,3)
            hold on
            plot(s,roll)
            plot(s,roll_fit)
            hold off
        case{2,4}
            figure(109+i)
            subplot(1,3,1)
            hold on
            plot(s,dyaw)
            plot(s,dyaw_fit)
            hold off
            subplot(1,3,2)
            hold on
            plot(s,dpitch)
            plot(s,dpitch_fit)
            hold off
            subplot(1,3,3)
            hold on
            plot(s,droll)
            plot(s,droll_fit)
            hold off
    end
end

% save('./Controllers/Yukai/mat/GaitLibrary_output/GaitLibrary_output_v1.mat','GaitLibrary_output')
% save('./Controllers/Yukai/mat/GaitLibrary_output/GaitLibrary_output_Omar_torso_3.mat','GaitLibrary_output')

save('C:\Users\RoahmLab\Documents\GitHub\Cassie_FlatGround_Controller\Controllers\Flatground\mat\GL_PD_BO9_COM_v1F.mat','GaitLibrary_output')