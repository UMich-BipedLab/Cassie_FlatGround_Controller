function [Data] = getSlrtDataStruct(varargin)
%GETDATASTRUCTURE Summary of this function goes here
%   Detailed explanation goes here

Data = struct;
if nargin > 0
    if ischar(varargin{1}) && strcmp(varargin{1}, 'annotated')
        Data.busname_ = 'CassieSlrtDataBus';
        Data.cstructname_ = 'cassie_slrt_data_t';
        Data.outputs = CassieModule.getOutStruct('annotated');
    else
        error('Unrecognized input');
    end
else
   Data.outputs = CassieModule.getOutStruct(); 
end

Data.t = 0;

end

