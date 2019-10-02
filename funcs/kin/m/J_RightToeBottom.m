function [output1] = J_RightToeBottom(var1)
    if coder.target('MATLAB')
        [output1] = J_RightToeBottom_mex(var1);
    else
        coder.cinclude('J_RightToeBottom_src.h');
        
        output1 = zeros(3, 20);

        
        coder.ceval('J_RightToeBottom_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
