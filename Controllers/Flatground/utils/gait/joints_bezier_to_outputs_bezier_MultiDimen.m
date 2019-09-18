M          = 5;
s          = linspace(0,1,30); % phase parameter from 0 to 1
check_case = 1; 
% 1 is output position, 2 is output velocity, 3 is joint position, 4 is joint velocity

GL = load(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_LIP_FROST_SOL_v1.mat'));
LIPsol_curEx = GL.GL_FROST_SOL;

% %A and B: cell arrays of matrices. Must have the same size
% %Matrices in corresponding cells in A and B must have the same number of rows
% angle = (0:3:360)';
% newb = cellfun(@(a,b) interp1(a, b(:, 2:end)), angle), A, B, 'UniformOutput', false);

NoAx = 2;
NoIx = 50;

% Dimension of the gait library
xo_range  = GL.xo_range;
dxo_range = GL.dxo_range;

GaitLibrary_output = [];
GaitLibrary_output.StrideTime = cell(NoIx*ones(1,NoAx));
GaitLibrary_output.Velocity = cell(NoIx*ones(1,NoAx));
GaitLibrary_output.RightStance = cell(NoIx*ones(1,NoAx));
GaitLibrary_output.LeftStance  = cell(NoIx*ones(1,NoAx));


GaitLibrary_joint = [];
GaitLibrary_joint.StrideTime = cell(NoIx*ones(1,NoAx));
GaitLibrary_joint.Velocity = cell(NoIx*ones(1,NoAx));
GaitLibrary_joint.RightStance = cell(NoIx*ones(1,NoAx));
GaitLibrary_joint.LeftStance  = cell(NoIx*ones(1,NoAx));

% Prepare the data structure
for m = 1:NoIx
    
    for n = 1:NoIx
        
        if ~isempty(LIPsol_curEx{m,n})
            % make sure the right stance phase (3) is symmetrical to the left
            % stance phase (1)
            LIPsol_curEx{m,n}.gait(3).states       = MirrorGaitStates(LIPsol_curEx{m,n}.gait(1).states);
            LIPsol_curEx{m,n}.gait(3).params.atime = MirrorGaitParams(LIPsol_curEx{m,n}.gait(1).params.atime); % atime 60x1
            % compute the average speed if this does not exist 
            LIPsol_curEx{m,n}.velocity = LIPsol_curEx{m,n}.gait(3).states.dx(1,:);
            
            % Joint Trajectories
            GaitLibrary_joint.RightStance{m,n} = reshape(LIPsol_curEx{m,n}.gait(1).params.atime,10,6);
            GaitLibrary_joint.LeftStance{m,n}  = reshape(LIPsol_curEx{m,n}.gait(3).params.atime,10,6);
            GaitLibrary_joint.Velocity{m,n}    = LIPsol_curEx{m,n}.velocity;
            GaitLibrary_joint.StrideTime{m,n}  = LIPsol_curEx{m,n}.gait(1).params.ptime(1);
            
            % Virtual Constraints
            % Left stance phase
            [ ~, ~, ...
              ~, ~, ...
              ~, ~, ...
              ~, ~, alpha_output_left ] = ...
              Alpha_Joint_to_Alpha_output( GaitLibrary_joint.LeftStance{m,n}, s, GaitLibrary_joint.StrideTime{m,n}, M );

            GaitLibrary_output.LeftStance{m,n} = alpha_output_left;
            
            % Right stance phase
            [ ~, ~, ...
              ~, ~, ...
              ~, ~, ...
              ~, ~, alpha_output_right ] = ...
            Alpha_Joint_to_Alpha_output( GaitLibrary_joint.RightStance{m,n}, s, GaitLibrary_joint.StrideTime{m,n}, M );

            GaitLibrary_output.RightStance{m,n} = alpha_output_right;
            GaitLibrary_output.StrideTime{m,n}  = GaitLibrary_joint.StrideTime{m,n};
            GaitLibrary_output.Velocity{m,n}    = GaitLibrary_joint.Velocity{m,n};
            
            
        else % if gait not exist, use NaN
            
            GaitLibrary_output.LeftStance{m,n}  = NaN(10,6);            
            GaitLibrary_output.RightStance{m,n} = NaN(10,6);
            GaitLibrary_output.StrideTime{m,n}  = NaN(1,1);
            GaitLibrary_output.Velocity{m,n}    = NaN(1,21);

        end
    end
    
end


save(fullfile('Controllers', 'Flatground', 'mat', 'GaitLibrary_LIP_v1.mat'), 'GaitLibrary_output');