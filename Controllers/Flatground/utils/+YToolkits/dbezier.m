function fcn = dbezier(coeff,s)

  dcoeff = YToolkits.diff_coeff(coeff);
	fcn = YToolkits.bezier(dcoeff,s);