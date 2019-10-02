/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:40 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RightToeBottomFront_src.h"

#ifdef _MSC_VER
  #define INLINE __forceinline /* use __forceinline (VC++ specific) */
#else
  #define INLINE inline        /* use standard inline */
#endif

/**
 * Copied from Wolfram Mathematica C Definitions file mdefs.hpp
 * Changed marcos to inline functions (Eric Cousineau)
 */
INLINE double Power(double x, double y) { return pow(x, y); }
INLINE double Sqrt(double x) { return sqrt(x); }

INLINE double Abs(double x) { return fabs(x); }

INLINE double Exp(double x) { return exp(x); }
INLINE double Log(double x) { return log(x); }

INLINE double Sin(double x) { return sin(x); }
INLINE double Cos(double x) { return cos(x); }
INLINE double Tan(double x) { return tan(x); }

INLINE double Csc(double x) { return 1.0/sin(x); }
INLINE double Sec(double x) { return 1.0/cos(x); }

INLINE double ArcSin(double x) { return asin(x); }
INLINE double ArcCos(double x) { return acos(x); }
//INLINE double ArcTan(double x) { return atan(x); }

/* update ArcTan function to use atan2 instead. */
INLINE double ArcTan(double x, double y) { return atan2(y,x); }

INLINE double Sinh(double x) { return sinh(x); }
INLINE double Cosh(double x) { return cosh(x); }
INLINE double Tanh(double x) { return tanh(x); }

