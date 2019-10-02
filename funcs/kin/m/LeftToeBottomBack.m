function [output1] = LeftToeBottomBack(var1)
    if coder.target('MATLAB')
        [output1] = LeftToeBottomBack_mex(var1);
    else
        coder.cinclude('LeftToeBottomBack_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('LeftToeBottomBack_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
