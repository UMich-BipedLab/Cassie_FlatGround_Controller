tg = slrt;
% sc1 = getscope(tg,1);
sc5 = getscope(tg,5);
% scope_object_vector = stop(sc1);
scope_object_vector = stop(sc5);


%% Create folder
clk = clock;
date_str = [num2str(clk(1)),'-',num2str(clk(2)),'-',num2str(clk(3))];
time_str = [num2str(clk(4)),'-',num2str(clk(5))];
save_path = [root_dir,'/ExpLog/',date_str,'/',time_str,'/'];
mkdir(save_path)
cd(save_path)

%% copy the dat files from target computer
% SimulinkRealTime.copyFileToHost(tg, ['CASSIE02.dat'])
SimulinkRealTime.copyFileToHost(tg, ['DATA1.dat'])
% SimulinkRealTime.copyFileToHost(tg, ['DATA2.dat'])
% SimulinkRealTime.copyFileToHost(tg, ['DATA3.dat'])
% SimulinkRealTime.copyFileToHost(tg, ['DATA4.dat'])
%% Parse Data.dat
% DataMatrix1 = SimulinkRealTime.utils.getFileScopeData('DATA1.dat');
% DataMatrix2 = SimulinkRealTime.utils.getFileScopeData('DATA2.dat');
% DataMatrix3 = SimulinkRealTime.utils.getFileScopeData('DATA3.dat');
% DataMatrix.data = [DataMatrix1.data;DataMatrix2.data;DataMatrix3.data];
% DataMatrix.data = [DataMatrix1.data;DataMatrix2.data];
DataMatrix = SimulinkRealTime.utils.getFileScopeData('DATA1.dat');

DataBusSelectorName = 'Data Bus Selector';

%
% mdl = char(tg.Application);
mdl = 'FG_RealTime';
sys = get_param(mdl, 'Handle');
BusSelectors = find_system(sys,'FollowLinks','on','SearchDepth',10,'BlockType','BusSelector');

% Find the bus selector
index = 1;
signal_names = cell(1,1);
DataBusSelectorIndex =[];

for i = 1:length(BusSelectors)
    if strcmp(DataBusSelectorName, char(get_param(BusSelectors(i), 'Name')))
        DataBusSelectorIndex = [DataBusSelectorIndex i];
    end
end
if length(DataBusSelectorIndex) > 1
    error('There are more than one Bus Selector named ''Data Bus Selector''')
elseif length(DataBusSelectorIndex) < 1
    error('There is no Bus Selector named ''Data Bus Selector''')
end

% Find the name of signals in the data bus selector
ph = get_param(BusSelectors(DataBusSelectorIndex), 'PortHandles');
sh = get_param(ph.Inport, 'SignalHierarchy');
for j = 1:length(ph.Outport)
    signal_name = get_param(ph.Outport(j), 'Name');
    signal_name = strrep(signal_name, '<', '');
    signal_name = strrep(signal_name, '>', '');
    signal_names{index} = signal_name;
    index = index + 1;
end


% Find the corresponding bus in all_buses()
all_bus_data = all_buses();
for i = 1:length(all_bus_data)
    bus_name = all_bus_data{i}{1};
    if strcmp(sh.BusObject, bus_name)
       BusIndex = i;
    end
end
DataBus = all_bus_data{BusIndex};
DataBusSignals = DataBus{6};
% Parse data.dat and store using signal names
signal_column_index_begin = 0;
signal_column_index_end = 0;
for i = 1:length(signal_names)
    for j = 1:length(DataBusSignals)
        if strcmp(signal_names{i}, DataBusSignals{j}{1})
            dims = DataBusSignals{j}{2};
            signal_column_index_begin = signal_column_index_end+1;
            signal_column_index_end = signal_column_index_end + dims(1);
            log.Data.(DataBusSignals{j}{1}) = DataMatrix.data(:,signal_column_index_begin:signal_column_index_end);
        end
    end
end
log.Data.t = DataMatrix.data(:,end);

%% Save log
user_input = inputdlg({'Date/Time','Setup','Results'}, 'Data Log', ...
    [1 20; 3 50; 3 50], ...
    {[date_str,'-',time_str],'',''});

log.description.DateTime = user_input{1};
log.description.Setup = user_input{2};
log.description.Results = user_input{3};
% save('Log', 'log') 
save('Log', 'log', '-v7.3')
% cd(root_dir);
%%
% Define intial pelvis state
% pelvisPosition = [0; 0; 1.2];
% pelvisVelocity = [0; 0; 0];
% pelvisRotation = Rotation3d.identity.getValue;
% pelvisAngularVelocity = [0; 0; 0];
% 
% % Define initial motor states
% figure;
% motorPositions = testLegIK;
% motorVelocities = zeros(10,1);
% close(gcf);