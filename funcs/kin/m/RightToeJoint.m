function [output1] = RightToeJoint(var1)
    if coder.target('MATLAB')
        [output1] = RightToeJoint_mex(var1);
    else
        coder.cinclude('RightToeJoint_src.h');
        
        output1 = zeros(3, 1);

        
        coder.ceval('RightToeJoint_src' ...
            ,coder.wref(output1) ...
            ,coder.rref(var1) );
    end
end
