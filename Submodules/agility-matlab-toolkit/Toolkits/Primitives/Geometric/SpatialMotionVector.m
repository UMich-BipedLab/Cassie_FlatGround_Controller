% SPATIALMOTIONVECTOR Implements a 6D spatial motion vector object
% 
%  Syntax:
%    V = SpatialMotionVector
%    V = SpatialMotionVector.zero
%    V = SpatialMotionVector.rand
%    V = SpatialMotionVector.randn
%    V = SpatialMotionVector(spatialVector)
%    V = SpatialMotionVector(rotational, translational)
%    V = SpatialMotionVector(wx, wy, wz, vx, vy, vz)
% 
%  where,
%    spatialVector = A 6x1 numeric vector [wx; wy; wz; vx; vy; vz]
%    rotational = A scalar Vector3d
%    translational = A scalar Vector3d
%    wx, wy, wz, vx, vy, vz = Numeric scalars
%
%    Reference page in Doc Center
%       doc SpatialMotionVector
%
%