function  [ hd_joint,dhd_joint,hd_output,dhd_output,hd_joint_fit,dhd_joint_fit,hd_output_fit,dhd_output_fit,alpha_output ] = Alpha_Joint_to_Alpha_output( alpha_joint,s,Tp,M )
    hd_joint = YToolkits.bezier(alpha_joint,s);
    dhd_joint = YToolkits.dbezier(alpha_joint,s)/Tp;
    
    for j = 1:length(s)
        hd_output(:,j) = hd_joint(:,j);
        dhd_output(:,j) = dhd_joint(:,j);
        [hd_output(3,j) hd_output(4,j)] = Forward_Kinematics_p(hd_joint(3,j), hd_joint(4,j));
        [hd_output(8,j) hd_output(9,j)] = Forward_Kinematics_p(hd_joint(8,j), hd_joint(9,j));
        [dhd_output(3,j) dhd_output(4,j)] = Forward_Kinematics_v(hd_joint(3,j), hd_joint(4,j), dhd_joint(3,j), dhd_joint(4,j));
        [dhd_output(8,j) dhd_output(9,j)] = Forward_Kinematics_v(hd_joint(8,j), hd_joint(9,j), dhd_joint(8,j), dhd_joint(9,j));
    end
     alpha_output  = points_to_bc_v3( hd_output,dhd_output,Tp,5 );
%     alpha_output=zeros(10,M+1);
%     alpha_output(:,1) = hd_output(:,1);
%     alpha_output(:,end) = hd_output(:,end);
%     alpha_output(:,2) = alpha_output(:,1) + dhd_output(:,1)*1/M*Tp;
%     alpha_output(:,end-1) = alpha_output(:,end) - dhd_output(:,end)*1/M*Tp;
%     
%     [alpha_output_sym,b_sym,s_sym]=bc_curve_symbolic(M);
%     alpha_output_str=arrayfun(@char,alpha_output_sym,'UniformOutput', false);
%     
%     p_a=alpha_output_str([1,2,end-1,end]);
%     c_a=alpha_output_str(3:end-2);
%     g=matlabFunction(b_sym,'Vars',[ alpha_output_sym(3:end-2) alpha_output_sym([1,2,end-1,end]) s_sym]);
%     bcft=fittype(g,'independent','s','coefficients',c_a,'problem',p_a);
%     
%     for k=1:10
%         result=fit(s',hd_output(k,:)',bcft,'problem',num2cell(alpha_output(k,[1,2,end-1,end])),'StartPoint',zeros(1,M-3));
%         mid_index=3:M-1;
%         alpha_output(k,mid_index)=coeffvalues(result);
%     end

    %% check the fitting result
    hd_output_fit = YToolkits.bezier(alpha_output,s);
    dhd_output_fit =YToolkits.dbezier(alpha_output,s)/Tp;
    for j = 1:length(s)
        hd_joint_fit(:,j) = hd_output_fit(:,j);
        dhd_joint_fit(:,j) = dhd_output_fit(:,j);
        [hd_joint_fit(3,j) hd_joint_fit(4,j)] = Inverse_Kinematics_p(hd_output_fit(3,j), hd_output_fit(4,j));
        [hd_joint_fit(8,j) hd_joint_fit(9,j)] = Inverse_Kinematics_p(hd_output_fit(8,j), hd_output_fit(9,j));
        [dhd_joint_fit(3,j) dhd_joint_fit(4,j)] = Inverse_Kinematics_v(hd_output_fit(3,j), hd_output_fit(4,j), dhd_output_fit(3,j), dhd_output_fit(4,j));
        [dhd_joint_fit(8,j) dhd_joint_fit(9,j)] = Inverse_Kinematics_v(hd_output_fit(8,j), hd_output_fit(9,j), dhd_output_fit(8,j), dhd_output_fit(9,j));
    end


end