#define E 2.71828182845904523536029
#define Pi 3.14159265358979323846264
#define Degree 0.01745329251994329576924

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var1)
{
  double t190;
  double t924;
  double t1051;
  double t940;
  double t1124;
  double t678;
  double t693;
  double t752;
  double t838;
  double t907;
  double t943;
  double t1153;
  double t1162;
  double t1257;
  double t1422;
  double t1490;
  double t1509;
  double t313;
  double t1698;
  double t1957;
  double t1992;
  double t2092;
  double t2102;
  double t2165;
  double t2235;
  double t2296;
  double t2299;
  double t2336;
  double t2725;
  double t2789;
  double t2805;
  double t2826;
  double t2838;
  double t2898;
  double t2976;
  double t3041;
  double t3047;
  double t3053;
  double t3190;
  double t3214;
  double t3230;
  double t3324;
  double t3347;
  double t3386;
  double t3458;
  double t3598;
  double t3606;
  double t3625;
  double t3731;
  double t3802;
  double t3972;
  double t4159;
  double t4171;
  double t4206;
  double t4227;
  double t4450;
  double t4454;
  double t4659;
  double t4852;
  double t4911;
  double t5007;
  double t5069;
  double t5074;
  double t5209;
  double t5290;
  double t5469;
  double t5579;
  double t5661;
  double t6011;
  double t6083;
  double t6153;
  double t769;
  double t883;
  double t900;
  double t911;
  double t917;
  double t1262;
  double t1288;
  double t1292;
  double t1299;
  double t1529;
  double t1539;
  double t1557;
  double t6424;
  double t6431;
  double t6438;
  double t6462;
  double t6472;
  double t6484;
  double t2206;
  double t2290;
  double t2291;
  double t6500;
  double t6505;
  double t6514;
  double t2632;
  double t2687;
  double t2707;
  double t2974;
  double t2992;
  double t3033;
  double t6531;
  double t6539;
  double t6546;
  double t6647;
  double t6650;
  double t6657;
  double t3150;
  double t3161;
  double t3182;
  double t3435;
  double t3481;
  double t3585;
  double t6666;
  double t6682;
  double t6687;
  double t6715;
  double t6727;
  double t6730;
  double t3667;
  double t3718;
  double t3727;
  double t4211;
  double t4437;
  double t4442;
  double t6746;
  double t6751;
  double t6762;
  double t6776;
  double t6794;
  double t6811;
  double t4739;
  double t4767;
  double t4833;
  double t5256;
  double t5361;
  double t5382;
  double t6821;
  double t6830;
  double t6835;
  double t6841;
  double t6845;
  double t6852;
  double t5736;
  double t5826;
  double t5965;
  double t6880;
  double t6885;
  double t6889;
  double t6899;
  double t6920;
  double t6922;
  double t7026;
  double t7039;
  double t7051;
  double t7080;
  double t7089;
  double t7092;
  double t7114;
  double t7115;
  double t7126;
  double t7138;
  double t7155;
  double t7164;
  double t7179;
  double t7185;
  double t7191;
  double t7208;
  double t7217;
  double t7223;
  double t7226;
  double t7229;
  double t7239;
  double t7261;
  double t7269;
  double t7274;
  double t7278;
  double t7285;
  double t7286;
  double t7292;
  double t7294;
  double t7296;
  double t7308;
  double t7311;
  double t7324;
  t190 = Cos(var1[3]);
  t924 = Cos(var1[5]);
  t1051 = Sin(var1[3]);
  t940 = Sin(var1[4]);
  t1124 = Sin(var1[5]);
  t678 = Cos(var1[14]);
  t693 = -1.*t678;
  t752 = 1. + t693;
  t838 = Sin(var1[14]);
  t907 = Sin(var1[13]);
  t943 = t190*t924*t940;
  t1153 = t1051*t1124;
  t1162 = t943 + t1153;
  t1257 = Cos(var1[13]);
  t1422 = -1.*t924*t1051;
  t1490 = t190*t940*t1124;
  t1509 = t1422 + t1490;
  t313 = Cos(var1[4]);
  t1698 = t907*t1162;
  t1957 = t1257*t1509;
  t1992 = t1698 + t1957;
  t2092 = Cos(var1[15]);
  t2102 = -1.*t2092;
  t2165 = 1. + t2102;
  t2235 = Sin(var1[15]);
  t2296 = t1257*t1162;
  t2299 = -1.*t907*t1509;
  t2336 = t2296 + t2299;
  t2725 = t678*t190*t313;
  t2789 = t838*t1992;
  t2805 = t2725 + t2789;
  t2826 = Cos(var1[16]);
  t2838 = -1.*t2826;
  t2898 = 1. + t2838;
  t2976 = Sin(var1[16]);
  t3041 = t2235*t2336;
  t3047 = t2092*t2805;
  t3053 = t3041 + t3047;
  t3190 = t2092*t2336;
  t3214 = -1.*t2235*t2805;
  t3230 = t3190 + t3214;
  t3324 = Cos(var1[17]);
  t3347 = -1.*t3324;
  t3386 = 1. + t3347;
  t3458 = Sin(var1[17]);
  t3598 = -1.*t2976*t3053;
  t3606 = t2826*t3230;
  t3625 = t3598 + t3606;
  t3731 = t2826*t3053;
  t3802 = t2976*t3230;
  t3972 = t3731 + t3802;
  t4159 = Cos(var1[18]);
  t4171 = -1.*t4159;
  t4206 = 1. + t4171;
  t4227 = Sin(var1[18]);
  t4450 = t3458*t3625;
  t4454 = t3324*t3972;
  t4659 = t4450 + t4454;
  t4852 = t3324*t3625;
  t4911 = -1.*t3458*t3972;
  t5007 = t4852 + t4911;
  t5069 = Cos(var1[19]);
  t5074 = -1.*t5069;
  t5209 = 1. + t5074;
  t5290 = Sin(var1[19]);
  t5469 = -1.*t4227*t4659;
  t5579 = t4159*t5007;
  t5661 = t5469 + t5579;
  t6011 = t4159*t4659;
  t6083 = t4227*t5007;
  t6153 = t6011 + t6083;
  t769 = -0.049*t752;
  t883 = -0.135*t838;
  t900 = 0. + t769 + t883;
  t911 = 0.135*t907;
  t917 = 0. + t911;
  t1262 = -1.*t1257;
  t1288 = 1. + t1262;
  t1292 = -0.135*t1288;
  t1299 = 0. + t1292;
  t1529 = -0.135*t752;
  t1539 = 0.049*t838;
  t1557 = 0. + t1529 + t1539;
  t6424 = t924*t1051*t940;
  t6431 = -1.*t190*t1124;
  t6438 = t6424 + t6431;
  t6462 = t190*t924;
  t6472 = t1051*t940*t1124;
  t6484 = t6462 + t6472;
  t2206 = -0.09*t2165;
  t2290 = 0.049*t2235;
  t2291 = 0. + t2206 + t2290;
  t6500 = t907*t6438;
  t6505 = t1257*t6484;
  t6514 = t6500 + t6505;
  t2632 = -0.049*t2165;
  t2687 = -0.09*t2235;
  t2707 = 0. + t2632 + t2687;
  t2974 = -0.049*t2898;
  t2992 = -0.21*t2976;
  t3033 = 0. + t2974 + t2992;
  t6531 = t1257*t6438;
  t6539 = -1.*t907*t6484;
  t6546 = t6531 + t6539;
  t6647 = t678*t313*t1051;
  t6650 = t838*t6514;
  t6657 = t6647 + t6650;
  t3150 = -0.21*t2898;
  t3161 = 0.049*t2976;
  t3182 = 0. + t3150 + t3161;
  t3435 = -0.2707*t3386;
  t3481 = 0.0016*t3458;
  t3585 = 0. + t3435 + t3481;
  t6666 = t2235*t6546;
  t6682 = t2092*t6657;
  t6687 = t6666 + t6682;
  t6715 = t2092*t6546;
  t6727 = -1.*t2235*t6657;
  t6730 = t6715 + t6727;
  t3667 = -0.0016*t3386;
  t3718 = -0.2707*t3458;
  t3727 = 0. + t3667 + t3718;
  t4211 = 0.0184*t4206;
  t4437 = -0.7055*t4227;
  t4442 = 0. + t4211 + t4437;
  t6746 = -1.*t2976*t6687;
  t6751 = t2826*t6730;
  t6762 = t6746 + t6751;
  t6776 = t2826*t6687;
  t6794 = t2976*t6730;
  t6811 = t6776 + t6794;
  t4739 = -0.7055*t4206;
  t4767 = -0.0184*t4227;
  t4833 = 0. + t4739 + t4767;
  t5256 = -1.1135*t5209;
  t5361 = 0.0216*t5290;
  t5382 = 0. + t5256 + t5361;
  t6821 = t3458*t6762;
  t6830 = t3324*t6811;
  t6835 = t6821 + t6830;
  t6841 = t3324*t6762;
  t6845 = -1.*t3458*t6811;
  t6852 = t6841 + t6845;
  t5736 = -0.0216*t5209;
  t5826 = -1.1135*t5290;
  t5965 = 0. + t5736 + t5826;
  t6880 = -1.*t4227*t6835;
  t6885 = t4159*t6852;
  t6889 = t6880 + t6885;
  t6899 = t4159*t6835;
  t6920 = t4227*t6852;
  t6922 = t6899 + t6920;
  t7026 = t313*t924*t907;
  t7039 = t1257*t313*t1124;
  t7051 = t7026 + t7039;
  t7080 = t1257*t313*t924;
  t7089 = -1.*t313*t907*t1124;
  t7092 = t7080 + t7089;
  t7114 = -1.*t678*t940;
  t7115 = t838*t7051;
  t7126 = t7114 + t7115;
  t7138 = t2235*t7092;
  t7155 = t2092*t7126;
  t7164 = t7138 + t7155;
  t7179 = t2092*t7092;
  t7185 = -1.*t2235*t7126;
  t7191 = t7179 + t7185;
  t7208 = -1.*t2976*t7164;
  t7217 = t2826*t7191;
  t7223 = t7208 + t7217;
  t7226 = t2826*t7164;
  t7229 = t2976*t7191;
  t7239 = t7226 + t7229;
  t7261 = t3458*t7223;
  t7269 = t3324*t7239;
  t7274 = t7261 + t7269;
  t7278 = t3324*t7223;
  t7285 = -1.*t3458*t7239;
  t7286 = t7278 + t7285;
  t7292 = -1.*t4227*t7274;
  t7294 = t4159*t7286;
  t7296 = t7292 + t7294;
  t7308 = t4159*t7274;
  t7311 = t4227*t7286;
  t7324 = t7308 + t7311;
  p_output1[0]=0. + t1299*t1509 + t1557*t1992 + t2291*t2336 + t2707*t2805 + t3033*t3053 + t3182*t3230 + t3585*t3625 + t3727*t3972 + t4442*t4659 + t4833*t5007 + t5382*t5661 + t5965*t6153 + 0.077577*(t5290*t5661 + t5069*t6153) - 1.059658*(t5069*t5661 - 1.*t5290*t6153) - 0.1305*(t1992*t678 - 1.*t190*t313*t838) + t190*t313*t900 + t1162*t917 + var1[0];
  p_output1[1]=0. + t1299*t6484 + t1557*t6514 + t2291*t6546 + t2707*t6657 + t3033*t6687 + t3182*t6730 + t3585*t6762 + t3727*t6811 + t4442*t6835 + t4833*t6852 + t5382*t6889 + t5965*t6922 + 0.077577*(t5290*t6889 + t5069*t6922) - 1.059658*(t5069*t6889 - 1.*t5290*t6922) - 0.1305*(t6514*t678 - 1.*t1051*t313*t838) + t1051*t313*t900 + t6438*t917 + var1[1];
  p_output1[2]=0. + t1124*t1299*t313 + t1557*t7051 + t2291*t7092 + t2707*t7126 + t3033*t7164 + t3182*t7191 + t3585*t7223 + t3727*t7239 + t4442*t7274 + t4833*t7286 + t5382*t7296 + t5965*t7324 + 0.077577*(t5290*t7296 + t5069*t7324) - 1.059658*(t5069*t7296 - 1.*t5290*t7324) + t313*t917*t924 - 1.*t900*t940 - 0.1305*(t678*t7051 + t838*t940) + var1[2];
}



void RightToeBottomFront_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
