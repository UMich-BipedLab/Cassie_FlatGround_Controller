M          = 5;
s          = linspace(0,1,30); % phase parameter from 0 to 1
check_case = 1; 
% 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity

GL = load(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_2D_Velocity_FootHeight_Organized_v1.mat'));
GL = GL.PaConfigGait;

for i = 1:length(GL)
    
    if ~isempty(GL{i})
        GL{i}.solution(3).states       = MirrorGaitStates(GL{i}.solution(1).states);
        GL{i}.solution(3).params.atime = MirrorGaitParams(GL{i}.solution(1).params.atime);

        if isfield(GL{i}, 'velocity') == false
            GL{i}.velocity = GL{i}.step_length / (GL{i}.solution.tspan{1}(end) - GL{i}.solution.tspan{1}(1));
        end

        if isfield(GL{i}, 'opt') == false
            GL{i}.opt = GL{i}.solution;
        end
    end
    
end

GaitLibrary_joint.RightStance.HAlpha = zeros(length(GL),10,M+1);
GaitLibrary_joint.LeftStance.HAlpha  = zeros(length(GL),10,M+1);
GaitLibrary_joint.Desired_Velocity   = zeros(2,length(GL));
GaitLibrary_joint.RightStance.ct     = zeros(1,length(GL));
GaitLibrary_joint.LeftStance.ct      = zeros(1,length(GL));

for i = 1:length(GL)
    if ~isempty(GL{i})
    GaitLibrary_joint.RightStance.HAlpha(i,:,:) = reshape(GL{i}.opt(1).params.atime,10,6);
    GaitLibrary_joint.LeftStance.HAlpha(i,:,:)  = reshape(GL{i}.opt(3).params.atime,10,6);
    GaitLibrary_joint.Desired_Velocity(:,i)     = GL{i}.velocity;
    GaitLibrary_joint.RightStance.ct(i)         = 1/GL{i}.opt(1).params.ptime(1);
    GaitLibrary_joint.LeftStance.ct(i)          = 1/GL{i}.opt(3).params.ptime(1);
    end
end

GaitLibrary_output.RightStance.HAlpha           = zeros(length(GL),10,M+1);
GaitLibrary_output.LeftStance.HAlpha            = zeros(length(GL),10,M+1);
GaitLibrary_output.RightStance.TorsoAngleAlpha  = zeros(length(GL),3,M+1);
GaitLibrary_output.LeftStance.TorsoAngleAlpha   = zeros(length(GL),3,M+1);
GaitLibrary_output.RightStance.ct               = zeros(1,length(GL));
GaitLibrary_output.LeftStance.ct                = zeros(1,length(GL));
GaitLibrary_output.Velocity                     = zeros(2,length(GL));

%% RightStance
for i = 1:length(GL)
    
    if ~isempty(GL{i})
    

                RightStance_Alpha_joint = reshape(GaitLibrary_joint.RightStance.HAlpha(i,:,:),10,6);

                [ hd_joint,     dhd_joint,     hd_output,     dhd_output, ...
                  hd_joint_fit, dhd_joint_fit, hd_output_fit, dhd_output_fit, alpha_output ] = ...
                Alpha_Joint_to_Alpha_output( RightStance_Alpha_joint, s, 1/GaitLibrary_joint.RightStance.ct(i), M );

                GaitLibrary_output.RightStance.HAlpha(i,:,:) = alpha_output;
                GaitLibrary_output.RightStance.ct(i)         = GaitLibrary_joint.RightStance.ct(i);
                GaitLibrary_output.Velocity(:,i)             = GL{i}.velocity;


%             % output level check
%             switch check_case
%                 case 1
%                     figure(i)
%                     for j = 1:10
%                         subplot(2,5,j)
%                         plot(s,hd_output(j,:))
%                         hold on
%                         plot(s,hd_output_fit(j,:))
%                         hold off
%                     end
%                     title('output position')
%                     set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%                 case 2
%                     figure(i+9)
%                     for j = 1:10
%                         subplot(2,5,j)
%                         plot(s,dhd_output(j,:))
%                         hold on
%                         plot(s,dhd_output_fit(j,:))
%                         hold off
%                     end
%                     title('output velocity')
%                     set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%                 case 3
%                     figure(i)
%                     for j = 1:10
%                         subplot(2,5,j)
%                         plot(s,hd_joint(j,:))
%                         hold on
%                         plot(s,hd_joint_fit(j,:))
%                         hold off
%                     end
%                     title('joint position')
%                     set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%                 case 4
%                     figure(i+9)
%                     for j = 1:10
%                         subplot(2,5,j)
%                         plot(s,dhd_joint(j,:))
%                         hold on
%                         plot(s,dhd_joint_fit(j,:))
%                         hold off
%                     end
%                     title('joint_velocity')
%                     set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%             end


     end
end


%% LeftStance
for i = 1:length(GL)
    
  if ~isempty(GL{i})
    
    LeftStance_Alpha_joint = reshape(GaitLibrary_joint.LeftStance.HAlpha(i,:,:),10,6);
    
    [ hd_joint,      dhd_joint, ...
      hd_output,     dhd_output, ...
      hd_joint_fit,  dhd_joint_fit, ...
      hd_output_fit, dhd_output_fit, alpha_output ] = ...
      Alpha_Joint_to_Alpha_output( LeftStance_Alpha_joint, s, 1/GaitLibrary_joint.LeftStance.ct(i), M );
    
    GaitLibrary_output.LeftStance.HAlpha(i,:,:) = alpha_output;
    GaitLibrary_output.LeftStance.ct(i)         = GaitLibrary_joint.LeftStance.ct(i);
    GaitLibrary_output.Velocity(:,i)            = GL{i}.velocity;
    
    hd_output      = StanceLegSwitch(hd_output);
    dhd_output     = StanceLegSwitch(dhd_output);
    hd_output_fit  = StanceLegSwitch(hd_output_fit);
    dhd_output_fit = StanceLegSwitch(dhd_output_fit);
    hd_joint       = StanceLegSwitch(hd_joint);
    dhd_joint      = StanceLegSwitch(dhd_joint);
    hd_joint_fit   = StanceLegSwitch(hd_joint_fit);
    dhd_joint_fit  = StanceLegSwitch(dhd_joint_fit);

  end  
% switch check_case
%     case 1
%         figure(i)
%         for j = 1:10
%             subplot(2,5,j)
%             hold on
%             plot(s,hd_output(j,:))
%             plot(s,hd_output_fit(j,:))
%             hold off
%         end
%         title('output position')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 2
%         figure(i+9)
%         for j = 1:10
%             subplot(2,5,j)
%             hold on
%             plot(s,dhd_output(j,:))
%             plot(s,dhd_output_fit(j,:))
%             hold off
%         end
%         title('output velocity')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 3
%         figure(i)
%         for j = 1:10
%             subplot(2,5,j)
%             hold on
%             plot(s,hd_joint(j,:))
%             plot(s,hd_joint_fit(j,:))
%             hold off
%         end
%         title('joint position')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
%     case 4
%         figure(i+9)
%         for j = 1:10
%             subplot(2,5,j)
%             hold on
%             plot(s,dhd_joint(j,:))
%             plot(s,dhd_joint_fit(j,:))
%             hold off
%         end
%         title('joint_velocity')
%         set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0.04, 1, 0.96])
% end

