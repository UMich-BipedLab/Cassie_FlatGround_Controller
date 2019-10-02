/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:32 GMT-04:00
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
  double t220;
  double t2306;
  double t2315;
  double t2307;
  double t2319;
  double t485;
  double t625;
  double t674;
  double t1749;
  double t2115;
  double t2311;
  double t2323;
  double t2327;
  double t2331;
  double t2351;
  double t2586;
  double t2590;
  double t376;
  double t3564;
  double t3646;
  double t3670;
  double t4138;
  double t4140;
  double t4175;
  double t4239;
  double t4419;
  double t4421;
  double t4498;
  double t4687;
  double t4763;
  double t4791;
  double t4802;
  double t4809;
  double t4819;
  double t4834;
  double t4914;
  double t4916;
  double t4952;
  double t5017;
  double t5026;
  double t5040;
  double t5046;
  double t5047;
  double t5083;
  double t5142;
  double t5161;
  double t5184;
  double t5191;
  double t5220;
  double t5245;
  double t5249;
  double t5264;
  double t5289;
  double t5297;
  double t5306;
  double t5344;
  double t5368;
  double t5373;
  double t5412;
  double t5424;
  double t5436;
  double t5448;
  double t5462;
  double t5473;
  double t5497;
  double t5503;
  double t5504;
  double t5505;
  double t5532;
  double t5536;
  double t5542;
  double t705;
  double t1795;
  double t1864;
  double t2239;
  double t2305;
  double t2335;
  double t2339;
  double t2343;
  double t2347;
  double t2775;
  double t2815;
  double t2913;
  double t5621;
  double t5623;
  double t5629;
  double t5633;
  double t5648;
  double t5664;
  double t4194;
  double t4369;
  double t4388;
  double t5676;
  double t5684;
  double t5707;
  double t4668;
  double t4675;
  double t4683;
  double t4831;
  double t4851;
  double t4890;
  double t5718;
  double t5731;
  double t5732;
  double t5747;
  double t5749;
  double t5754;
  double t4981;
  double t5005;
  double t5014;
  double t5127;
  double t5144;
  double t5154;
  double t5759;
  double t5760;
  double t5768;
  double t5772;
  double t5775;
  double t5776;
  double t5209;
  double t5213;
  double t5219;
  double t5302;
  double t5321;
  double t5324;
  double t5781;
  double t5785;
  double t5790;
  double t5798;
  double t5801;
  double t5802;
  double t5379;
  double t5382;
  double t5408;
  double t5486;
  double t5500;
  double t5501;
  double t5805;
  double t5809;
  double t5815;
  double t5828;
  double t5831;
  double t5837;
  double t5509;
  double t5514;
  double t5522;
  double t5843;
  double t5850;
  double t5853;
  double t5856;
  double t5860;
  double t5866;
  double t5916;
  double t5918;
  double t5928;
  double t5942;
  double t5944;
  double t5951;
  double t5968;
  double t5970;
  double t5973;
  double t5979;
  double t5981;
  double t5986;
  double t5989;
  double t5995;
  double t5997;
  double t6002;
  double t6005;
  double t6011;
  double t6015;
  double t6017;
  double t6018;
  double t6022;
  double t6025;
  double t6028;
  double t6031;
  double t6033;
  double t6034;
  double t6036;
  double t6037;
  double t6041;
  double t6047;
  double t6050;
  double t6051;
  t220 = Cos(var1[3]);
  t2306 = Cos(var1[5]);
  t2315 = Sin(var1[3]);
  t2307 = Sin(var1[4]);
  t2319 = Sin(var1[5]);
  t485 = Cos(var1[14]);
  t625 = -1.*t485;
  t674 = 1. + t625;
  t1749 = Sin(var1[14]);
  t2115 = Sin(var1[13]);
  t2311 = t220*t2306*t2307;
  t2323 = t2315*t2319;
  t2327 = t2311 + t2323;
  t2331 = Cos(var1[13]);
  t2351 = -1.*t2306*t2315;
  t2586 = t220*t2307*t2319;
  t2590 = t2351 + t2586;
  t376 = Cos(var1[4]);
  t3564 = t2115*t2327;
  t3646 = t2331*t2590;
  t3670 = t3564 + t3646;
  t4138 = Cos(var1[15]);
  t4140 = -1.*t4138;
  t4175 = 1. + t4140;
  t4239 = Sin(var1[15]);
  t4419 = t2331*t2327;
  t4421 = -1.*t2115*t2590;
  t4498 = t4419 + t4421;
  t4687 = t485*t220*t376;
  t4763 = t1749*t3670;
  t4791 = t4687 + t4763;
  t4802 = Cos(var1[16]);
  t4809 = -1.*t4802;
  t4819 = 1. + t4809;
  t4834 = Sin(var1[16]);
  t4914 = t4239*t4498;
  t4916 = t4138*t4791;
  t4952 = t4914 + t4916;
  t5017 = t4138*t4498;
  t5026 = -1.*t4239*t4791;
  t5040 = t5017 + t5026;
  t5046 = Cos(var1[17]);
  t5047 = -1.*t5046;
  t5083 = 1. + t5047;
  t5142 = Sin(var1[17]);
  t5161 = -1.*t4834*t4952;
  t5184 = t4802*t5040;
  t5191 = t5161 + t5184;
  t5220 = t4802*t4952;
  t5245 = t4834*t5040;
  t5249 = t5220 + t5245;
  t5264 = Cos(var1[18]);
  t5289 = -1.*t5264;
  t5297 = 1. + t5289;
  t5306 = Sin(var1[18]);
  t5344 = t5142*t5191;
  t5368 = t5046*t5249;
  t5373 = t5344 + t5368;
  t5412 = t5046*t5191;
  t5424 = -1.*t5142*t5249;
  t5436 = t5412 + t5424;
  t5448 = Cos(var1[19]);
  t5462 = -1.*t5448;
  t5473 = 1. + t5462;
  t5497 = Sin(var1[19]);
  t5503 = -1.*t5306*t5373;
  t5504 = t5264*t5436;
  t5505 = t5503 + t5504;
  t5532 = t5264*t5373;
  t5536 = t5306*t5436;
  t5542 = t5532 + t5536;
  t705 = -0.049*t674;
  t1795 = -0.135*t1749;
  t1864 = 0. + t705 + t1795;
  t2239 = 0.135*t2115;
  t2305 = 0. + t2239;
  t2335 = -1.*t2331;
  t2339 = 1. + t2335;
  t2343 = -0.135*t2339;
  t2347 = 0. + t2343;
  t2775 = -0.135*t674;
  t2815 = 0.049*t1749;
  t2913 = 0. + t2775 + t2815;
  t5621 = t2306*t2315*t2307;
  t5623 = -1.*t220*t2319;
  t5629 = t5621 + t5623;
  t5633 = t220*t2306;
  t5648 = t2315*t2307*t2319;
  t5664 = t5633 + t5648;
  t4194 = -0.09*t4175;
  t4369 = 0.049*t4239;
  t4388 = 0. + t4194 + t4369;
  t5676 = t2115*t5629;
  t5684 = t2331*t5664;
  t5707 = t5676 + t5684;
  t4668 = -0.049*t4175;
  t4675 = -0.09*t4239;
  t4683 = 0. + t4668 + t4675;
  t4831 = -0.049*t4819;
  t4851 = -0.21*t4834;
  t4890 = 0. + t4831 + t4851;
  t5718 = t2331*t5629;
  t5731 = -1.*t2115*t5664;
  t5732 = t5718 + t5731;
  t5747 = t485*t376*t2315;
  t5749 = t1749*t5707;
  t5754 = t5747 + t5749;
  t4981 = -0.21*t4819;
  t5005 = 0.049*t4834;
  t5014 = 0. + t4981 + t5005;
  t5127 = -0.2707*t5083;
  t5144 = 0.0016*t5142;
  t5154 = 0. + t5127 + t5144;
  t5759 = t4239*t5732;
  t5760 = t4138*t5754;
  t5768 = t5759 + t5760;
  t5772 = t4138*t5732;
  t5775 = -1.*t4239*t5754;
  t5776 = t5772 + t5775;
  t5209 = -0.0016*t5083;
  t5213 = -0.2707*t5142;
  t5219 = 0. + t5209 + t5213;
  t5302 = 0.0184*t5297;
  t5321 = -0.7055*t5306;
  t5324 = 0. + t5302 + t5321;
  t5781 = -1.*t4834*t5768;
  t5785 = t4802*t5776;
  t5790 = t5781 + t5785;
  t5798 = t4802*t5768;
  t5801 = t4834*t5776;
  t5802 = t5798 + t5801;
  t5379 = -0.7055*t5297;
  t5382 = -0.0184*t5306;
  t5408 = 0. + t5379 + t5382;
  t5486 = -1.1135*t5473;
  t5500 = 0.0216*t5497;
  t5501 = 0. + t5486 + t5500;
  t5805 = t5142*t5790;
  t5809 = t5046*t5802;
  t5815 = t5805 + t5809;
  t5828 = t5046*t5790;
  t5831 = -1.*t5142*t5802;
  t5837 = t5828 + t5831;
  t5509 = -0.0216*t5473;
  t5514 = -1.1135*t5497;
  t5522 = 0. + t5509 + t5514;
  t5843 = -1.*t5306*t5815;
  t5850 = t5264*t5837;
  t5853 = t5843 + t5850;
  t5856 = t5264*t5815;
  t5860 = t5306*t5837;
  t5866 = t5856 + t5860;
  t5916 = t376*t2306*t2115;
  t5918 = t2331*t376*t2319;
  t5928 = t5916 + t5918;
  t5942 = t2331*t376*t2306;
  t5944 = -1.*t376*t2115*t2319;
  t5951 = t5942 + t5944;
  t5968 = -1.*t485*t2307;
  t5970 = t1749*t5928;
  t5973 = t5968 + t5970;
  t5979 = t4239*t5951;
  t5981 = t4138*t5973;
  t5986 = t5979 + t5981;
  t5989 = t4138*t5951;
  t5995 = -1.*t4239*t5973;
  t5997 = t5989 + t5995;
  t6002 = -1.*t4834*t5986;
  t6005 = t4802*t5997;
  t6011 = t6002 + t6005;
  t6015 = t4802*t5986;
  t6017 = t4834*t5997;
  t6018 = t6015 + t6017;
  t6022 = t5142*t6011;
  t6025 = t5046*t6018;
  t6028 = t6022 + t6025;
  t6031 = t5046*t6011;
  t6033 = -1.*t5142*t6018;
  t6034 = t6031 + t6033;
  t6036 = -1.*t5306*t6028;
  t6037 = t5264*t6034;
  t6041 = t6036 + t6037;
  t6047 = t5264*t6028;
  t6050 = t5306*t6034;
  t6051 = t6047 + t6050;
  p_output1[0]=0. + t2305*t2327 + t2347*t2590 + t2913*t3670 + t1864*t220*t376 + t4388*t4498 + t4683*t4791 - 0.1305*(-1.*t1749*t220*t376 + t3670*t485) + t4890*t4952 + t5014*t5040 + t5154*t5191 + t5219*t5249 + t5324*t5373 + t5408*t5436 + t5501*t5505 + t5522*t5542 - 0.031697*(t5497*t5505 + t5448*t5542) - 1.189886*(t5448*t5505 - 1.*t5497*t5542) + var1[0];
  p_output1[1]=0. + t1864*t2315*t376 + t2305*t5629 + t2347*t5664 + t2913*t5707 - 0.1305*(-1.*t1749*t2315*t376 + t485*t5707) + t4388*t5732 + t4683*t5754 + t4890*t5768 + t5014*t5776 + t5154*t5790 + t5219*t5802 + t5324*t5815 + t5408*t5837 + t5501*t5853 + t5522*t5866 - 0.031697*(t5497*t5853 + t5448*t5866) - 1.189886*(t5448*t5853 - 1.*t5497*t5866) + var1[1];
  p_output1[2]=0. - 1.*t1864*t2307 + t2305*t2306*t376 + t2319*t2347*t376 + t2913*t5928 - 0.1305*(t1749*t2307 + t485*t5928) + t4388*t5951 + t4683*t5973 + t4890*t5986 + t5014*t5997 + t5154*t6011 + t5219*t6018 + t5324*t6028 + t5408*t6034 + t5501*t6041 + t5522*t6051 - 0.031697*(t5497*t6041 + t5448*t6051) - 1.189886*(t5448*t6041 - 1.*t5497*t6051) + var1[2];
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

#include "RightToeBottomBack_mex.hh"

namespace SymExpression
{

void RightToeBottomBack_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
