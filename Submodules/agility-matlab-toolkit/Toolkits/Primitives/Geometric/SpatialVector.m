% SPATIALVECTOR Abstract class for implementing 6D spatial vectors
% 
%  Syntax:
%    V = SpatialVector
%    V = SpatialVector.zero
%    V = SpatialVector.rand
%    V = SpatialVector.randn
%    V = SpatialVector(spatialVector)
%    V = SpatialVector(rotational, translational)
%    V = SpatialVector(rx, ry, rz, tx, ty, tz)
% 
%  where,
%    spatialVector = A 6x1 numeric vector [rx; ry; rz; tx; ty; tz]
%    rotational = A scalar Vector3d
%    translational = A scalar Vector3d
%
%    Reference page in Doc Center
%       doc SpatialVector
%
%