function [output1] = J_RightToeBottomFront(var1)
    if coder.target('MATLAB')
        [output1] = J_RightToeBottomFront_mex(var1);
    else
        coder.cinclude('J_RightToeBottomFront_src.h');
        
        output1 = zeros(3, 20);

        
        coder.ceval('J_RightToeBottomFront_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
