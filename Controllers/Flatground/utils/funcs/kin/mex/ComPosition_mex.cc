/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:44 GMT-04:00
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
  double t49;
  double t90;
  double t186;
  double t215;
  double t224;
  double t262;
  double t359;
  double t440;
  double t464;
  double t519;
  double t574;
  double t671;
  double t676;
  double t677;
  double t534;
  double t575;
  double t670;
  double t688;
  double t869;
  double t872;
  double t873;
  double t887;
  double t702;
  double t719;
  double t723;
  double t726;
  double t764;
  double t772;
  double t878;
  double t890;
  double t899;
  double t909;
  double t925;
  double t927;
  double t928;
  double t929;
  double t933;
  double t939;
  double t948;
  double t1005;
  double t1024;
  double t1040;
  double t1067;
  double t962;
  double t963;
  double t966;
  double t1046;
  double t1074;
  double t1092;
  double t1097;
  double t1151;
  double t1158;
  double t1175;
  double t1181;
  double t1189;
  double t1219;
  double t1259;
  double t1382;
  double t1397;
  double t1412;
  double t1438;
  double t1270;
  double t1271;
  double t1285;
  double t1424;
  double t1453;
  double t1465;
  double t1467;
  double t1472;
  double t1485;
  double t1487;
  double t1519;
  double t1521;
  double t1527;
  double t1558;
  double t1683;
  double t1720;
  double t1584;
  double t1589;
  double t1607;
  double t1693;
  double t1713;
  double t1719;
  double t1721;
  double t1733;
  double t1734;
  double t1743;
  double t1825;
  double t1863;
  double t1872;
  double t1874;
  double t1994;
  double t2001;
  double t2004;
  double t2011;
  double t1953;
  double t1959;
  double t1966;
  double t2031;
  double t2035;
  double t2037;
  double t2009;
  double t2012;
  double t2029;
  double t2055;
  double t2059;
  double t2067;
  double t2090;
  double t2098;
  double t2109;
  double t2133;
  double t2174;
  double t2276;
  double t2284;
  double t2296;
  double t2317;
  double t2185;
  double t2197;
  double t2219;
  double t518;
  double t2604;
  double t2624;
  double t2609;
  double t2614;
  double t2623;
  double t2640;
  double t2695;
  double t2705;
  double t2706;
  double t2650;
  double t2656;
  double t2683;
  double t2807;
  double t2817;
  double t2823;
  double t2871;
  double t2842;
  double t2877;
  double t2879;
  double t2880;
  double t2887;
  double t2889;
  double t2892;
  double t2893;
  double t2910;
  double t2923;
  double t2934;
  double t2944;
  double t2948;
  double t2969;
  double t3002;
  double t3006;
  double t3010;
  double t3018;
  double t3013;
  double t3043;
  double t3048;
  double t3055;
  double t3056;
  double t3062;
  double t3066;
  double t3071;
  double t3076;
  double t3103;
  double t3110;
  double t3224;
  double t3237;
  double t3238;
  double t3244;
  double t3153;
  double t3177;
  double t3181;
  double t3239;
  double t3255;
  double t3257;
  double t3272;
  double t3274;
  double t3276;
  double t3299;
  double t3301;
  double t3305;
  double t3309;
  double t3313;
  double t3392;
  double t3436;
  double t3331;
  double t3343;
  double t3350;
  double t3408;
  double t3422;
  double t3432;
  double t3455;
  double t3464;
  double t3483;
  double t3487;
  double t3489;
  double t3509;
  double t3519;
  double t3532;
  double t3615;
  double t3621;
  double t3623;
  double t3627;
  double t3559;
  double t3563;
  double t3580;
  double t3633;
  double t3641;
  double t3642;
  double t3625;
  double t3630;
  double t3632;
  double t3658;
  double t3660;
  double t3662;
  double t3689;
  double t3699;
  double t3714;
  double t3716;
  double t3719;
  double t3791;
  double t3797;
  double t3823;
  double t3841;
  double t3748;
  double t3755;
  double t3760;
  double t4044;
  double t4046;
  double t4051;
  double t4081;
  double t4094;
  double t4097;
  double t4072;
  double t4103;
  double t4117;
  double t4118;
  double t4127;
  double t4149;
  double t4163;
  double t4175;
  double t4184;
  double t4187;
  double t4225;
  double t4230;
  double t4237;
  double t4267;
  double t4275;
  double t4298;
  double t4343;
  double t4370;
  double t4371;
  double t4423;
  double t4429;
  double t4437;
  double t4448;
  double t4459;
  double t4498;
  double t4517;
  double t4521;
  double t4532;
  double t4540;
  double t4609;
  double t4618;
  double t4641;
  double t4680;
  double t4681;
  double t4705;
  double t4724;
  double t4727;
  double t4782;
  double t4800;
  double t4801;
  double t4807;
  double t4814;
  double t2304;
  double t2320;
  double t2343;
  double t4830;
  double t4853;
  double t4859;
  double t2361;
  double t2398;
  double t2404;
  double t4905;
  double t4912;
  double t4914;
  double t4060;
  double t5065;
  double t5078;
  double t5135;
  double t5140;
  double t5155;
  double t5094;
  double t5116;
  double t5123;
  double t5183;
  double t5187;
  double t5188;
  double t5225;
  double t5242;
  double t5284;
  double t5286;
  double t5292;
  double t5370;
  double t5381;
  double t5398;
  double t5440;
  double t5450;
  double t5483;
  double t5515;
  double t5544;
  double t5572;
  double t5583;
  double t5594;
  double t5612;
  double t5654;
  double t5683;
  double t5687;
  double t5697;
  double t5732;
  double t5748;
  double t5853;
  double t5857;
  double t5890;
  double t5915;
  double t5920;
  double t5938;
  double t5942;
  double t5943;
  double t3837;
  double t3848;
  double t3866;
  double t5950;
  double t6005;
  double t6008;
  double t3895;
  double t3920;
  double t3952;
  double t6064;
  double t6097;
  double t6103;
  double t6621;
  double t6730;
  double t6776;
  double t6782;
  double t6794;
  double t6805;
  double t6830;
  double t6868;
  double t6955;
  double t6988;
  double t7039;
  double t7115;
  double t7146;
  double t7199;
  double t7231;
  double t7383;
  double t7564;
  double t7601;
  double t7620;
  double t7654;
  double t7687;
  double t7738;
  double t7740;
  double t7748;
  double t7805;
  double t7821;
  double t7822;
  double t7850;
  double t7854;
  double t7871;
  double t7882;
  double t7889;
  double t8000;
  double t8015;
  double t8099;
  double t8116;
  double t8129;
  double t8219;
  double t8227;
  double t8240;
  double t8249;
  double t8277;
  double t8287;
  double t8292;
  double t8306;
  double t8414;
  double t8439;
  double t8443;
  double t6666;
  double t8555;
  double t8558;
  double t8575;
  double t8585;
  double t8590;
  double t8563;
  double t8565;
  double t8568;
  double t8623;
  double t8632;
  double t8633;
  double t8638;
  double t8647;
  double t8661;
  double t8664;
  double t8672;
  double t8690;
  double t8694;
  double t8697;
  double t8699;
  double t8700;
  double t8708;
  double t8713;
  double t8720;
  double t8727;
  double t8730;
  double t8737;
  double t8745;
  double t8746;
  double t8752;
  double t8755;
  double t8757;
  double t8794;
  double t8800;
  double t8831;
  double t8835;
  double t8840;
  double t8865;
  double t8871;
  double t8875;
  double t8882;
  double t8885;
  double t8891;
  double t8904;
  double t8906;
  double t8910;
  double t8911;
  double t8912;
  t49 = Cos(var1[3]);
  t90 = Cos(var1[4]);
  t186 = Cos(var1[5]);
  t215 = Sin(var1[4]);
  t224 = t49*t186*t215;
  t262 = Sin(var1[3]);
  t359 = Sin(var1[5]);
  t440 = t262*t359;
  t464 = t224 + t440;
  t519 = Sin(var1[13]);
  t574 = Cos(var1[13]);
  t671 = -1.*t186*t262;
  t676 = t49*t215*t359;
  t677 = t671 + t676;
  t534 = 0.135*t519*t464;
  t575 = -1.*t574;
  t670 = 1. + t575;
  t688 = -0.135*t670*t677;
  t869 = Cos(var1[14]);
  t872 = -1.*t869;
  t873 = 1. + t872;
  t887 = Sin(var1[14]);
  t702 = t519*t464;
  t719 = t574*t677;
  t723 = t702 + t719;
  t726 = t574*t464;
  t764 = -1.*t519*t677;
  t772 = t726 + t764;
  t878 = -0.049*t873;
  t890 = -0.135*t887;
  t899 = t878 + t890;
  t909 = t49*t90*t899;
  t925 = -0.135*t873;
  t927 = 0.049*t887;
  t928 = t925 + t927;
  t929 = t928*t723;
  t933 = -1.*t49*t90*t887;
  t939 = t869*t723;
  t948 = t933 + t939;
  t1005 = Cos(var1[15]);
  t1024 = -1.*t1005;
  t1040 = 1. + t1024;
  t1067 = Sin(var1[15]);
  t962 = t869*t49*t90;
  t963 = t887*t723;
  t966 = t962 + t963;
  t1046 = -0.09*t1040;
  t1074 = 0.049*t1067;
  t1092 = t1046 + t1074;
  t1097 = t1092*t772;
  t1151 = -0.049*t1040;
  t1158 = -0.09*t1067;
  t1175 = t1151 + t1158;
  t1181 = t1175*t966;
  t1189 = t1067*t772;
  t1219 = t1005*t966;
  t1259 = t1189 + t1219;
  t1382 = Cos(var1[16]);
  t1397 = -1.*t1382;
  t1412 = 1. + t1397;
  t1438 = Sin(var1[16]);
  t1270 = t1005*t772;
  t1271 = -1.*t1067*t966;
  t1285 = t1270 + t1271;
  t1424 = -0.049*t1412;
  t1453 = -0.21*t1438;
  t1465 = t1424 + t1453;
  t1467 = t1465*t1259;
  t1472 = -0.21*t1412;
  t1485 = 0.049*t1438;
  t1487 = t1472 + t1485;
  t1519 = t1487*t1285;
  t1521 = -1.*t1438*t1259;
  t1527 = t1382*t1285;
  t1558 = t1521 + t1527;
  t1683 = Cos(var1[17]);
  t1720 = Sin(var1[17]);
  t1584 = t1382*t1259;
  t1589 = t1438*t1285;
  t1607 = t1584 + t1589;
  t1693 = -1.*t1683;
  t1713 = 1. + t1693;
  t1719 = -0.2707*t1713;
  t1721 = 0.0016*t1720;
  t1733 = t1719 + t1721;
  t1734 = t1733*t1558;
  t1743 = -1. + t1683;
  t1825 = 0.0016*t1743;
  t1863 = -0.2707*t1720;
  t1872 = t1825 + t1863;
  t1874 = t1872*t1607;
  t1994 = Cos(var1[18]);
  t2001 = -1.*t1994;
  t2004 = 1. + t2001;
  t2011 = Sin(var1[18]);
  t1953 = t1683*t1558;
  t1959 = -1.*t1720*t1607;
  t1966 = t1953 + t1959;
  t2031 = t1720*t1558;
  t2035 = t1683*t1607;
  t2037 = t2031 + t2035;
  t2009 = 0.0184*t2004;
  t2012 = -0.7055*t2011;
  t2029 = t2009 + t2012;
  t2055 = t2029*t2037;
  t2059 = -0.7055*t2004;
  t2067 = -0.0184*t2011;
  t2090 = t2059 + t2067;
  t2098 = t2090*t1966;
  t2109 = -1.*t2011*t2037;
  t2133 = t1994*t1966;
  t2174 = t2109 + t2133;
  t2276 = Cos(var1[19]);
  t2284 = -1.*t2276;
  t2296 = 1. + t2284;
  t2317 = Sin(var1[19]);
  t2185 = t1994*t2037;
  t2197 = t2011*t1966;
  t2219 = t2185 + t2197;
  t518 = -0.0233*t49*t90;
  t2604 = Cos(var1[6]);
  t2624 = Sin(var1[6]);
  t2609 = -1.*t2604;
  t2614 = 1. + t2609;
  t2623 = 0.135*t2614*t677;
  t2640 = -0.135*t464*t2624;
  t2695 = t2604*t464;
  t2705 = -1.*t677*t2624;
  t2706 = t2695 + t2705;
  t2650 = t2604*t677;
  t2656 = t464*t2624;
  t2683 = t2650 + t2656;
  t2807 = Cos(var1[7]);
  t2817 = -1.*t2807;
  t2823 = 1. + t2817;
  t2871 = Sin(var1[7]);
  t2842 = 0.135*t2823;
  t2877 = 0.049*t2871;
  t2879 = t2842 + t2877;
  t2880 = t2683*t2879;
  t2887 = -0.049*t2823;
  t2889 = 0.135*t2871;
  t2892 = t2887 + t2889;
  t2893 = t49*t90*t2892;
  t2910 = t2807*t2683;
  t2923 = -1.*t49*t90*t2871;
  t2934 = t2910 + t2923;
  t2944 = t49*t90*t2807;
  t2948 = t2683*t2871;
  t2969 = t2944 + t2948;
  t3002 = Cos(var1[8]);
  t3006 = -1.*t3002;
  t3010 = 1. + t3006;
  t3018 = Sin(var1[8]);
  t3013 = -0.049*t3010;
  t3043 = -0.09*t3018;
  t3048 = t3013 + t3043;
  t3055 = t2969*t3048;
  t3056 = -0.09*t3010;
  t3062 = 0.049*t3018;
  t3066 = t3056 + t3062;
  t3071 = t2706*t3066;
  t3076 = t3002*t2969;
  t3103 = t2706*t3018;
  t3110 = t3076 + t3103;
  t3224 = Cos(var1[9]);
  t3237 = -1.*t3224;
  t3238 = 1. + t3237;
  t3244 = Sin(var1[9]);
  t3153 = t3002*t2706;
  t3177 = -1.*t2969*t3018;
  t3181 = t3153 + t3177;
  t3239 = -0.049*t3238;
  t3255 = -0.21*t3244;
  t3257 = t3239 + t3255;
  t3272 = t3257*t3110;
  t3274 = -0.21*t3238;
  t3276 = 0.049*t3244;
  t3299 = t3274 + t3276;
  t3301 = t3299*t3181;
  t3305 = -1.*t3244*t3110;
  t3309 = t3224*t3181;
  t3313 = t3305 + t3309;
  t3392 = Cos(var1[10]);
  t3436 = Sin(var1[10]);
  t3331 = t3224*t3110;
  t3343 = t3244*t3181;
  t3350 = t3331 + t3343;
  t3408 = -1.*t3392;
  t3422 = 1. + t3408;
  t3432 = -0.2707*t3422;
  t3455 = 0.0016*t3436;
  t3464 = t3432 + t3455;
  t3483 = t3464*t3313;
  t3487 = -1. + t3392;
  t3489 = 0.0016*t3487;
  t3509 = -0.2707*t3436;
  t3519 = t3489 + t3509;
  t3532 = t3519*t3350;
  t3615 = Cos(var1[11]);
  t3621 = -1.*t3615;
  t3623 = 1. + t3621;
  t3627 = Sin(var1[11]);
  t3559 = t3392*t3313;
  t3563 = -1.*t3436*t3350;
  t3580 = t3559 + t3563;
  t3633 = t3436*t3313;
  t3641 = t3392*t3350;
  t3642 = t3633 + t3641;
  t3625 = 0.0184*t3623;
  t3630 = -0.7055*t3627;
  t3632 = t3625 + t3630;
  t3658 = t3632*t3642;
  t3660 = -0.7055*t3623;
  t3662 = -0.0184*t3627;
  t3689 = t3660 + t3662;
  t3699 = t3689*t3580;
  t3714 = -1.*t3627*t3642;
  t3716 = t3615*t3580;
  t3719 = t3714 + t3716;
  t3791 = Cos(var1[12]);
  t3797 = -1.*t3791;
  t3823 = 1. + t3797;
  t3841 = Sin(var1[12]);
  t3748 = t3615*t3642;
  t3755 = t3627*t3580;
  t3760 = t3748 + t3755;
  t4044 = t186*t262*t215;
  t4046 = -1.*t49*t359;
  t4051 = t4044 + t4046;
  t4081 = t49*t186;
  t4094 = t262*t215*t359;
  t4097 = t4081 + t4094;
  t4072 = 0.135*t519*t4051;
  t4103 = -0.135*t670*t4097;
  t4117 = t519*t4051;
  t4118 = t574*t4097;
  t4127 = t4117 + t4118;
  t4149 = t574*t4051;
  t4163 = -1.*t519*t4097;
  t4175 = t4149 + t4163;
  t4184 = t90*t899*t262;
  t4187 = t928*t4127;
  t4225 = -1.*t90*t887*t262;
  t4230 = t869*t4127;
  t4237 = t4225 + t4230;
  t4267 = t869*t90*t262;
  t4275 = t887*t4127;
  t4298 = t4267 + t4275;
  t4343 = t1092*t4175;
  t4370 = t1175*t4298;
  t4371 = t1067*t4175;
  t4423 = t1005*t4298;
  t4429 = t4371 + t4423;
  t4437 = t1005*t4175;
  t4448 = -1.*t1067*t4298;
  t4459 = t4437 + t4448;
  t4498 = t1465*t4429;
  t4517 = t1487*t4459;
  t4521 = -1.*t1438*t4429;
  t4532 = t1382*t4459;
  t4540 = t4521 + t4532;
  t4609 = t1382*t4429;
  t4618 = t1438*t4459;
  t4641 = t4609 + t4618;
  t4680 = t1733*t4540;
  t4681 = t1872*t4641;
  t4705 = t1683*t4540;
  t4724 = -1.*t1720*t4641;
  t4727 = t4705 + t4724;
  t4782 = t1720*t4540;
  t4800 = t1683*t4641;
  t4801 = t4782 + t4800;
  t4807 = t2029*t4801;
  t4814 = t2090*t4727;
  t2304 = -1.1135*t2296;
  t2320 = 0.0216*t2317;
  t2343 = t2304 + t2320;
  t4830 = -1.*t2011*t4801;
  t4853 = t1994*t4727;
  t4859 = t4830 + t4853;
  t2361 = -0.0216*t2296;
  t2398 = -1.1135*t2317;
  t2404 = t2361 + t2398;
  t4905 = t1994*t4801;
  t4912 = t2011*t4727;
  t4914 = t4905 + t4912;
  t4060 = -0.0233*t90*t262;
  t5065 = 0.135*t2614*t4097;
  t5078 = -0.135*t4051*t2624;
  t5135 = t2604*t4051;
  t5140 = -1.*t4097*t2624;
  t5155 = t5135 + t5140;
  t5094 = t2604*t4097;
  t5116 = t4051*t2624;
  t5123 = t5094 + t5116;
  t5183 = t5123*t2879;
  t5187 = t90*t262*t2892;
  t5188 = t2807*t5123;
  t5225 = -1.*t90*t262*t2871;
  t5242 = t5188 + t5225;
  t5284 = t90*t2807*t262;
  t5286 = t5123*t2871;
  t5292 = t5284 + t5286;
  t5370 = t5292*t3048;
  t5381 = t5155*t3066;
  t5398 = t3002*t5292;
  t5440 = t5155*t3018;
  t5450 = t5398 + t5440;
  t5483 = t3002*t5155;
  t5515 = -1.*t5292*t3018;
  t5544 = t5483 + t5515;
  t5572 = t3257*t5450;
  t5583 = t3299*t5544;
  t5594 = -1.*t3244*t5450;
  t5612 = t3224*t5544;
  t5654 = t5594 + t5612;
  t5683 = t3224*t5450;
  t5687 = t3244*t5544;
  t5697 = t5683 + t5687;
  t5732 = t3464*t5654;
  t5748 = t3519*t5697;
  t5853 = t3392*t5654;
  t5857 = -1.*t3436*t5697;
  t5890 = t5853 + t5857;
  t5915 = t3436*t5654;
  t5920 = t3392*t5697;
  t5938 = t5915 + t5920;
  t5942 = t3632*t5938;
  t5943 = t3689*t5890;
  t3837 = -1.1135*t3823;
  t3848 = 0.0216*t3841;
  t3866 = t3837 + t3848;
  t5950 = -1.*t3627*t5938;
  t6005 = t3615*t5890;
  t6008 = t5950 + t6005;
  t3895 = -0.0216*t3823;
  t3920 = -1.1135*t3841;
  t3952 = t3895 + t3920;
  t6064 = t3615*t5938;
  t6097 = t3627*t5890;
  t6103 = t6064 + t6097;
  t6621 = 0.135*t90*t186*t519;
  t6730 = -0.135*t670*t90*t359;
  t6776 = t90*t186*t519;
  t6782 = t574*t90*t359;
  t6794 = t6776 + t6782;
  t6805 = t574*t90*t186;
  t6830 = -1.*t90*t519*t359;
  t6868 = t6805 + t6830;
  t6955 = -1.*t899*t215;
  t6988 = t928*t6794;
  t7039 = t887*t215;
  t7115 = t869*t6794;
  t7146 = t7039 + t7115;
  t7199 = -1.*t869*t215;
  t7231 = t887*t6794;
  t7383 = t7199 + t7231;
  t7564 = t1092*t6868;
  t7601 = t1175*t7383;
  t7620 = t1067*t6868;
  t7654 = t1005*t7383;
  t7687 = t7620 + t7654;
  t7738 = t1005*t6868;
  t7740 = -1.*t1067*t7383;
  t7748 = t7738 + t7740;
  t7805 = t1465*t7687;
  t7821 = t1487*t7748;
  t7822 = -1.*t1438*t7687;
  t7850 = t1382*t7748;
  t7854 = t7822 + t7850;
  t7871 = t1382*t7687;
  t7882 = t1438*t7748;
  t7889 = t7871 + t7882;
  t8000 = t1733*t7854;
  t8015 = t1872*t7889;
  t8099 = t1683*t7854;
  t8116 = -1.*t1720*t7889;
  t8129 = t8099 + t8116;
  t8219 = t1720*t7854;
  t8227 = t1683*t7889;
  t8240 = t8219 + t8227;
  t8249 = t2029*t8240;
  t8277 = t2090*t8129;
  t8287 = -1.*t2011*t8240;
  t8292 = t1994*t8129;
  t8306 = t8287 + t8292;
  t8414 = t1994*t8240;
  t8439 = t2011*t8129;
  t8443 = t8414 + t8439;
  t6666 = 0.0233*t215;
  t8555 = 0.135*t90*t2614*t359;
  t8558 = -0.135*t90*t186*t2624;
  t8575 = t90*t186*t2604;
  t8585 = -1.*t90*t359*t2624;
  t8590 = t8575 + t8585;
  t8563 = t90*t2604*t359;
  t8565 = t90*t186*t2624;
  t8568 = t8563 + t8565;
  t8623 = t8568*t2879;
  t8632 = -1.*t215*t2892;
  t8633 = t2807*t8568;
  t8638 = t215*t2871;
  t8647 = t8633 + t8638;
  t8661 = -1.*t2807*t215;
  t8664 = t8568*t2871;
  t8672 = t8661 + t8664;
  t8690 = t8672*t3048;
  t8694 = t8590*t3066;
  t8697 = t3002*t8672;
  t8699 = t8590*t3018;
  t8700 = t8697 + t8699;
  t8708 = t3002*t8590;
  t8713 = -1.*t8672*t3018;
  t8720 = t8708 + t8713;
  t8727 = t3257*t8700;
  t8730 = t3299*t8720;
  t8737 = -1.*t3244*t8700;
  t8745 = t3224*t8720;
  t8746 = t8737 + t8745;
  t8752 = t3224*t8700;
  t8755 = t3244*t8720;
  t8757 = t8752 + t8755;
  t8794 = t3464*t8746;
  t8800 = t3519*t8757;
  t8831 = t3392*t8746;
  t8835 = -1.*t3436*t8757;
  t8840 = t8831 + t8835;
  t8865 = t3436*t8746;
  t8871 = t3392*t8757;
  t8875 = t8865 + t8871;
  t8882 = t3632*t8875;
  t8885 = t3689*t8840;
  t8891 = -1.*t3627*t8875;
  t8904 = t3615*t8840;
  t8906 = t8891 + t8904;
  t8910 = t3615*t8875;
  t8911 = t3627*t8840;
  t8912 = t8910 + t8911;
  p_output1[0]=0.0313636933885334*(1.17*(t2623 + t2640 - 0.0343*t2706 + t2880 + t2893 + 0.135*t2934 - 0.049*t2969 + var1[0]) + 5.52*(t2623 + t2640 + t2880 + t2893 + 0.1708*t2934 + t3055 + t3071 - 0.0489*t3110 - 0.1498*t3181 + var1[0]) + 0.758*(t2623 + t2640 + t2880 + t2893 + 0.1327*t2934 + t3055 + t3071 + t3272 + t3301 - 0.233*t3313 - 0.0169*t3350 + var1[0]) + 0.577*(t2623 + t2640 + t2880 + t2893 + 0.1303*t2934 + t3055 + t3071 + t3272 + t3301 + 0.0004*(-1.*t3350*t3392 - 1.*t3313*t3436) + t3483 + t3532 - 0.4541*t3580 + var1[0]) + 0.782*(t2623 + t2640 + t2880 + t2893 + 0.1318*t2934 + t3055 + t3071 + t3272 + t3301 + t3483 + t3532 + t3658 + t3699 - 0.816*t3719 - 0.0122*t3760 + var1[0]) + 0.15*(t2623 + t2640 + t2880 + t2893 + 0.1306*t2934 + t3055 + t3071 + t3272 + t3301 + t3483 + t3532 + t3658 + t3699 + 0.0059*(t3760*t3791 + t3719*t3841) - 1.1182*(t3719*t3791 - 1.*t3760*t3841) + t3719*t3866 + t3760*t3952 + var1[0]) + 1.82*(t2623 + t2640 + 0.1351*t2683 + 0.0179*t2706 + t518 + var1[0]) + 1.82*(t518 + t534 + t688 - 0.1351*t723 + 0.0179*t772 + var1[0]) + 10.33*(0.0284*t464 + 0.0507*t49*t90 + var1[0]) + 5.52*(t1097 + t1181 - 0.0489*t1259 - 0.1498*t1285 + t534 + t688 + t909 + t929 - 0.1708*t948 + var1[0]) + 0.758*(t1097 + t1181 + t1467 + t1519 - 0.233*t1558 - 0.0169*t1607 + t534 + t688 + t909 + t929 - 0.1327*t948 + var1[0]) + 0.782*(t1097 + t1181 + t1467 + t1519 + t1734 + t1874 + t2055 + t2098 - 0.816*t2174 - 0.0122*t2219 + t534 + t688 + t909 + t929 - 0.1318*t948 + var1[0]) + 0.15*(t1097 + t1181 + t1467 + t1519 + t1734 + t1874 + t2055 + t2098 + 0.0059*(t2219*t2276 + t2174*t2317) - 1.1182*(t2174*t2276 - 1.*t2219*t2317) + t2174*t2343 + t2219*t2404 + t534 + t688 + t909 + t929 - 0.1306*t948 + var1[0]) + 0.577*(t1097 + t1181 + t1467 + t1519 + 0.0004*(-1.*t1607*t1683 - 1.*t1558*t1720) + t1734 + t1874 - 0.4541*t1966 + t534 + t688 + t909 + t929 - 0.1303*t948 + var1[0]) + 1.17*(t534 + t688 - 0.0343*t772 + t909 + t929 - 0.135*t948 - 0.049*t966 + var1[0]));
  p_output1[1]=0.0313636933885334*(1.82*(t4060 + t4072 + t4103 - 0.1351*t4127 + 0.0179*t4175 + var1[1]) + 1.17*(t4072 + t4103 - 0.0343*t4175 + t4184 + t4187 - 0.135*t4237 - 0.049*t4298 + var1[1]) + 5.52*(t4072 + t4103 + t4184 + t4187 - 0.1708*t4237 + t4343 + t4370 - 0.0489*t4429 - 0.1498*t4459 + var1[1]) + 0.758*(t4072 + t4103 + t4184 + t4187 - 0.1327*t4237 + t4343 + t4370 + t4498 + t4517 - 0.233*t4540 - 0.0169*t4641 + var1[1]) + 0.577*(t4072 + t4103 + t4184 + t4187 - 0.1303*t4237 + t4343 + t4370 + t4498 + t4517 + 0.0004*(-1.*t1720*t4540 - 1.*t1683*t4641) + t4680 + t4681 - 0.4541*t4727 + var1[1]) + 0.782*(t4072 + t4103 + t4184 + t4187 - 0.1318*t4237 + t4343 + t4370 + t4498 + t4517 + t4680 + t4681 + t4807 + t4814 - 0.816*t4859 - 0.0122*t4914 + var1[1]) + 0.15*(t4072 + t4103 + t4184 + t4187 - 0.1306*t4237 + t4343 + t4370 + t4498 + t4517 + t4680 + t4681 + t4807 + t4814 + t2343*t4859 + t2404*t4914 + 0.0059*(t2317*t4859 + t2276*t4914) - 1.1182*(t2276*t4859 - 1.*t2317*t4914) + var1[1]) + 1.82*(t4060 + t5065 + t5078 + 0.1351*t5123 + 0.0179*t5155 + var1[1]) + 1.17*(t5065 + t5078 - 0.0343*t5155 + t5183 + t5187 + 0.135*t5242 - 0.049*t5292 + var1[1]) + 5.52*(t5065 + t5078 + t5183 + t5187 + 0.1708*t5242 + t5370 + t5381 - 0.0489*t5450 - 0.1498*t5544 + var1[1]) + 0.758*(t5065 + t5078 + t5183 + t5187 + 0.1327*t5242 + t5370 + t5381 + t5572 + t5583 - 0.233*t5654 - 0.0169*t5697 + var1[1]) + 0.577*(t5065 + t5078 + t5183 + t5187 + 0.1303*t5242 + t5370 + t5381 + t5572 + t5583 + 0.0004*(-1.*t3436*t5654 - 1.*t3392*t5697) + t5732 + t5748 - 0.4541*t5890 + var1[1]) + 0.782*(t5065 + t5078 + t5183 + t5187 + 0.1318*t5242 + t5370 + t5381 + t5572 + t5583 + t5732 + t5748 + t5942 + t5943 - 0.816*t6008 - 0.0122*t6103 + var1[1]) + 0.15*(t5065 + t5078 + t5183 + t5187 + 0.1306*t5242 + t5370 + t5381 + t5572 + t5583 + t5732 + t5748 + t5942 + t5943 + t3866*t6008 + t3952*t6103 + 0.0059*(t3841*t6008 + t3791*t6103) - 1.1182*(t3791*t6008 - 1.*t3841*t6103) + var1[1]) + 10.33*(0.0284*t4051 + 0.0507*t262*t90 + var1[1]));
  p_output1[2]=0.0313636933885334*(1.82*(t6621 + t6666 + t6730 - 0.1351*t6794 + 0.0179*t6868 + var1[2]) + 1.17*(t6621 + t6730 - 0.0343*t6868 + t6955 + t6988 - 0.135*t7146 - 0.049*t7383 + var1[2]) + 5.52*(t6621 + t6730 + t6955 + t6988 - 0.1708*t7146 + t7564 + t7601 - 0.0489*t7687 - 0.1498*t7748 + var1[2]) + 0.758*(t6621 + t6730 + t6955 + t6988 - 0.1327*t7146 + t7564 + t7601 + t7805 + t7821 - 0.233*t7854 - 0.0169*t7889 + var1[2]) + 0.577*(t6621 + t6730 + t6955 + t6988 - 0.1303*t7146 + t7564 + t7601 + t7805 + t7821 + 0.0004*(-1.*t1720*t7854 - 1.*t1683*t7889) + t8000 + t8015 - 0.4541*t8129 + var1[2]) + 0.782*(t6621 + t6730 + t6955 + t6988 - 0.1318*t7146 + t7564 + t7601 + t7805 + t7821 + t8000 + t8015 + t8249 + t8277 - 0.816*t8306 - 0.0122*t8443 + var1[2]) + 0.15*(t6621 + t6730 + t6955 + t6988 - 0.1306*t7146 + t7564 + t7601 + t7805 + t7821 + t8000 + t8015 + t8249 + t8277 + t2343*t8306 + t2404*t8443 + 0.0059*(t2317*t8306 + t2276*t8443) - 1.1182*(t2276*t8306 - 1.*t2317*t8443) + var1[2]) + 1.82*(t6666 + t8555 + t8558 + 0.1351*t8568 + 0.0179*t8590 + var1[2]) + 1.17*(t8555 + t8558 - 0.0343*t8590 + t8623 + t8632 + 0.135*t8647 - 0.049*t8672 + var1[2]) + 5.52*(t8555 + t8558 + t8623 + t8632 + 0.1708*t8647 + t8690 + t8694 - 0.0489*t8700 - 0.1498*t8720 + var1[2]) + 0.758*(t8555 + t8558 + t8623 + t8632 + 0.1327*t8647 + t8690 + t8694 + t8727 + t8730 - 0.233*t8746 - 0.0169*t8757 + var1[2]) + 0.577*(t8555 + t8558 + t8623 + t8632 + 0.1303*t8647 + t8690 + t8694 + t8727 + t8730 + 0.0004*(-1.*t3436*t8746 - 1.*t3392*t8757) + t8794 + t8800 - 0.4541*t8840 + var1[2]) + 0.782*(t8555 + t8558 + t8623 + t8632 + 0.1318*t8647 + t8690 + t8694 + t8727 + t8730 + t8794 + t8800 + t8882 + t8885 - 0.816*t8906 - 0.0122*t8912 + var1[2]) + 0.15*(t8555 + t8558 + t8623 + t8632 + 0.1306*t8647 + t8690 + t8694 + t8727 + t8730 + t8794 + t8800 + t8882 + t8885 + t3866*t8906 + t3952*t8912 + 0.0059*(t3841*t8906 + t3791*t8912) - 1.1182*(t3791*t8906 - 1.*t3841*t8912) + var1[2]) + 10.33*(-0.0507*t215 + 0.0284*t186*t90 + var1[2]));
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 1, (mwSize) 3, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var1);


}

#else // MATLAB_MEX_FILE

#include "ComPosition_mex.hh"

namespace SymExpression
{

void ComPosition_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
