% RADIOBUTTONMAP Radio controller button mapping
% 
%  Description:
%    Enumeration of the button mapping on the Taranis X9D. The radio returns a
%    16-element vector representing the state of each button/joystick. This
%    enumeration makes indexing into the correct channel corresponding to the
%    desired button simple and readable. For example, to get the state of the
%    left vertical joystick requires the following code
% 
%      state = radioChannel(RadioButtonMap.LV);
%
%    Reference page in Doc Center
%       doc RadioButtonMap
%
%