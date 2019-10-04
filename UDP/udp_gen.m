%% Add Paths
addpath(genpath(fullfile(fileparts(pwd),'agility-cassie-doc/Software')));

%% Create Buses
SlrtData = getSlrtDataStruct();
CassieSlrtDataBusInfo = Simulink.Bus.createObject(SlrtData);
CassieSlrtDataBus = eval(CassieSlrtDataBusInfo.busName);

LinuxData = getLinuxDataStruct();
CassieLinuxDataBusInfo = Simulink.Bus.createObject(LinuxData);
CassieLinuxDataBus = eval(CassieLinuxDataBusInfo.busName);

%% Run when buses change
generateBusPackingSystems;
generateUdpUserCode('gen');