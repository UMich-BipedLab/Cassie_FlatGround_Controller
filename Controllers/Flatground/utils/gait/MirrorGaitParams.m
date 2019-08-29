function gaitLeft = MirrorGaitParams(gaitRight)
    gaitRight = reshape(gaitRight, 10, 6);
    
    gaitLeft = gaitRight;
    gaitLeft(1:5, :) = gaitRight(6:10, :);
    gaitLeft(6:10, :) = gaitRight(1:5, :);
    
    a = [-1, -1, 1, 1, 1, -1, -1, 1, 1, 1]';
    
    gaitLeft = a.*gaitLeft;
    
    gaitLeft = reshape(gaitLeft, 1, 60);
end
