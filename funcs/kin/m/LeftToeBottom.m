function [output1] = LeftToeBottom(var1)
    if coder.target('MATLAB')
        [output1] = LeftToeBottom_mex(var1);
    else
        coder.cinclude('LeftToeBottom_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('LeftToeBottom_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
