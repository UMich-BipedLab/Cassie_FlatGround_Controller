/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:32 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "LeftToeBottomBack_src.h"

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
  double t1518;
  double t1236;
  double t1625;
  double t1242;
  double t1742;
  double t538;
  double t1271;
  double t1749;
  double t1754;
  double t1864;
  double t1867;
  double t2115;
  double t2247;
  double t2951;
  double t3162;
  double t3318;
  double t3358;
  double t2590;
  double t2863;
  double t2936;
  double t3619;
  double t4252;
  double t4339;
  double t4347;
  double t4372;
  double t4194;
  double t4239;
  double t4250;
  double t4447;
  double t4457;
  double t4477;
  double t4557;
  double t4571;
  double t4576;
  double t4592;
  double t4603;
  double t4605;
  double t4619;
  double t4687;
  double t4700;
  double t4703;
  double t4716;
  double t4719;
  double t4730;
  double t4749;
  double t4785;
  double t4791;
  double t4794;
  double t4831;
  double t4834;
  double t4842;
  double t4856;
  double t4874;
  double t4881;
  double t4891;
  double t4916;
  double t4928;
  double t4932;
  double t4971;
  double t4976;
  double t4981;
  double t4991;
  double t4998;
  double t5000;
  double t5012;
  double t5018;
  double t5026;
  double t5027;
  double t5079;
  double t5083;
  double t5088;
  double t631;
  double t707;
  double t1044;
  double t1194;
  double t2295;
  double t2328;
  double t5184;
  double t5191;
  double t5198;
  double t5209;
  double t5212;
  double t5213;
  double t3348;
  double t3443;
  double t3564;
  double t3670;
  double t3678;
  double t4057;
  double t5219;
  double t5220;
  double t5225;
  double t4369;
  double t4388;
  double t4419;
  double t4489;
  double t4491;
  double t4498;
  double t4581;
  double t4595;
  double t4597;
  double t5257;
  double t5259;
  double t5260;
  double t5269;
  double t5271;
  double t5289;
  double t4668;
  double t4675;
  double t4683;
  double t4737;
  double t4763;
  double t4774;
  double t5302;
  double t5306;
  double t5319;
  double t5324;
  double t5330;
  double t5338;
  double t4809;
  double t4817;
  double t4819;
  double t4890;
  double t4899;
  double t4914;
  double t5356;
  double t5368;
  double t5373;
  double t5379;
  double t5382;
  double t5392;
  double t4949;
  double t4952;
  double t4964;
  double t5005;
  double t5014;
  double t5017;
  double t5412;
  double t5424;
  double t5434;
  double t5442;
  double t5443;
  double t5448;
  double t5041;
  double t5046;
  double t5047;
  double t5458;
  double t5462;
  double t5467;
  double t5475;
  double t5486;
  double t5491;
  double t5533;
  double t5536;
  double t5542;
  double t5568;
  double t5569;
  double t5576;
  double t5586;
  double t5591;
  double t5596;
  double t5606;
  double t5611;
  double t5614;
  double t5619;
  double t5620;
  double t5621;
  double t5625;
  double t5628;
  double t5629;
  double t5633;
  double t5634;
  double t5644;
  double t5664;
  double t5668;
  double t5670;
  double t5676;
  double t5678;
  double t5682;
  double t5691;
  double t5700;
  double t5701;
  double t5714;
  double t5718;
  double t5723;
  t1518 = Cos(var1[3]);
  t1236 = Cos(var1[5]);
  t1625 = Sin(var1[4]);
  t1242 = Sin(var1[3]);
  t1742 = Sin(var1[5]);
  t538 = Cos(var1[6]);
  t1271 = -1.*t1236*t1242;
  t1749 = t1518*t1625*t1742;
  t1754 = t1271 + t1749;
  t1864 = t1518*t1236*t1625;
  t1867 = t1242*t1742;
  t2115 = t1864 + t1867;
  t2247 = Sin(var1[6]);
  t2951 = Cos(var1[7]);
  t3162 = -1.*t2951;
  t3318 = 1. + t3162;
  t3358 = Sin(var1[7]);
  t2590 = t538*t1754;
  t2863 = t2115*t2247;
  t2936 = t2590 + t2863;
  t3619 = Cos(var1[4]);
  t4252 = Cos(var1[8]);
  t4339 = -1.*t4252;
  t4347 = 1. + t4339;
  t4372 = Sin(var1[8]);
  t4194 = t1518*t3619*t2951;
  t4239 = t2936*t3358;
  t4250 = t4194 + t4239;
  t4447 = t538*t2115;
  t4457 = -1.*t1754*t2247;
  t4477 = t4447 + t4457;
  t4557 = Cos(var1[9]);
  t4571 = -1.*t4557;
  t4576 = 1. + t4571;
  t4592 = Sin(var1[9]);
  t4603 = t4252*t4250;
  t4605 = t4477*t4372;
  t4619 = t4603 + t4605;
  t4687 = t4252*t4477;
  t4700 = -1.*t4250*t4372;
  t4703 = t4687 + t4700;
  t4716 = Cos(var1[10]);
  t4719 = -1.*t4716;
  t4730 = 1. + t4719;
  t4749 = Sin(var1[10]);
  t4785 = -1.*t4592*t4619;
  t4791 = t4557*t4703;
  t4794 = t4785 + t4791;
  t4831 = t4557*t4619;
  t4834 = t4592*t4703;
  t4842 = t4831 + t4834;
  t4856 = Cos(var1[11]);
  t4874 = -1.*t4856;
  t4881 = 1. + t4874;
  t4891 = Sin(var1[11]);
  t4916 = t4749*t4794;
  t4928 = t4716*t4842;
  t4932 = t4916 + t4928;
  t4971 = t4716*t4794;
  t4976 = -1.*t4749*t4842;
  t4981 = t4971 + t4976;
  t4991 = Cos(var1[12]);
  t4998 = -1.*t4991;
  t5000 = 1. + t4998;
  t5012 = Sin(var1[12]);
  t5018 = -1.*t4891*t4932;
  t5026 = t4856*t4981;
  t5027 = t5018 + t5026;
  t5079 = t4856*t4932;
  t5083 = t4891*t4981;
  t5088 = t5079 + t5083;
  t631 = -1.*t538;
  t707 = 1. + t631;
  t1044 = 0.135*t707;
  t1194 = 0. + t1044;
  t2295 = -0.135*t2247;
  t2328 = 0. + t2295;
  t5184 = t1518*t1236;
  t5191 = t1242*t1625*t1742;
  t5198 = t5184 + t5191;
  t5209 = t1236*t1242*t1625;
  t5212 = -1.*t1518*t1742;
  t5213 = t5209 + t5212;
  t3348 = 0.135*t3318;
  t3443 = 0.049*t3358;
  t3564 = 0. + t3348 + t3443;
  t3670 = -0.049*t3318;
  t3678 = 0.135*t3358;
  t4057 = 0. + t3670 + t3678;
  t5219 = t538*t5198;
  t5220 = t5213*t2247;
  t5225 = t5219 + t5220;
  t4369 = -0.049*t4347;
  t4388 = -0.09*t4372;
  t4419 = 0. + t4369 + t4388;
  t4489 = -0.09*t4347;
  t4491 = 0.049*t4372;
  t4498 = 0. + t4489 + t4491;
  t4581 = -0.049*t4576;
  t4595 = -0.21*t4592;
  t4597 = 0. + t4581 + t4595;
  t5257 = t3619*t2951*t1242;
  t5259 = t5225*t3358;
  t5260 = t5257 + t5259;
  t5269 = t538*t5213;
  t5271 = -1.*t5198*t2247;
  t5289 = t5269 + t5271;
  t4668 = -0.21*t4576;
  t4675 = 0.049*t4592;
  t4683 = 0. + t4668 + t4675;
  t4737 = -0.2707*t4730;
  t4763 = 0.0016*t4749;
  t4774 = 0. + t4737 + t4763;
  t5302 = t4252*t5260;
  t5306 = t5289*t4372;
  t5319 = t5302 + t5306;
  t5324 = t4252*t5289;
  t5330 = -1.*t5260*t4372;
  t5338 = t5324 + t5330;
  t4809 = -0.0016*t4730;
  t4817 = -0.2707*t4749;
  t4819 = 0. + t4809 + t4817;
  t4890 = 0.0184*t4881;
  t4899 = -0.7055*t4891;
  t4914 = 0. + t4890 + t4899;
  t5356 = -1.*t4592*t5319;
  t5368 = t4557*t5338;
  t5373 = t5356 + t5368;
  t5379 = t4557*t5319;
  t5382 = t4592*t5338;
  t5392 = t5379 + t5382;
  t4949 = -0.7055*t4881;
  t4952 = -0.0184*t4891;
  t4964 = 0. + t4949 + t4952;
  t5005 = -1.1135*t5000;
  t5014 = 0.0216*t5012;
  t5017 = 0. + t5005 + t5014;
  t5412 = t4749*t5373;
  t5424 = t4716*t5392;
  t5434 = t5412 + t5424;
  t5442 = t4716*t5373;
  t5443 = -1.*t4749*t5392;
  t5448 = t5442 + t5443;
  t5041 = -0.0216*t5000;
  t5046 = -1.1135*t5012;
  t5047 = 0. + t5041 + t5046;
  t5458 = -1.*t4891*t5434;
  t5462 = t4856*t5448;
  t5467 = t5458 + t5462;
  t5475 = t4856*t5434;
  t5486 = t4891*t5448;
  t5491 = t5475 + t5486;
  t5533 = t3619*t538*t1742;
  t5536 = t3619*t1236*t2247;
  t5542 = t5533 + t5536;
  t5568 = -1.*t2951*t1625;
  t5569 = t5542*t3358;
  t5576 = t5568 + t5569;
  t5586 = t3619*t1236*t538;
  t5591 = -1.*t3619*t1742*t2247;
  t5596 = t5586 + t5591;
  t5606 = t4252*t5576;
  t5611 = t5596*t4372;
  t5614 = t5606 + t5611;
  t5619 = t4252*t5596;
  t5620 = -1.*t5576*t4372;
  t5621 = t5619 + t5620;
  t5625 = -1.*t4592*t5614;
  t5628 = t4557*t5621;
  t5629 = t5625 + t5628;
  t5633 = t4557*t5614;
  t5634 = t4592*t5621;
  t5644 = t5633 + t5634;
  t5664 = t4749*t5629;
  t5668 = t4716*t5644;
  t5670 = t5664 + t5668;
  t5676 = t4716*t5629;
  t5678 = -1.*t4749*t5644;
  t5682 = t5676 + t5678;
  t5691 = -1.*t4891*t5670;
  t5700 = t4856*t5682;
  t5701 = t5691 + t5700;
  t5714 = t4856*t5670;
  t5718 = t4891*t5682;
  t5723 = t5714 + t5718;
  p_output1[0]=0. + t1194*t1754 + t2115*t2328 + t2936*t3564 + 0.1305*(t2936*t2951 - 1.*t1518*t3358*t3619) + t1518*t3619*t4057 + t4250*t4419 + t4477*t4498 + t4597*t4619 + t4683*t4703 + t4774*t4794 + t4819*t4842 + t4914*t4932 + t4964*t4981 + t5017*t5027 + t5047*t5088 - 0.031697*(t5012*t5027 + t4991*t5088) - 1.189886*(t4991*t5027 - 1.*t5012*t5088) + var1[0];
  p_output1[1]=0. + t1242*t3619*t4057 + t1194*t5198 + t2328*t5213 + t3564*t5225 + 0.1305*(-1.*t1242*t3358*t3619 + t2951*t5225) + t4419*t5260 + t4498*t5289 + t4597*t5319 + t4683*t5338 + t4774*t5373 + t4819*t5392 + t4914*t5434 + t4964*t5448 + t5017*t5467 + t5047*t5491 - 0.031697*(t5012*t5467 + t4991*t5491) - 1.189886*(t4991*t5467 - 1.*t5012*t5491) + var1[1];
  p_output1[2]=0. + t1194*t1742*t3619 + t1236*t2328*t3619 - 1.*t1625*t4057 + t3564*t5542 + 0.1305*(t1625*t3358 + t2951*t5542) + t4419*t5576 + t4498*t5596 + t4597*t5614 + t4683*t5621 + t4774*t5629 + t4819*t5644 + t4914*t5670 + t4964*t5682 + t5017*t5701 + t5047*t5723 - 0.031697*(t5012*t5701 + t4991*t5723) - 1.189886*(t4991*t5701 - 1.*t5012*t5723) + var1[2];
}



void LeftToeBottomBack_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
