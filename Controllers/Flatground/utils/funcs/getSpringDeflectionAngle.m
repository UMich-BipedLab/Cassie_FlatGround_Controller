function qs = getSpringDeflectionAngle(knee_motor,knee_joint,ankle_joint)
qs = zeros(2,1);
qs(1) = knee_joint;
qs(2) = knee_motor + knee_joint + ankle_joint - deg2rad(13);
end

