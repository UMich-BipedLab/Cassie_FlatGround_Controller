function [output1] = RightToeBottom(var1)
    if coder.target('MATLAB')
        [output1] = RightToeBottom_mex(var1);
    else
        coder.cinclude('RightToeBottom_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('RightToeBottom_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