end


%% Get the torso angle
for i = 1:length(GL)
    
  if ~isempty(GL{i})
    
    %Right Stance
    yaw = GL{i}.opt(1).states.x(4,:);
    pitch = GL{i}.opt(1).states.x(5,:);
    roll = GL{i}.opt(1).states.x(6,:);
    dyaw = GL{i}.opt(1).states.dx(4,:);
    dpitch = GL{i}.opt(1).states.dx(5,:);
    droll = GL{i}.opt(1).states.dx(6,:);
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
    yaw = GL{i}.opt(3).states.x(4,:);
    pitch = GL{i}.opt(3).states.x(5,:);
    roll = GL{i}.opt(3).states.x(6,:);
    dyaw = GL{i}.opt(3).states.dx(4,:);
    dpitch = GL{i}.opt(3).states.dx(5,:);
    droll = GL{i}.opt(3).states.dx(6,:);
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
%     switch check_case
%         case {1,3}
%             figure(100+i)
%             subplot(1,3,1)
%             hold on
%             plot(s,yaw)
%             plot(s,yaw_fit)
%             hold off
%             subplot(1,3,2)
%             hold on
%             plot(s,pitch)
%             plot(s,pitch_fit)
%             hold off
%             subplot(1,3,3)
%             hold on
%             plot(s,roll)
%             plot(s,roll_fit)
%             hold off
%         case{2,4}
%             figure(109+i)
%             subplot(1,3,1)
%             hold on
%             plot(s,dyaw)
%             plot(s,dyaw_fit)
%             hold off
%             subplot(1,3,2)
%             hold on
%             plot(s,dpitch)
%             plot(s,dpitch_fit)
%             hold off
%             subplot(1,3,3)
%             hold on
%             plot(s,droll)
%             plot(s,droll_fit)
%             hold off
%     end

  end

end

% save(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_2D_Velocity_FootHeight_v1.mat'), 'GaitLibrary_output');
save('GaitLibrary_2D_Velocity_FootHeight_v1.mat', 'GaitLibrary_output');