PreFunctions.ParamInit;
PreFunctions.FilterInit;
UserParams.SampleTime = 1/2000;
% Create Data Bus
Data = PreFunctions.Construct_Data;
cassieDataBusInfo = Simulink.Bus.createObject(Data);
cassieDataBus = eval(cassieDataBusInfo.busName);

% Create GaitLibrary Bus
% GL = load('GaitLibrary_2D_Velocity_FootHeight_v1.mat');  % desired trajectories
% GL = load('GaitLibrary_LIP_v2.mat');  % desired trajectories
GL = load('GaitLibrary_LIP_v7.mat');
GaitLibrary = GL.GaitLibrary_output;

cassieGaitLibraryBusInfo = Simulink.Bus.createObject(GaitLibrary);
cassieGaitLibraryBus = eval(cassieGaitLibraryBusInfo.busName);


% GL = load('GaitLibrary_2D_Velocity_FootHeight_v1.mat');  % desired trajectories
GL2 = load('GaitLibrary_output_v1.mat');
GaitLibrary2 = GL2.GaitLibrary_output;
cassieGaitLibraryBusInfo2 = Simulink.Bus.createObject(GaitLibrary2);
cassieGaitLibraryBus2 = eval(cassieGaitLibraryBusInfo2.busName);

% Create UDP data Bus
SlrtData = getSlrtDataStruct();
CassieSlrtDataBusInfo = Simulink.Bus.createObject(SlrtData);
CassieSlrtDataBus = eval(CassieSlrtDataBusInfo.busName);

LinuxData = getLinuxDataStruct();
CassieLinuxDataBusInfo = Simulink.Bus.createObject(LinuxData);
CassieLinuxDataBus = eval(CassieLinuxDataBusInfo.busName);

% fname = which('all_buses.m');
% delete(fname)
% Simulink.Bus.save([root_dir '\all_buses.m'])