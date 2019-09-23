
% The order of the Bezier Polynomial
% M = 5;
M = 5;


s = linspace(0,1,30);
check_case = 1; % 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity

% GL = load('GaitLibrary_Omar_3.mat');
% GL = load('GaitLibrary_v1.mat');
GL_Data = load('GaitLibrary_LIP_FROST_SOL_v4.mat');

GaitLibrary_2D = cell(length(GL_Data.GL_2D),1);

for h = 1:length(GL_Data.GL_2D)


    GL = GL_Data.GL_2D{h};
    GaitLibrary_joint.RightStance.HAlpha = zeros(length(GL),10,M+1);
    GaitLibrary_joint.LeftStance.HAlpha = zeros(length(GL),10,M+1);
    GaitLibrary_joint.Desired_Velocity = zeros(2,length(GL));
    GaitLibrary_joint.RightStance.ct = zeros(1,length(GL));
    GaitLibrary_joint.LeftStance.ct = zeros(1,length(GL));

    for i = 1:length(GL)


        GaitLibrary_joint.RightStance.HAlpha(i,:,:) =  reshape(GL{i}.gait(1).params.atime,10,M+1);
        GaitLibrary_joint.LeftStance.HAlpha(i,:,:) =  reshape(GL{i}.gait(3).params.atime,10,M+1);
        GaitLibrary_joint.Desired_Velocity(:,i) = GL{i}.velocity;

        GaitLibrary_joint.RightStance.ct(i) = 1/0.4;
        GaitLibrary_joint.LeftStance.ct(i) = 1/0.4;
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
        GaitLibrary_output.Velocity(1,i) = GL{i}.velocity;
        GaitLibrary_output.Velocity(2,i) = GL{i}.SidesSpeed;

    end
    % LeftStance
    for i = 1:length(GL)
        LeftStance_Alpha_joint = reshape(GaitLibrary_joint.LeftStance.HAlpha(i,:,:),10,M+1);

        [ hd_joint,dhd_joint,hd_output,dhd_output,hd_joint_fit,dhd_joint_fit,hd_output_fit,dhd_output_fit,alpha_output ] = Alpha_Joint_to_Alpha_output( LeftStance_Alpha_joint,s,1/GaitLibrary_joint.LeftStance.ct(i),M );

        GaitLibrary_output.LeftStance.HAlpha(i,:,:) = alpha_output;
        GaitLibrary_output.LeftStance.ct(i) = GaitLibrary_joint.LeftStance.ct(i);
        GaitLibrary_output.Velocity(1,i) = GL{i}.velocity;
        GaitLibrary_output.Velocity(2,i) = GL{i}.SidesSpeed;

    end

    
    GaitLibrary_2D{h} = GaitLibrary_output;
end

% create strings
GaitLibrary_2D_struct = [];
for i = 1:length(GaitLibrary_2D)
    
    fdname = ['f_',num2str(i)];    
    GaitLibrary_2D_struct.(fdname) = GaitLibrary_2D{i};

end

save('C:\Users\RoahmLab\Documents\GitHub\Cassie_FlatGround_Controller\Controllers\Flatground\mat\GaitLibrary_LIP_v4.mat','GaitLibrary_2D_struct')