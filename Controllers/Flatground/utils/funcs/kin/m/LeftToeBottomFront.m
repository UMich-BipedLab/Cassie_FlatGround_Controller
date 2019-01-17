function [output1] = LeftToeBottomFront(var1)
    if coder.target('MATLAB')
        [output1] = LeftToeBottomFront_mex(var1);
    else
        coder.cinclude('LeftToeBottomFront_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('LeftToeBottomFront_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
