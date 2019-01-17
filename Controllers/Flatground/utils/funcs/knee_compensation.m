function [ u_c ] = knee_compensation(w,qall, Legside)
% This compesation is based on : 1. Cassie is static 2. weight go
% through toe joint
if Legside == 1
    J = J_RightToeJoint(qall);
else
    J = J_LeftToeJoint(qall);
end
q_force = -J'*[0;0;w];

if Legside == 1
    u_c = q_force(19) - q_force(21);
else
    u_c = q_force(11) - q_force(13);
end
end