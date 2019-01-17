function [l_foot_p r_foot_p] = get_feet_position(q,dq)
r_foot_p = RightToeJoint(q);
l_foot_p = LeftToeJoint(q);
end