figure_index = 1;
% qc_index = [5;7;8;9;10;];
qc_index = [10];
hide_index = setdiff(1:20,qc_index);

figure(1+5*figure_index)
h = plot(Data.q_r);
set(h(hide_index),'Visible','off')
hold on
h = plot(Data.q_0);
ps = plot(3*Data.stanceLeg,'--');
set(h(hide_index),'Visible','off')
hold off
lg = legend('q_r_1','q_r_2','q_r_3','q_r_4','q_r_5','q_r_6','q_r_7','q_r_8','q_r_9','q_r_10','q_r_11','q_r_12','q_r_13','q_r_14','q_r_15','q_r_16','q_r_17','q_r_18','q_r_19','q_r_20',...
    'q_0_1','q_0_2','q_0_3','q_0_4','q_0_5','q_0_6','q_0_7','q_0_8','q_0_9','q_0_10','q_0_11','q_0_12','q_0_13','q_0_14','q_0_15','q_0_16','q_0_17','q_0_18','q_0_19','q_0_20');
set(lg,'visible','off');
plotbrowser('on')
grid on


figure(2+5*figure_index)
h = plot(Data.dq_r);
set(h(hide_index),'Visible','off')
hold on
h = plot(Data.dq_0);
set(h(hide_index),'Visible','off')
ps = plot(1*Data.stanceLeg,'--');
set(ps,'Visible','off')
hold off
lg = legend('dq_r_1','dq_r_2','dq_r_3','dq_r_4','dq_r_5','dq_r_6','dq_r_7','dq_r_8','dq_r_9','dq_r_10','dq_r_11','dq_r_12','dq_r_13','dq_r_14','dq_r_15','dq_r_16','dq_r_17','dq_r_18','dq_r_19','dq_r_20',...
    'dq_0_1','dq_0_2','dq_0_3','dq_0_4','dq_0_5','dq_0_6','dq_0_7','dq_0_8','dq_0_9','dq_0_10','dq_0_11','dq_0_12','dq_0_13','dq_0_14','dq_0_15','dq_0_16','dq_0_17','dq_0_18','dq_0_19','dq_0_20');
set(lg,'visible','off');
plotbrowser('on')
grid on

figure(3+5*figure_index)
h = plot(Data.q_y);
set(h(hide_index),'Visible','off')
hold on;
ps = plot(0.1*Data.stanceLeg,'--');
set(ps,'Visible','off')
hold off;
lg = legend('q_y_1','q_y_2','q_y_3','q_y_4','q_y_5','q_y_6','q_y_7','q_y_8','q_y_9','q_y_10','q_y_11','q_y_12','q_y_13','q_y_14','q_y_15','q_y_16','q_y_17','q_y_18','q_y_19','q_y_20');
set(lg,'visible','off');
plotbrowser('on')
grid on

% figure(4)
% h = plot(Data.dq_y)
% set(h(hide_index),'Visible','off')
% hold on;
% ps = plot(0.5*Data.stanceLeg,'--')
% set(ps,'Visible','off')
% hold off;
% lg =
% legend('dq_y_1','dq_y_2','dq_y_3','dq_y_4','dq_y_5','dq_y_6','dq_y_7','dq_y_8','dq_y_9','dq_y_10','dq_y_11','dq_y_12','dq_y_13','dq_y_14','dq_y_15','dq_y_16','dq_y_17','dq_y_18','dq_y_19','dq_y_20');
% set(lg,'visible','off');
% plotbrowser('on')
% grid on
figure(5+5*figure_index)
plot(Data.u)
lg = legend('u_1','u_2','u_3','u_4','u_5','u_6','u_7','u_8','u_9','u_10');
set(lg,'visible','off');
plotbrowser('on')

% save('Data','Data');figure(1);savefig('Postion.fig');saveas(gcf,'Postion.bmp');figure(2);savefig('Velocity.fig');saveas(gcf,'Velocity.bmp');figure(3);savefig('Error.fig');saveas(gcf,'Error.bmp');figure(5);savefig('Torque.fig');saveas(gcf,'Torque.bmp');
