function alpha_output = bc_joint2output( alpha_joint,tp,M )
n = size(alpha_joint,1); % how many trajectories
alpha_output = zeros(n,M);
s = linspace(0,1,100);
hd_joint = bezier(alpha_joint,s);
dhd_jointds = dbezier(alpha_joint,s);
dhd_joint = dhd_jointds/tp;

for j = 1:length(s)
    hd_output(:,j) = hd_joint(:,j);
    dhd_output(:,j) = dhd_joint(:,j);
    [hd_output(3,j) hd_output(4,j)] = Forward_Kinematics_p(hd_joint(3,j), hd_joint(4,j));
    [hd_output(8,j) hd_output(9,j)] = Forward_Kinematics_p(hd_joint(8,j), hd_joint(9,j));
    [dhd_output(3,j) dhd_output(4,j)] = Forward_Kinematics_v(hd_joint(3,j), hd_joint(4,j), dhd_joint(3,j), dhd_joint(4,j));
    [dhd_output(8,j) dhd_output(9,j)] = Forward_Kinematics_v(hd_joint(8,j), hd_joint(9,j), dhd_joint(8,j), dhd_joint(9,j));
end
alpha_output = points_to_bc_v3( hd_output,dhd_output,tp,M );

end
% hd_output_fit = bezier(alpha_output,s);
% for i = 1:10
% figure(2)
% subplot(2,5,i)
% plot(hd_output(i,:))
% hold on 
% plot(hd_output_fit(i,:))
% hold off
% end
