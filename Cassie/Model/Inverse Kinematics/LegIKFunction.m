%LEGIKFUNCTION Inverse kinematics function

% Copyright 2016-2018 Agility Robotics

classdef LegIKFunction < Function %#codegen
  
  % PUBLIC PROPERTIES ==========================================================
  properties (Access = public)
    % Desired left foot transformation
    leftFootTransform
    % Desired right foot transformation
    rightFootTransform
  end % public properties
  
  % PUBLIC METHODS =============================================================
  methods (Access = public)
    function obj = LegIKFunction
      %LEGIKFUNCTION Construct inverse kinematics function
      
      % Set code generation settings
      coder.allowpcode('plain');
      
      % Call superclass constructor
      obj = obj@Function('Leg IK', 10, 10);
      
      % Initialize desired hand position vectors
      obj.leftFootTransform = Transform3d;
      obj.rightFootTransform = Transform3d;
    end % LegIKFunction
    
    function [f, J] = evaluate(obj, q)
      %EVALUATE Evaluate inverse kinematics error and Jacobian
      
      % Parse state vector into left/right portions
      qm_l = q(1:5);
      qm_r = q(6:10);
      
      % Compute joint states by assuming zero deflection in the springs
      qj_l = [0; 13*pi/180 - qm_l(4)];
      qj_r = [0; 13*pi/180 - qm_r(4)];
      
      % Compute current forward kinematics
      [T_l, J_l] = generatedLeftLegKinematics(qm_l, qj_l);
      [T_r, J_r] = generatedRightLegKinematics(qm_r, qj_r);
      
      % Compute the motor Jacobian with the achilles rod constraint
      Jm_l = [J_l(:,1:3), J_l(:,4) - J_l(:,7), J_l(:,5)];
      Jm_r = [J_r(:,1:3), J_r(:,4) - J_r(:,7), J_r(:,5)];
      
      % Compute spatial difference between transforms
      e_l = getValue(diff(obj.leftFootTransform, Transform3d(T_l)));
      e_r = getValue(diff(obj.rightFootTransform, Transform3d(T_r)));
      
      % Define indices for objective
      ind = [2 3 4 5 6];
      
      % Compute inverse kinematics objective and Jacobian
      f = [...
        e_l(ind); ...
        e_r(ind)];
      J = blkdiag(Jm_l(ind,:), Jm_r(ind,:));
    end % evaluate
  end % public methods
end % classdef
