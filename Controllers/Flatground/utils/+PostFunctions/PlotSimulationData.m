% Date = '2018-7-10';
% Time = '16-8';
% load([root_dir,'/ExpLog/',Date,'/',Time,'/','Log']) 

figure(1)
plot(log.Data.t,log.Data.hd)
hold on
plot(log.Data.t,log.Data.h0)
hold off
lg = legend('hd_1','hd_2','hd_3','hd_4','hd_5','hd_6','hd_7','hd_8','hd_9','hd_10','h0_1','h0_2','h0_3','h0_4','h0_5','h0_6','h0_7','h0_8','h0_9','h0_10')
set(lg,'visible','off');
plotbrowser('on')


figure(2)
plot(log.Data.t,log.Data.dhd)
hold on
plot(log.Data.t,log.Data.dh0)
hold off
lg = legend('dhd_1','dhd_2','dhd_3','dhd_4','dhd_5','dhd_6','dhd_7','dhd_8','dhd_9','dhd_10','dh0_1','dh0_2','dh0_3','dh0_4','dh0_5','dh0_6','dh0_7','dh0_8','dh0_9','dh0_10')
set(lg,'visible','off');
plotbrowser('on')

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
%% Plot torso position and velocities
close all
DataL = length(Data.qall.Time);
Time  = reshape(Data.t.Time,1,DataL);  
qall  = reshape(Data.qall.Data,20,DataL);  
dqall  = reshape(Data.dqall.Data,20,DataL); 

figure
plot(Time,qall(4:6,:));
legend('yaw','pitch','roll');

figure
plot(Time,dqall(4:6,:));
legend('dyaw','dpitch','droll');



%% Joint left
close all

DataL = length(Data.hd_joint.Time);
Time =  reshape(Data.t.Time, 1,DataL);  
% hd_joint = reshape(Data.hd_joint.Data, 10,DataL);  
hd_joint = reshape(Data.hd_joint.Data, 10,DataL);  
h0_joint = reshape(Data.h0_joint.Data, 10,DataL);  

dhd_joint = reshape(Data.dhd_joint.Data, 10,DataL);  
dh0_joint = reshape(Data.dh0_joint.Data, 10,DataL);  

u_motors   =reshape(Data.u.Data, 10,DataL) ; 
hd_joint_original = reshape(Data.hd_original.Data, 10,DataL);  

s          = reshape(Data.s.Data, 1,DataL);
stanceleg  = reshape(Data.stanceLeg.Data, 1,DataL);
TitleNames = {'Abduction','Yaw','Hip','Knee','Toe'}; 


tlb = 10;
tup = 15; %3383;


tlbInd = find(Time>tlb);
tlbInd = tlbInd(1);

tupInd = find(Time<tup);
tupInd = tupInd(end);

