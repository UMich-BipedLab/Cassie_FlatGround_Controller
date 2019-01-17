function [output1] = RightToeBottomFront(var1)
    if coder.target('MATLAB')
        [output1] = RightToeBottomFront_mex(var1);
    else
        coder.cinclude('RightToeBottomFront_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('RightToeBottomFront_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
