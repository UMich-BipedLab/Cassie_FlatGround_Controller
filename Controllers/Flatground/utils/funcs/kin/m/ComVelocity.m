function [output1] = ComVelocity(var1,var2)
    if coder.target('MATLAB')
        [output1] = ComVelocity_mex(var1,var2);
    else
        coder.cinclude('ComVelocity_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('ComVelocity_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) ,coder.rref(var2) );
    end
end