for k = 1:5
    

   figure('Position',[k*100,100,800,600]);
   
   % position plot
   ax1 = subplot(3,1,1);
   hold on;


   minlim = min([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd), hd_joint(k+5,tlbInd:tupInd), h0_joint(k+5,tlbInd:tupInd)]);
   maxlim = max([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd), hd_joint(k+5,tlbInd:tupInd), h0_joint(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   plot(Time, hd_joint_original(k,:),'linewidth',2,'color',[0.93,0.69,0.13]);   
   plot(Data.t.Time, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.t.Time, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);


   ps = plot(Data.t.Time(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',1,'MarkerEdgeColor',[17 17 17]./256 ,'MarkerFaceColor',[17 17 17]./256);
   
   p1 = plot(Data.t.Time, hd_joint(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   p2 = plot(Data.t.Time, h0_joint(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   
   
   p1.Color(4) = 0.2;   
   p2.Color(4) = 0.2;  


   
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);   
   legend('gait library','desired','actual')
   title(['Joint position tracking of left ', TitleNames{k},' motor']);
   title([TitleNames{k},' motor']);
   xlabel('Time (sec)');
   ylabel('Joint Angle (rad)');
   box on;
   xlim([tlb,tup]);
   grid on;
   
   
   % velocity plot
   ax2 = subplot(3,1,2);
   hold on
   
   minlim = min([dhd_joint(k,tlbInd:tupInd), dh0_joint(k,tlbInd:tupInd),dhd_joint(k+5,tlbInd:tupInd), dh0_joint(k+5,tlbInd:tupInd)]);
   maxlim = max([dhd_joint(k,tlbInd:tupInd), dh0_joint(k,tlbInd:tupInd),dhd_joint(k+5,tlbInd:tupInd), dh0_joint(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   
   plot(Data.t.Time, dhd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.t.Time, dh0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   ps = plot(Data.t.Time(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',1,'MarkerEdgeColor',[17 17 17]./256 ,'MarkerFaceColor',[17 17 17]./256);
   
   p1 = plot(Data.t.Time, dhd_joint(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   p2 = plot(Data.t.Time, dh0_joint(k+5,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
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
   ax3 = subplot(3,1,3);
   hold on
   
   minlim = min([u_motors(k,tlbInd:tupInd), u_motors(k+5,tlbInd:tupInd)]);
   maxlim = max([u_motors(k,tlbInd:tupInd), u_motors(k+5,tlbInd:tupInd)]);
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   
   
   plot(Data.t.Time, u_motors(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   %plot(log.Data.t, u_motors(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   
   ps = plot(Data.t.Time(stanceleg~=1),Ns(stanceleg~=1),'o','MarkerSize',1,'MarkerEdgeColor',[17 17 17]./256 ,'MarkerFaceColor',[17 17 17]./256);
   
   p1 = plot(Data.t.Time, u_motors(k+5,:),'linewidth',2,'color',[202/256,100/256,73/256]);
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
   
   linkaxes([ax1,ax2,ax3],'x'); 
   
%    print(gcf, '-dpdf', '-painters', [num2str(k),'Push_Test.pdf']); 
end    

%    xlim([LpB,LpB+LD]);
%    %minlim = min([hd_joint(k,round(length(Data.hd_joint.Time)/2):end), h0_joint(k,round(length(Data.hd_joint.Time)/2):end)]);
%    %maxlim = max([hd_joint(k,round(length(Data.hd_joint.Time)/2):end), h0_joint(k,round(length(Data.hd_joint.Time)/2):end)]);
%    Ns = s*(maxlim - minlim) + minlim;
% %    h1 = plot(Data.s.Time(stanceleg==1),Ns(stanceleg==1),'.','MarkerSize',0.1,'MarkerEdgeColor',[202/256,100/256,73/256],'MarkerFaceColor',[202/256,100/256,73/256]);
%    h2 = plot(Data.s.Time(stanceleg~=1), ones(size(Ns(stanceleg~=1))),'.','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
%    plot(Data.hd_joint.Time, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
%    plot(Data.h0_joint.Time, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
%    %ylim([minlim - 0.05, maxlim + 0.05]);
%    legend('left stance','desired','actual')
%    title(['Joint tracking of left ', TitleNames{k},' motor']);
%    xlabel('Time (sec)');
%    ylabel('Angle (rad)');
    
% end    
%%

figure(501)
hold on
plot(Data.u_CP_stance_knee)
plot(Data.e_CP_stance_knee*c_Gamma_knee)
plot(Data.s*100)
plot(Data.u_OT_stance_knee)
legend('uCP','euCP','s','u_SK')
xlim([tlb,tup]);
% Data.stanceLeg

figure(502)
hold on
plot(Data.u_CP_stance_hip_pitch)
plot(Data.e_CP_stance_hip_pitch*c_Gamma_knee)
plot(Data.s*20)
plot(Data.u_OT_stance_hip_pitch)
legend('uCP','euCP','s','u_SH')
xlim([tlb,tup]);

figure(503)
hold on
plot(Data.u_CP_stance_abduction)
plot(Data.e_CP_stance_abduction*c_Gamma_knee)
plot(Data.s*20)
plot(Data.u_OT_stance_abduction)
legend('uCP','euCP','s','u_SH')
xlim([tlb,tup]);
%% Joint right
close all
hd_joint = reshape(Data.hd_joint.Data, 10,length(Data.hd_joint.Time));  
h0_joint = reshape(Data.h0_joint.Data, 10,length(Data.h0_joint.Time));  
s        = reshape(Data.s.Data, 1,length(Data.s.Time));
stanceleg = reshape(Data.stanceLeg.Data, 1,length(Data.stanceLeg.Time));
TitleNames = {'Abduction','Yaw','Hip','Knee','Toe'}; 


for k = 6:10
    
%    figure(k)
   figure('Position',[(k-5)*300,300,800,600])
   hold on;
   minlim = min([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd)]);
   maxlim = max([hd_joint(k,tlbInd:tupInd), h0_joint(k,tlbInd:tupInd)]);
   
   Byu = abs(maxlim - minlim);
   Ns = ones(size(s))*(maxlim + minlim)/2;
   plot(Data.hd_joint.Time, hd_joint(k,:),'linewidth',2,'color',[202/256,100/256,73/256]);
   plot(Data.h0_joint.Time, h0_joint(k,:),'linewidth',2,'color',[0/256,114/256,189/256]);
   ylim([minlim - 0.1*Byu, maxlim + 0.1*Byu]);
   h2 = plot(Data.t.Time(stanceleg==1),Ns(stanceleg==1),'o','MarkerSize',0.1,'MarkerEdgeColor',[0/256,114/256,189/256] ,'MarkerFaceColor',[0/256,114/256,189/256]);
   legend('desired','actual')
   title(['Joint tracking of right ', TitleNames{k-5},' motor']);
   xlabel('Time (sec)');
   ylabel('Angle (rad)');
      xlim([tlb,tup]);
    
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