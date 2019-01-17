sample_time = 1/2000;


lpf_damping = sqrt(2)/2; % Butterworth filter damping

fcut_velocity_joint = 100*(2*pi); % Cutoff frequency for velocities
B1_lpf_velocity_joint = -2*exp(-lpf_damping*fcut_velocity_joint*sample_time)*cos(fcut_velocity_joint*sample_time*sqrt(1-lpf_damping^2));
B2_lpf_velocity_joint = exp(-2*lpf_damping*fcut_velocity_joint*sample_time);
A_lpf_velocity_joint = 1 + B1_lpf_velocity_joint + B2_lpf_velocity_joint;

fcut_velocity_IMU = 100*(2*pi); % Cutoff frequency for velocities
B1_lpf_velocity_IMU = -2*exp(-lpf_damping*fcut_velocity_IMU*sample_time)*cos(fcut_velocity_IMU*sample_time*sqrt(1-lpf_damping^2));
B2_lpf_velocity_IMU = exp(-2*lpf_damping*fcut_velocity_IMU*sample_time);
A_lpf_velocity_IMU = 1 + B1_lpf_velocity_IMU + B2_lpf_velocity_IMU;
