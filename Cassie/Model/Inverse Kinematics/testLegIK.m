function [q, status] = testLegIK(leftFootTransform, rightFootTransform)
  %TESTLEGIK Test inverse kinematics NLS solver
  %
  % Syntax:
  %   [q, status] = testLegIK(leftFootTransform, rightFootTransform)
  %
  % Description:
  %   Formulates the inverse kinematics problem as a nonlinear least squares
  %   optimization problem with joint limit constraints.
  
  % Copyright 2016-2018 Agility Robotics
  
  % Get the motor position limits
  lowerBound = CassieCore.motorPositionLowerLimit;
  upperBound = CassieCore.motorPositionUpperLimit;
  
  % Construct the inverse kinematics function
  legIKFunction = LegIKFunction;
  
  % Construct the nonlinear least squares problem
  legIKProblem = NonlinearLeastSquaresProblem(...
    legIKFunction, lowerBound, upperBound);
  
  % Construct the nonlinear least squares solver
  legIKSolver = NonlinearLeastSquaresSolver(legIKProblem);
  legIKSolver.setIterationLimit(10);
  legIKSolver.setGTolerance(eps);
  legIKSolver.setXTolerance(eps);
  
  % Check the number of input arguments
  if nargin == 0
    % Define the desired foot positions
    leftFootTransform = Transform3d(Vector3d(0, 0.135, -1));
    rightFootTransform = Transform3d(Vector3d(0, -0.135, -1));
  end % if
  
  % Update the desired foot transforms in the inverse kinematics problem
  legIKFunction.leftFootTransform = leftFootTransform;
  legIKFunction.rightFootTransform = rightFootTransform;
  
  % Solve the problem
  legIKSolver.solve;
  
  % Get the solver status
  status = legIKSolver.getStatus;
  
  % Get the solver solution
  q = legIKSolver.getSolution;
  
  % Initialize multi body tree structure
  tree = MultiBodyTree.fromDescriptor(CassieDescriptor);
  
  % Remove connecting rods from visualization
  tree.getBodyByName('left-achilles-rod').isVisible = false;
  tree.getEndEffectorByName('left-achilles-rod-end').isVisible = false;
  tree.getBodyByName('left-plantar-rod').isVisible = false;
  tree.getEndEffectorByName('left-plantar-rod-end').isVisible = false;
  tree.getBodyByName('right-achilles-rod').isVisible = false;
  tree.getEndEffectorByName('right-achilles-rod-end').isVisible = false;
  tree.getBodyByName('right-plantar-rod').isVisible = false;
  tree.getEndEffectorByName('right-plantar-rod-end').isVisible = false;
  
  % Update multi body tree joint positions
  tree.getJointByName('left-hip-roll-joint').setPosition(q(1));
  tree.getJointByName('left-hip-yaw-joint').setPosition(q(2));
  tree.getJointByName('left-hip-pitch-joint').setPosition(q(3));
  tree.getJointByName('left-knee-joint').setPosition(q(4));
  tree.getJointByName('left-foot-joint').setPosition(q(5));
  tree.getJointByName('left-foot-crank-joint').setPosition(q(5));
  tree.getJointByName('left-shin-joint').setPosition(0);
  tree.getJointByName('left-tarsus-joint').setPosition(-q(4) + 13*pi/180);
  tree.getJointByName('right-hip-roll-joint').setPosition(q(6));
  tree.getJointByName('right-hip-yaw-joint').setPosition(q(7));
  tree.getJointByName('right-hip-pitch-joint').setPosition(q(8));
  tree.getJointByName('right-knee-joint').setPosition(q(9));
  tree.getJointByName('right-foot-joint').setPosition(q(10));
  tree.getJointByName('right-foot-crank-joint').setPosition(q(10));
  tree.getJointByName('right-shin-joint').setPosition(0);
  tree.getJointByName('right-tarsus-joint').setPosition(-q(9) + 13*pi/180);
  
  % Update visualization
  tree.draw;
  leftFootTransform.draw;
  rightFootTransform.draw;
end % testLegIK
