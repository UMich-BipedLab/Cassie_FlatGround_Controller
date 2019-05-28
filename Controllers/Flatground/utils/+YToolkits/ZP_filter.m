function filtered_data = ZP_filter(data_)

    if coder.target('MATLAB')
         data_ = reshape(data_,1,length(data_));
         data_fil_1 = doFilter2_mex( data_);
         data_fil_1_FP  = flip(data_fil_1);
         data_fil_2 = doFilter2_mex(data_fil_1_FP);
         filtered_data = flip(data_fil_2);
    else
        coder.cinclude('doFilter2.h');
        
        filtered_data = zeros(1, 100);
        
        coder.ceval('doFilter2.cpp' ...
            ,coder.wref(filtered_data) ...
            ,coder.rref(data_) );
    end




end