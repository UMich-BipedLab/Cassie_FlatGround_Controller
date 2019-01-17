function [output1] = LeftToeJoint(var1)
    if coder.target('MATLAB')
        [output1] = LeftToeJoint_mex(var1);
    else
        coder.cinclude('LeftToeJoint_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('LeftToeJoint_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
