M          = 5;
s          = linspace(0,1,30); % phase parameter from 0 to 1
check_case = 1; 
% 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity

GL = load(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_LIP_FROST_SOL_v2.mat'));
LIPsol_curEx = GL.LIPsol_curEx;

% %A and B: cell arrays of matrices. Must have the same size
% %Matrices in corresponding cells in A and B must have the same number of rows
% angle = (0:3:360)';
% newb = cellfun(@(a,b) interp1(a, b(:, 2:end)), angle), A, B, 'UniformOutput', false);

NoAx = 2;
NoIx = GL.dxN;
NoIy = GL.dyN;

% Dimension of the gait library
dxo_range  = GL.dxo_range;
dyo_range  = GL.dyo_range;

GaitLibrary_joint = [];
GaitLibrary_joint.StrideTime  = cell(NoIx,NoIy);
GaitLibrary_joint.Velocity    = cell(NoIx,NoIy);
GaitLibrary_joint.RightStance = cell(NoIx,NoIy);
GaitLibrary_joint.LeftStance  = cell(NoIx,NoIy);

GaitLibrary_output = [];
GaitLibrary_output.StrideTime  = zeros(NoIx,NoIy);
GaitLibrary_output.Velocity    = zeros(NoIx,NoIy,2);
GaitLibrary_output.RightStance = zeros(NoIx,NoIy,10*6);
GaitLibrary_output.LeftStance  = zeros(NoIx,NoIy,10*6);

% Prepare the data structure
for m = 1:NoIx
    
    for n = 1:NoIy
        
        if ~isempty(LIPsol_curEx{m,n})
            % make sure the right stance phase (3) is symmetrical to the left
            % stance phase (1)
            LIPsol_curEx{m,n}.gait(3).states       = MirrorGaitStates(LIPsol_curEx{m,n}.gait(1).states);
            LIPsol_curEx{m,n}.gait(3).params.atime = MirrorGaitParams(LIPsol_curEx{m,n}.gait(1).params.atime); % atime 60x1
            % compute the average speed if this does not exist 
            LIPsol_curEx{m,n}.velocity = LIPsol_curEx{m,n}.gait(3).states.dx(1:2,:);
            
            % Joint Trajectories
            GaitLibrary_joint.RightStance{m,n} = reshape(LIPsol_curEx{m,n}.gait(1).params.atime,10,6);
            GaitLibrary_joint.LeftStance{m,n}  = reshape(LIPsol_curEx{m,n}.gait(3).params.atime,10,6);
            GaitLibrary_joint.Velocity{m,n}    = mean(transpose(LIPsol_curEx{m,n}.velocity)); %2x1
            GaitLibrary_joint.StrideTime{m,n}  = LIPsol_curEx{m,n}.gait(1).params.ptime(1);
            
            % Virtual Constraints
            % Left stance phase
            [ ~, ~, ...
              ~, ~, ...
              ~, ~, ...
              ~, ~, alpha_output_left ] = ...
              Alpha_Joint_to_Alpha_output( GaitLibrary_joint.LeftStance{m,n}, s, GaitLibrary_joint.StrideTime{m,n}, M );

            GaitLibrary_output.LeftStance(m,n,:) = reshape(alpha_output_left,10*6,1);
            
            % Right stance phase
            [ ~, ~, ...
              ~, ~, ...
              ~, ~, ...
              ~, ~, alpha_output_right ] = ...
            Alpha_Joint_to_Alpha_output( GaitLibrary_joint.RightStance{m,n}, s, GaitLibrary_joint.StrideTime{m,n}, M );

            GaitLibrary_output.RightStance(m,n,:) = reshape(alpha_output_right,10*6,1);
            GaitLibrary_output.StrideTime(m,n)    = GaitLibrary_joint.StrideTime{m,n};
            GaitLibrary_output.Velocity(m,n,:)    = GaitLibrary_joint.Velocity{m,n};
            
            
        else % if gait not exist, use NaN
            
            GaitLibrary_output.LeftStance(m,n,:)  = 1e6*ones(10*6,1);            
            GaitLibrary_output.RightStance(m,n,:) = 1e6*ones(10*6,1);
            GaitLibrary_output.StrideTime(m,n)    = 1e6*ones(1);
            GaitLibrary_output.Velocity(m,n,:)    = 1e6*ones(2,1);

        end
    end
    
end


save(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_LIP_v2.mat'), 'GaitLibrary_output');