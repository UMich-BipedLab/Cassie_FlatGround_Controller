%HEELSPRINGIKFUNCTION Inverse kinematics function

% Copyright 2016-2018 Agility Robotics

classdef HeelSpringIKFunction < Function %#codegen
  
  % PUBLIC PROPERTIES ==========================================================
  properties (Access = public)
    % Current motor positions
    motorPosition
    % Current joint positions
    jointPosition
  end % public properties
  
  % PUBLIC METHODS =============================================================
  methods (Access = public)
    function obj = HeelSpringIKFunction
      %HEELSPRINGIKFUNCTION Construct inverse kinematics function
      
      % Set code generation settings
      coder.allowpcode('plain');
      
      % Call superclass constructor
      obj = obj@Function('Heel Spring IK', 2, 2);
      
      % Initialize desired hand position vectors
      obj.motorPosition = zeros(10,1);
      obj.jointPosition = zeros(6,1);
    end % HeelSpringIKFunction
    
    function [f, J] = evaluate(obj, q)
      %EVALUATE Evaluate inverse kinematics error and Jacobian
      
      % Extract motor and joint positions
      q_m = obj.motorPosition;
      q_j = obj.jointPosition;
      
      % Compute current forward kinematics
      [g_l, G_l] = generatedLeftLegConstraints(q_m(1:5), q_j(1:2), q(1));
      [g_r, G_r] = generatedRightLegConstraints(q_m(6:10), q_j(4:5), q(2));
      
      % Compute inverse kinematics objective and Jacobian
      f = [...
        g_l; ...
        g_r];
      J = blkdiag(...
        G_l(:,end), ...
        G_r(:,end));
    end % evaluate
  end % public methods
end % classdef
