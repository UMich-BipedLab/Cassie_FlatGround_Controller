s = linspace(0,1,100);
d_CP_stance_knee = YToolkits.bezier(c_CP_StanceKnee,s);
d_CP_swing_knee = YToolkits.bezier(c_CP_SwingKnee,s);
d_CP_stance_abduc = YToolkits.bezier(c_CP_StanceAbdu,s);
d_CP_swing_abduc  = YToolkits.bezier(c_CP_SwingAbdu,s);

% CP_StanceKnee;
% CP_SwingKnee;
% CP_StanceAbdu;
% CP_SwingAbdu;

figure(101)
subplot(2,2,1)
plot(s*0.4,d_CP_stance_knee);
title('stance knee compensation');

subplot(2,2,2)
plot(s*0.4,d_CP_swing_knee);
title('swing knee compensation');

subplot(2,2,3)
plot(s*0.4,d_CP_stance_abduc);
title('stance abduction compensation');

subplot(2,2,4)
plot(s*0.4,d_CP_swing_abduc);
title('swing abduction compensation');

%%
close all

figure
hold on
plot(Data.u_CP_stance_knee)
plot(Data.e_CP_stance_knee*c_Gamma_knee)
plot(Data.s*100)
plot(Data.u_OT_stance_knee)
legend('uCP','euCP','s','u_SK')
% plot(Data.u.Time, reshape(Data.u.Data(4,:,:),length(Data.u.Time),1))
% plot(Data.u.Time, reshape(Data.u.Data(9,:,:),length(Data.u.Time),1))
% xlim([11,12]);
% Data.stanceLeg

figure
hold on
plot(Data.u_CP_stance_hip_pitch)
plot(Data.e_CP_stance_hip_pitch*c_Gamma_knee)
plot(Data.s*20)
plot(Data.u_OT_stance_hip_pitch)
legend('uCP','euCP','s','u_SH')
% xlim([11,12]);
%%
figure(1)
clf
plot(u_stance_knee_interp)
hold on
plot(filtfilt(b, a, u_stance_knee_interp))

figure(2)
clf
plot(u_stance_knee_interp)
hold on
plot(filtfilt(b, a, u_stance_knee_interp))