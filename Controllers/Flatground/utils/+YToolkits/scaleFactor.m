function s = scaleFactor(f, tl, tu)
	%SCALEFACTOR Compute scalar (0 to 1) representing forces in leg.

	s = (clamp(f, tl, tu) - tl)/(tu - tl);
end % scaleFactor