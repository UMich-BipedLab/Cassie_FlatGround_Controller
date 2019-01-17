function b = clamp(a, lim1, lim2)
	%CLAMP Clamp value between two bounds.

	% Find which limit is min and max
	a_min = min(lim1, lim2);
	a_max = max(lim1, lim2);

	% Clamp value between limits
	b = max(min(a, a_max), a_min);
end % clamp