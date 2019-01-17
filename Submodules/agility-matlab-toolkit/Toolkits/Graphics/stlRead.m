% STLREAD Read STL binary file
% 
%  Syntax:
%    [faces, vertices, name] = stlRead(fileName)
% 
%  Description:
%    This functions reads binary STL files and returns a list of faces and
%    vertices.
% 
%  Notes:
%    - STL Binary Header
%      - UINT8[80] - Header/title
%      - UINT32[1] - Number of facets
% 
%    - For each facet
%      - FLOAT32[3] - Normal vector
%      - FLOAT32[3] - Vertex 1
%      - FLOAT32[3] - Vertex 2
%      - FLOAT32[3] - Vertex 3
%      - UINT16[1] - Attribute byte
%