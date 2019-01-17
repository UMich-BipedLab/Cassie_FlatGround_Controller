function [l_foot_v r_foot_v] = get_feet_velocity(q,dq)
JR = J_RightToeJoint(q);
JL = J_LeftToeJoint(q);
r_foot_v = JR * dq;
l_foot_v = JL * dq;
end