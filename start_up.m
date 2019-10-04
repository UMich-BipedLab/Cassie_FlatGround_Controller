%STARTUP Startup routine for Cassie project.

% Copyright 2017 Mikhail S. Jones

% Get project root location
projectRoot = fileparts(mfilename('fullpath'));
restoredefaultpath;
% Construct paths to cache and code folders
myCacheFolder = fullfile(projectRoot, 'Build', 'Cache');
myCodeFolder = fullfile(projectRoot, 'Build', 'Code');


removefolder = true;
if (removefolder == true) && exist(myCacheFolder, 'dir') 
    rmdir(myCacheFolder, 's')
end

if (removefolder == true) && exist(myCodeFolder, 'dir') 
    rmdir(myCodeFolder, 's')
end
    

if ~exist(myCacheFolder, 'dir') 
    mkdir(myCacheFolder);
end


if ~exist(myCodeFolder, 'dir') 

    mkdir(myCodeFolder);

end


% Set the file generation folder paths
Simulink.fileGenControl('set',...
    'CacheFolder', myCacheFolder,...
    'CodeGenFolder', myCodeFolder,...
    'createDir', true);

root_dir = pwd;
% Add all subfolders to MATLAB path
addpath(genpath('./'));
addpath(genpath('../UDP/'));

% cd(fullfile(projectRoot, 'Controllers', 'Yukai'))