% Date = '2018-7-10';
% Time = '16-8';
% load([root_dir,'/ExpLog/',Date,'/',Time,'/','Log']) 

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
plot(log.Data.t,log.Data.hd_joint)
hold on
plot(log.Data.t,log.Data.h0_joint)
hold off
lg = legend('hd_joint_1','hd_joint_2','hd_joint_3','hd_joint_4','hd_joint_5','hd_joint_6','hd_joint_7','hd_joint_8','hd_joint_9','hd_joint_10','h0_joint_1','h0_joint_2','h0_joint_3','h0_joint_4','h0_joint_5','h0_joint_6','h0_joint_7','h0_joint_8','h0_joint_9','h0_joint_10')
set(lg,'visible','off');
plotbrowser('on')

figure(4)
plot(log.Data.t,log.Data.dhd_joint)
hold on
plot(log.Data.t,log.Data.dh0_joint)
hold off
lg = legend('dhd_joint_1','dhd_joint_2','dhd_joint_3','dhd_joint_4','dhd_joint_5','dhd_joint_6','dhd_joint_7','dhd_joint_8','dhd_joint_9','dhd_joint_10','dh0_joint_1','dh0_joint_2','dh0_joint_3','dh0_joint_4','dh0_joint_5','dh0_joint_6','dh0_joint_7','dh0_joint_8','dh0_joint_9','dh0_joint_10')
set(lg,'visible','off');
plotbrowser('on')

figure(5)
plot(log.Data.t,log.Data.u)
lg = legend('u_1','u_2','u_3','u_4','u_5','u_6','u_7','u_8','u_9','u_10')
set(lg,'visible','off');
plotbrowser('on')
%%

% Radio control signals 
% RadioButton.LVA = RadioChannel(1);
% RadioButton.LHA = RadioChannel(2);
% RadioButton.RVA = RadioChannel(3);
% RadioButton.RHA = RadioChannel(4);
% RadioButton.S1A = RadioChannel(5);
% RadioButton.S2A = RadioChannel(6);
% RadioButton.LSA = RadioChannel(7);
% RadioButton.RSA = RadioChannel(8);
% RadioButton.SAA = RadioChannel(9);
% RadioButton.SBA = RadioChannel(10);
% RadioButton.SCA = RadioChannel(11);
    % when SC button is at  0, use constant compensation
    % when SC button is at -1, use ILC for stance knee compensation only
    % when SC button is at +1, use ILC for both stance and
    % swing knee compensation

% RadioButton.SDA = RadioChannel(12);
    % when SD button is at -1, use constant compensation
    % when SD button is at  0, use ILC for stance hip compensation only
    % when SD button is at +1, use ILC for both stance and
    % swing hip compensation

% RadioButton.SEA = RadioChannel(13);
% RadioButton.SFA = RadioChannel(14); 
    % update the data if SFA == +1
% RadioButton.SGA = RadioChannel(15);
    % when SG button is at -1, use constant compensation abduction
    % when SG button is at  0, use ILC for stance compensation only
    % when SG button is at +1, use ILC for both stance and swing
% RadioButton.SHA = RadioChannel(16);
% figure
% plot(log.Data.t,log.Data.RadioChannel(:,12))
close all
figure
hold on
plot(log.Data.t,log.Data.RadioChannel(:,11)); % knee
plot(log.Data.t,log.Data.RadioChannel(:,12)); % hip
plot(log.Data.t,log.Data.RadioChannel(:,14)); % SFA update data
plot(log.Data.t,log.Data.tg_velocity_x);
legend('Knee','Hip','Update','Desired Speed')
ylim([-1.5 1.5])
%% Joint left
close all

hd_joint   = log.Data.hd_joint';  
h0_joint   = log.Data.h0_joint';  
dhd_joint  = log.Data.dhd_joint';  
dh0_joint  = log.Data.dh0_joint';  
u_motors   = log.Data.u'; 

s          = log.Data.s';
stanceleg  = log.Data.stanceLeg';
TitleNames = {'Abduction','Yaw','Hip','Knee','Toe'}; 

tlb = 1000; % time in seconds
tup = tlb + 5; % 3383;

tlbInd = find(log.Data.t>tlb);
tlbInd = tlbInd(1);

