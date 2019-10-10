%PROCESSUDPPACKET Process incoming UDP packet
%
% Processes latency measurement headers on the incoming data. Produces the
% header for the outgoing packet.
%
% Monitors the time interval between received packets. If the time since the
% last valid packet is greater than the heartbeat interval, the data bytes are
% zeroed out.

% Copyright 2018 Agility Robotics

classdef ProcessUdpPacket < ...
    matlab.System & ...
    matlab.system.mixin.Propagates & ...
    matlab.system.mixin.SampleTime %#codegen
  
  % NONTUNABLE PROPERTIES ======================================================
  properties (Nontunable)
    % Maximum allowed time between incoming UDP packets [s]
    heartbeatInterval = 0.01
    % Number of bytes in header
    HeaderLength = 2
    % Number of bytes in the incoming CassieLinuxData data
    CassieLinuxDataLength = 0
  end % nontunable properties
  % PROTECTED PROPERTIES =======================================================
  properties (Access = protected)
    % Sequence number for outgoing packets
    seqNumOut
    % Sequence number from last incoming packet
    seqNumInLast
    % Number of cycles since last new packet recieved
    newPacketTimer
    % Bytes from last valid packet received
    lastValidUdpData
    % Total data length
    totalDataLength
    % Flag indicating whether or not 2-way communication has begun
    first_packet_received = false;
    % Counter that increments when a communication timeout was detected
    timeout = 0;
  end % properties
  
  % PROTECTED METHODS ==========================================================
  methods (Access = protected)
    % SYSTEM CLASS METHODS =====================================================
    function setupImpl(obj)
      %SETUPIMPL Initialize System object
      
      % Initialize properties
      obj.seqNumOut = int32(0);
      obj.seqNumInLast = int32(0);
      obj.newPacketTimer = 0;
      obj.totalDataLength = 2 + obj.CassieLinuxDataLength;
      obj.lastValidUdpData = uint8(zeros(obj.totalDataLength, 1));
    end % setupImpl
    
    function [udpLog, headerOut, linuxData, timeout] = stepImpl(obj, udpData, recieveLength)
      %STEPIMPL System output and state update equations
      
      if recieveLength == obj.totalDataLength
        % Received packet correctly sized for header + data
        obj.newPacketTimer = 0;
        obj.lastValidUdpData = udpData;
        obj.first_packet_received = true;
      else
        % No new packet received or received bad packet
        obj.newPacketTimer = obj.newPacketTimer + 1;
        udpData = obj.lastValidUdpData(1:length(udpData));
      end % if
      
      % If no new packets are received within the heartbeat interval, set the
      % incoming data bytes to zero
      packetInterval = obj.newPacketTimer * obj.getSampleTime.SampleTime;
      if packetInterval > obj.heartbeatInterval
        udpData = udpData * 0;
        if (obj.first_packet_received)
            obj.timeout = obj.timeout + 1;
        end
      end % if
      
      % Split off header and data
      headerIn = udpData(1:2);
      linuxData = udpData(3:end); 
      
      % Increment sequence number and perform rollover
      obj.seqNumOut = mod(obj.seqNumOut + 1, 2^8);
      
      % First header element is the sequence number of the incoming packet
      seqNumIn = int32(headerIn(1));
      
      % Second header element is the sequence number of a packet sent by this
      % computer, looped back by the other computer
      loopback = int32(headerIn(2));
      
      % Measure round-trip delay using the loopback
      delay = mod(obj.seqNumOut - loopback, 2^8);
      
      % Measure difference from last incoming sequence number
      seqNumInDiff = mod(seqNumIn - obj.seqNumInLast, 2^8);
      obj.seqNumInLast = seqNumIn;
      
      % Log delay and incoming sequence number diff
      udpLog = uint8([delay; seqNumInDiff]);
      
      % Construct outgoing packet header
      headerOut = uint8([obj.seqNumOut; seqNumIn]);
      
      % Output timeout flag
      timeout = obj.timeout;
      
    end % stepImpl
    
    function resetImpl(~)
      %RESETIMPL Reset System object states
    end % resetImpl
    
    function [name_1, name_2] = getInputNamesImpl(~)
      %GETINPUTNAMESIMPL Return input port names for System block
      name_1 = 'UDP Data';
      name_2 = 'Length';
    end % getInputNamesImpl
    
    function [name_1, name_2, name_3, name_4] = getOutputNamesImpl(~)
      %GETOUTPUTNAMESIMPL Return output port names for System block
      name_1 = 'Log';
      name_2 = 'Header';
      name_3 = 'LinuxData';
      name_4 = 'timeout';
    end % getOutputNamesImpl
    
    % PROPAGATES CLASS METHODS =================================================
    function [sz_1, sz_2, sz_3, sz_4] = getOutputSizeImpl(obj)
      %GETOUTPUTSIZEIMPL Get sizes of output ports
      sz_1 = [2, 1];
      sz_2 = [2, 1];
      sz_3 = [obj.CassieLinuxDataLength, 1];
      sz_4 = [1, 1];
    end % getOutputSizeImpl
    
    function [dt_1, dt_2, dt_3, dt_4] = getOutputDataTypeImpl(~)
      %GETOUTPUTDATATYPEIMPL Get data types of output ports
      dt_1 = 'uint8';
      dt_2 = 'uint8';
      dt_3 = 'uint8';
      dt_4 = 'double';
    end % getOutputDataTypeImpl
    
    function [cp_1, cp_2, cp_3, cp_4] = isOutputComplexImpl(~)
      %ISOUTPUTCOMPLEXIMPL Complexity of output ports
      cp_1 = false;
      cp_2 = false;
      cp_3 = false;
      cp_4 = false;
    end % isOutputComplexImpl
    
    function [flag_1, flag_2, flag_3, flag_4] = isOutputFixedSizeImpl(~)
      %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports
      flag_1 = true;
      flag_2 = true;
      flag_3 = true;
      flag_4 = true;
    end % isOutputFixedSizeImpl
  end % methods
end % classdef
