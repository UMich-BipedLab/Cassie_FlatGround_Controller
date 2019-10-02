/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:38 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "LeftToeBottomFront_src.h"

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
  double t417;
  double t362;
  double t459;
  double t386;
  double t487;
  double t165;
  double t411;
  double t499;
  double t522;
  double t533;
  double t543;
  double t557;
  double t568;
  double t885;
  double t891;
  double t896;
  double t918;
  double t710;
  double t816;
  double t827;
  double t952;
  double t1183;
  double t1207;
  double t1214;
  double t1224;
  double t1162;
  double t1166;
  double t1177;
  double t1262;
  double t1275;
  double t1311;
  double t1503;
  double t1514;
  double t1517;
  double t1524;
  double t1539;
  double t1557;
  double t1564;
  double t1767;
  double t1782;
  double t1800;
  double t1830;
  double t1857;
  double t1894;
  double t1917;
  double t2137;
  double t2165;
  double t2206;
  double t2296;
  double t2336;
  double t2366;
  double t2386;
  double t2396;
  double t2428;
  double t2430;
  double t2474;
  double t2520;
  double t2538;
  double t2733;
  double t2744;
  double t2752;
  double t2766;
  double t2772;
  double t2777;
  double t2783;
  double t2798;
  double t2805;
  double t2812;
  double t2855;
  double t2865;
  double t2926;
  double t176;
  double t321;
  double t327;
  double t329;
  double t576;
  double t581;
  double t3068;
  double t3087;
  double t3094;
  double t3161;
  double t3171;
  double t3212;
  double t900;
  double t940;
  double t943;
  double t1010;
  double t1119;
  double t1120;
  double t3230;
  double t3281;
  double t3288;
  double t1217;
  double t1225;
  double t1237;
  double t1324;
  double t1460;
  double t1476;
  double t1522;
  double t1529;
  double t1532;
  double t3458;
  double t3469;
  double t3475;
  double t3507;
  double t3514;
  double t3542;
  double t1698;
  double t1708;
  double t1761;
  double t1915;
  double t2063;
  double t2126;
  double t3591;
  double t3606;
  double t3616;
  double t3644;
  double t3659;
  double t3666;
  double t2235;
  double t2254;
  double t2290;
  double t2429;
  double t2452;
  double t2462;
  double t3675;
  double t3718;
  double t3727;
  double t3940;
  double t3972;
  double t3984;
  double t2598;
  double t2630;
  double t2632;
  double t2782;
  double t2789;
  double t2790;
  double t4046;
  double t4056;
  double t4096;
  double t4159;
  double t4198;
  double t4206;
  double t2826;
  double t2827;
  double t2838;
  double t4355;
  double t4362;
  double t4596;
  double t4685;
  double t4739;
  double t4751;
  double t5361;
  double t5382;
  double t5455;
  double t5801;
  double t5826;
  double t5904;
  double t6011;
  double t6017;
  double t6026;
  double t6083;
  double t6111;
  double t6123;
  double t6167;
  double t6170;
  double t6221;
  double t6248;
  double t6258;
  double t6291;
  double t6330;
  double t6332;
  double t6337;
  double t6360;
  double t6362;
  double t6367;
  double t6372;
  double t6378;
  double t6379;
  double t6392;
  double t6398;
  double t6417;
  double t6431;
  double t6438;
  double t6450;
  t417 = Cos(var1[3]);
  t362 = Cos(var1[5]);
  t459 = Sin(var1[4]);
  t386 = Sin(var1[3]);
  t487 = Sin(var1[5]);
  t165 = Cos(var1[6]);
  t411 = -1.*t362*t386;
  t499 = t417*t459*t487;
  t522 = t411 + t499;
  t533 = t417*t362*t459;
  t543 = t386*t487;
  t557 = t533 + t543;
  t568 = Sin(var1[6]);
  t885 = Cos(var1[7]);
  t891 = -1.*t885;
  t896 = 1. + t891;
  t918 = Sin(var1[7]);
  t710 = t165*t522;
  t816 = t557*t568;
  t827 = t710 + t816;
  t952 = Cos(var1[4]);
  t1183 = Cos(var1[8]);
  t1207 = -1.*t1183;
  t1214 = 1. + t1207;
  t1224 = Sin(var1[8]);
  t1162 = t417*t952*t885;
  t1166 = t827*t918;
  t1177 = t1162 + t1166;
  t1262 = t165*t557;
  t1275 = -1.*t522*t568;
  t1311 = t1262 + t1275;
  t1503 = Cos(var1[9]);
  t1514 = -1.*t1503;
  t1517 = 1. + t1514;
  t1524 = Sin(var1[9]);
  t1539 = t1183*t1177;
  t1557 = t1311*t1224;
  t1564 = t1539 + t1557;
  t1767 = t1183*t1311;
  t1782 = -1.*t1177*t1224;
  t1800 = t1767 + t1782;
  t1830 = Cos(var1[10]);
  t1857 = -1.*t1830;
  t1894 = 1. + t1857;
  t1917 = Sin(var1[10]);
  t2137 = -1.*t1524*t1564;
  t2165 = t1503*t1800;
  t2206 = t2137 + t2165;
  t2296 = t1503*t1564;
  t2336 = t1524*t1800;
  t2366 = t2296 + t2336;
  t2386 = Cos(var1[11]);
  t2396 = -1.*t2386;
  t2428 = 1. + t2396;
  t2430 = Sin(var1[11]);
  t2474 = t1917*t2206;
  t2520 = t1830*t2366;
  t2538 = t2474 + t2520;
  t2733 = t1830*t2206;
  t2744 = -1.*t1917*t2366;
  t2752 = t2733 + t2744;
  t2766 = Cos(var1[12]);
  t2772 = -1.*t2766;
  t2777 = 1. + t2772;
  t2783 = Sin(var1[12]);
  t2798 = -1.*t2430*t2538;
  t2805 = t2386*t2752;
  t2812 = t2798 + t2805;
  t2855 = t2386*t2538;
  t2865 = t2430*t2752;
  t2926 = t2855 + t2865;
  t176 = -1.*t165;
  t321 = 1. + t176;
  t327 = 0.135*t321;
  t329 = 0. + t327;
  t576 = -0.135*t568;
  t581 = 0. + t576;
  t3068 = t417*t362;
  t3087 = t386*t459*t487;
  t3094 = t3068 + t3087;
  t3161 = t362*t386*t459;
  t3171 = -1.*t417*t487;
  t3212 = t3161 + t3171;
  t900 = 0.135*t896;
  t940 = 0.049*t918;
  t943 = 0. + t900 + t940;
  t1010 = -0.049*t896;
  t1119 = 0.135*t918;
  t1120 = 0. + t1010 + t1119;
  t3230 = t165*t3094;
  t3281 = t3212*t568;
  t3288 = t3230 + t3281;
  t1217 = -0.049*t1214;
  t1225 = -0.09*t1224;
  t1237 = 0. + t1217 + t1225;
  t1324 = -0.09*t1214;
  t1460 = 0.049*t1224;
  t1476 = 0. + t1324 + t1460;
  t1522 = -0.049*t1517;
  t1529 = -0.21*t1524;
  t1532 = 0. + t1522 + t1529;
  t3458 = t952*t885*t386;
  t3469 = t3288*t918;
  t3475 = t3458 + t3469;
  t3507 = t165*t3212;
  t3514 = -1.*t3094*t568;
  t3542 = t3507 + t3514;
  t1698 = -0.21*t1517;
  t1708 = 0.049*t1524;
  t1761 = 0. + t1698 + t1708;
  t1915 = -0.2707*t1894;
  t2063 = 0.0016*t1917;
  t2126 = 0. + t1915 + t2063;
  t3591 = t1183*t3475;
  t3606 = t3542*t1224;
  t3616 = t3591 + t3606;
  t3644 = t1183*t3542;
  t3659 = -1.*t3475*t1224;
  t3666 = t3644 + t3659;
  t2235 = -0.0016*t1894;
  t2254 = -0.2707*t1917;
  t2290 = 0. + t2235 + t2254;
  t2429 = 0.0184*t2428;
  t2452 = -0.7055*t2430;
  t2462 = 0. + t2429 + t2452;
  t3675 = -1.*t1524*t3616;
  t3718 = t1503*t3666;
  t3727 = t3675 + t3718;
  t3940 = t1503*t3616;
  t3972 = t1524*t3666;
  t3984 = t3940 + t3972;
  t2598 = -0.7055*t2428;
  t2630 = -0.0184*t2430;
  t2632 = 0. + t2598 + t2630;
  t2782 = -1.1135*t2777;
  t2789 = 0.0216*t2783;
  t2790 = 0. + t2782 + t2789;
  t4046 = t1917*t3727;
  t4056 = t1830*t3984;
  t4096 = t4046 + t4056;
  t4159 = t1830*t3727;
  t4198 = -1.*t1917*t3984;
  t4206 = t4159 + t4198;
  t2826 = -0.0216*t2777;
  t2827 = -1.1135*t2783;
  t2838 = 0. + t2826 + t2827;
  t4355 = -1.*t2430*t4096;
  t4362 = t2386*t4206;
  t4596 = t4355 + t4362;
  t4685 = t2386*t4096;
  t4739 = t2430*t4206;
  t4751 = t4685 + t4739;
  t5361 = t952*t165*t487;
  t5382 = t952*t362*t568;
  t5455 = t5361 + t5382;
  t5801 = -1.*t885*t459;
  t5826 = t5455*t918;
  t5904 = t5801 + t5826;
  t6011 = t952*t362*t165;
  t6017 = -1.*t952*t487*t568;
  t6026 = t6011 + t6017;
  t6083 = t1183*t5904;
  t6111 = t6026*t1224;
  t6123 = t6083 + t6111;
  t6167 = t1183*t6026;
  t6170 = -1.*t5904*t1224;
  t6221 = t6167 + t6170;
  t6248 = -1.*t1524*t6123;
  t6258 = t1503*t6221;
  t6291 = t6248 + t6258;
  t6330 = t1503*t6123;
  t6332 = t1524*t6221;
  t6337 = t6330 + t6332;
  t6360 = t1917*t6291;
  t6362 = t1830*t6337;
  t6367 = t6360 + t6362;
  t6372 = t1830*t6291;
  t6378 = -1.*t1917*t6337;
  t6379 = t6372 + t6378;
  t6392 = -1.*t2430*t6367;
  t6398 = t2386*t6379;
  t6417 = t6392 + t6398;
  t6431 = t2386*t6367;
  t6438 = t2430*t6379;
  t6450 = t6431 + t6438;
  p_output1[0]=0. + t1177*t1237 + t1311*t1476 + t1532*t1564 + t1761*t1800 + t2126*t2206 + t2290*t2366 + t2462*t2538 + t2632*t2752 + t2790*t2812 + t2838*t2926 + 0.077577*(t2783*t2812 + t2766*t2926) - 1.059658*(t2766*t2812 - 1.*t2783*t2926) + t329*t522 + t557*t581 + t827*t943 + t1120*t417*t952 + 0.1305*(t827*t885 - 1.*t417*t918*t952) + var1[0];
  p_output1[1]=0. + t3094*t329 + t1237*t3475 + t1476*t3542 + t1532*t3616 + t1761*t3666 + t2126*t3727 + t2290*t3984 + t2462*t4096 + t2632*t4206 + t2790*t4596 + t2838*t4751 + 0.077577*(t2783*t4596 + t2766*t4751) - 1.059658*(t2766*t4596 - 1.*t2783*t4751) + t3212*t581 + t3288*t943 + t1120*t386*t952 + 0.1305*(t3288*t885 - 1.*t386*t918*t952) + var1[1];
  p_output1[2]=0. - 1.*t1120*t459 + t1237*t5904 + t1476*t6026 + t1532*t6123 + t1761*t6221 + t2126*t6291 + t2290*t6337 + t2462*t6367 + t2632*t6379 + t2790*t6417 + t2838*t6450 + 0.077577*(t2783*t6417 + t2766*t6450) - 1.059658*(t2766*t6417 - 1.*t2783*t6450) + 0.1305*(t5455*t885 + t459*t918) + t5455*t943 + t329*t487*t952 + t362*t581*t952 + var1[2];
}



void LeftToeBottomFront_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