tupInd = find(log.Data.t<tup);
tupInd = tupInd(end);

for k = 1:5
    
   figure('Position',[k*300,100,1600,1200]);
   % position plot
   ax1 = subplot(4,1,1);
   hold on;

   minlim = min([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd), hd_joint(k+5,tlbInd:tupInd), h0_joint(k+5,tlbInd:tupInd)]);
   maxlim = max([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd), hd_joint(k+5,tlbInd:tupInd), h0_joint(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   plot(log.Data.t, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(log.Data.t, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   

   p1 = plot(log.Data.t, hd_joint(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   p2 = plot(log.Data.t, h0_joint(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   p1.Color(4) = 0.2;   
   p2.Color(4) = 0.2;  
   
   h2 = plot(log.Data.t(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
   legend('desired','actual')
   title(['Joint tracking of left ', TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Angle (rad)');
   box on;
   grid on;
   xlim([tlb,tup]);
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);
   
   
   % velocity plot
   ax2 = subplot(4,1,2);
   hold on
   
   minlim = min([dhd_joint(k,tlbInd:tupInd), dh0_joint(k,tlbInd:tupInd),dhd_joint(k+5,tlbInd:tupInd), dh0_joint(k+5,tlbInd:tupInd)]);
   maxlim = max([dhd_joint(k,tlbInd:tupInd), dh0_joint(k,tlbInd:tupInd),dhd_joint(k+5,tlbInd:tupInd), dh0_joint(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   
   plot(log.Data.t, dhd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(log.Data.t, dh0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   ps = plot(log.Data.t(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',1,'MarkerEdgeColor',[17 17 17]./256 ,'MarkerFaceColor',[17 17 17]./256);
   
   p1 = plot(log.Data.t, dhd_joint(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   p2 = plot(log.Data.t, dh0_joint(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   p1.Color(4) = 0.2;   
   p2.Color(4) = 0.2;   
   
   
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);  
   legend('desired','actual')
   title(['Joint velocity tracking of left ', TitleNames{k},' motor']);
   title([TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Joint Velocity (rad/s)');
   box on;
   xlim([tlb,tup]);
   grid on;
   
   
   
   
   % velocity plot
   ax3 = subplot(4,1,3);
   hold on
   
   minlim = min([u_motors(k,tlbInd:tupInd), u_motors(k+5,tlbInd:tupInd)]);
   maxlim = max([u_motors(k,tlbInd:tupInd), u_motors(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   
   plot(log.Data.t, u_motors(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   %plot(log.Data.t, u_motors(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   ps = plot(log.Data.t(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',1,'MarkerEdgeColor',[17 17 17]./256 ,'MarkerFaceColor',[17 17 17]./256);
   
   p1 = plot(log.Data.t, u_motors(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   %p2 = plot(log.Data.t, u_motors(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   p1.Color(4) = 0.2;   
   %p2.Color(4) = 0.2;   
   
   
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);  
   % legend('desired','actual')
   title(['Joint torque of left ', TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Joint Torques (Nm/s)');
   box on;
   xlim([tlb,tup]);
   grid on;
   
   
  % velocity plot
   ax4 = subplot(4,1,4);
   hold on
   
%    plot(log.Data.t, u_motors(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(log.Data.t,log.Data.RadioChannel(:,11),'linewidth',2); % knee
   plot(log.Data.t,log.Data.RadioChannel(:,12),'linewidth',1); % hip
   plot(log.Data.t,log.Data.RadioChannel(:,14)); % SFA update data
   plot(log.Data.t,log.Data.RadioChannel(:,15)); % Abu update data
   plot(log.Data.t,log.Data.tg_velocity_x);
   
   ylim([-1.2, 1.2]);  
   % legend('desired','actual')
   title('Control Signals');
   legend('Knee','Hip','Update','Abudction','target speed')
   xlabel('Time (sec)');
   ylabel('Control Signals');
   box on;

   grid on;  
   
   
   linkaxes([ax1,ax2,ax3,ax4],'x'); 
   
   xlim([tlb,tup]);   
%    print(gcf, '-dpdf', '-painters', [num2str(k),'Push_Test.pdf']); 
end    
%% Plot joint torques of 10 continuous steps
close all
figure('Position',[300,100,1400,600]);
hold on
view([45 45]);
grid on; box on;
xlabel('Time (s)');
ylabel('Desired Speed (m/s)');
zlabel('Torques (Nm)');
c = jet(7);
CM = colormap(c);

vd = [-0.1, 0, 0.1, 0.2, 0.3, 0.4, 0.5];
StimeV = [1020, 317, 391, 492, 628, 770, 892];
Jnum = 5;


for i = 1:7
    
    Stime = StimeV(i);
    tlbInd = find(log.Data.t>Stime);
    tlbInd = tlbInd(1);
    NoSP = 20; % number of steps to plot
    stanceleg  = log.Data.stanceLeg';
    % Find all left stance to right stance transitions 
    LRt = find(diff(stanceleg)==-2);
    % get 11 elements starting from Stime  
    LRt = LRt(LRt>tlbInd);
    LRt = LRt(1:NoSP+1);

    for k = 1:NoSP
        plot3(log.Data.t(LRt(k):LRt(k+1)) - log.Data.t(LRt(k)), ...
              vd(i)*ones(1,LRt(k+1)-LRt(k)+1), u_motors(Jnum,LRt(k):LRt(k+1)),'linewidth',1,'color',CM(i,:));
        drawnow();
    end

end

%
%% Plot joint trajectories of 10 continuous steps
close all
figure('Position',[300,100,1400,600]);
hold on
view([45 45]);
grid on; box on;
xlabel('Time (s)');
ylabel('Desired Speed (m/s)');
zlabel('Joint Trajectory (rad)');
c = jet(7);
CM = colormap(c);

vd = [-0.1, 0, 0.1, 0.2, 0.3, 0.4, 0.5];
StimeV = [1020, 317, 391, 492, 628, 770, 892];


Jnum = 1;


for i = 1:7
    
    Stime = StimeV(i);
    tlbInd = find(log.Data.t>Stime);
    tlbInd = tlbInd(1);
    NoSP = 20; % number of steps to plot
    stanceleg  = log.Data.stanceLeg';
    % Find all left stance to right stance transitions 
    LRt = find(diff(stanceleg)==-2);
    % get 11 elements starting from Stime  
    LRt = LRt(LRt>tlbInd);
    LRt = LRt(1:NoSP+1);

    for k = 1:NoSP
%            plot(log.Data.t, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
%            plot(log.Data.t, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
        if k == 1
              plot3(log.Data.t(LRt(k):LRt(k+1)) - log.Data.t(LRt(k)), ...
              vd(i)*ones(1,LRt(k+1)-LRt(k)+1), hd_joint(Jnum,LRt(k):LRt(k+1)),'linewidth',2,'color',[0,0,0]);
              drawnow();  
        end    
        plot3(log.Data.t(LRt(k):LRt(k+1)) - log.Data.t(LRt(k)), ...
              vd(i)*ones(1,LRt(k+1)-LRt(k)+1), h0_joint(Jnum,LRt(k):LRt(k+1)),'linewidth',1,'color',CM(i,:));
        drawnow();
    end

end
%%
figure
hold on;
plot(Data.EKF_v)
plot(Data.tg_velocity_x_fil )
%%
figure
hold on;
plot(log.Data.t,log.Data.EKF_v(:,1))
plot(log.Data.t,log.Data.tg_velocity_x_fil )
%%
figure
hold on;
plot(log.Data.t,log.Data.EKF_v(:,1))
plot(log.Data.t,log.Data.tg_velocity_x_fil)
%%
figure
hold on;
plot(log.Data.t,log.Data.EKF_v(:,2))
plot(log.Data.t,log.Data.tg_velocity_y_fil)
%% Simulation Joint left
close all
hd_joint = reshape(Data.hd_joint.Data, 10,length(Data.hd_joint.Time));  
h0_joint = reshape(Data.h0_joint.Data, 10,length(Data.h0_joint.Time));  
s        = reshape(Data.s.Data, 1,length(Data.s.Time));
stanceleg = reshape(Data.stanceLeg.Data, 1,length(Data.stanceLeg.Time));
TitleNames = {'Abduction','Yaw','Hip','Knee','Toe'}; 


tlb = 6;
tup = 10;%Data.t.Time(end);

tlbInd = find(Data.t.Time>tlb);
tlbInd = tlbInd(1);

tupInd = find(Data.t.Time<tup);
tupInd = tupInd(end);


for k = 1:5
    
minlim = min([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd)]);
maxlim = max([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd)]);    
    
%    figure(k)
   figure('Position',[k*300,300,800,600])
   hold on;
%    xlim([28,30]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   %h1 = plot(Data.s.Time(stanceleg==1),Ns(stanceleg==1),'.','MarkerSize',0.1,'MarkerEdgeColor',[202/256,100/256,73/256],'MarkerFaceColor',[202/256,100/256,73/256]);
   plot(Data.hd_joint.Time, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.h0_joint.Time, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);
   xlim([tlb,tup]);
   h2 = plot(Data.t.Time(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
   legend('desired','actual')
   title(['Joint tracking of left ', TitleNames{k},' motor']);
   title([TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Angle (rad)');
   box on;
    
end    
%% virtual left
close all
hd = reshape(Data.hd.Data, 10,length(Data.hd.Time));  
h0 = reshape(Data.h0.Data, 10,length(Data.h0.Time));  
s        = reshape(Data.s.Data, 1,length(Data.s.Time));
stanceleg = reshape(Data.stanceLeg.Data, 1,length(Data.stanceLeg.Time));
TitleNames = {'Abduction','Yaw','LA','LL','Toe'}; 


for k = 3:4
    
   figure('Position',[k*300,300,800,600])
   hold on;



   minlim = min([hd(k,round(length(Data.hd.Time)/4):round(length(Data.hd.Time)*3/4)), h0(k,round(length(Data.hd.Time)/2):round(length(Data.hd.Time)*3/4))]);
   maxlim = max([hd(k,round(length(Data.hd.Time)/4):round(length(Data.hd.Time)*3/4)), h0(k,round(length(Data.hd.Time)/2):round(length(Data.hd.Time)*3/4))]);
   Ns = s*(maxlim - minlim) + minlim;
   h1 = plot(Data.s.Time(stanceleg==1),Ns(stanceleg==1),'.','MarkerSize',0.1,'MarkerEdgeColor',[202/256,100/256,73/256],'MarkerFaceColor',[202/256,100/256,73/256]);
   h2 = plot(Data.s.Time(stanceleg~=1),Ns(stanceleg~=1),'.','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
   plot(Data.hd.Time, hd(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.h0.Time, h0(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   xlim([28,30]);
   ylim([minlim, maxlim]);
   legend('right stance','left stance','desired','actual')
   title(['Joint tracking of left ', TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Angle (rad)');
    
end    

%% virtual right
close all
hd = reshape(Data.hd.Data, 10,length(Data.hd.Time));  
h0 = reshape(Data.h0.Data, 10,length(Data.h0.Time));  
s        = reshape(Data.s.Data, 1,length(Data.s.Time));
stanceleg = reshape(Data.stanceLeg.Data, 1,length(Data.stanceLeg.Time));
TitleNames = {'Abduction','Yaw','LA','LL','Toe'}; 


for k = 3:4
    
   figure('Position',[k*300,300,800,600])
   hold on;


   xlim([28,30]);
   minlim = min([hd(k,round(length(Data.hd.Time)/4):round(length(Data.hd.Time)*3/4)), h0(k,round(length(Data.hd.Time)/2):round(length(Data.hd.Time)*3/4))]);
   maxlim = max([hd(k,round(length(Data.hd.Time)/4):round(length(Data.hd.Time)*3/4)), h0(k,round(length(Data.hd.Time)/2):round(length(Data.hd.Time)*3/4))]);
   Ns = s*(maxlim - minlim) + minlim;
   h1 = plot(Data.s.Time(stanceleg==1),Ns(stanceleg==1),'.','MarkerSize',0.1,'MarkerEdgeColor',[202/256,100/256,73/256],'MarkerFaceColor',[202/256,100/256,73/256]);
   h2 = plot(Data.s.Time(stanceleg~=1),Ns(stanceleg~=1),'.','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
   plot(Data.hd.Time, hd(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.h0.Time, h0(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   ylim([minlim , maxlim ]);
   legend('right stance','left stance','desired','actual')
   title(['Joint tracking of right ', TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Angle (rad)');
    
end    