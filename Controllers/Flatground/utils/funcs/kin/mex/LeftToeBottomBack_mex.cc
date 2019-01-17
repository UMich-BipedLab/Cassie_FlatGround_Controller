/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:30 GMT-04:00
 */

#ifdef MATLAB_MEX_FILE
#include <stdexcept>
#include <cmath>
/**
 * Copied from Wolfram Mathematica C Definitions file mdefs.hpp
 * Changed marcos to inline functions (Eric Cousineau)
 */
inline double Power(double x, double y) { return pow(x, y); }
inline double Sqrt(double x) { return sqrt(x); }

inline double Abs(double x) { return fabs(x); }

inline double Exp(double x) { return exp(x); }
inline double Log(double x) { return log(x); }

inline double Sin(double x) { return sin(x); }
inline double Cos(double x) { return cos(x); }
inline double Tan(double x) { return tan(x); }

inline double ArcSin(double x) { return asin(x); }
inline double ArcCos(double x) { return acos(x); }
inline double ArcTan(double x) { return atan(x); }

/* update ArcTan function to use atan2 instead. */
inline double ArcTan(double x, double y) { return atan2(y,x); }

inline double Sinh(double x) { return sinh(x); }
inline double Cosh(double x) { return cosh(x); }
inline double Tanh(double x) { return tanh(x); }

const double E	= 2.71828182845904523536029;
const double Pi = 3.14159265358979323846264;
const double Degree = 0.01745329251994329576924;


