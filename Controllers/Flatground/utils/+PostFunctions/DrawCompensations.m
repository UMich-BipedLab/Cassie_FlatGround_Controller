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
figure
hold on
plot(Data.u_CP_stance_knee)
plot(Data.e_CP_stance_knee*c_Gamma_knee)
plot(Data.s*100)
legend('u','eu','s')


Data.stanceLeg