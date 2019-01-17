function s = CassieDescriptor
  %CASSIEDESCRIPTOR Rigid body model descriptor for Cassie
  %
  % Notes:
  %   - Units are metric (m, kg, s)
  %   - Inertia matrices are taken as 6d vectors [xx yy zz xy xz yz]
  %   - Populating 3x3 inertia tensor from inertia vector indices
  %       [1 4 5]
  %       [. 2 6]
  %       [. . 3]
  
  % Copyright 2018 Agility Robotics
  
  % Define helper functions
  Rx = @(t) [1 0 0; 0 cosd(t) -sind(t); 0 sind(t) cosd(t)]; % degrees
  Ry = @(t) [cosd(t) 0 sind(t); 0 1 0; -sind(t) 0 cosd(t)]; % degrees
  Rz = @(t) [cosd(t) -sind(t) 0; sind(t) cosd(t) 0; 0 0 1]; % degrees
  Rxyz = @(v) Rx(v(1))*Ry(v(2))*Rz(v(3));
  bodyIndex = @(s, name) find(arrayfun(@(s)isequal(s.name, name), s));
  
  % Initialize body structure format
  s = struct('name', [] ... % string
    ,'p',  [] ... % parent index
    ,'r',  [] ... % position in parent's frame
    ,'R',  [] ... % rotation in parent's frame
    ,'m',  [] ... % total mass of body
    ,'c',  [] ... % center of mass in body frame
    ,'Ic', [] ... % inertia vector @ CoM, aligned with body frame
    ,'Sw', [] ... % angular joint motion subspace
    ,'Sv', [] ... % linear joint motion subspace
    );
  
  % ROOT =======================================================================
  s(1).name = 'cassie-pelvis';
  s(end).p  = 0; % base
  s(end).r  = [0 0 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 10.33;
  s(end).c  = [50.66 0.346 28.41] / 1000;
  s(end).Ic = [85821 49222 86260 12.76 -160.22 -414] / 1000000;
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  % LEFT LEG ===================================================================
  s(end+1).name = 'left-hip-roll';
  s(end).p  = bodyIndex(s, 'cassie-pelvis');
  s(end).r = [0.021 0.135 0];
  s(end).R = Rxyz([0 90 0]);
  s(end).m  = 1.82;
  s(end).c  = [-0.01793 0.0001 -0.04428];
  s(end).Ic = [3.4310e-03  3.7930e-03 2.1350e-03 ...
    -6.6500e-07 -8.4000e-04 3.9900e-06];
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-hip-yaw';
  s(end).p  = bodyIndex(s, 'left-hip-roll');
  s(end).r  = [0 0 -0.070];
  s(end).R  = Rxyz([0 -90 0]);
  s(end).m  = 1.171;
  s(end).c  = [0 -0.00001 -0.034277];
  s(end).Ic = [2.4430e-03 2.8030e-03  8.4200e-04 ...
    -4.0000e-08 2.4620e-07 -2.7100e-08];
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-hip-pitch';
  s(end).p  = bodyIndex(s, 'left-hip-yaw');
  s(end).r  = [0 0 -0.090];
  s(end).R  = Rxyz([90 0 -90]);
  s(end).m  = 5.52;
  s(end).c  = [59.46 0.05 -35.81] / 1000;
  s(end).Ic = [10898 29714 30257 -266.9 -57.21 9.17] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-achilles-rod';
  s(end).p  = bodyIndex(s, 'left-hip-pitch');
  s(end).r  = [0 0 45] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1567;
  s(end).c  = [247.19 0 0] / 1000;
  s(end).Ic = [3.754 4487 4488 -0.0374 -0.0161 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-knee';
  s(end).p  = bodyIndex(s, 'left-hip-pitch');
  s(end).r  = [120 0 4.5] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.7578;
  s(end).c  = [23.0 32.07 -2.181] / 1000;
  s(end).Ic = [1376 1033.5 2163.7 -397.44 -40.85 -53.74] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-knee-spring';
  s(end).p  = bodyIndex(s, 'left-knee');
  s(end).r  = [60.68 82.41 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.186;
  s(end).c  = [83.6 3.4 0] / 1000;
  s(end).Ic = [52.15 412.05 366.90 6.87 0 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-shin';
  s(end).p  = bodyIndex(s, 'left-knee');
  s(end).r  = [60.68 47.41 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.577;
  s(end).c  = [183.38 1.169 0.2123] / 1000;
  s(end).Ic = [359.39 14728 14707 -209.81 22.66 -0.12] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-tarsus';
  s(end).p  = bodyIndex(s, 'left-shin');
  s(end).r  = [434.76 20 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.782;
  s(end).c  = [110.46 -30.58 -1.31] / 1000;
  s(end).Ic = [392.38 13595 13674 236.51 -49.87 -4.82] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-heel-spring';
  s(end).p  = bodyIndex(s, 'left-tarsus');
  s(end).r  = [-12.69 -30.59 0.92] / 1000;
  s(end).R  = Rxyz([4.47 0.315 155.8]);
  s(end).m  = 0.126;
  s(end).c  = [81 2.2 0] / 1000;
  s(end).Ic = [29.59 222.31 200.70 7.15 -0.6 0.1] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-foot-crank';
  s(end).p  = bodyIndex(s, 'left-tarsus');
  s(end).r  = [58 -34 22.75] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1261;
  s(end).c  = [4.93 0.02 -2.15] / 1000;
  s(end).Ic = [26.941 49.621 63.362 -0.0021 -3.9623 -0.0109] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-plantar-rod';
  s(end).p  = bodyIndex(s, 'left-foot-crank');
  s(end).r  = [55 0 -7.91] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1186;
  s(end).c  = [177.92 0 0] / 1000;
  s(end).Ic = [2.779 1774 1775 -0.0234 -0.0081 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-foot';
  s(end).p  = bodyIndex(s, 'left-tarsus');
  s(end).r  = [408 -40 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1498;
  s(end).c  = [4.74 27.48 -0.14] / 1000;
  s(end).Ic = [173.88 167.93 332.61 118.14 1.36 -0.40] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  % Fixed frames ---------------------------------------------------------------
  s(end+1).name = 'left-achilles-rod-end';
  s(end).p = bodyIndex(s, 'left-achilles-rod');
  s(end).r = [501.2 0 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-heel-spring-end';
  s(end).p = bodyIndex(s, 'left-heel-spring');
  s(end).r = [118.77 -10 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-plantar-rod-end';
  s(end).p = bodyIndex(s, 'left-plantar-rod');
  s(end).r = [305.12 0 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-foot-pin';
  s(end).p = bodyIndex(s, 'left-foot');
  s(end).r = [55 0 7.76] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'left-foot-mid';
  s(end).p = bodyIndex(s, 'left-foot');
  s(end).r = [17.62 52.19 0] / 1000;
  s(end).R = Rxyz([-90 -140 0]);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  % RIGHT LEG ==================================================================
  s(end+1).name = 'right-hip-roll';
  s(end).p  = bodyIndex(s, 'cassie-pelvis');
  s(end).r = [0.021 -0.135 0];
  s(end).R = Rxyz([0 90 0]);
  s(end).m  = 1.82;
  s(end).c  = [-0.01793 0.0001 -0.04428];
  s(end).Ic = [3.4310e-03  3.7930e-03  2.1350e-03 ...
    6.6500e-07 -8.4000e-04 -3.9900e-06];
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-hip-yaw';
  s(end).p  = bodyIndex(s, 'right-hip-roll');
  s(end).r  = [0 0 -0.070];
  s(end).R  = Rxyz([0 -90 0]);
  s(end).m  = 1.171;
  s(end).c  = [0 0.00001 -0.034277];
  s(end).Ic = [2.4430e-03  2.8030e-03  8.4200e-04 ...
    4.0000e-08  2.4620e-07  2.7100e-08];
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-hip-pitch';
  s(end).p  = bodyIndex(s, 'right-hip-yaw');
  s(end).r  = [0 0 -0.090];
  s(end).R  = Rxyz([90 0 -90]);
  s(end).m  = 5.52;
  s(end).c  = [59.46 0.05 35.81] / 1000;
  s(end).Ic = [10898 29714 30257 -266.9 57.21 -9.17] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-achilles-rod';
  s(end).p  = bodyIndex(s, 'right-hip-pitch');
  s(end).r  = [0 0 -45] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1567;
  s(end).c  = [247.19 0 0] / 1000;
  s(end).Ic = [3.754 4487 4488 -0.0374 0.0161 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-knee';
  s(end).p  = bodyIndex(s, 'right-hip-pitch');
  s(end).r  = [120 0 -4.5] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.7578;
  s(end).c  = [23.0 32.07 2.181] / 1000;
  s(end).Ic = [1376 1033.5 2163.7 -397.44 40.85 53.74] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-knee-spring';
  s(end).p  = bodyIndex(s, 'right-knee');
  s(end).r  = [60.68 82.41 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.186;
  s(end).c  = [83.6 3.4 0] / 1000;
  s(end).Ic = [52.15 412.05 366.90 6.87 0 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-shin';
  s(end).p  = bodyIndex(s, 'right-knee');
  s(end).r  = [60.68 47.41 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.577;
  s(end).c  = [183.38 1.169 -0.2123] / 1000;
  s(end).Ic = [359.39 14728 14707 -209.81 -22.66 0.12] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-tarsus';
  s(end).p  = bodyIndex(s, 'right-shin');
  s(end).r  = [434.76 20 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.782;
  s(end).c  = [110.46 -30.58 1.31] / 1000;
  s(end).Ic = [392.38 13595 13674 236.51 49.87 4.82] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-heel-spring';
  s(end).p  = bodyIndex(s, 'right-tarsus');
  s(end).r  = [-12.69 -30.59 -0.92] / 1000;
  s(end).R  = Rxyz([-4.47 -0.315 155.8]);
  s(end).m  = 0.126;
  s(end).c  = [81 2.2 0] / 1000;
  s(end).Ic = [29.59 222.31 200.70 7.15 0.6 -0.1] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-foot-crank';
  s(end).p  = bodyIndex(s, 'right-tarsus');
  s(end).r  = [58 -34 -22.75] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1261;
  s(end).c  = [4.93 0.02 2.15] / 1000;
  s(end).Ic = [26.941 49.621 63.362 -0.0021 3.9623 0.0109] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-plantar-rod';
  s(end).p  = bodyIndex(s, 'right-foot-crank');
  s(end).r  = [55 0 7.91] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1186;
  s(end).c  = [177.92 0 0] / 1000;
  s(end).Ic = [2.779 1774 1775 -0.0234 0.0081 0] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-foot';
  s(end).p  = bodyIndex(s, 'right-tarsus');
  s(end).r  = [408 -40 0] / 1000;
  s(end).R  = eye(3);
  s(end).m  = 0.1498;
  s(end).c  = [4.74 27.48 0.14] / 1000;
  s(end).Ic = [173.88 167.93 332.61 118.14 -1.36 0.40] / 1000000;
  s(end).Sw = [0 0 1];
  s(end).Sv = [0 0 0];
  
  % Fixed frames ---------------------------------------------------------------
  s(end+1).name = 'right-achilles-rod-end';
  s(end).p = bodyIndex(s, 'right-achilles-rod');
  s(end).r = [501.2 0 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-heel-spring-end';
  s(end).p = bodyIndex(s, 'right-heel-spring');
  s(end).r = [118.77 -10 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-plantar-rod-end';
  s(end).p = bodyIndex(s, 'right-plantar-rod');
  s(end).r = [305.12 0 0] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-foot-pin';
  s(end).p = bodyIndex(s, 'right-foot');
  s(end).r = [55 0 7.76] / 1000;
  s(end).R = eye(3);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  s(end+1).name = 'right-foot-mid';
  s(end).p = bodyIndex(s, 'right-foot');
  s(end).r = [17.62 52.19 0] / 1000;
  s(end).R = Rxyz([-90 -140 0]);
  s(end).m = 0;
  s(end).c = [0 0 0];
  s(end).Ic = [0 0 0 0 0 0];
  s(end).Sw = [0 0 0];
  s(end).Sv = [0 0 0];
  
  %   % JOINTS ===================================================================
  %   hipRoll.G = 25; % :1
  %   hipRoll.I = 61; % kg.mm^2
  %
  %   hipYaw.G = 25; % :1
  %   hipYaw.I = 61; % kg.mm^2
  %
  %   hipPitch.G = 16; % :1
  %   hipPitch.I = 365; % kg.mm^2
  %
  %   knee.G = 16; % :1
  %   knee.I = 365; % kg.mm^2
  %
  %   foot.G = 50; % :1
  %   foot.I = 4.9; % kg.mm^2
  %
  %   % LOOP CLOSURES ===========================================================
  %   bodyIndex(s, 'plantar-rod-end');
  %   bodyIndex(s, 'toe-pin');
  %
  %   bodyIndex(s, 'achilles-rod-end');
  %   bodyIndex(s, 'heel-spring-end');
end % CassieDescriptor
