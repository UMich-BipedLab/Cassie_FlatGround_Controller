/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:24 GMT-04:00
 */

#ifndef LEFTTOEJOINT_MEX_HH
#define LEFTTOEJOINT_MEX_HH

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE


#include "math2mat.hpp"
#include "mdefs.hpp"

namespace SymExpression
{

  void LeftToeJoint_mex_raw(double *p_output1, const double *var1);

  inline void LeftToeJoint_mex(Eigen::MatrixXd &p_output1, const Eigen::VectorXd &var1)
  {
    // Check
    // - Inputs
    assert_size_matrix(var1, 20, 1);

	
    // - Outputs
    assert_size_matrix(p_output1, 3, 1);


    // set zero the matrix
    p_output1.setZero();


    // Call Subroutine with raw data
    LeftToeJoint_mex_raw(p_output1.data(), var1.data());
    }
  
  
}

#endif // MATLAB_MEX_FILE

#endif // LEFTTOEJOINT_MEX_HH