#endif

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var1)
{
  double t861;
  double t637;
  double t874;
  double t825;
  double t932;
  double t189;
  double t855;
  double t1044;
  double t1092;
  double t1236;
  double t1242;
  double t1271;
  double t1433;
  double t1988;
  double t2043;
  double t2226;
  double t2309;
  double t1828;
  double t1867;
  double t1879;
  double t2970;
  double t3992;
  double t4009;
  double t4052;
  double t4073;
  double t3670;
  double t3678;
  double t3687;
  double t4147;
  double t4149;
  double t4175;
  double t4271;
  double t4329;
  double t4336;
  double t4341;
  double t4372;
  double t4388;
  double t4396;
  double t4477;
  double t4487;
  double t4489;
  double t4493;
  double t4494;
  double t4495;
  double t4500;
  double t4568;
  double t4571;
  double t4576;
  double t4603;
  double t4605;
  double t4615;
  double t4625;
  double t4629;
  double t4643;
  double t4667;
  double t4683;
  double t4687;
  double t4688;
  double t4719;
  double t4727;
  double t4730;
  double t4738;
  double t4740;
  double t4746;
  double t4753;
  double t4782;
  double t4785;
  double t4786;
  double t4817;
  double t4819;
  double t4821;
  double t393;
  double t478;
  double t538;
  double t631;
  double t1518;
  double t1625;
  double t4914;
  double t4916;
  double t4921;
  double t4932;
  double t4940;
  double t4945;
  double t2247;
  double t2328;
  double t2863;
  double t3162;
  double t3318;
  double t3336;
  double t4952;
  double t4964;
  double t4969;
  double t4057;
  double t4137;
  double t4138;
  double t4194;
  double t4239;
  double t4250;
  double t4339;
  double t4347;
  double t4369;
  double t5000;
  double t5005;
  double t5009;
  double t5014;
  double t5015;
  double t5017;
  double t4421;
  double t4447;
  double t4457;
  double t4498;
  double t4511;
  double t4557;
  double t5026;
  double t5027;
  double t5035;
  double t5041;
  double t5043;
  double t5046;
  double t4592;
  double t4595;
  double t4597;
  double t4659;
  double t4668;
  double t4675;
  double t5070;
  double t5079;
  double t5083;
  double t5089;
  double t5095;
  double t5100;
  double t4703;
  double t4707;
  double t4716;
  double t4749;
  double t4763;
  double t4774;
  double t5127;
  double t5130;
  double t5139;
  double t5144;
  double t5148;
  double t5154;
  double t4794;
  double t4802;
  double t4809;
  double t5165;
  double t5172;
  double t5173;
  double t5191;
  double t5198;
  double t5204;
  double t5248;
  double t5249;
  double t5257;
  double t5292;
  double t5297;
  double t5300;
  double t5306;
  double t5312;
  double t5319;
  double t5324;
  double t5330;
  double t5334;
  double t5344;
  double t5352;
  double t5356;
  double t5370;
  double t5373;
  double t5378;
  double t5382;
  double t5392;
  double t5398;
  double t5412;
  double t5424;
  double t5430;
  double t5436;
  double t5440;
  double t5442;
  double t5447;
  double t5448;
  double t5454;
  double t5458;
  double t5462;
  double t5466;
  t861 = Cos(var1[3]);
  t637 = Cos(var1[5]);
  t874 = Sin(var1[4]);
  t825 = Sin(var1[3]);
  t932 = Sin(var1[5]);
  t189 = Cos(var1[6]);
  t855 = -1.*t637*t825;
  t1044 = t861*t874*t932;
  t1092 = t855 + t1044;
  t1236 = t861*t637*t874;
  t1242 = t825*t932;
  t1271 = t1236 + t1242;
  t1433 = Sin(var1[6]);
  t1988 = Cos(var1[7]);
  t2043 = -1.*t1988;
  t2226 = 1. + t2043;
  t2309 = Sin(var1[7]);
  t1828 = t189*t1092;
  t1867 = t1271*t1433;
  t1879 = t1828 + t1867;
  t2970 = Cos(var1[4]);
  t3992 = Cos(var1[8]);
  t4009 = -1.*t3992;
  t4052 = 1. + t4009;
  t4073 = Sin(var1[8]);
  t3670 = t861*t2970*t1988;
  t3678 = t1879*t2309;
  t3687 = t3670 + t3678;
  t4147 = t189*t1271;
  t4149 = -1.*t1092*t1433;
  t4175 = t4147 + t4149;
  t4271 = Cos(var1[9]);
  t4329 = -1.*t4271;
  t4336 = 1. + t4329;
  t4341 = Sin(var1[9]);
  t4372 = t3992*t3687;
  t4388 = t4175*t4073;
  t4396 = t4372 + t4388;
  t4477 = t3992*t4175;
  t4487 = -1.*t3687*t4073;
  t4489 = t4477 + t4487;
  t4493 = Cos(var1[10]);
  t4494 = -1.*t4493;
  t4495 = 1. + t4494;
  t4500 = Sin(var1[10]);
  t4568 = -1.*t4341*t4396;
  t4571 = t4271*t4489;
  t4576 = t4568 + t4571;
  t4603 = t4271*t4396;
  t4605 = t4341*t4489;
  t4615 = t4603 + t4605;
  t4625 = Cos(var1[11]);
  t4629 = -1.*t4625;
  t4643 = 1. + t4629;
  t4667 = Sin(var1[11]);
  t4683 = t4500*t4576;
  t4687 = t4493*t4615;
  t4688 = t4683 + t4687;
  t4719 = t4493*t4576;
  t4727 = -1.*t4500*t4615;
  t4730 = t4719 + t4727;
  t4738 = Cos(var1[12]);
  t4740 = -1.*t4738;
  t4746 = 1. + t4740;
  t4753 = Sin(var1[12]);
  t4782 = -1.*t4667*t4688;
  t4785 = t4625*t4730;
  t4786 = t4782 + t4785;
  t4817 = t4625*t4688;
  t4819 = t4667*t4730;
  t4821 = t4817 + t4819;
  t393 = -1.*t189;
  t478 = 1. + t393;
  t538 = 0.135*t478;
  t631 = 0. + t538;
  t1518 = -0.135*t1433;
  t1625 = 0. + t1518;
  t4914 = t861*t637;
  t4916 = t825*t874*t932;
  t4921 = t4914 + t4916;
  t4932 = t637*t825*t874;
  t4940 = -1.*t861*t932;
  t4945 = t4932 + t4940;
  t2247 = 0.135*t2226;
  t2328 = 0.049*t2309;
  t2863 = 0. + t2247 + t2328;
  t3162 = -0.049*t2226;
  t3318 = 0.135*t2309;
  t3336 = 0. + t3162 + t3318;
  t4952 = t189*t4921;
  t4964 = t4945*t1433;
  t4969 = t4952 + t4964;
  t4057 = -0.049*t4052;
  t4137 = -0.09*t4073;
  t4138 = 0. + t4057 + t4137;
  t4194 = -0.09*t4052;
  t4239 = 0.049*t4073;
  t4250 = 0. + t4194 + t4239;
  t4339 = -0.049*t4336;
  t4347 = -0.21*t4341;
  t4369 = 0. + t4339 + t4347;
  t5000 = t2970*t1988*t825;
  t5005 = t4969*t2309;
  t5009 = t5000 + t5005;
  t5014 = t189*t4945;
  t5015 = -1.*t4921*t1433;
  t5017 = t5014 + t5015;
  t4421 = -0.21*t4336;
  t4447 = 0.049*t4341;
  t4457 = 0. + t4421 + t4447;
  t4498 = -0.2707*t4495;
  t4511 = 0.0016*t4500;
  t4557 = 0. + t4498 + t4511;
  t5026 = t3992*t5009;
  t5027 = t5017*t4073;
  t5035 = t5026 + t5027;
  t5041 = t3992*t5017;
  t5043 = -1.*t5009*t4073;
  t5046 = t5041 + t5043;
  t4592 = -0.0016*t4495;
  t4595 = -0.2707*t4500;
  t4597 = 0. + t4592 + t4595;
  t4659 = 0.0184*t4643;
  t4668 = -0.7055*t4667;
  t4675 = 0. + t4659 + t4668;
  t5070 = -1.*t4341*t5035;
  t5079 = t4271*t5046;
  t5083 = t5070 + t5079;
  t5089 = t4271*t5035;
  t5095 = t4341*t5046;
  t5100 = t5089 + t5095;
  t4703 = -0.7055*t4643;
  t4707 = -0.0184*t4667;
  t4716 = 0. + t4703 + t4707;
  t4749 = -1.1135*t4746;
  t4763 = 0.0216*t4753;
  t4774 = 0. + t4749 + t4763;
  t5127 = t4500*t5083;
  t5130 = t4493*t5100;
  t5139 = t5127 + t5130;
  t5144 = t4493*t5083;
  t5148 = -1.*t4500*t5100;
  t5154 = t5144 + t5148;
  t4794 = -0.0216*t4746;
  t4802 = -1.1135*t4753;
  t4809 = 0. + t4794 + t4802;
  t5165 = -1.*t4667*t5139;
  t5172 = t4625*t5154;
  t5173 = t5165 + t5172;
  t5191 = t4625*t5139;
  t5198 = t4667*t5154;
  t5204 = t5191 + t5198;
  t5248 = t2970*t189*t932;
  t5249 = t2970*t637*t1433;
  t5257 = t5248 + t5249;
  t5292 = -1.*t1988*t874;
  t5297 = t5257*t2309;
  t5300 = t5292 + t5297;
  t5306 = t2970*t637*t189;
  t5312 = -1.*t2970*t932*t1433;
  t5319 = t5306 + t5312;
  t5324 = t3992*t5300;
  t5330 = t5319*t4073;
  t5334 = t5324 + t5330;
  t5344 = t3992*t5319;
  t5352 = -1.*t5300*t4073;
  t5356 = t5344 + t5352;
  t5370 = -1.*t4341*t5334;
  t5373 = t4271*t5356;
  t5378 = t5370 + t5373;
  t5382 = t4271*t5334;
  t5392 = t4341*t5356;
  t5398 = t5382 + t5392;
  t5412 = t4500*t5378;
  t5424 = t4493*t5398;
  t5430 = t5412 + t5424;
  t5436 = t4493*t5378;
  t5440 = -1.*t4500*t5398;
  t5442 = t5436 + t5440;
  t5447 = -1.*t4667*t5430;
  t5448 = t4625*t5442;
  t5454 = t5447 + t5448;
  t5458 = t4625*t5430;
  t5462 = t4667*t5442;
  t5466 = t5458 + t5462;
  p_output1[0]=0. + t1271*t1625 + t1879*t2863 + t3687*t4138 + t4175*t4250 + t4369*t4396 + t4457*t4489 + t4557*t4576 + t4597*t4615 + t4675*t4688 + t4716*t4730 + t4774*t4786 + t4809*t4821 - 0.031697*(t4753*t4786 + t4738*t4821) - 1.189886*(t4738*t4786 - 1.*t4753*t4821) + t1092*t631 + t2970*t3336*t861 + 0.1305*(t1879*t1988 - 1.*t2309*t2970*t861) + var1[0];
  p_output1[1]=0. + t1625*t4945 + t2863*t4969 + t4138*t5009 + t4250*t5017 + t4369*t5035 + t4457*t5046 + t4557*t5083 + t4597*t5100 + t4675*t5139 + t4716*t5154 + t4774*t5173 + t4809*t5204 - 0.031697*(t4753*t5173 + t4738*t5204) - 1.189886*(t4738*t5173 - 1.*t4753*t5204) + t4921*t631 + t2970*t3336*t825 + 0.1305*(t1988*t4969 - 1.*t2309*t2970*t825) + var1[1];
  p_output1[2]=0. + t2863*t5257 + t4138*t5300 + t4250*t5319 + t4369*t5334 + t4457*t5356 + t4557*t5378 + t4597*t5398 + t4675*t5430 + t4716*t5442 + t4774*t5454 + t4809*t5466 - 0.031697*(t4753*t5454 + t4738*t5466) - 1.189886*(t4738*t5454 - 1.*t4753*t5466) + t1625*t2970*t637 - 1.*t3336*t874 + 0.1305*(t1988*t5257 + t2309*t874) + t2970*t631*t932 + var1[2];
}



#ifdef MATLAB_MEX_FILE

#include "mex.h"
/*
 * Main function
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  size_t mrows, ncols;

  double *var1;
  double *p_output1;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (var1).");
    }
  else if( nlhs > 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 20 && ncols == 1) && 
      !(mrows == 1 && ncols == 20))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var1 is wrong.");
    }

  /*  Assign pointers to each input.  */
  var1 = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var1);


}

#else // MATLAB_MEX_FILE

#include "LeftToeBottomBack_mex.hh"

namespace SymExpression
{

void LeftToeBottomBack_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
