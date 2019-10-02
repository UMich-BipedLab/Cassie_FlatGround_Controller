function [output1] = RightToeBottomBack(var1)
    if coder.target('MATLAB')
        [output1] = RightToeBottomBack_mex(var1);
    else
        coder.cinclude('RightToeBottomBack_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('RightToeBottomBack_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
