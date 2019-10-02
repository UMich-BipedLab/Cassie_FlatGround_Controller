function [output1] = ComPosition(var1)
    if coder.target('MATLAB')
        [output1] = ComPosition_mex(var1);
    else
        coder.cinclude('ComPosition_src.h');
        
        output1 = zeros(1, 3);

        
        coder.ceval('ComPosition_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
