InterpSpX = zeros(21,31,21); % dx, dy, s
InterpSpY = zeros(21,31,21); % dx, dy, s

S_interp = linspace(0,1,21);

j = 1;
k = 1;

RS_dx =  GL_Data.LIPsol_curEx{j,k}.gait(1).states.dx(1,:); % 1x21
LS_dx =  GL_Data.LIPsol_curEx{j,k}.gait(3).states.dx(1,:); % 1x21

RS_dy =  GL_Data.LIPsol_curEx{j,k}.gait(1).states.dx(2,:); % 1x21
LS_dy =  GL_Data.LIPsol_curEx{j,k}.gait(3).states.dx(2,:); % 1x21