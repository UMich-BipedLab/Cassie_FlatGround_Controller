function dqs = getSpringDeflectionRates(knee_motor,knee_joint,ankle_joint)
dqs = zeros(2,1);
dqs(1) = knee_joint;
dqs(2) = knee_motor + knee_joint + ankle_joint;
end

