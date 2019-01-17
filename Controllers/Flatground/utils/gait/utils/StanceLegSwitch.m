function h_switch = StanceLegSwitch( h )
% This function is useful only for certain output
h_switch = zeros(size(h));
h_switch = h([6 7 8 9 10 1 2 3 4 5],:);
h_switch([1,2,6,7],:) = -h_switch([1,2,6,7],:);
end

