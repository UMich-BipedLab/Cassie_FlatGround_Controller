function [ hd_output, dhd_output ] = hd_joint2output( hd_joint,dhd_joint)
m = size(hd_joint,2);
for j = 1:m
    hd_output(:,j) = hd_joint(:,j);
    dhd_output(:,j) = dhd_joint(:,j);
    [hd_output(3,j) hd_output(4,j)] = Forward_Kinematics_p(hd_joint(3,j), hd_joint(4,j));
    [hd_output(8,j) hd_output(9,j)] = Forward_Kinematics_p(hd_joint(8,j), hd_joint(9,j));
    [dhd_output(3,j) dhd_output(4,j)] = Forward_Kinematics_v(hd_joint(3,j), hd_joint(4,j), dhd_joint(3,j), dhd_joint(4,j));
    [dhd_output(8,j) dhd_output(9,j)] = Forward_Kinematics_v(hd_joint(8,j), hd_joint(9,j), dhd_joint(8,j), dhd_joint(9,j));
end

end

