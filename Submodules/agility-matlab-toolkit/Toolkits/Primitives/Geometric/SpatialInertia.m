% SPATIALINERTIA Implements a spatial inertia object
% 
%  Syntax:
%    M = SpatialInertia
%    M = SpatialInertia.zero
%    M = SpatialInertia.rand
%    M = SpatialInertia(m, c, I)
% 
%  where,
%    m = Scalar mass of the body
%    c = Position of center of mass in output coordinates
%    I = Rotational inertia taken at center of mass and aligned with body
% 
%  Description:
%    This class describes the spatial mass or inertia of a body. This includes
%    the mass of the body, the location of the center of mass, and it's
%    rotational inertia.
%
%    Reference page in Doc Center
%       doc SpatialInertia
%
%