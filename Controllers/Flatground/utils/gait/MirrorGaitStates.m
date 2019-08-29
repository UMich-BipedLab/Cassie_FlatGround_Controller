function gaitLeft = MirrorGaitStates(gaitRight)
    gaitLeft = gaitRight;
    gaitLeft.x(7:13) = gaitRight.x(14:20);
    gaitLeft.x(14:20) = gaitRight.x(7:13);
    gaitLeft.dx(7:13) = gaitRight.dx(14:20);
    gaitLeft.dx(14:20) = gaitRight.dx(7:13);
    gaitLeft.ddx(7:13) = gaitRight.ddx(14:20);
    gaitLeft.ddx(14:20) = gaitRight.ddx(7:13);
    
    a = [-1, -1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1]';
    
    gaitLeft.x(7:end, :) = a.*gaitLeft.x(7:end, :);
    gaitLeft.dx(7:end, :) = gaitLeft.dx(7:end, :);
    gaitLeft.ddx(7:end, :) = gaitLeft.ddx(7:end, :);
    
    gaitLeft.x(2, :) = -gaitLeft.x(2, :);
    gaitLeft.x([4, 6], :) = -gaitLeft.x([4, 6], :);
    gaitLeft.dx(2, :) = -gaitLeft.dx(2, :);
    gaitLeft.dx([4, 6], :) = -gaitLeft.dx([4, 6], :);
    gaitLeft.ddx(2, :) = -gaitLeft.ddx(2, :);
    gaitLeft.ddx([4, 6], :) = -gaitLeft.ddx([4, 6], :);
end
