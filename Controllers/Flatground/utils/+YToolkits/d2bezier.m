function fcn = d2bezier(coeff,s)

	dcoeff = YToolkits.diff_coeff(coeff);
	d2coeff = YToolkits.diff_coeff(dcoeff); 
	
	fcn = YToolkits.bezier(d2coeff,s);