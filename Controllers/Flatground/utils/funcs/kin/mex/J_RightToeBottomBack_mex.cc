/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:35 GMT-04:00
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
  double t225;
  double t371;
  double t334;
  double t335;
  double t400;
  double t46;
  double t65;
  double t69;
  double t159;
  double t252;
  double t349;
  double t415;
  double t445;
  double t484;
  double t593;
  double t669;
  double t712;
  double t38;
  double t891;
  double t895;
  double t918;
  double t974;
  double t978;
  double t1000;
  double t1030;
  double t1051;
  double t1060;
  double t1080;
  double t1186;
  double t1237;
  double t1374;
  double t1409;
  double t1435;
  double t1484;
  double t1495;
  double t1531;
  double t1539;
  double t1549;
  double t1615;
  double t1617;
  double t1629;
  double t1638;
  double t1639;
  double t1641;
  double t1694;
  double t1849;
  double t2026;
  double t2064;
  double t2385;
  double t2407;
  double t2466;
  double t2488;
  double t2504;
  double t2506;
  double t2517;
  double t2538;
  double t2550;
  double t2559;
  double t2630;
  double t2634;
  double t2643;
  double t2713;
  double t2729;
  double t2730;
  double t2778;
  double t2851;
  double t2853;
  double t2965;
  double t3075;
  double t3084;
  double t3101;
  double t157;
  double t180;
  double t192;
  double t299;
  double t326;
  double t515;
  double t521;
  double t525;
  double t590;
  double t741;
  double t796;
  double t857;
  double t3352;
  double t3383;
  double t3400;
  double t3424;
  double t3431;
  double t3478;
  double t1003;
  double t1032;
  double t1034;
  double t3644;
  double t3655;
  double t3663;
  double t1149;
  double t1162;
  double t1169;
  double t1486;
  double t1496;
  double t1503;
  double t3718;
  double t4048;
  double t4105;
  double t5069;
  double t5074;
  double t5110;
  double t1585;
  double t1605;
  double t1611;
  double t1686;
  double t1698;
  double t1799;
  double t5209;
  double t5324;
  double t5379;
  double t5579;
  double t5648;
  double t5714;
  double t2290;
  double t2296;
  double t2366;
  double t2511;
  double t2529;
  double t2535;
  double t5735;
  double t5736;
  double t5771;
  double t5805;
  double t5826;
  double t5837;
  double t2585;
  double t2604;
  double t2627;
  double t2777;
  double t2783;
  double t2827;
  double t5910;
  double t5965;
  double t5979;
  double t6017;
  double t6020;
  double t6022;
  double t2992;
  double t3033;
  double t3051;
  double t6074;
  double t6083;
  double t6096;
  double t6111;
  double t6123;
  double t6126;
  double t6253;
  double t6258;
  double t6276;
  double t6301;
  double t6309;
  double t6319;
  double t6340;
  double t6352;
  double t6356;
  double t6362;
  double t6364;
  double t6366;
  double t6368;
  double t6370;
  double t6372;
  double t6377;
  double t6378;
  double t6379;
  double t6390;
  double t6392;
  double t6395;
  double t6398;
  double t6403;
  double t6414;
  double t6424;
  double t6425;
  double t6431;
  double t6436;
  double t6438;
  double t6445;
  double t6450;
  double t6451;
  double t6455;
  double t6511;
  double t6512;
  double t6514;
  double t6518;
  double t6521;
  double t6522;
  double t6536;
  double t6539;
  double t6541;
  double t6546;
  double t6547;
  double t6552;
  double t6556;
  double t6560;
  double t6565;
  double t6572;
  double t6574;
  double t6578;
  double t6582;
  double t6584;
  double t6590;
  double t6596;
  double t6600;
  double t6607;
  double t6611;
  double t6612;
  double t6614;
  double t6617;
  double t6621;
  double t6626;
  double t6630;
  double t6631;
  double t6633;
  double t6670;
  double t6675;
  double t6679;
  double t6684;
  double t6687;
  double t6691;
  double t6708;
  double t6709;
  double t6710;
  double t6715;
  double t6722;
  double t6726;
  double t6730;
  double t6732;
  double t6736;
  double t6740;
  double t6746;
  double t6750;
  double t6754;
  double t6755;
  double t6756;
  double t6762;
  double t6764;
  double t6765;
  double t6779;
  double t6787;
  double t6789;
  double t6800;
  double t6801;
  double t6806;
  double t6813;
  double t6814;
  double t6817;
  double t6845;
  double t6847;
  double t6851;
  double t6866;
  double t6869;
  double t6855;
  double t6858;
  double t6860;
  double t6878;
  double t6880;
  double t6884;
  double t6887;
  double t6888;
  double t6889;
  double t6892;
  double t6893;
  double t6895;
  double t6900;
  double t6911;
  double t6914;
  double t6922;
  double t6925;
  double t6928;
  double t6932;
  double t6933;
  double t6939;
  double t6945;
  double t6946;
  double t6954;
  double t6958;
  double t6961;
  double t6964;
  double t6989;
  double t6991;
  double t6993;
  double t7006;
  double t7009;
  double t7013;
  double t7001;
  double t7002;
  double t7026;
  double t7028;
  double t7029;
  double t7039;
  double t7045;
  double t7046;
  double t7054;
  double t7061;
  double t7062;
  double t7069;
  double t7074;
  double t7075;
  double t7080;
  double t7086;
  double t7087;
  double t7092;
  double t7095;
  double t7097;
  double t7099;
  double t7101;
  double t7102;
  double t7109;
  double t7110;
  double t7111;
  double t7155;
  double t7157;
  double t7159;
  double t7142;
  double t7147;
  double t7148;
  double t7164;
  double t7165;
  double t7167;
  double t7173;
  double t7178;
  double t7179;
  double t7182;
  double t7184;
  double t7185;
  double t7191;
  double t7198;
  double t7202;
  double t7206;
  double t7208;
  double t7210;
  double t7214;
  double t7215;
  double t7217;
  double t7221;
  double t7223;
  double t7224;
  double t7226;
  double t7229;
  double t7232;
  double t7265;
  double t7266;
  double t7277;
  double t7278;
  double t7279;
  double t7281;
  double t7282;
  double t7285;
  double t7289;
  double t7291;
  double t7292;
  double t7295;
  double t7296;
  double t7297;
  double t7302;
  double t7308;
  double t7310;
  double t7316;
  double t7317;
  double t7318;
  double t7322;
  double t7324;
  double t7327;
  double t7336;
  double t7337;
  double t7338;
  double t7363;
  double t7364;
  double t7367;
  double t7377;
  double t7379;
  double t7373;
  double t7374;
  double t7394;
  double t7397;
  double t7398;
  double t7401;
  double t7402;
  double t7404;
  double t7413;
  double t7415;
  double t7418;
  double t7423;
  double t7424;
  double t7429;
  double t7433;
  double t7434;
  double t7436;
  double t7438;
  double t7440;
  double t7441;
  double t7447;
  double t7453;
  double t7454;
  double t7458;
  double t7459;
  double t7460;
  double t7152;
  double t7160;
  double t7161;
  double t7163;
  double t7172;
  double t7181;
  double t7189;
  double t7203;
  double t7211;
  double t7218;
  double t7225;
  double t7233;
  double t7238;
  double t7239;
  double t7241;
  double t7242;
  double t7244;
  double t7249;
  double t7250;
  double t7256;
  double t4766;
  double t4767;
  double t4831;
  double t7505;
  double t7508;
  double t7510;
  double t7513;
  double t7514;
  double t7515;
  double t7517;
  double t7519;
  double t7521;
  double t7524;
  double t7527;
  double t7529;
  double t7532;
  double t7533;
  double t7535;
  double t7537;
  double t7538;
  double t7540;
  double t7483;
  double t7484;
  double t7488;
  double t7493;
  double t7494;
  double t7564;
  double t7565;
  double t7566;
  double t7568;
  double t7569;
  double t7570;
  double t7583;
  double t7586;
  double t7587;
  double t7592;
  double t7594;
  double t7595;
  double t7597;
  double t7598;
  double t7600;
  double t7602;
  double t7606;
  double t7607;
  double t7614;
  double t7615;
  double t7618;
  double t7620;
  double t7621;
  double t7622;
  double t7648;
  double t7649;
  double t7651;
  double t7654;
  double t7655;
  double t7656;
  double t7670;
  double t7671;
  double t7672;
  double t7674;
  double t7675;
  double t7676;
  double t7679;
  double t7682;
  double t7684;
  double t7687;
  double t7688;
  double t7689;
  double t7692;
  double t7693;
  double t7695;
  double t7699;
  double t7702;
  double t7704;
  double t7728;
  double t7731;
  double t7732;
  double t7738;
  double t7740;
  double t7743;
  double t7744;
  double t7745;
  double t7748;
  double t7749;
  double t7751;
  double t7755;
  double t7756;
  double t7757;
  double t7759;
  double t7760;
  double t7761;
  double t7763;
  double t7764;
  double t7765;
  double t7721;
  double t7722;
  double t7724;
  double t7725;
  double t7726;
  double t7783;
  double t7784;
  double t7785;
  double t7788;
  double t7791;
  double t7792;
  double t7794;
  double t7795;
  double t7796;
  double t7798;
  double t7799;
  double t7800;
  double t7802;
  double t7803;
  double t7804;
  double t7806;
  double t7807;
  double t7809;
  double t7811;
  double t7812;
  double t7814;
  double t7818;
  double t7819;
  double t7820;
  double t7822;
  double t7823;
  double t7824;
  double t7840;
  double t7842;
  double t7843;
  double t7847;
  double t7848;
  double t7849;
  double t7851;
  double t7852;
  double t7853;
  double t7855;
  double t7856;
  double t7857;
  double t7860;
  double t7862;
  double t7863;
  double t7867;
  double t7868;
  double t7870;
  double t7874;
  double t7875;
  double t7876;
  double t7878;
  double t7879;
  double t7880;
  double t7882;
  double t7883;
  double t7884;
  double t7906;
  double t7907;
  double t7912;
  double t7913;
  double t7915;
  double t7917;
  double t7919;
  double t7921;
  double t7922;
  double t7923;
  double t7926;
  double t7927;
  double t7930;
  double t7897;
  double t7898;
  double t7899;
  double t7901;
  double t7902;
  double t7944;
  double t7945;
  double t7946;
  double t7949;
  double t7950;
  double t7952;
  double t7953;
  double t7955;
  double t7956;
  double t7957;
  double t7960;
  double t7961;
  double t7962;
  double t7964;
  double t7965;
  double t7966;
  double t7968;
  double t7969;
  double t7971;
  double t7982;
  double t7983;
  double t7984;
  double t7987;
  double t7988;
  double t7990;
  double t7991;
  double t7993;
  double t7994;
  double t7995;
  double t7997;
  double t7998;
  double t7999;
  double t8001;
  double t8002;
  double t8003;
  double t8005;
  double t8006;
  double t8007;
  double t8025;
  double t8026;
  double t8029;
  double t8030;
  double t8032;
  double t8033;
  double t8034;
  double t8018;
  double t8019;
  double t8021;
  double t8022;
  double t8023;
  double t8046;
  double t8047;
  double t8048;
  double t8050;
  double t8051;
  double t8053;
  double t8054;
  double t8056;
  double t8057;
  double t8058;
  double t8060;
  double t8061;
  double t8062;
  double t8074;
  double t8075;
  double t8076;
  double t8078;
  double t8079;
  double t8081;
  double t8082;
  double t8084;
  double t8085;
  double t8086;
  double t8088;
  double t8089;
  double t8090;
  double t8109;
  double t8110;
  double t6186;
  double t8101;
  double t8102;
  double t8103;
  double t8105;
  double t8106;
  double t8120;
  double t8121;
  double t8122;
  double t8125;
  double t8126;
  double t8128;
  double t8129;
  double t8140;
  double t8141;
  double t8142;
  double t8145;
  double t8146;
  double t8148;
  double t8149;
  double t8112;
  double t6199;
  double t6221;
  double t8160;
  double t8161;
  double t8163;
  double t8164;
  double t8165;
  double t8131;
  double t8173;
  double t8174;
  double t8175;
  double t8135;
  double t8151;
  double t8185;
  double t8186;
  double t8187;
  double t8155;
  t225 = Sin(var1[3]);
  t371 = Cos(var1[3]);
  t334 = Cos(var1[5]);
  t335 = Sin(var1[4]);
  t400 = Sin(var1[5]);
  t46 = Cos(var1[14]);
  t65 = -1.*t46;
  t69 = 1. + t65;
  t159 = Sin(var1[14]);
  t252 = Sin(var1[13]);
  t349 = -1.*t334*t225*t335;
  t415 = t371*t400;
  t445 = t349 + t415;
  t484 = Cos(var1[13]);
  t593 = -1.*t371*t334;
  t669 = -1.*t225*t335*t400;
  t712 = t593 + t669;
  t38 = Cos(var1[4]);
  t891 = t252*t445;
  t895 = t484*t712;
  t918 = t891 + t895;
  t974 = Cos(var1[15]);
  t978 = -1.*t974;
  t1000 = 1. + t978;
  t1030 = Sin(var1[15]);
  t1051 = t484*t445;
  t1060 = -1.*t252*t712;
  t1080 = t1051 + t1060;
  t1186 = -1.*t46*t38*t225;
  t1237 = t159*t918;
  t1374 = t1186 + t1237;
  t1409 = Cos(var1[16]);
  t1435 = -1.*t1409;
  t1484 = 1. + t1435;
  t1495 = Sin(var1[16]);
  t1531 = t1030*t1080;
  t1539 = t974*t1374;
  t1549 = t1531 + t1539;
  t1615 = t974*t1080;
  t1617 = -1.*t1030*t1374;
  t1629 = t1615 + t1617;
  t1638 = Cos(var1[17]);
  t1639 = -1.*t1638;
  t1641 = 1. + t1639;
  t1694 = Sin(var1[17]);
  t1849 = -1.*t1495*t1549;
  t2026 = t1409*t1629;
  t2064 = t1849 + t2026;
  t2385 = t1409*t1549;
  t2407 = t1495*t1629;
  t2466 = t2385 + t2407;
  t2488 = Cos(var1[18]);
  t2504 = -1.*t2488;
  t2506 = 1. + t2504;
  t2517 = Sin(var1[18]);
  t2538 = t1694*t2064;
  t2550 = t1638*t2466;
  t2559 = t2538 + t2550;
  t2630 = t1638*t2064;
  t2634 = -1.*t1694*t2466;
  t2643 = t2630 + t2634;
  t2713 = Cos(var1[19]);
  t2729 = -1.*t2713;
  t2730 = 1. + t2729;
  t2778 = Sin(var1[19]);
  t2851 = -1.*t2517*t2559;
  t2853 = t2488*t2643;
  t2965 = t2851 + t2853;
  t3075 = t2488*t2559;
  t3084 = t2517*t2643;
  t3101 = t3075 + t3084;
  t157 = -0.049*t69;
  t180 = -0.135*t159;
  t192 = 0. + t157 + t180;
  t299 = 0.135*t252;
  t326 = 0. + t299;
  t515 = -1.*t484;
  t521 = 1. + t515;
  t525 = -0.135*t521;
  t590 = 0. + t525;
  t741 = -0.135*t69;
  t796 = 0.049*t159;
  t857 = 0. + t741 + t796;
  t3352 = t371*t334*t335;
  t3383 = t225*t400;
  t3400 = t3352 + t3383;
  t3424 = -1.*t334*t225;
  t3431 = t371*t335*t400;
  t3478 = t3424 + t3431;
  t1003 = -0.09*t1000;
  t1032 = 0.049*t1030;
  t1034 = 0. + t1003 + t1032;
  t3644 = t252*t3400;
  t3655 = t484*t3478;
  t3663 = t3644 + t3655;
  t1149 = -0.049*t1000;
  t1162 = -0.09*t1030;
  t1169 = 0. + t1149 + t1162;
  t1486 = -0.049*t1484;
  t1496 = -0.21*t1495;
  t1503 = 0. + t1486 + t1496;
  t3718 = t484*t3400;
  t4048 = -1.*t252*t3478;
  t4105 = t3718 + t4048;
  t5069 = t46*t371*t38;
  t5074 = t159*t3663;
  t5110 = t5069 + t5074;
  t1585 = -0.21*t1484;
  t1605 = 0.049*t1495;
  t1611 = 0. + t1585 + t1605;
  t1686 = -0.2707*t1641;
  t1698 = 0.0016*t1694;
  t1799 = 0. + t1686 + t1698;
  t5209 = t1030*t4105;
  t5324 = t974*t5110;
  t5379 = t5209 + t5324;
  t5579 = t974*t4105;
  t5648 = -1.*t1030*t5110;
  t5714 = t5579 + t5648;
  t2290 = -0.0016*t1641;
  t2296 = -0.2707*t1694;
  t2366 = 0. + t2290 + t2296;
  t2511 = 0.0184*t2506;
  t2529 = -0.7055*t2517;
  t2535 = 0. + t2511 + t2529;
  t5735 = -1.*t1495*t5379;
  t5736 = t1409*t5714;
  t5771 = t5735 + t5736;
  t5805 = t1409*t5379;
  t5826 = t1495*t5714;
  t5837 = t5805 + t5826;
  t2585 = -0.7055*t2506;
  t2604 = -0.0184*t2517;
  t2627 = 0. + t2585 + t2604;
  t2777 = -1.1135*t2730;
  t2783 = 0.0216*t2778;
  t2827 = 0. + t2777 + t2783;
  t5910 = t1694*t5771;
  t5965 = t1638*t5837;
  t5979 = t5910 + t5965;
  t6017 = t1638*t5771;
  t6020 = -1.*t1694*t5837;
  t6022 = t6017 + t6020;
  t2992 = -0.0216*t2730;
  t3033 = -1.1135*t2778;
  t3051 = 0. + t2992 + t3033;
  t6074 = -1.*t2517*t5979;
  t6083 = t2488*t6022;
  t6096 = t6074 + t6083;
  t6111 = t2488*t5979;
  t6123 = t2517*t6022;
  t6126 = t6111 + t6123;
  t6253 = t371*t38*t334*t252;
  t6258 = t484*t371*t38*t400;
  t6276 = t6253 + t6258;
  t6301 = t484*t371*t38*t334;
  t6309 = -1.*t371*t38*t252*t400;
  t6319 = t6301 + t6309;
  t6340 = -1.*t46*t371*t335;
  t6352 = t159*t6276;
  t6356 = t6340 + t6352;
  t6362 = t1030*t6319;
  t6364 = t974*t6356;
  t6366 = t6362 + t6364;
  t6368 = t974*t6319;
  t6370 = -1.*t1030*t6356;
  t6372 = t6368 + t6370;
  t6377 = -1.*t1495*t6366;
  t6378 = t1409*t6372;
  t6379 = t6377 + t6378;
  t6390 = t1409*t6366;
  t6392 = t1495*t6372;
  t6395 = t6390 + t6392;
  t6398 = t1694*t6379;
  t6403 = t1638*t6395;
  t6414 = t6398 + t6403;
  t6424 = t1638*t6379;
  t6425 = -1.*t1694*t6395;
  t6431 = t6424 + t6425;
  t6436 = -1.*t2517*t6414;
  t6438 = t2488*t6431;
  t6445 = t6436 + t6438;
  t6450 = t2488*t6414;
  t6451 = t2517*t6431;
  t6455 = t6450 + t6451;
  t6511 = t38*t334*t252*t225;
  t6512 = t484*t38*t225*t400;
  t6514 = t6511 + t6512;
  t6518 = t484*t38*t334*t225;
  t6521 = -1.*t38*t252*t225*t400;
  t6522 = t6518 + t6521;
  t6536 = -1.*t46*t225*t335;
  t6539 = t159*t6514;
  t6541 = t6536 + t6539;
  t6546 = t1030*t6522;
  t6547 = t974*t6541;
  t6552 = t6546 + t6547;
  t6556 = t974*t6522;
  t6560 = -1.*t1030*t6541;
  t6565 = t6556 + t6560;
  t6572 = -1.*t1495*t6552;
  t6574 = t1409*t6565;
  t6578 = t6572 + t6574;
  t6582 = t1409*t6552;
  t6584 = t1495*t6565;
  t6590 = t6582 + t6584;
  t6596 = t1694*t6578;
  t6600 = t1638*t6590;
  t6607 = t6596 + t6600;
  t6611 = t1638*t6578;
  t6612 = -1.*t1694*t6590;
  t6614 = t6611 + t6612;
  t6617 = -1.*t2517*t6607;
  t6621 = t2488*t6614;
  t6626 = t6617 + t6621;
  t6630 = t2488*t6607;
  t6631 = t2517*t6614;
  t6633 = t6630 + t6631;
  t6670 = -1.*t334*t252*t335;
  t6675 = -1.*t484*t335*t400;
  t6679 = t6670 + t6675;
  t6684 = -1.*t484*t334*t335;
  t6687 = t252*t335*t400;
  t6691 = t6684 + t6687;
  t6708 = -1.*t46*t38;
  t6709 = t159*t6679;
  t6710 = t6708 + t6709;
  t6715 = t1030*t6691;
  t6722 = t974*t6710;
  t6726 = t6715 + t6722;
  t6730 = t974*t6691;
  t6732 = -1.*t1030*t6710;
  t6736 = t6730 + t6732;
  t6740 = -1.*t1495*t6726;
  t6746 = t1409*t6736;
  t6750 = t6740 + t6746;
  t6754 = t1409*t6726;
  t6755 = t1495*t6736;
  t6756 = t6754 + t6755;
  t6762 = t1694*t6750;
  t6764 = t1638*t6756;
  t6765 = t6762 + t6764;
  t6779 = t1638*t6750;
  t6787 = -1.*t1694*t6756;
  t6789 = t6779 + t6787;
  t6800 = -1.*t2517*t6765;
  t6801 = t2488*t6789;
  t6806 = t6800 + t6801;
  t6813 = t2488*t6765;
  t6814 = t2517*t6789;
  t6817 = t6813 + t6814;
  t6845 = t334*t225;
  t6847 = -1.*t371*t335*t400;
  t6851 = t6845 + t6847;
  t6866 = t252*t6851;
  t6869 = t3718 + t6866;
  t6855 = -1.*t252*t3400;
  t6858 = t484*t6851;
  t6860 = t6855 + t6858;
  t6878 = t1030*t6860;
  t6880 = t974*t159*t6869;
  t6884 = t6878 + t6880;
  t6887 = t974*t6860;
  t6888 = -1.*t159*t1030*t6869;
  t6889 = t6887 + t6888;
  t6892 = -1.*t1495*t6884;
  t6893 = t1409*t6889;
  t6895 = t6892 + t6893;
  t6900 = t1409*t6884;
  t6911 = t1495*t6889;
  t6914 = t6900 + t6911;
  t6922 = t1694*t6895;
  t6925 = t1638*t6914;
  t6928 = t6922 + t6925;
  t6932 = t1638*t6895;
  t6933 = -1.*t1694*t6914;
  t6939 = t6932 + t6933;
  t6945 = -1.*t2517*t6928;
  t6946 = t2488*t6939;
  t6954 = t6945 + t6946;
  t6958 = t2488*t6928;
  t6961 = t2517*t6939;
  t6964 = t6958 + t6961;
  t6989 = t334*t225*t335;
  t6991 = -1.*t371*t400;
  t6993 = t6989 + t6991;
  t7006 = t484*t6993;
  t7009 = t252*t712;
  t7013 = t7006 + t7009;
  t7001 = -1.*t252*t6993;
  t7002 = t7001 + t895;
  t7026 = t1030*t7002;
  t7028 = t974*t159*t7013;
  t7029 = t7026 + t7028;
  t7039 = t974*t7002;
  t7045 = -1.*t159*t1030*t7013;
  t7046 = t7039 + t7045;
  t7054 = -1.*t1495*t7029;
  t7061 = t1409*t7046;
  t7062 = t7054 + t7061;
  t7069 = t1409*t7029;
  t7074 = t1495*t7046;
  t7075 = t7069 + t7074;
  t7080 = t1694*t7062;
  t7086 = t1638*t7075;
  t7087 = t7080 + t7086;
  t7092 = t1638*t7062;
  t7095 = -1.*t1694*t7075;
  t7097 = t7092 + t7095;
  t7099 = -1.*t2517*t7087;
  t7101 = t2488*t7097;
  t7102 = t7099 + t7101;
  t7109 = t2488*t7087;
  t7110 = t2517*t7097;
  t7111 = t7109 + t7110;
  t7155 = t484*t38*t334;
  t7157 = -1.*t38*t252*t400;
  t7159 = t7155 + t7157;
  t7142 = -1.*t38*t334*t252;
  t7147 = -1.*t484*t38*t400;
  t7148 = t7142 + t7147;
  t7164 = t1030*t7148;
  t7165 = t974*t159*t7159;
  t7167 = t7164 + t7165;
  t7173 = t974*t7148;
  t7178 = -1.*t159*t1030*t7159;
  t7179 = t7173 + t7178;
  t7182 = -1.*t1495*t7167;
  t7184 = t1409*t7179;
  t7185 = t7182 + t7184;
  t7191 = t1409*t7167;
  t7198 = t1495*t7179;
  t7202 = t7191 + t7198;
  t7206 = t1694*t7185;
  t7208 = t1638*t7202;
  t7210 = t7206 + t7208;
  t7214 = t1638*t7185;
  t7215 = -1.*t1694*t7202;
  t7217 = t7214 + t7215;
  t7221 = -1.*t2517*t7210;
  t7223 = t2488*t7217;
  t7224 = t7221 + t7223;
  t7226 = t2488*t7210;
  t7229 = t2517*t7217;
  t7232 = t7226 + t7229;
  t7265 = -1.*t484*t3478;
  t7266 = t6855 + t7265;
  t7277 = t1030*t7266;
  t7278 = t974*t159*t4105;
  t7279 = t7277 + t7278;
  t7281 = t974*t7266;
  t7282 = -1.*t159*t1030*t4105;
  t7285 = t7281 + t7282;
  t7289 = -1.*t1495*t7279;
  t7291 = t1409*t7285;
  t7292 = t7289 + t7291;
  t7295 = t1409*t7279;
  t7296 = t1495*t7285;
  t7297 = t7295 + t7296;
  t7302 = t1694*t7292;
  t7308 = t1638*t7297;
  t7310 = t7302 + t7308;
  t7316 = t1638*t7292;
  t7317 = -1.*t1694*t7297;
  t7318 = t7316 + t7317;
  t7322 = -1.*t2517*t7310;
  t7324 = t2488*t7318;
  t7327 = t7322 + t7324;
  t7336 = t2488*t7310;
  t7337 = t2517*t7318;
  t7338 = t7336 + t7337;
  t7363 = t371*t334;
  t7364 = t225*t335*t400;
  t7367 = t7363 + t7364;
  t7377 = -1.*t252*t7367;
  t7379 = t7006 + t7377;
  t7373 = -1.*t484*t7367;
  t7374 = t7001 + t7373;
  t7394 = t1030*t7374;
  t7397 = t974*t159*t7379;
  t7398 = t7394 + t7397;
  t7401 = t974*t7374;
  t7402 = -1.*t159*t1030*t7379;
  t7404 = t7401 + t7402;
  t7413 = -1.*t1495*t7398;
  t7415 = t1409*t7404;
  t7418 = t7413 + t7415;
  t7423 = t1409*t7398;
  t7424 = t1495*t7404;
  t7429 = t7423 + t7424;
  t7433 = t1694*t7418;
  t7434 = t1638*t7429;
  t7436 = t7433 + t7434;
  t7438 = t1638*t7418;
  t7440 = -1.*t1694*t7429;
  t7441 = t7438 + t7440;
  t7447 = -1.*t2517*t7436;
  t7453 = t2488*t7441;
  t7454 = t7447 + t7453;
  t7458 = t2488*t7436;
  t7459 = t2517*t7441;
  t7460 = t7458 + t7459;
  t7152 = t1034*t7148;
  t7160 = -0.1305*t46*t7159;
  t7161 = t857*t7159;
  t7163 = t159*t1169*t7159;
  t7172 = t1503*t7167;
  t7181 = t1611*t7179;
  t7189 = t1799*t7185;
  t7203 = t2366*t7202;
  t7211 = t2535*t7210;
  t7218 = t2627*t7217;
  t7225 = t2827*t7224;
  t7233 = t3051*t7232;
  t7238 = t2778*t7224;
  t7239 = t2713*t7232;
  t7241 = t7238 + t7239;
  t7242 = -0.031697*t7241;
  t7244 = t2713*t7224;
  t7249 = -1.*t2778*t7232;
  t7250 = t7244 + t7249;
  t7256 = -1.189886*t7250;
  t4766 = -1.*t371*t38*t159;
  t4767 = t46*t3663;
  t4831 = t4766 + t4767;
  t7505 = -1.*t1409*t1030*t4831;
  t7508 = -1.*t974*t1495*t4831;
  t7510 = t7505 + t7508;
  t7513 = t974*t1409*t4831;
  t7514 = -1.*t1030*t1495*t4831;
  t7515 = t7513 + t7514;
  t7517 = t1694*t7510;
  t7519 = t1638*t7515;
  t7521 = t7517 + t7519;
  t7524 = t1638*t7510;
  t7527 = -1.*t1694*t7515;
  t7529 = t7524 + t7527;
  t7532 = -1.*t2517*t7521;
  t7533 = t2488*t7529;
  t7535 = t7532 + t7533;
  t7537 = t2488*t7521;
  t7538 = t2517*t7529;
  t7540 = t7537 + t7538;
  t7483 = -0.135*t46;
  t7484 = -0.049*t159;
  t7488 = t7483 + t7484;
  t7493 = 0.049*t46;
  t7494 = t7493 + t180;
  t7564 = t252*t6993;
  t7565 = t484*t7367;
  t7566 = t7564 + t7565;
  t7568 = -1.*t38*t159*t225;
  t7569 = t46*t7566;
  t7570 = t7568 + t7569;
  t7583 = -1.*t1409*t1030*t7570;
  t7586 = -1.*t974*t1495*t7570;
  t7587 = t7583 + t7586;
  t7592 = t974*t1409*t7570;
  t7594 = -1.*t1030*t1495*t7570;
  t7595 = t7592 + t7594;
  t7597 = t1694*t7587;
  t7598 = t1638*t7595;
  t7600 = t7597 + t7598;
  t7602 = t1638*t7587;
  t7606 = -1.*t1694*t7595;
  t7607 = t7602 + t7606;
  t7614 = -1.*t2517*t7600;
  t7615 = t2488*t7607;
  t7618 = t7614 + t7615;
  t7620 = t2488*t7600;
  t7621 = t2517*t7607;
  t7622 = t7620 + t7621;
  t7648 = t38*t334*t252;
  t7649 = t484*t38*t400;
  t7651 = t7648 + t7649;
  t7654 = t159*t335;
  t7655 = t46*t7651;
  t7656 = t7654 + t7655;
  t7670 = -1.*t1409*t1030*t7656;
  t7671 = -1.*t974*t1495*t7656;
  t7672 = t7670 + t7671;
  t7674 = t974*t1409*t7656;
  t7675 = -1.*t1030*t1495*t7656;
  t7676 = t7674 + t7675;
  t7679 = t1694*t7672;
  t7682 = t1638*t7676;
  t7684 = t7679 + t7682;
  t7687 = t1638*t7672;
  t7688 = -1.*t1694*t7676;
  t7689 = t7687 + t7688;
  t7692 = -1.*t2517*t7684;
  t7693 = t2488*t7689;
  t7695 = t7692 + t7693;
  t7699 = t2488*t7684;
  t7702 = t2517*t7689;
  t7704 = t7699 + t7702;
  t7728 = -1.*t1030*t4105;
  t7731 = -1.*t974*t5110;
  t7732 = t7728 + t7731;
  t7738 = t1495*t7732;
  t7740 = t7738 + t5736;
  t7743 = t1409*t7732;
  t7744 = -1.*t1495*t5714;
  t7745 = t7743 + t7744;
  t7748 = -1.*t1694*t7740;
  t7749 = t1638*t7745;
  t7751 = t7748 + t7749;
  t7755 = t1638*t7740;
  t7756 = t1694*t7745;
  t7757 = t7755 + t7756;
  t7759 = t2517*t7751;
  t7760 = t2488*t7757;
  t7761 = t7759 + t7760;
  t7763 = t2488*t7751;
  t7764 = -1.*t2517*t7757;
  t7765 = t7763 + t7764;
  t7721 = 0.049*t974;
  t7722 = t7721 + t1162;
  t7724 = -0.09*t974;
  t7725 = -0.049*t1030;
  t7726 = t7724 + t7725;
  t7783 = t46*t38*t225;
  t7784 = t159*t7566;
  t7785 = t7783 + t7784;
  t7788 = -1.*t1030*t7379;
  t7791 = -1.*t974*t7785;
  t7792 = t7788 + t7791;
  t7794 = t974*t7379;
  t7795 = -1.*t1030*t7785;
  t7796 = t7794 + t7795;
  t7798 = t1495*t7792;
  t7799 = t1409*t7796;
  t7800 = t7798 + t7799;
  t7802 = t1409*t7792;
  t7803 = -1.*t1495*t7796;
  t7804 = t7802 + t7803;
  t7806 = -1.*t1694*t7800;
  t7807 = t1638*t7804;
  t7809 = t7806 + t7807;
  t7811 = t1638*t7800;
  t7812 = t1694*t7804;
  t7814 = t7811 + t7812;
  t7818 = t2517*t7809;
  t7819 = t2488*t7814;
  t7820 = t7818 + t7819;
  t7822 = t2488*t7809;
  t7823 = -1.*t2517*t7814;
  t7824 = t7822 + t7823;
  t7840 = -1.*t46*t335;
  t7842 = t159*t7651;
  t7843 = t7840 + t7842;
  t7847 = -1.*t1030*t7159;
  t7848 = -1.*t974*t7843;
  t7849 = t7847 + t7848;
  t7851 = t974*t7159;
  t7852 = -1.*t1030*t7843;
  t7853 = t7851 + t7852;
  t7855 = t1495*t7849;
  t7856 = t1409*t7853;
  t7857 = t7855 + t7856;
  t7860 = t1409*t7849;
  t7862 = -1.*t1495*t7853;
  t7863 = t7860 + t7862;
  t7867 = -1.*t1694*t7857;
  t7868 = t1638*t7863;
  t7870 = t7867 + t7868;
  t7874 = t1638*t7857;
  t7875 = t1694*t7863;
  t7876 = t7874 + t7875;
  t7878 = t2517*t7870;
  t7879 = t2488*t7876;
  t7880 = t7878 + t7879;
  t7882 = t2488*t7870;
  t7883 = -1.*t2517*t7876;
  t7884 = t7882 + t7883;
  t7906 = -1.*t1409*t5379;
  t7907 = t7906 + t7744;
  t7912 = -1.*t1694*t5771;
  t7913 = t1638*t7907;
  t7915 = t7912 + t7913;
  t7917 = t1694*t7907;
  t7919 = t6017 + t7917;
  t7921 = t2517*t7915;
  t7922 = t2488*t7919;
  t7923 = t7921 + t7922;
  t7926 = t2488*t7915;
  t7927 = -1.*t2517*t7919;
  t7930 = t7926 + t7927;
  t7897 = -0.21*t1409;
  t7898 = -0.049*t1495;
  t7899 = t7897 + t7898;
  t7901 = 0.049*t1409;
  t7902 = t7901 + t1496;
  t7944 = t1030*t7379;
  t7945 = t974*t7785;
  t7946 = t7944 + t7945;
  t7949 = -1.*t1495*t7946;
  t7950 = t7949 + t7799;
  t7952 = -1.*t1409*t7946;
  t7953 = t7952 + t7803;
  t7955 = -1.*t1694*t7950;
  t7956 = t1638*t7953;
  t7957 = t7955 + t7956;
  t7960 = t1638*t7950;
  t7961 = t1694*t7953;
  t7962 = t7960 + t7961;
  t7964 = t2517*t7957;
  t7965 = t2488*t7962;
  t7966 = t7964 + t7965;
  t7968 = t2488*t7957;
  t7969 = -1.*t2517*t7962;
  t7971 = t7968 + t7969;
  t7982 = t1030*t7159;
  t7983 = t974*t7843;
  t7984 = t7982 + t7983;
  t7987 = -1.*t1495*t7984;
  t7988 = t7987 + t7856;
  t7990 = -1.*t1409*t7984;
  t7991 = t7990 + t7862;
  t7993 = -1.*t1694*t7988;
  t7994 = t1638*t7991;
  t7995 = t7993 + t7994;
  t7997 = t1638*t7988;
  t7998 = t1694*t7991;
  t7999 = t7997 + t7998;
  t8001 = t2517*t7995;
  t8002 = t2488*t7999;
  t8003 = t8001 + t8002;
  t8005 = t2488*t7995;
  t8006 = -1.*t2517*t7999;
  t8007 = t8005 + t8006;
  t8025 = -1.*t1638*t5837;
  t8026 = t7912 + t8025;
  t8029 = t2517*t8026;
  t8030 = t8029 + t6083;
  t8032 = t2488*t8026;
  t8033 = -1.*t2517*t6022;
  t8034 = t8032 + t8033;
  t8018 = 0.0016*t1638;
  t8019 = t8018 + t2296;
  t8021 = -0.2707*t1638;
  t8022 = -0.0016*t1694;
  t8023 = t8021 + t8022;
  t8046 = t1409*t7946;
  t8047 = t1495*t7796;
  t8048 = t8046 + t8047;
  t8050 = -1.*t1638*t8048;
  t8051 = t7955 + t8050;
  t8053 = -1.*t1694*t8048;
  t8054 = t7960 + t8053;
  t8056 = t2517*t8051;
  t8057 = t2488*t8054;
  t8058 = t8056 + t8057;
  t8060 = t2488*t8051;
  t8061 = -1.*t2517*t8054;
  t8062 = t8060 + t8061;
  t8074 = t1409*t7984;
  t8075 = t1495*t7853;
  t8076 = t8074 + t8075;
  t8078 = -1.*t1638*t8076;
  t8079 = t7993 + t8078;
  t8081 = -1.*t1694*t8076;
  t8082 = t7997 + t8081;
  t8084 = t2517*t8079;
  t8085 = t2488*t8082;
  t8086 = t8084 + t8085;
  t8088 = t2488*t8079;
  t8089 = -1.*t2517*t8082;
  t8090 = t8088 + t8089;
  t8109 = -1.*t2488*t5979;
  t8110 = t8109 + t8033;
  t6186 = t2713*t6096;
  t8101 = -0.7055*t2488;
  t8102 = 0.0184*t2517;
  t8103 = t8101 + t8102;
  t8105 = -0.0184*t2488;
  t8106 = t8105 + t2529;
  t8120 = t1694*t7950;
  t8121 = t1638*t8048;
  t8122 = t8120 + t8121;
  t8125 = -1.*t2517*t8122;
  t8126 = t8125 + t8057;
  t8128 = -1.*t2488*t8122;
  t8129 = t8128 + t8061;
  t8140 = t1694*t7988;
  t8141 = t1638*t8076;
  t8142 = t8140 + t8141;
  t8145 = -1.*t2517*t8142;
  t8146 = t8145 + t8085;
  t8148 = -1.*t2488*t8142;
  t8149 = t8148 + t8089;
  t8112 = -1.*t2778*t6096;
  t6199 = -1.*t2778*t6126;
  t6221 = t6186 + t6199;
  t8160 = 0.0216*t2713;
  t8161 = t8160 + t3033;
  t8163 = -1.1135*t2713;
  t8164 = -0.0216*t2778;
  t8165 = t8163 + t8164;
  t8131 = -1.*t2778*t8126;
  t8173 = t2488*t8122;
  t8174 = t2517*t8054;
  t8175 = t8173 + t8174;
  t8135 = t2713*t8126;
  t8151 = -1.*t2778*t8146;
  t8185 = t2488*t8142;
  t8186 = t2517*t8082;
  t8187 = t8185 + t8186;
  t8155 = t2713*t8146;
  p_output1[0]=1.;
  p_output1[1]=0;
  p_output1[2]=0;
  p_output1[3]=0;
  p_output1[4]=1.;
  p_output1[5]=0;
  p_output1[6]=0;
  p_output1[7]=0;
  p_output1[8]=1.;
  p_output1[9]=t1034*t1080 + t1169*t1374 + t1503*t1549 + t1611*t1629 + t1799*t2064 + t2366*t2466 + t2535*t2559 + t2627*t2643 + t2827*t2965 + t3051*t3101 - 0.031697*(t2778*t2965 + t2713*t3101) - 1.189886*(t2713*t2965 - 1.*t2778*t3101) - 1.*t192*t225*t38 + t326*t445 + t590*t712 + t857*t918 - 0.1305*(t159*t225*t38 + t46*t918);
  p_output1[10]=t326*t3400 + t192*t371*t38 + t1034*t4105 - 0.1305*t4831 + t1169*t5110 + t1503*t5379 + t1611*t5714 + t1799*t5771 + t2366*t5837 + t3478*t590 + t2535*t5979 + t2627*t6022 + t2827*t6096 + t3051*t6126 - 0.031697*(t2778*t6096 + t2713*t6126) - 1.189886*t6221 + t3663*t857;
  p_output1[11]=0;
  p_output1[12]=-1.*t192*t335*t371 + t326*t334*t371*t38 + t371*t38*t400*t590 - 0.1305*(t159*t335*t371 + t46*t6276) + t1034*t6319 + t1169*t6356 + t1503*t6366 + t1611*t6372 + t1799*t6379 + t2366*t6395 + t2535*t6414 + t2627*t6431 + t2827*t6445 + t3051*t6455 - 0.031697*(t2778*t6445 + t2713*t6455) - 1.189886*(t2713*t6445 - 1.*t2778*t6455) + t6276*t857;
  p_output1[13]=-1.*t192*t225*t335 + t225*t326*t334*t38 + t225*t38*t400*t590 - 0.1305*(t159*t225*t335 + t46*t6514) + t1034*t6522 + t1169*t6541 + t1503*t6552 + t1611*t6565 + t1799*t6578 + t2366*t6590 + t2535*t6607 + t2627*t6614 + t2827*t6626 + t3051*t6633 - 0.031697*(t2778*t6626 + t2713*t6633) - 1.189886*(t2713*t6626 - 1.*t2778*t6633) + t6514*t857;
  p_output1[14]=-1.*t326*t334*t335 - 1.*t192*t38 - 1.*t335*t400*t590 - 0.1305*(t159*t38 + t46*t6679) + t1034*t6691 + t1169*t6710 + t1503*t6726 + t1611*t6736 + t1799*t6750 + t2366*t6756 + t2535*t6765 + t2627*t6789 + t2827*t6806 + t3051*t6817 - 0.031697*(t2778*t6806 + t2713*t6817) - 1.189886*(t2713*t6806 - 1.*t2778*t6817) + t6679*t857;
  p_output1[15]=t3400*t590 + t326*t6851 + t1034*t6860 + t1169*t159*t6869 - 0.1305*t46*t6869 + t1503*t6884 + t1611*t6889 + t1799*t6895 + t2366*t6914 + t2535*t6928 + t2627*t6939 + t2827*t6954 + t3051*t6964 - 0.031697*(t2778*t6954 + t2713*t6964) - 1.189886*(t2713*t6954 - 1.*t2778*t6964) + t6869*t857;
  p_output1[16]=t590*t6993 + t1034*t7002 + t1169*t159*t7013 - 0.1305*t46*t7013 + t1503*t7029 + t1611*t7046 + t1799*t7062 + t2366*t7075 + t2535*t7087 + t2627*t7097 + t2827*t7102 + t3051*t7111 - 0.031697*(t2778*t7102 + t2713*t7111) - 1.189886*(t2713*t7102 - 1.*t2778*t7111) + t326*t712 + t7013*t857;
  p_output1[17]=-1.*t326*t38*t400 + t334*t38*t590 + t7152 + t7160 + t7161 + t7163 + t7172 + t7181 + t7189 + t7203 + t7211 + t7218 + t7225 + t7233 + t7242 + t7256;
  p_output1[18]=0;
  p_output1[19]=0;
  p_output1[20]=0;
  p_output1[21]=0;
  p_output1[22]=0;
  p_output1[23]=0;
  p_output1[24]=0;
  p_output1[25]=0;
  p_output1[26]=0;
  p_output1[27]=0;
  p_output1[28]=0;
  p_output1[29]=0;
  p_output1[30]=0;
  p_output1[31]=0;
  p_output1[32]=0;
  p_output1[33]=0;
  p_output1[34]=0;
  p_output1[35]=0;
  p_output1[36]=0;
  p_output1[37]=0;
  p_output1[38]=0;
  p_output1[39]=-0.135*t252*t3478 + t1169*t159*t4105 - 0.1305*t4105*t46 + 0.135*t3400*t484 + t1034*t7266 + t1503*t7279 + t1611*t7285 + t1799*t7292 + t2366*t7297 + t2535*t7310 + t2627*t7318 + t2827*t7327 + t3051*t7338 - 0.031697*(t2778*t7327 + t2713*t7338) - 1.189886*(t2713*t7327 - 1.*t2778*t7338) + t4105*t857;
  p_output1[40]=0.135*t484*t6993 - 0.135*t252*t7367 + t1034*t7374 + t1169*t159*t7379 - 0.1305*t46*t7379 + t1503*t7398 + t1611*t7404 + t1799*t7418 + t2366*t7429 + t2535*t7436 + t2627*t7441 + t2827*t7454 + t3051*t7460 - 0.031697*(t2778*t7454 + t2713*t7460) - 1.189886*(t2713*t7454 - 1.*t2778*t7460) + t7379*t857;
  p_output1[41]=-0.135*t252*t38*t400 + 0.135*t334*t38*t484 + t7152 + t7160 + t7161 + t7163 + t7172 + t7181 + t7189 + t7203 + t7211 + t7218 + t7225 + t7233 + t7242 + t7256;
  p_output1[42]=-0.1305*(-1.*t159*t3663 - 1.*t371*t38*t46) + t1169*t4831 - 1.*t1030*t1611*t4831 + t371*t38*t7488 + t3663*t7494 + t1799*t7510 + t2366*t7515 + t2535*t7521 + t2627*t7529 + t2827*t7535 + t3051*t7540 - 0.031697*(t2778*t7535 + t2713*t7540) - 1.189886*(t2713*t7535 - 1.*t2778*t7540) + t1503*t4831*t974;
  p_output1[43]=t225*t38*t7488 + t7494*t7566 - 0.1305*(t1186 - 1.*t159*t7566) + t1169*t7570 - 1.*t1030*t1611*t7570 + t1799*t7587 + t2366*t7595 + t2535*t7600 + t2627*t7607 + t2827*t7618 + t3051*t7622 - 0.031697*(t2778*t7618 + t2713*t7622) - 1.189886*(t2713*t7618 - 1.*t2778*t7622) + t1503*t7570*t974;
  p_output1[44]=-1.*t335*t7488 + t7494*t7651 - 0.1305*(t335*t46 - 1.*t159*t7651) + t1169*t7656 - 1.*t1030*t1611*t7656 + t1799*t7672 + t2366*t7676 + t2535*t7684 + t2627*t7689 + t2827*t7695 + t3051*t7704 - 0.031697*(t2778*t7695 + t2713*t7704) - 1.189886*(t2713*t7695 - 1.*t2778*t7704) + t1503*t7656*t974;
  p_output1[45]=t1503*t5714 + t4105*t7722 + t5110*t7726 + t1611*t7732 + t2366*t7740 + t1799*t7745 + t2627*t7751 + t2535*t7757 + t3051*t7761 + t2827*t7765 - 1.189886*(-1.*t2778*t7761 + t2713*t7765) - 0.031697*(t2713*t7761 + t2778*t7765);
  p_output1[46]=t7379*t7722 + t7726*t7785 + t1611*t7792 + t1503*t7796 + t2366*t7800 + t1799*t7804 + t2627*t7809 + t2535*t7814 + t3051*t7820 + t2827*t7824 - 1.189886*(-1.*t2778*t7820 + t2713*t7824) - 0.031697*(t2713*t7820 + t2778*t7824);
  p_output1[47]=t7159*t7722 + t7726*t7843 + t1611*t7849 + t1503*t7853 + t2366*t7857 + t1799*t7863 + t2627*t7870 + t2535*t7876 + t3051*t7880 + t2827*t7884 - 1.189886*(-1.*t2778*t7880 + t2713*t7884) - 0.031697*(t2713*t7880 + t2778*t7884);
  p_output1[48]=t2366*t5771 + t5379*t7899 + t5714*t7902 + t1799*t7907 + t2627*t7915 + t2535*t7919 + t3051*t7923 + t2827*t7930 - 1.189886*(-1.*t2778*t7923 + t2713*t7930) - 0.031697*(t2713*t7923 + t2778*t7930);
  p_output1[49]=t7796*t7902 + t7899*t7946 + t2366*t7950 + t1799*t7953 + t2627*t7957 + t2535*t7962 + t3051*t7966 + t2827*t7971 - 1.189886*(-1.*t2778*t7966 + t2713*t7971) - 0.031697*(t2713*t7966 + t2778*t7971);
  p_output1[50]=t7853*t7902 + t7899*t7984 + t2366*t7988 + t1799*t7991 + t2627*t7995 + t2535*t7999 + t3051*t8003 + t2827*t8007 - 1.189886*(-1.*t2778*t8003 + t2713*t8007) - 0.031697*(t2713*t8003 + t2778*t8007);
  p_output1[51]=t2535*t6022 + t5771*t8019 + t5837*t8023 + t2627*t8026 + t3051*t8030 + t2827*t8034 - 1.189886*(-1.*t2778*t8030 + t2713*t8034) - 0.031697*(t2713*t8030 + t2778*t8034);
  p_output1[52]=t7950*t8019 + t8023*t8048 + t2627*t8051 + t2535*t8054 + t3051*t8058 + t2827*t8062 - 1.189886*(-1.*t2778*t8058 + t2713*t8062) - 0.031697*(t2713*t8058 + t2778*t8062);
  p_output1[53]=t7988*t8019 + t8023*t8076 + t2627*t8079 + t2535*t8082 + t3051*t8086 + t2827*t8090 - 1.189886*(-1.*t2778*t8086 + t2713*t8090) - 0.031697*(t2713*t8086 + t2778*t8090);
  p_output1[54]=t3051*t6096 + t5979*t8103 + t6022*t8106 + t2827*t8110 - 0.031697*(t6186 + t2778*t8110) - 1.189886*(t2713*t8110 + t8112);
  p_output1[55]=t8054*t8106 + t8103*t8122 + t3051*t8126 + t2827*t8129 - 1.189886*(t2713*t8129 + t8131) - 0.031697*(t2778*t8129 + t8135);
  p_output1[56]=t8082*t8106 + t8103*t8142 + t3051*t8146 + t2827*t8149 - 1.189886*(t2713*t8149 + t8151) - 0.031697*(t2778*t8149 + t8155);
  p_output1[57]=-0.031697*t6221 - 1.189886*(-1.*t2713*t6126 + t8112) + t6096*t8161 + t6126*t8165;
  p_output1[58]=t8126*t8161 + t8165*t8175 - 1.189886*(t8131 - 1.*t2713*t8175) - 0.031697*(t8135 - 1.*t2778*t8175);
  p_output1[59]=t8146*t8161 + t8165*t8187 - 1.189886*(t8151 - 1.*t2713*t8187) - 0.031697*(t8155 - 1.*t2778*t8187);
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 20, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var1);


}

#else // MATLAB_MEX_FILE

#include "J_RightToeBottomBack_mex.hh"

namespace SymExpression
{

void J_RightToeBottomBack_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
