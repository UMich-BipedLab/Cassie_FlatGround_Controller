function [ hd_joint, dhd_joint ] = hd_output2joint( hd_output,dhd_output)
m = size(hd_output,2);
for j = 1:m
    hd_joint(:,j) = hd_output(:,j);
    dhd_joint(:,j) = dhd_output(:,j);
    [hd_joint(3,j) hd_joint(4,j)] = Inverse_Kinematics_p(hd_output(3,j), hd_output(4,j));
    [hd_joint(8,j) hd_joint(9,j)] = Inverse_Kinematics_p(hd_output(8,j), hd_output(9,j));
    [dhd_joint(3,j) dhd_joint(4,j)] = Inverse_Kinematics_v(hd_output(3,j), hd_output(4,j), dhd_output(3,j), dhd_output(4,j));
    [dhd_joint(8,j) dhd_joint(9,j)] = Inverse_Kinematics_v(hd_output(8,j), hd_output(9,j), dhd_output(8,j), dhd_output(9,j));
end

end

