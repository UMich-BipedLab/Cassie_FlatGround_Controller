function y = doFilter2(x)
%DOFILTER Filters input x and returns output y.

% MATLAB Code
% Generated by MATLAB(R) 9.3 and DSP System Toolbox 9.5.
% Generated on: 28-May-2019 11:23:45

%#codegen

% To generate C/C++ code from this function use the codegen command.
% Type 'help codegen' for more information.

persistent Hd;

if isempty(Hd)
    
    % The following code was used to design the filter coefficients:
    %
    % Fpass = 5;     % Passband Frequency
    % Fstop = 10;    % Stopband Frequency
    % Apass = 1;     % Passband Ripple (dB)
    % Astop = 80;    % Stopband Attenuation (dB)
    % Fs    = 2000;  % Sampling Frequency
    %
    % h = fdesign.lowpass('fp,fst,ap,ast', Fpass, Fstop, Apass, Astop, Fs);
    %
    % Hd = design(h, 'butter', ...
    %     'MatchExactly', 'stopband', ...
    %     'SystemObject', true);
    
    Hd = dsp.BiquadFilter( ...
        'Structure', 'Direct form II', ...
        'SOSMatrix', [1 2 1 1 -1.99616346197925 0.996452021461684; 1 2 1 1 ...
        -1.98925984173658 0.989547403252102; 1 2 1 1 -1.98285516002368 ...
        0.983141795697362; 1 2 1 1 -1.977217641326 0.977503462056666; 1 2 1 1 ...
        -1.97257906535629 0.972864215548143; 1 2 1 1 -1.96912712676391 ...
        0.969411777953736; 1 2 1 1 -1.96699974562219 0.967284089284092; 1 1 0 1 ...
        -0.983140587570102 0], ...
        'ScaleValues', [7.2139870607604e-05; 7.18903788798391e-05; ...
        7.16589184213885e-05; 7.14551826667048e-05; 7.12875479631187e-05; ...
        7.11627974563878e-05; 7.10859154759187e-05; 0.00842970621494907; 1]);
end
 

s = double(x);
y = step(Hd,s);

