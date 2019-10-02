/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:33 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RightToeBottomBack_src.h"

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
  double t705;
  double t2530;
  double t2753;
  double t2536;
  double t2775;
  double t1508;
  double t1795;
  double t1867;
  double t2305;
  double t2328;
  double t2586;
  double t2815;
  double t2822;
  double t3564;
  double t4388;
  double t4419;
  double t4498;
  double t1497;
  double t4659;
  double t4668;
  double t4675;
  double t4687;
  double t4763;
  double t4794;
  double t4851;
  double t4916;
  double t4971;
  double t4981;
  double t5184;
  double t5191;
  double t5205;
  double t5213;
  double t5219;
  double t5220;
  double t5257;
  double t5324;
  double t5344;
  double t5368;
  double t5412;
  double t5436;
  double t5442;
  double t5500;
  double t5501;
  double t5504;
  double t5509;
  double t5532;
  double t5536;
  double t5553;
  double t5579;
  double t5596;
  double t5601;
  double t5616;
  double t5619;
  double t5621;
  double t5630;
  double t5673;
  double t5676;
  double t5684;
  double t5736;
  double t5737;
  double t5739;
  double t5747;
  double t5749;
  double t5758;
  double t5760;
  double t5776;
  double t5779;
  double t5785;
  double t5803;
  double t5805;
  double t5809;
  double t2239;
  double t2311;
  double t2323;
  double t2343;
  double t2347;
  double t3646;
  double t3678;
  double t4194;
  double t4369;
  double t4595;
  double t4597;
  double t4603;
  double t5891;
  double t5892;
  double t5895;
  double t5899;
  double t5901;
  double t5907;
  double t4831;
  double t4890;
  double t4914;
  double t5910;
  double t5911;
  double t5916;
  double t5127;
  double t5144;
  double t5154;
  double t5245;
  double t5302;
  double t5321;
  double t5928;
  double t5934;
  double t5942;
  double t5965;
  double t5970;
  double t5974;
  double t5379;
  double t5382;
  double t5408;
  double t5507;
  double t5514;
  double t5522;
  double t5981;
  double t5988;
  double t5989;
  double t6001;
  double t6005;
  double t6011;
  double t5557;
  double t5558;
  double t5569;
  double t5629;
  double t5633;
  double t5648;
  double t6015;
  double t6017;
  double t6020;
  double t6025;
  double t6030;
  double t6031;
  double t5718;
  double t5732;
  double t5735;
  double t5759;
  double t5771;
  double t5772;
  double t6035;
  double t6037;
  double t6042;
  double t6050;
  double t6053;
  double t6054;
  double t5797;
  double t5798;
  double t5801;
  double t6066;
  double t6067;
  double t6068;
  double t6073;
  double t6074;
  double t6076;
  double t6100;
  double t6101;
  double t6102;
  double t6111;
  double t6112;
  double t6116;
  double t6127;
  double t6130;
  double t6131;
  double t6141;
  double t6143;
  double t6147;
  double t6150;
  double t6152;
  double t6153;
  double t6156;
  double t6158;
  double t6161;
  double t6163;
  double t6167;
  double t6169;
  double t6172;
  double t6173;
  double t6175;
  double t6179;
  double t6180;
  double t6183;
  double t6189;
  double t6190;
  double t6192;
  double t6195;
  double t6199;
  double t6200;
  t705 = Cos(var1[3]);
  t2530 = Cos(var1[5]);
  t2753 = Sin(var1[3]);
  t2536 = Sin(var1[4]);
  t2775 = Sin(var1[5]);
  t1508 = Cos(var1[14]);
  t1795 = -1.*t1508;
  t1867 = 1. + t1795;
  t2305 = Sin(var1[14]);
  t2328 = Sin(var1[13]);
  t2586 = t705*t2530*t2536;
  t2815 = t2753*t2775;
  t2822 = t2586 + t2815;
  t3564 = Cos(var1[13]);
  t4388 = -1.*t2530*t2753;
  t4419 = t705*t2536*t2775;
  t4498 = t4388 + t4419;
  t1497 = Cos(var1[4]);
  t4659 = t2328*t2822;
  t4668 = t3564*t4498;
  t4675 = t4659 + t4668;
  t4687 = Cos(var1[15]);
  t4763 = -1.*t4687;
  t4794 = 1. + t4763;
  t4851 = Sin(var1[15]);
  t4916 = t3564*t2822;
  t4971 = -1.*t2328*t4498;
  t4981 = t4916 + t4971;
  t5184 = t1508*t705*t1497;
  t5191 = t2305*t4675;
  t5205 = t5184 + t5191;
  t5213 = Cos(var1[16]);
  t5219 = -1.*t5213;
  t5220 = 1. + t5219;
  t5257 = Sin(var1[16]);
  t5324 = t4851*t4981;
  t5344 = t4687*t5205;
  t5368 = t5324 + t5344;
  t5412 = t4687*t4981;
  t5436 = -1.*t4851*t5205;
  t5442 = t5412 + t5436;
  t5500 = Cos(var1[17]);
  t5501 = -1.*t5500;
  t5504 = 1. + t5501;
  t5509 = Sin(var1[17]);
  t5532 = -1.*t5257*t5368;
  t5536 = t5213*t5442;
  t5553 = t5532 + t5536;
  t5579 = t5213*t5368;
  t5596 = t5257*t5442;
  t5601 = t5579 + t5596;
  t5616 = Cos(var1[18]);
  t5619 = -1.*t5616;
  t5621 = 1. + t5619;
  t5630 = Sin(var1[18]);
  t5673 = t5509*t5553;
  t5676 = t5500*t5601;
  t5684 = t5673 + t5676;
  t5736 = t5500*t5553;
  t5737 = -1.*t5509*t5601;
  t5739 = t5736 + t5737;
  t5747 = Cos(var1[19]);
  t5749 = -1.*t5747;
  t5758 = 1. + t5749;
  t5760 = Sin(var1[19]);
  t5776 = -1.*t5630*t5684;
  t5779 = t5616*t5739;
  t5785 = t5776 + t5779;
  t5803 = t5616*t5684;
  t5805 = t5630*t5739;
  t5809 = t5803 + t5805;
  t2239 = -0.049*t1867;
  t2311 = -0.135*t2305;
  t2323 = 0. + t2239 + t2311;
  t2343 = 0.135*t2328;
  t2347 = 0. + t2343;
  t3646 = -1.*t3564;
  t3678 = 1. + t3646;
  t4194 = -0.135*t3678;
  t4369 = 0. + t4194;
  t4595 = -0.135*t1867;
  t4597 = 0.049*t2305;
  t4603 = 0. + t4595 + t4597;
  t5891 = t2530*t2753*t2536;
  t5892 = -1.*t705*t2775;
  t5895 = t5891 + t5892;
  t5899 = t705*t2530;
  t5901 = t2753*t2536*t2775;
  t5907 = t5899 + t5901;
  t4831 = -0.09*t4794;
  t4890 = 0.049*t4851;
  t4914 = 0. + t4831 + t4890;
  t5910 = t2328*t5895;
  t5911 = t3564*t5907;
  t5916 = t5910 + t5911;
  t5127 = -0.049*t4794;
  t5144 = -0.09*t4851;
  t5154 = 0. + t5127 + t5144;
  t5245 = -0.049*t5220;
  t5302 = -0.21*t5257;
  t5321 = 0. + t5245 + t5302;
  t5928 = t3564*t5895;
  t5934 = -1.*t2328*t5907;
  t5942 = t5928 + t5934;
  t5965 = t1508*t1497*t2753;
  t5970 = t2305*t5916;
  t5974 = t5965 + t5970;
  t5379 = -0.21*t5220;
  t5382 = 0.049*t5257;
  t5408 = 0. + t5379 + t5382;
  t5507 = -0.2707*t5504;
  t5514 = 0.0016*t5509;
  t5522 = 0. + t5507 + t5514;
  t5981 = t4851*t5942;
  t5988 = t4687*t5974;
  t5989 = t5981 + t5988;
  t6001 = t4687*t5942;
  t6005 = -1.*t4851*t5974;
  t6011 = t6001 + t6005;
  t5557 = -0.0016*t5504;
  t5558 = -0.2707*t5509;
  t5569 = 0. + t5557 + t5558;
  t5629 = 0.0184*t5621;
  t5633 = -0.7055*t5630;
  t5648 = 0. + t5629 + t5633;
  t6015 = -1.*t5257*t5989;
  t6017 = t5213*t6011;
  t6020 = t6015 + t6017;
  t6025 = t5213*t5989;
  t6030 = t5257*t6011;
  t6031 = t6025 + t6030;
  t5718 = -0.7055*t5621;
  t5732 = -0.0184*t5630;
  t5735 = 0. + t5718 + t5732;
  t5759 = -1.1135*t5758;
  t5771 = 0.0216*t5760;
  t5772 = 0. + t5759 + t5771;
  t6035 = t5509*t6020;
  t6037 = t5500*t6031;
  t6042 = t6035 + t6037;
  t6050 = t5500*t6020;
  t6053 = -1.*t5509*t6031;
  t6054 = t6050 + t6053;
  t5797 = -0.0216*t5758;
  t5798 = -1.1135*t5760;
  t5801 = 0. + t5797 + t5798;
  t6066 = -1.*t5630*t6042;
  t6067 = t5616*t6054;
  t6068 = t6066 + t6067;
  t6073 = t5616*t6042;
  t6074 = t5630*t6054;
  t6076 = t6073 + t6074;
  t6100 = t1497*t2530*t2328;
  t6101 = t3564*t1497*t2775;
  t6102 = t6100 + t6101;
  t6111 = t3564*t1497*t2530;
  t6112 = -1.*t1497*t2328*t2775;
  t6116 = t6111 + t6112;
  t6127 = -1.*t1508*t2536;
  t6130 = t2305*t6102;
  t6131 = t6127 + t6130;
  t6141 = t4851*t6116;
  t6143 = t4687*t6131;
  t6147 = t6141 + t6143;
  t6150 = t4687*t6116;
  t6152 = -1.*t4851*t6131;
  t6153 = t6150 + t6152;
  t6156 = -1.*t5257*t6147;
  t6158 = t5213*t6153;
  t6161 = t6156 + t6158;
  t6163 = t5213*t6147;
  t6167 = t5257*t6153;
  t6169 = t6163 + t6167;
  t6172 = t5509*t6161;
  t6173 = t5500*t6169;
  t6175 = t6172 + t6173;
  t6179 = t5500*t6161;
  t6180 = -1.*t5509*t6169;
  t6183 = t6179 + t6180;
  t6189 = -1.*t5630*t6175;
  t6190 = t5616*t6183;
  t6192 = t6189 + t6190;
  t6195 = t5616*t6175;
  t6199 = t5630*t6183;
  t6200 = t6195 + t6199;
  p_output1[0]=0. + t2347*t2822 + t4369*t4498 + t4603*t4675 + t4914*t4981 + t5154*t5205 + t5321*t5368 + t5408*t5442 + t5522*t5553 + t5569*t5601 + t5648*t5684 + t5735*t5739 + t5772*t5785 + t5801*t5809 - 0.031697*(t5760*t5785 + t5747*t5809) - 1.189886*(t5747*t5785 - 1.*t5760*t5809) + t1497*t2323*t705 - 0.1305*(t1508*t4675 - 1.*t1497*t2305*t705) + var1[0];
  p_output1[1]=0. + t1497*t2323*t2753 + t2347*t5895 + t4369*t5907 + t4603*t5916 - 0.1305*(-1.*t1497*t2305*t2753 + t1508*t5916) + t4914*t5942 + t5154*t5974 + t5321*t5989 + t5408*t6011 + t5522*t6020 + t5569*t6031 + t5648*t6042 + t5735*t6054 + t5772*t6068 + t5801*t6076 - 0.031697*(t5760*t6068 + t5747*t6076) - 1.189886*(t5747*t6068 - 1.*t5760*t6076) + var1[1];
  p_output1[2]=0. + t1497*t2347*t2530 - 1.*t2323*t2536 + t1497*t2775*t4369 + t4603*t6102 - 0.1305*(t2305*t2536 + t1508*t6102) + t4914*t6116 + t5154*t6131 + t5321*t6147 + t5408*t6153 + t5522*t6161 + t5569*t6169 + t5648*t6175 + t5735*t6183 + t5772*t6192 + t5801*t6200 - 0.031697*(t5760*t6192 + t5747*t6200) - 1.189886*(t5747*t6192 - 1.*t5760*t6200) + var1[2];
}



void RightToeBottomBack_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
