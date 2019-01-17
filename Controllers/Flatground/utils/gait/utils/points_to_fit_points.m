function [ points_fit,dpoints_fit,alpha_fit ] = points_to_fit_points( points,dpoints,Tp,M )
% fit original points with bezier curve, get the fit points
s = linspace(0,1,size(points,2));
alpha_fit = points_to_bc_v3( points,dpoints,Tp,M );
points_fit = YToolkits.bezier(alpha_fit,s);
dpoints_fit = YToolkits.dbezier(alpha_fit,s)/Tp;

end

