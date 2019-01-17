/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:39 GMT-04:00
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
  double t504;
  double t947;
  double t1132;
  double t1119;
  double t1145;
  double t680;
  double t704;
  double t710;
  double t816;
  double t912;
  double t1124;
  double t1153;
  double t1162;
  double t1225;
  double t1310;
  double t1422;
  double t1460;
  double t528;
  double t1539;
  double t1557;
  double t1672;
  double t1708;
  double t1824;
  double t1885;
  double t2126;
  double t2235;
  double t2254;
  double t2290;
  double t2630;
  double t2632;
  double t2718;
  double t2752;
  double t2762;
  double t2782;
  double t2790;
  double t2826;
  double t2838;
  double t2966;
  double t3041;
  double t3046;
  double t3047;
  double t3063;
  double t3067;
  double t3068;
  double t3138;
  double t3167;
  double t3190;
  double t3230;
  double t3435;
  double t3458;
  double t3469;
  double t3495;
  double t3506;
  double t3507;
  double t3591;
  double t3625;
  double t3644;
  double t3666;
  double t3802;
  double t3812;
  double t3972;
  double t4015;
  double t4056;
  double t4152;
  double t4167;
  double t4362;
  double t4442;
  double t4452;
  double t4767;
  double t4852;
  double t4865;
  double t752;
  double t838;
  double t842;
  double t940;
  double t943;
  double t1237;
  double t1250;
  double t1257;
  double t1262;
  double t1509;
  double t1522;
  double t1529;
  double t5686;
  double t5715;
  double t5736;
  double t5965;
  double t6011;
  double t6037;
  double t2063;
  double t2165;
  double t2206;
  double t6153;
  double t6167;
  double t6222;
  double t2452;
  double t2572;
  double t2593;
  double t2789;
  double t2805;
  double t2821;
  double t6301;
  double t6330;
  double t6352;
  double t6390;
  double t6396;
  double t6398;
  double t2976;
  double t2992;
  double t3033;
  double t3074;
  double t3150;
  double t3161;
  double t6431;
  double t6438;
  double t6451;
  double t6462;
  double t6465;
  double t6472;
  double t3324;
  double t3347;
  double t3386;
  double t3585;
  double t3598;
  double t3606;
  double t6491;
  double t6495;
  double t6500;
  double t6514;
  double t6522;
  double t6524;
  double t3718;
  double t3727;
  double t3731;
  double t4159;
  double t4171;
  double t4206;
  double t6539;
  double t6546;
  double t6555;
  double t6580;
  double t6595;
  double t6608;
  double t4659;
  double t4685;
  double t4739;
  double t6629;
  double t6636;
  double t6644;
  double t6650;
  double t6657;
  double t6661;
  double t6776;
  double t6794;
  double t6811;
  double t6821;
  double t6826;
  double t6830;
  double t6858;
  double t6872;
  double t6873;
  double t6885;
  double t6889;
  double t6893;
  double t6899;
  double t6911;
  double t6920;
  double t6929;
  double t6932;
  double t6942;
  double t6955;
  double t6958;
  double t6967;
  double t6970;
  double t6974;
  double t6978;
  double t6989;
  double t6997;
  double t7002;
  double t7009;
  double t7015;
  double t7018;
  double t7039;
  double t7051;
  double t7067;
  t504 = Cos(var1[3]);
  t947 = Cos(var1[5]);
  t1132 = Sin(var1[3]);
  t1119 = Sin(var1[4]);
  t1145 = Sin(var1[5]);
  t680 = Cos(var1[14]);
  t704 = -1.*t680;
  t710 = 1. + t704;
  t816 = Sin(var1[14]);
  t912 = Sin(var1[13]);
  t1124 = t504*t947*t1119;
  t1153 = t1132*t1145;
  t1162 = t1124 + t1153;
  t1225 = Cos(var1[13]);
  t1310 = -1.*t947*t1132;
  t1422 = t504*t1119*t1145;
  t1460 = t1310 + t1422;
  t528 = Cos(var1[4]);
  t1539 = t912*t1162;
  t1557 = t1225*t1460;
  t1672 = t1539 + t1557;
  t1708 = Cos(var1[15]);
  t1824 = -1.*t1708;
  t1885 = 1. + t1824;
  t2126 = Sin(var1[15]);
  t2235 = t1225*t1162;
  t2254 = -1.*t912*t1460;
  t2290 = t2235 + t2254;
  t2630 = t680*t504*t528;
  t2632 = t816*t1672;
  t2718 = t2630 + t2632;
  t2752 = Cos(var1[16]);
  t2762 = -1.*t2752;
  t2782 = 1. + t2762;
  t2790 = Sin(var1[16]);
  t2826 = t2126*t2290;
  t2838 = t1708*t2718;
  t2966 = t2826 + t2838;
  t3041 = t1708*t2290;
  t3046 = -1.*t2126*t2718;
  t3047 = t3041 + t3046;
  t3063 = Cos(var1[17]);
  t3067 = -1.*t3063;
  t3068 = 1. + t3067;
  t3138 = Sin(var1[17]);
  t3167 = -1.*t2790*t2966;
  t3190 = t2752*t3047;
  t3230 = t3167 + t3190;
  t3435 = t2752*t2966;
  t3458 = t2790*t3047;
  t3469 = t3435 + t3458;
  t3495 = Cos(var1[18]);
  t3506 = -1.*t3495;
  t3507 = 1. + t3506;
  t3591 = Sin(var1[18]);
  t3625 = t3138*t3230;
  t3644 = t3063*t3469;
  t3666 = t3625 + t3644;
  t3802 = t3063*t3230;
  t3812 = -1.*t3138*t3469;
  t3972 = t3802 + t3812;
  t4015 = Cos(var1[19]);
  t4056 = -1.*t4015;
  t4152 = 1. + t4056;
  t4167 = Sin(var1[19]);
  t4362 = -1.*t3591*t3666;
  t4442 = t3495*t3972;
  t4452 = t4362 + t4442;
  t4767 = t3495*t3666;
  t4852 = t3591*t3972;
  t4865 = t4767 + t4852;
  t752 = -0.049*t710;
  t838 = -0.135*t816;
  t842 = 0. + t752 + t838;
  t940 = 0.135*t912;
  t943 = 0. + t940;
  t1237 = -1.*t1225;
  t1250 = 1. + t1237;
  t1257 = -0.135*t1250;
  t1262 = 0. + t1257;
  t1509 = -0.135*t710;
  t1522 = 0.049*t816;
  t1529 = 0. + t1509 + t1522;
  t5686 = t947*t1132*t1119;
  t5715 = -1.*t504*t1145;
  t5736 = t5686 + t5715;
  t5965 = t504*t947;
  t6011 = t1132*t1119*t1145;
  t6037 = t5965 + t6011;
  t2063 = -0.09*t1885;
  t2165 = 0.049*t2126;
  t2206 = 0. + t2063 + t2165;
  t6153 = t912*t5736;
  t6167 = t1225*t6037;
  t6222 = t6153 + t6167;
  t2452 = -0.049*t1885;
  t2572 = -0.09*t2126;
  t2593 = 0. + t2452 + t2572;
  t2789 = -0.049*t2782;
  t2805 = -0.21*t2790;
  t2821 = 0. + t2789 + t2805;
  t6301 = t1225*t5736;
  t6330 = -1.*t912*t6037;
  t6352 = t6301 + t6330;
  t6390 = t680*t528*t1132;
  t6396 = t816*t6222;
  t6398 = t6390 + t6396;
  t2976 = -0.21*t2782;
  t2992 = 0.049*t2790;
  t3033 = 0. + t2976 + t2992;
  t3074 = -0.2707*t3068;
  t3150 = 0.0016*t3138;
  t3161 = 0. + t3074 + t3150;
  t6431 = t2126*t6352;
  t6438 = t1708*t6398;
  t6451 = t6431 + t6438;
  t6462 = t1708*t6352;
  t6465 = -1.*t2126*t6398;
  t6472 = t6462 + t6465;
  t3324 = -0.0016*t3068;
  t3347 = -0.2707*t3138;
  t3386 = 0. + t3324 + t3347;
  t3585 = 0.0184*t3507;
  t3598 = -0.7055*t3591;
  t3606 = 0. + t3585 + t3598;
  t6491 = -1.*t2790*t6451;
  t6495 = t2752*t6472;
  t6500 = t6491 + t6495;
  t6514 = t2752*t6451;
  t6522 = t2790*t6472;
  t6524 = t6514 + t6522;
  t3718 = -0.7055*t3507;
  t3727 = -0.0184*t3591;
  t3731 = 0. + t3718 + t3727;
  t4159 = -1.1135*t4152;
  t4171 = 0.0216*t4167;
  t4206 = 0. + t4159 + t4171;
  t6539 = t3138*t6500;
  t6546 = t3063*t6524;
  t6555 = t6539 + t6546;
  t6580 = t3063*t6500;
  t6595 = -1.*t3138*t6524;
  t6608 = t6580 + t6595;
  t4659 = -0.0216*t4152;
  t4685 = -1.1135*t4167;
  t4739 = 0. + t4659 + t4685;
  t6629 = -1.*t3591*t6555;
  t6636 = t3495*t6608;
  t6644 = t6629 + t6636;
  t6650 = t3495*t6555;
  t6657 = t3591*t6608;
  t6661 = t6650 + t6657;
  t6776 = t528*t947*t912;
  t6794 = t1225*t528*t1145;
  t6811 = t6776 + t6794;
  t6821 = t1225*t528*t947;
  t6826 = -1.*t528*t912*t1145;
  t6830 = t6821 + t6826;
  t6858 = -1.*t680*t1119;
  t6872 = t816*t6811;
  t6873 = t6858 + t6872;
  t6885 = t2126*t6830;
  t6889 = t1708*t6873;
  t6893 = t6885 + t6889;
  t6899 = t1708*t6830;
  t6911 = -1.*t2126*t6873;
  t6920 = t6899 + t6911;
  t6929 = -1.*t2790*t6893;
  t6932 = t2752*t6920;
  t6942 = t6929 + t6932;
  t6955 = t2752*t6893;
  t6958 = t2790*t6920;
  t6967 = t6955 + t6958;
  t6970 = t3138*t6942;
  t6974 = t3063*t6967;
  t6978 = t6970 + t6974;
  t6989 = t3063*t6942;
  t6997 = -1.*t3138*t6967;
  t7002 = t6989 + t6997;
  t7009 = -1.*t3591*t6978;
  t7015 = t3495*t7002;
  t7018 = t7009 + t7015;
  t7039 = t3495*t6978;
  t7051 = t3591*t7002;
  t7067 = t7039 + t7051;
  p_output1[0]=0. + t1262*t1460 + t1529*t1672 + t2206*t2290 + t2593*t2718 + t2821*t2966 + t3033*t3047 + t3161*t3230 + t3386*t3469 + t3606*t3666 + t3731*t3972 + t4206*t4452 + t4739*t4865 + 0.077577*(t4167*t4452 + t4015*t4865) - 1.059658*(t4015*t4452 - 1.*t4167*t4865) - 0.1305*(t1672*t680 - 1.*t504*t528*t816) + t504*t528*t842 + t1162*t943 + var1[0];
  p_output1[1]=0. + t1262*t6037 + t1529*t6222 + t2206*t6352 + t2593*t6398 + t2821*t6451 + t3033*t6472 + t3161*t6500 + t3386*t6524 + t3606*t6555 + t3731*t6608 + t4206*t6644 + t4739*t6661 + 0.077577*(t4167*t6644 + t4015*t6661) - 1.059658*(t4015*t6644 - 1.*t4167*t6661) - 0.1305*(t6222*t680 - 1.*t1132*t528*t816) + t1132*t528*t842 + t5736*t943 + var1[1];
  p_output1[2]=0. + t1145*t1262*t528 + t1529*t6811 + t2206*t6830 + t2593*t6873 + t2821*t6893 + t3033*t6920 + t3161*t6942 + t3386*t6967 + t3606*t6978 + t3731*t7002 + t4206*t7018 + t4739*t7067 + 0.077577*(t4167*t7018 + t4015*t7067) - 1.059658*(t4015*t7018 - 1.*t4167*t7067) - 0.1305*(t680*t6811 + t1119*t816) - 1.*t1119*t842 + t528*t943*t947 + var1[2];
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

#include "RightToeBottomFront_mex.hh"

namespace SymExpression
{

void RightToeBottomFront_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
