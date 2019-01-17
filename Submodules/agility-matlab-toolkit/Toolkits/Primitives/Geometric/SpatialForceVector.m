% SPATIALFORCEVECTOR Implements a 6D spatial force vector object
% 
%  Syntax:
%    F = SpatialForceVector
%    F = SpatialForceVector.zero
%    F = SpatialForceVector.rand
%    F = SpatialForceVector.randn
%    F = SpatialForceVector(spatialVector)
%    F = SpatialForceVector(rotational, translational)
%    F = SpatialForceVector(nx, ny, nz, fx, fy, fz)
% 
%  where,
%    spatialVector = A 6x1 numeric vector [nx; ny; nz; fx; fy; fz]
%    rotational = A scalar Vector3d
%    translational = A scalar Vector3d
%    nx, ny, nz, fx, fy, fz = Numeric scalars
%
%    Reference page in Doc Center
%       doc SpatialForceVector
%
%