function [q_s, status] = testHeelSpringIK(q_m, q_j)
  %TESTHEELSPRINGIK Test inverse kinematics NLS solver
  %
  % Syntax:
  %   [q_s, status] = testHeelSpringIK(q_m, q_j)
  %
  % Description:
  %   Formulates the inverse kinematics problem as a nonlinear least squares
  %   optimization problem.
  
  % Copyright 2016-2018 Agility Robotics
  
  % Construct the inverse kinematics function
  heelSpringIKFunction = HeelSpringIKFunction;
  
  % Construct the nonlinear least squares problem
  heelSpringIKProblem = NonlinearLeastSquaresProblem(...
    heelSpringIKFunction, repmat(-pi/4, 2, 1), repmat(pi/4, 2, 1));
  
  % Construct the nonlinear least squares solver
  heelSpringIKSolver = NonlinearLeastSquaresSolver(heelSpringIKProblem);
  heelSpringIKSolver.setIterationLimit(5);
  heelSpringIKSolver.setGTolerance(sqrt(eps));
  heelSpringIKSolver.setXTolerance(sqrt(eps));
  
  % Check the number of input arguments
  if nargin == 0
    % Define the motor and joint positions
    q_m = [0; 0; 0.52; -1.196; -1.62; 0; 0; 0.52; -1.196; -1.62];
    q_j = [0 - 0.1; 1.423 + 0.2; -1.62; 0 - 0.1; 1.423 + 0.2; -1.62];
  end % if
  
  % Update the desired foot transforms in the inverse kinematics problem
  heelSpringIKFunction.motorPosition = q_m;
  heelSpringIKFunction.jointPosition = q_j;
  
  % Solve the problem
  heelSpringIKSolver.solve;
  
  % Get the solver status
  status = heelSpringIKSolver.getStatus;
  
  % Get the solver solution
  q_s = heelSpringIKSolver.getSolution;
  
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
  tree.getJointByName('left-hip-roll-joint').setPosition(q_m(1));
  tree.getJointByName('left-hip-yaw-joint').setPosition(q_m(2));
  tree.getJointByName('left-hip-pitch-joint').setPosition(q_m(3));
  tree.getJointByName('left-knee-joint').setPosition(q_m(4));
  tree.getJointByName('left-foot-joint').setPosition(q_m(5));
  tree.getJointByName('left-foot-crank-joint').setPosition(q_m(5));
  tree.getJointByName('left-shin-joint').setPosition(q_j(1));
  tree.getJointByName('left-tarsus-joint').setPosition(q_j(2));
  tree.getJointByName('left-knee-spring-joint').setPosition(q_j(1));
  tree.getJointByName('left-heel-spring-joint').setPosition(q_s(1));
  tree.getJointByName('right-hip-roll-joint').setPosition(q_m(6));
  tree.getJointByName('right-hip-yaw-joint').setPosition(q_m(7));
  tree.getJointByName('right-hip-pitch-joint').setPosition(q_m(8));
  tree.getJointByName('right-knee-joint').setPosition(q_m(9));
  tree.getJointByName('right-foot-joint').setPosition(q_m(10));
  tree.getJointByName('right-foot-crank-joint').setPosition(q_m(10));
  tree.getJointByName('right-shin-joint').setPosition(q_j(4));
  tree.getJointByName('right-tarsus-joint').setPosition(q_j(5));
  tree.getJointByName('right-knee-spring-joint').setPosition(q_j(4));
  tree.getJointByName('right-heel-spring-joint').setPosition(q_s(2));
  
  % Update visualization
  tree.draw;
end % testHeelSpringIK
