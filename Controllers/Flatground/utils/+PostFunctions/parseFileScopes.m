function log = parseFileScopes(tg, varargin)
%% 
%   Author: Ross Hartley
%   Date:   10/9/17
%

%% Read file scope files
if nargin < 1
    tg = xpc;
end
tg.stop();

% Parse inputs
p = inputParser;
p.addOptional('DataBusSelectorName','Data Bus Selector',@isstr);
p.addOptional('SavePath','./log/',@isstr);
p.addOptional('LogMessage',false);
p.addOptional('LogEnergy',false);
p.addOptional('LogInputs',false);
p.addOptional('LogOutputs',true);
p.addOptional('LogData',true);
p.addOptional('LogEKF',true);

p.parse(varargin{:});
results = p.Results;
DataBusSelectorName = results.DataBusSelectorName;
SavePath = results.SavePath;
LogMessage = results.LogMessage;
LogEnergy = results.LogEnergy;
LogInputs = results.LogInputs;
LogOutputs = results.LogOutputs;
LogData = results.LogData;
LogEKF = results.LogEKF;

% Attach to the target computer file system.
f = SimulinkRealTime.fileSystem;

% Open the file, read the data, close the file.
message = [];
energy = [];
inputs = [];
outputs = [];
data = [];

if LogMessage
    h = fopen(f,'message.dat');
    if h ~= -1
        message_raw = fread(f,h);
        f.fclose(h);
        message = SimulinkRealTime.utils.getFileScopeData(message_raw);
    end
end

if LogEnergy
    h = fopen(f,'energy.dat');
    if h ~= -1
        energy_raw = fread(f,h);
        f.fclose(h);
        energy = SimulinkRealTime.utils.getFileScopeData(energy_raw);
    end
end

if LogInputs
    h = fopen(f,'inputs.dat');
    if h ~= -1
        inputs_raw = fread(f,h);
        f.fclose(h);
        inputs = SimulinkRealTime.utils.getFileScopeData(inputs_raw);
    end
end

if LogOutputs
    h = fopen(f,'outputs.dat');
    if h ~= -1
        outputs_raw = fread(f,h);
        f.fclose(h);
        outputs = SimulinkRealTime.utils.getFileScopeData(outputs_raw);
    end
end

if LogData
    h = fopen(f,'data.dat');
    if h ~= -1
        data_raw = fread(f,h);
        f.fclose(h);
        data = SimulinkRealTime.utils.getFileScopeData(data_raw);
    end
end

ekf = [];
if LogEKF
    h = fopen(f,'ekf.dat');
    if h ~= -1
        ekf_raw = fread(f,h);
        f.fclose(h);
        ekf = SimulinkRealTime.utils.getFileScopeData(ekf_raw);
    end
end

% Create log structure
log = struct;


%% Parse Outputs
if ~isempty(outputs)
    log.outputs.t = outputs.data(:,end);
    log.outputs.vectorNavOrientation = outputs.data(:,1:4);
    log.outputs.vectorNavAngularVelocity = outputs.data(:,5:7);
    log.outputs.vectorNavLinearAcceleration = outputs.data(:,8:10);
    log.outputs.motorPosition = outputs.data(:,11:20);
    log.outputs.motorVelocity = outputs.data(:,21:30);
    log.outputs.jointPosition = outputs.data(:,31:34);
    log.outputs.jointVelocity = outputs.data(:,35:38);
    log.outputs.radio = outputs.data(:,39:54);
end


%% Parse Data
% Use Data Bus Selector to parse filescope data
if ~isempty(data)
    log.Data.t = data.data(:,end);
    
    all_bus_data = all_buses();
    mdl = char(tg.Application);
    sys = get_param(mdl, 'Handle');
    BusSelectors = find_system(sys,'FollowLinks','on','SearchDepth',10,'BlockType','BusSelector');
    
    % Extract logged signal names
    index = 1;
    signal_names = cell(1,1);
    for i = 1:length(BusSelectors)
        if strcmp(DataBusSelectorName, char(get_param(BusSelectors(i), 'Name')))
            ph = get_param(BusSelectors(i), 'PortHandles');
            sh = get_param(ph.Inport, 'SignalHierarchy');
            for j = 1:length(ph.Outport)
                signal_name = get_param(ph.Outport(j), 'Name');
                signal_name = strrep(signal_name, '<', '');
                signal_name = strrep(signal_name, '>', '');
                signal_names{index} = signal_name;
                index = index + 1;
            end
            break
        end
    end
    
    % Parse data.dat and store using signal names
    index = 1;
    signal_dimensions = length(signal_names);
    for i = 1:length(all_bus_data)
        bus_name = all_bus_data{i}{1};
        if strcmp(sh.BusObject, bus_name)
            for j = 1:length(all_bus_data{i}{6})
                if any(strcmp(all_bus_data{i}{6}{j}{1}, signal_names))
                    
                    dims = all_bus_data{i}{6}{j}{2};
                    signal_index = find(strcmp(all_bus_data{i}{6}{j}{1}, signal_names));
                    signal_dimensions(signal_index) = prod(dims); 
%                     log.Data.(all_bus_data{i}{6}{j}{1}) = data.data(:, index:index + prod(dims) - 1);
%                     index = index + prod(dims);
                end
            end
            for j = 1:length(all_bus_data{i}{6})
                if any(strcmp(all_bus_data{i}{6}{j}{1}, signal_names))
                    dims = all_bus_data{i}{6}{j}{2};
                    signal_index = find(strcmp(all_bus_data{i}{6}{j}{1}, signal_names));
                    log.Data.(all_bus_data{i}{6}{j}{1}) = data.data(:, sum(signal_dimensions(1:signal_index)) - signal_dimensions(signal_index) + 1 : sum(signal_dimensions(1:signal_index)));
                end
            end
        end
    end
end


%% Save Data
format shortg;
clk = clock;
date_str = [num2str(clk(1)),'-',num2str(clk(2)),'-',num2str(clk(3))];
time_str = [num2str(clk(4)),'-',num2str(clk(5))];

full_save_path = [SavePath,date_str,'/'];
listing = dir(full_save_path);
all_file_names = {listing.name};
indices = ~cellfun('isempty',strfind(all_file_names,'CassieData'));
data_files = all_file_names(indices);
exp_num = zeros(1,length(data_files));
for i = 1:length(data_files)
    [start_index, end_index] = regexp(data_files{i},'\d*');
    exp_num(i) = str2double(data_files{i}(start_index(1):end_index(1)));
end
max_exp_num = max(exp_num);
if isempty(max_exp_num)
    max_exp_num = 0;
end

user_input = inputdlg({'Experiment #','Date/Time','Setup','Results'}, 'Data Log', ...
    [1 13; 1 20; 3 50; 3 50], ...
    {num2str(max_exp_num+1),[date_str,'-',time_str],'',''});

if ~isempty(user_input)
    log.description.ExperimentNumber = user_input{1};
    log.description.DateTime = user_input{2};
    log.description.Setup = user_input{3};
    log.description.Results = user_input{4};
    
    if ~exist(full_save_path,'dir')
        mkdir(full_save_path);
    end
    
    save([full_save_path,'CassieData', '-Exp-', log.description.ExperimentNumber, '-DateTime-',log.description.DateTime], 'log')
end

end

