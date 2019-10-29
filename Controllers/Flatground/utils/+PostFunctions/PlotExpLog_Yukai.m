% Date = '2018-7-10';
% Time = '16-8';
% load([root_dir,'/ExpLog/',Date,'/',Time,'/','Log']) 
% start_index = find(log.Data.t == 2773);
% end_index = find(log.Data.t == 2777);
start_index = 1;
end_index = length(log.Data.t);
% figure(1)
% plot(log.Data.t,log.Data.hd)
% hold on
% plot(log.Data.t,log.Data.h0)
% hold off
% lg = legend('hd_1','hd_2','hd_3','hd_4','hd_5','hd_6','hd_7','hd_8','hd_9','hd_10','h0_1','h0_2','h0_3','h0_4','h0_5','h0_6','h0_7','h0_8','h0_9','h0_10')
% set(lg,'visible','off');
% plotbrowser('on')
% 
% 
% figure(2)
% plot(log.Data.t,log.Data.dhd)
% hold on
% plot(log.Data.t,log.Data.dh0)
% hold off
% lg = legend('dhd_1','dhd_2','dhd_3','dhd_4','dhd_5','dhd_6','dhd_7','dhd_8','dhd_9','dhd_10','dh0_1','dh0_2','dh0_3','dh0_4','dh0_5','dh0_6','dh0_7','dh0_8','dh0_9','dh0_10')
% set(lg,'visible','off');
% plotbrowser('on')

figure(3)
plot(log.Data.t(start_index:end_index),180/pi*log.Data.hd_joint(start_index:end_index,:))
hold on
plot(log.Data.t(start_index:end_index),180/pi*log.Data.h0_joint(start_index:end_index,:))
ps = plot(log.Data.t(start_index:end_index),2*180/pi*log.Data.stanceLeg(start_index:end_index),'g--');
set(ps,'Visible','off')
hold off
lg = legend('hd_joint_1','hd_joint_2','hd_joint_3','hd_joint_4','hd_joint_5','hd_joint_6','hd_joint_7','hd_joint_8','hd_joint_9','hd_joint_10','h0_joint_1','h0_joint_2','h0_joint_3','h0_joint_4','h0_joint_5','h0_joint_6','h0_joint_7','h0_joint_8','h0_joint_9','h0_joint_10')
set(lg,'visible','off');
plotbrowser('on')
ax3 = gca;

figure(4)
plot(log.Data.t(start_index:end_index),180/pi*log.Data.dhd_joint(start_index:end_index,:))
hold on
plot(log.Data.t(start_index:end_index),180/pi*log.Data.dh0_joint(start_index:end_index,:))
ps = plot(log.Data.t(start_index:end_index),180/pi*1*log.Data.stanceLeg(start_index:end_index),'g--');
hold off
lg = legend('dhd_joint_1','dhd_joint_2','dhd_joint_3','dhd_joint_4','dhd_joint_5','dhd_joint_6','dhd_joint_7','dhd_joint_8','dhd_joint_9','dhd_joint_10','dh0_joint_1','dh0_joint_2','dh0_joint_3','dh0_joint_4','dh0_joint_5','dh0_joint_6','dh0_joint_7','dh0_joint_8','dh0_joint_9','dh0_joint_10')
set(lg,'visible','off');
plotbrowser('on')
ax4 = gca;

figure(5)
plot(log.Data.t(start_index:end_index),log.Data.u(start_index:end_index,:))
hold on
ps = plot(log.Data.t(start_index:end_index),100*log.Data.stanceLeg(start_index:end_index),'g--');
hold off
lg = legend('u_1','u_2','u_3','u_4','u_5','u_6','u_7','u_8','u_9','u_10')
set(lg,'visible','off');
plotbrowser('on')
ax5 = gca;

figure(6)
plot(log.Data.t(start_index:end_index),180/pi*log.Data.ddq_r(start_index:end_index,:))
hold on
ps = plot(log.Data.t(start_index:end_index),180/pi*10*log.Data.stanceLeg(start_index:end_index),'g--');
hold off
lg = legend('ddq_r_1','ddq_r_2','ddq_r_3','ddq_r_4','ddq_r_5','ddq_r_6','ddq_r_7','ddq_r_8','ddq_r_9','ddq_r_10','ddq_r_11','ddq_r_12','ddq_r_13','ddq_r_14','ddq_r_15','ddq_r_16','ddq_r_17','ddq_r_18','ddq_r_19','ddq_r_20');
set(lg,'visible','off');
plotbrowser('on')
ax6 = gca;

% linkaxes([ax3 ax4 ax5 ax6],'x');
