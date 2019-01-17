% LA0 = 0.0336;
LA0 = 0.1;
LL0 = 0.5;
[qthigh0,qknee0] = Inverse_Kinematics_p(LA0,LL0);
qtoe0 = -0.9970+1/2*qknee0;
height0 = 0.16+LL0;
h0_output = [ 0.0045; 0; qthigh0; qknee0; qtoe0; -0.0045; 0; qthigh0; qknee0; qtoe0];


% Set initial pelvis position and rotation
pelvisPosition = [0; 0; height0];
pelvisRotation = Rotation3d().rotZYX([0; 0; 0]).getValue;

% Define initial motor states
figure;
motorPositions = h0_output;
motorVelocities = zeros(10,1);
close(gcf);

% Define intial pelvis state
pelvisPosition = [0; 0; height0];
pelvisVelocity = [0; 0; 0];
pelvisRotation = Rotation3d.identity.getValue;
pelvisAngularVelocity = [0; 0; 0];







