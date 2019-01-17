function [ wrapped_angle ] = wrap2Pi( angle )
if angle > 0
    
rotation = fix((angle+pi)/(2*pi));
wrapped_angle = angle - 2*pi*rotation;
else
    rotation = fix((angle-pi)/(2*pi));
wrapped_angle = angle - 2*pi*rotation;
end
    

end

