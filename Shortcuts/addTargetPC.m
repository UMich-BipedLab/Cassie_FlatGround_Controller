%ADDTARGETPC Add target PC settings to SLRT Explorer
%
% Syntax:
%   addTargetPC
%
% Description:
%   Add the target PC settings to the Simulink Real-Time Explorer.
%
% Notes:
%   - https://www.mathworks.com/help/xpc/ug/command-line-pci-bus-ethernet-setup-multiple-target-computers.html
%   - https://www.mathworks.com/help/xpc/ug/ethernet-card-selection-by-ethernet-index.html
%   - EthernetIndex: 0, Driver: I8254x, Bus: 3, Slot: 0 (Host)
%   - EthernetIndex: 1, Driver: I8254x, Bus: 4, Slot: 0 (EtherCAT)

% Copyright 2016-2018 Agility Robotics

% Add target to Simulink Real-Time
try
  target = SimulinkRealTime.addTarget('CassieV3');
catch
  target = SimulinkRealTime.getTargetSettings('CassieV3');
end

% Host-to-Target communication
target.TcpIpTargetAddress = '10.10.10.3';
target.TcpIpTargetPort = '22222';
target.TcpIpSubnetMask = '255.255.255.0';
target.TcpIpGateway = '255.255.255.255';
target.TcpIpTargetDriver = 'Auto';
target.TcpIpTargetBusType = 'PCI';
target.EthernetIndex = '0';

% Target settings
target.TargetRAMSizeMB = 'Auto';
target.LegacyMultiCoreConfig = 'on';
target.USBSupport = 'on';
target.ShowHardware = 'off';
target.TargetScope = 'Disabled';

% Boot configuration
target.TargetBoot = 'StandAlone';
