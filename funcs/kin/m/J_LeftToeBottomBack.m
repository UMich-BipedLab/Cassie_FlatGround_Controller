function [output1] = J_LeftToeBottomBack(var1)
    if coder.target('MATLAB')
        [output1] = J_LeftToeBottomBack_mex(var1);
    else
        coder.cinclude('J_LeftToeBottomBack_src.h');
        
        output1 = zeros(3, 20);

        
        coder.ceval('J_LeftToeBottomBack_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
