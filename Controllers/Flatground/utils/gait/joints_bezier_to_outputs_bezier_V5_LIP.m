
% The order of the Bezier Polynomial
M = 5;

s = linspace(0,1,30);
check_case = 1; % 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity
GL_Data = load('GaitLibrary_LIP_FROST_SOL_v8.mat');
GL = GL_Data.GL_2D;
GaitLibrary_2D = cell(size(GL));

sGL = size(GL);
GaitLibrary_joint.RightStance.HAlpha = zeros(sGL(1),sGL(2),10,M+1);
GaitLibrary_joint.LeftStance.HAlpha = zeros(sGL(1),sGL(2),10,M+1);
GaitLibrary_joint.Desired_Velocity = zeros(2,sGL(1),sGL(2));
GaitLibrary_joint.RightStance.ct = zeros(sGL(1),sGL(2));
GaitLibrary_joint.LeftStance.ct = zeros(sGL(1),sGL(2));


for i = 1:sGL(1)
   for j = 1:sGL(2)
        GaitLibrary_joint.RightStance.HAlpha(i,j,:,:) =  reshape(GL{i,j}.gait(1).params.atime,10,M+1);
        GaitLibrary_joint.LeftStance.HAlpha(i,j,:,:)  =  reshape(GL{i,j}.gait(3).params.atime,10,M+1);
        GaitLibrary_joint.Desired_Velocity(:,i,j) = GL{i,j}.velocity;

        GaitLibrary_joint.RightStance.ct(i,j) = 1/0.4;
        GaitLibrary_joint.LeftStance.ct(i,j) = 1/0.4;
   end
end


GaitLibrary_output.RightStance.HAlpha = zeros(sGL(1),sGL(2),10,M+1);
GaitLibrary_output.LeftStance.HAlpha = zeros(sGL(1),sGL(2),10,M+1);
GaitLibrary_output.RightStance.TorsoAngleAlpha = zeros(sGL(1),sGL(2),3,M+1);
GaitLibrary_output.LeftStance.TorsoAngleAlpha = zeros(sGL(1),sGL(2),3,M+1);
GaitLibrary_output.RightStance.ct = zeros(sGL(1),sGL(2));
GaitLibrary_output.LeftStance.ct = zeros(sGL(1),sGL(2));
GaitLibrary_output.Velocity = zeros(2,sGL(1),sGL(2));

GaitLibrary_output.LT_2D_Right = GL_Data.LT_2D_Right;
GaitLibrary_output.LT_2D_Left  = GL_Data.LT_2D_Left;
GaitLibrary_output.dxN = GL_Data.dxN;
GaitLibrary_output.dyN = GL_Data.dyN;

GaitLibrary_output.dxo_range = GL_Data.dxo_range;
GaitLibrary_output.dyo_range = GL_Data.dyo_range;

GaitLibrary_output.ct = GaitLibrary_joint.LeftStance.ct;

% Right
for i = 1:sGL(1)
    for j = 1:sGL(2)
        
        if j<=(sGL(2)+1)/2
            
            RightStance_Alpha_joint = reshape(GaitLibrary_joint.RightStance.HAlpha(i,j,:,:),10,M+1);

            [ ~,~,~,~,~,~,~,~,alpha_output ] = Alpha_Joint_to_Alpha_output( RightStance_Alpha_joint,s,1/GaitLibrary_joint.RightStance.ct(i),M );

            GaitLibrary_output.RightStance.HAlpha(i,j,:,:) = alpha_output;
            GaitLibrary_output.RightStance.ct(i,j) = GaitLibrary_joint.RightStance.ct(i,j);
%             GaitLibrary_output.Velocity(1,i,j) = GL{i,j}.velocity;
%             GaitLibrary_output.Velocity(2,i,j) = GL{i,j}.SidesSpeed;
            LeftStance_Alpha_joint = reshape(GaitLibrary_joint.LeftStance.HAlpha(i,j,:,:),10,M+1);
            [ hd_joint,dhd_joint,hd_output,dhd_output,hd_joint_fit,dhd_joint_fit,hd_output_fit,dhd_output_fit,alpha_output ] = Alpha_Joint_to_Alpha_output( LeftStance_Alpha_joint,s,1/GaitLibrary_joint.LeftStance.ct(i),M );

            GaitLibrary_output.LeftStance.HAlpha(i,j,:,:)  = alpha_output;
            GaitLibrary_output.LeftStance.ct(i,j)          = GaitLibrary_joint.LeftStance.ct(i,j);
            GaitLibrary_output.Velocity(1,i,j)             = GL{i,j}.velocity;
            GaitLibrary_output.Velocity(2,i,j)             = GL{i,j}.SidesSpeed;
        else
            GaitLibrary_output.RightStance.HAlpha(i,j,:,:) = MirrorGaitParams(GaitLibrary_output.LeftStance.HAlpha(i,sGL(2)+1-j,:,:));
            GaitLibrary_output.RightStance.ct(i,j)         = GaitLibrary_joint.RightStance.ct(i,j);
%             GaitLibrary_output.Velocity(1,i,j) = GL{i,j}.velocity;
%             GaitLibrary_output.Velocity(2,i,j) = GL{i,j}.SidesSpeed;
            GaitLibrary_output.LeftStance.HAlpha(i,j,:,:)  = MirrorGaitParams(GaitLibrary_output.RightStance.HAlpha(i,sGL(2)+1-j,:,:));
            GaitLibrary_output.LeftStance.ct(i,j)          = GaitLibrary_joint.LeftStance.ct(i,j);
            GaitLibrary_output.Velocity(1,i,j)             = GL{i,j}.velocity;
            GaitLibrary_output.Velocity(2,i,j)             = GL{i,j}.SidesSpeed;           
            
        end    
    end
end

save('C:\Users\RoahmLab\Documents\GitHub\Cassie_FlatGround_Controller\Controllers\Flatground\mat\GaitLibrary_LIP_v10.mat','GaitLibrary_output')