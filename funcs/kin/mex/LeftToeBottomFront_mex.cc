/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:37 GMT-04:00
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
  double t251;
  double t204;
  double t267;
  double t219;
  double t346;
  double t7;
  double t237;
  double t362;
  double t378;
  double t411;
  double t417;
  double t528;
  double t535;
  double t608;
  double t662;
  double t672;
  double t708;
  double t576;
  double t581;
  double t587;
  double t834;
  double t976;
  double t1001;
  double t1009;
  double t1086;
  double t947;
  double t952;
  double t955;
  double t1124;
  double t1143;
  double t1145;
  double t1167;
  double t1169;
  double t1172;
  double t1179;
  double t1214;
  double t1217;
  double t1222;
  double t1275;
  double t1284;
  double t1311;
  double t1368;
  double t1372;
  double t1400;
  double t1464;
  double t1496;
  double t1503;
  double t1514;
  double t1532;
  double t1539;
  double t1540;
  double t1575;
  double t1640;
  double t1646;
  double t1690;
  double t1767;
  double t1782;
  double t1799;
  double t1894;
  double t1911;
  double t1915;
  double t1981;
  double t1989;
  double t2026;
  double t2076;
  double t2157;
  double t2165;
  double t2178;
  double t2290;
  double t2296;
  double t2330;
  double t110;
  double t145;
  double t165;
  double t176;
  double t543;
  double t557;
  double t2538;
  double t2598;
  double t2606;
  double t2632;
  double t2663;
  double t2733;
  double t704;
  double t710;
  double t816;
  double t885;
  double t891;
  double t895;
  double t2752;
  double t2762;
  double t2765;
  double t1010;
  double t1119;
  double t1120;
  double t1149;
  double t1153;
  double t1162;
  double t1177;
  double t1183;
  double t1207;
  double t2790;
  double t2798;
  double t2799;
  double t2812;
  double t2813;
  double t2821;
  double t1225;
  double t1237;
  double t1257;
  double t1460;
  double t1476;
  double t1490;
  double t2827;
  double t2838;
  double t2853;
  double t2865;
  double t2917;
  double t2926;
  double t1522;
  double t1524;
  double t1529;
  double t1672;
  double t1698;
  double t1761;
  double t2975;
  double t2992;
  double t3019;
  double t3041;
  double t3047;
  double t3050;
  double t1824;
  double t1830;
  double t1857;
  double t2063;
  double t2126;
  double t2137;
  double t3063;
  double t3068;
  double t3084;
  double t3094;
  double t3133;
  double t3150;
  double t2212;
  double t2235;
  double t2254;
  double t3165;
  double t3171;
  double t3207;
  double t3221;
  double t3230;
  double t3245;
  double t3507;
  double t3514;
  double t3542;
  double t3703;
  double t3718;
  double t3724;
  double t3731;
  double t3878;
  double t3940;
  double t3984;
  double t3993;
  double t4034;
  double t4096;
  double t4099;
  double t4152;
  double t4170;
  double t4198;
  double t4206;
  double t4355;
  double t4362;
  double t4382;
  double t4659;
  double t4685;
  double t4693;
  double t4751;
  double t4760;
  double t4767;
  double t4860;
  double t4865;
  double t4869;
  double t5069;
  double t5074;
  double t5109;
  t251 = Cos(var1[3]);
  t204 = Cos(var1[5]);
  t267 = Sin(var1[4]);
  t219 = Sin(var1[3]);
  t346 = Sin(var1[5]);
  t7 = Cos(var1[6]);
  t237 = -1.*t204*t219;
  t362 = t251*t267*t346;
  t378 = t237 + t362;
  t411 = t251*t204*t267;
  t417 = t219*t346;
  t528 = t411 + t417;
  t535 = Sin(var1[6]);
  t608 = Cos(var1[7]);
  t662 = -1.*t608;
  t672 = 1. + t662;
  t708 = Sin(var1[7]);
  t576 = t7*t378;
  t581 = t528*t535;
  t587 = t576 + t581;
  t834 = Cos(var1[4]);
  t976 = Cos(var1[8]);
  t1001 = -1.*t976;
  t1009 = 1. + t1001;
  t1086 = Sin(var1[8]);
  t947 = t251*t834*t608;
  t952 = t587*t708;
  t955 = t947 + t952;
  t1124 = t7*t528;
  t1143 = -1.*t378*t535;
  t1145 = t1124 + t1143;
  t1167 = Cos(var1[9]);
  t1169 = -1.*t1167;
  t1172 = 1. + t1169;
  t1179 = Sin(var1[9]);
  t1214 = t976*t955;
  t1217 = t1145*t1086;
  t1222 = t1214 + t1217;
  t1275 = t976*t1145;
  t1284 = -1.*t955*t1086;
  t1311 = t1275 + t1284;
  t1368 = Cos(var1[10]);
  t1372 = -1.*t1368;
  t1400 = 1. + t1372;
  t1464 = Sin(var1[10]);
  t1496 = -1.*t1179*t1222;
  t1503 = t1167*t1311;
  t1514 = t1496 + t1503;
  t1532 = t1167*t1222;
  t1539 = t1179*t1311;
  t1540 = t1532 + t1539;
  t1575 = Cos(var1[11]);
  t1640 = -1.*t1575;
  t1646 = 1. + t1640;
  t1690 = Sin(var1[11]);
  t1767 = t1464*t1514;
  t1782 = t1368*t1540;
  t1799 = t1767 + t1782;
  t1894 = t1368*t1514;
  t1911 = -1.*t1464*t1540;
  t1915 = t1894 + t1911;
  t1981 = Cos(var1[12]);
  t1989 = -1.*t1981;
  t2026 = 1. + t1989;
  t2076 = Sin(var1[12]);
  t2157 = -1.*t1690*t1799;
  t2165 = t1575*t1915;
  t2178 = t2157 + t2165;
  t2290 = t1575*t1799;
  t2296 = t1690*t1915;
  t2330 = t2290 + t2296;
  t110 = -1.*t7;
  t145 = 1. + t110;
  t165 = 0.135*t145;
  t176 = 0. + t165;
  t543 = -0.135*t535;
  t557 = 0. + t543;
  t2538 = t251*t204;
  t2598 = t219*t267*t346;
  t2606 = t2538 + t2598;
  t2632 = t204*t219*t267;
  t2663 = -1.*t251*t346;
  t2733 = t2632 + t2663;
  t704 = 0.135*t672;
  t710 = 0.049*t708;
  t816 = 0. + t704 + t710;
  t885 = -0.049*t672;
  t891 = 0.135*t708;
  t895 = 0. + t885 + t891;
  t2752 = t7*t2606;
  t2762 = t2733*t535;
  t2765 = t2752 + t2762;
  t1010 = -0.049*t1009;
  t1119 = -0.09*t1086;
  t1120 = 0. + t1010 + t1119;
  t1149 = -0.09*t1009;
  t1153 = 0.049*t1086;
  t1162 = 0. + t1149 + t1153;
  t1177 = -0.049*t1172;
  t1183 = -0.21*t1179;
  t1207 = 0. + t1177 + t1183;
  t2790 = t834*t608*t219;
  t2798 = t2765*t708;
  t2799 = t2790 + t2798;
  t2812 = t7*t2733;
  t2813 = -1.*t2606*t535;
  t2821 = t2812 + t2813;
  t1225 = -0.21*t1172;
  t1237 = 0.049*t1179;
  t1257 = 0. + t1225 + t1237;
  t1460 = -0.2707*t1400;
  t1476 = 0.0016*t1464;
  t1490 = 0. + t1460 + t1476;
  t2827 = t976*t2799;
  t2838 = t2821*t1086;
  t2853 = t2827 + t2838;
  t2865 = t976*t2821;
  t2917 = -1.*t2799*t1086;
  t2926 = t2865 + t2917;
  t1522 = -0.0016*t1400;
  t1524 = -0.2707*t1464;
  t1529 = 0. + t1522 + t1524;
  t1672 = 0.0184*t1646;
  t1698 = -0.7055*t1690;
  t1761 = 0. + t1672 + t1698;
  t2975 = -1.*t1179*t2853;
  t2992 = t1167*t2926;
  t3019 = t2975 + t2992;
  t3041 = t1167*t2853;
  t3047 = t1179*t2926;
  t3050 = t3041 + t3047;
  t1824 = -0.7055*t1646;
  t1830 = -0.0184*t1690;
  t1857 = 0. + t1824 + t1830;
  t2063 = -1.1135*t2026;
  t2126 = 0.0216*t2076;
  t2137 = 0. + t2063 + t2126;
  t3063 = t1464*t3019;
  t3068 = t1368*t3050;
  t3084 = t3063 + t3068;
  t3094 = t1368*t3019;
  t3133 = -1.*t1464*t3050;
  t3150 = t3094 + t3133;
  t2212 = -0.0216*t2026;
  t2235 = -1.1135*t2076;
  t2254 = 0. + t2212 + t2235;
  t3165 = -1.*t1690*t3084;
  t3171 = t1575*t3150;
  t3207 = t3165 + t3171;
  t3221 = t1575*t3084;
  t3230 = t1690*t3150;
  t3245 = t3221 + t3230;
  t3507 = t834*t7*t346;
  t3514 = t834*t204*t535;
  t3542 = t3507 + t3514;
  t3703 = -1.*t608*t267;
  t3718 = t3542*t708;
  t3724 = t3703 + t3718;
  t3731 = t834*t204*t7;
  t3878 = -1.*t834*t346*t535;
  t3940 = t3731 + t3878;
  t3984 = t976*t3724;
  t3993 = t3940*t1086;
  t4034 = t3984 + t3993;
  t4096 = t976*t3940;
  t4099 = -1.*t3724*t1086;
  t4152 = t4096 + t4099;
  t4170 = -1.*t1179*t4034;
  t4198 = t1167*t4152;
  t4206 = t4170 + t4198;
  t4355 = t1167*t4034;
  t4362 = t1179*t4152;
  t4382 = t4355 + t4362;
  t4659 = t1464*t4206;
  t4685 = t1368*t4382;
  t4693 = t4659 + t4685;
  t4751 = t1368*t4206;
  t4760 = -1.*t1464*t4382;
  t4767 = t4751 + t4760;
  t4860 = -1.*t1690*t4693;
  t4865 = t1575*t4767;
  t4869 = t4860 + t4865;
  t5069 = t1575*t4693;
  t5074 = t1690*t4767;
  t5109 = t5069 + t5074;
  p_output1[0]=0. + t1145*t1162 + t1207*t1222 + t1257*t1311 + t1490*t1514 + t1529*t1540 + t1761*t1799 + t1857*t1915 + t2137*t2178 + t2254*t2330 + 0.077577*(t2076*t2178 + t1981*t2330) - 1.059658*(t1981*t2178 - 1.*t2076*t2330) + t176*t378 + t528*t557 + t587*t816 + 0.1305*(t587*t608 - 1.*t251*t708*t834) + t251*t834*t895 + t1120*t955 + var1[0];
  p_output1[1]=0. + t176*t2606 + t1120*t2799 + t1162*t2821 + t1207*t2853 + t1257*t2926 + t1490*t3019 + t1529*t3050 + t1761*t3084 + t1857*t3150 + t2137*t3207 + t2254*t3245 + 0.077577*(t2076*t3207 + t1981*t3245) - 1.059658*(t1981*t3207 - 1.*t2076*t3245) + t2733*t557 + t2765*t816 + 0.1305*(t2765*t608 - 1.*t219*t708*t834) + t219*t834*t895 + var1[1];
  p_output1[2]=0. + t1120*t3724 + t1162*t3940 + t1207*t4034 + t1257*t4152 + t1490*t4206 + t1529*t4382 + t1761*t4693 + t1857*t4767 + t2137*t4869 + t2254*t5109 + 0.077577*(t2076*t4869 + t1981*t5109) - 1.059658*(t1981*t4869 - 1.*t2076*t5109) + 0.1305*(t3542*t608 + t267*t708) + t3542*t816 + t176*t346*t834 + t204*t557*t834 - 1.*t267*t895 + var1[2];
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

#include "LeftToeBottomFront_mex.hh"

namespace SymExpression
{

void LeftToeBottomFront_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
