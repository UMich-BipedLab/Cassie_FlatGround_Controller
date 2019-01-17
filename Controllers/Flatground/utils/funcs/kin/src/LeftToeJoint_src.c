/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:25 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "LeftToeJoint_src.h"

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
  double t2223;
  double t2185;
  double t2227;
  double t2186;
  double t2238;
  double t2028;
  double t2219;
  double t2240;
  double t2255;
  double t2272;
  double t2297;
  double t2338;
  double t2344;
  double t2395;
  double t2424;
  double t2428;
  double t2434;
  double t2374;
  double t2389;
  double t2393;
  double t2465;
  double t2605;
  double t2613;
  double t2615;
  double t2640;
  double t2583;
  double t2594;
  double t2599;
  double t2657;
  double t2661;
  double t2664;
  double t2717;
  double t2736;
  double t2737;
  double t2750;
  double t2779;
  double t2802;
  double t2820;
  double t2866;
  double t2872;
  double t2886;
  double t2892;
  double t2896;
  double t2903;
  double t2920;
  double t2925;
  double t2929;
  double t2934;
  double t2963;
  double t2967;
  double t2973;
  double t2990;
  double t2996;
  double t2998;
  double t3004;
  double t3024;
  double t3027;
  double t3029;
  double t3056;
  double t3063;
  double t3064;
  double t3073;
  double t3080;
  double t3102;
  double t3116;
  double t3137;
  double t3138;
  double t3148;
  double t3160;
  double t3166;
  double t3172;
  double t2050;
  double t2149;
  double t2165;
  double t2181;
  double t2350;
  double t2361;
  double t3227;
  double t3228;
  double t3233;
  double t3238;
  double t3239;
  double t3242;
  double t2432;
  double t2435;
  double t2442;
  double t2481;
  double t2490;
  double t2514;
  double t3253;
  double t3257;
  double t3259;
  double t2631;
  double t2642;
  double t2647;
  double t2670;
  double t2674;
  double t2681;
  double t2741;
  double t2756;
  double t2773;
  double t3303;
  double t3306;
  double t3308;
  double t3314;
  double t3316;
  double t3325;
  double t2834;
  double t2845;
  double t2852;
  double t2906;
  double t2921;
  double t2923;
  double t3335;
  double t3337;
  double t3338;
  double t3343;
  double t3348;
  double t3354;
  double t2943;
  double t2945;
  double t2950;
  double t3000;
  double t3011;
  double t3019;
  double t3364;
  double t3365;
  double t3371;
  double t3379;
  double t3383;
  double t3386;
  double t3031;
  double t3041;
  double t3049;
  double t3109;
  double t3123;
  double t3134;
  double t3406;
  double t3408;
  double t3417;
  double t3429;
  double t3435;
  double t3438;
  double t3151;
  double t3156;
  double t3158;
  double t3451;
  double t3453;
  double t3455;
  double t3462;
  double t3464;
  double t3465;
  double t3500;
  double t3505;
  double t3508;
  double t3524;
  double t3528;
  double t3532;
  double t3541;
  double t3544;
  double t3546;
  double t3549;
  double t3552;
  double t3553;
  double t3560;
  double t3563;
  double t3566;
  double t3571;
  double t3572;
  double t3573;
  double t3583;
  double t3585;
  double t3590;
  double t3594;
  double t3596;
  double t3605;
  double t3610;
  double t3613;
  double t3614;
  double t3622;
  double t3624;
  double t3625;
  double t3629;
  double t3631;
  double t3633;
  t2223 = Cos(var1[3]);
  t2185 = Cos(var1[5]);
  t2227 = Sin(var1[4]);
  t2186 = Sin(var1[3]);
  t2238 = Sin(var1[5]);
  t2028 = Cos(var1[6]);
  t2219 = -1.*t2185*t2186;
  t2240 = t2223*t2227*t2238;
  t2255 = t2219 + t2240;
  t2272 = t2223*t2185*t2227;
  t2297 = t2186*t2238;
  t2338 = t2272 + t2297;
  t2344 = Sin(var1[6]);
  t2395 = Cos(var1[7]);
  t2424 = -1.*t2395;
  t2428 = 1. + t2424;
  t2434 = Sin(var1[7]);
  t2374 = t2028*t2255;
  t2389 = t2338*t2344;
  t2393 = t2374 + t2389;
  t2465 = Cos(var1[4]);
  t2605 = Cos(var1[8]);
  t2613 = -1.*t2605;
  t2615 = 1. + t2613;
  t2640 = Sin(var1[8]);
  t2583 = t2223*t2465*t2395;
  t2594 = t2393*t2434;
  t2599 = t2583 + t2594;
  t2657 = t2028*t2338;
  t2661 = -1.*t2255*t2344;
  t2664 = t2657 + t2661;
  t2717 = Cos(var1[9]);
  t2736 = -1.*t2717;
  t2737 = 1. + t2736;
  t2750 = Sin(var1[9]);
  t2779 = t2605*t2599;
  t2802 = t2664*t2640;
  t2820 = t2779 + t2802;
  t2866 = t2605*t2664;
  t2872 = -1.*t2599*t2640;
  t2886 = t2866 + t2872;
  t2892 = Cos(var1[10]);
  t2896 = -1.*t2892;
  t2903 = 1. + t2896;
  t2920 = Sin(var1[10]);
  t2925 = -1.*t2750*t2820;
  t2929 = t2717*t2886;
  t2934 = t2925 + t2929;
  t2963 = t2717*t2820;
  t2967 = t2750*t2886;
  t2973 = t2963 + t2967;
  t2990 = Cos(var1[11]);
  t2996 = -1.*t2990;
  t2998 = 1. + t2996;
  t3004 = Sin(var1[11]);
  t3024 = t2920*t2934;
  t3027 = t2892*t2973;
  t3029 = t3024 + t3027;
  t3056 = t2892*t2934;
  t3063 = -1.*t2920*t2973;
  t3064 = t3056 + t3063;
  t3073 = Cos(var1[12]);
  t3080 = -1.*t3073;
  t3102 = 1. + t3080;
  t3116 = Sin(var1[12]);
  t3137 = -1.*t3004*t3029;
  t3138 = t2990*t3064;
  t3148 = t3137 + t3138;
  t3160 = t2990*t3029;
  t3166 = t3004*t3064;
  t3172 = t3160 + t3166;
  t2050 = -1.*t2028;
  t2149 = 1. + t2050;
  t2165 = 0.135*t2149;
  t2181 = 0. + t2165;
  t2350 = -0.135*t2344;
  t2361 = 0. + t2350;
  t3227 = t2223*t2185;
  t3228 = t2186*t2227*t2238;
  t3233 = t3227 + t3228;
  t3238 = t2185*t2186*t2227;
  t3239 = -1.*t2223*t2238;
  t3242 = t3238 + t3239;
  t2432 = 0.135*t2428;
  t2435 = 0.049*t2434;
  t2442 = 0. + t2432 + t2435;
  t2481 = -0.049*t2428;
  t2490 = 0.135*t2434;
  t2514 = 0. + t2481 + t2490;
  t3253 = t2028*t3233;
  t3257 = t3242*t2344;
  t3259 = t3253 + t3257;
  t2631 = -0.049*t2615;
  t2642 = -0.09*t2640;
  t2647 = 0. + t2631 + t2642;
  t2670 = -0.09*t2615;
  t2674 = 0.049*t2640;
  t2681 = 0. + t2670 + t2674;
  t2741 = -0.049*t2737;
  t2756 = -0.21*t2750;
  t2773 = 0. + t2741 + t2756;
  t3303 = t2465*t2395*t2186;
  t3306 = t3259*t2434;
  t3308 = t3303 + t3306;
  t3314 = t2028*t3242;
  t3316 = -1.*t3233*t2344;
  t3325 = t3314 + t3316;
  t2834 = -0.21*t2737;
  t2845 = 0.049*t2750;
  t2852 = 0. + t2834 + t2845;
  t2906 = -0.2707*t2903;
  t2921 = 0.0016*t2920;
  t2923 = 0. + t2906 + t2921;
  t3335 = t2605*t3308;
  t3337 = t3325*t2640;
  t3338 = t3335 + t3337;
  t3343 = t2605*t3325;
  t3348 = -1.*t3308*t2640;
  t3354 = t3343 + t3348;
  t2943 = -0.0016*t2903;
  t2945 = -0.2707*t2920;
  t2950 = 0. + t2943 + t2945;
  t3000 = 0.0184*t2998;
  t3011 = -0.7055*t3004;
  t3019 = 0. + t3000 + t3011;
  t3364 = -1.*t2750*t3338;
  t3365 = t2717*t3354;
  t3371 = t3364 + t3365;
  t3379 = t2717*t3338;
  t3383 = t2750*t3354;
  t3386 = t3379 + t3383;
  t3031 = -0.7055*t2998;
  t3041 = -0.0184*t3004;
  t3049 = 0. + t3031 + t3041;
  t3109 = -1.1135*t3102;
  t3123 = 0.0216*t3116;
  t3134 = 0. + t3109 + t3123;
  t3406 = t2920*t3371;
  t3408 = t2892*t3386;
  t3417 = t3406 + t3408;
  t3429 = t2892*t3371;
  t3435 = -1.*t2920*t3386;
  t3438 = t3429 + t3435;
  t3151 = -0.0216*t3102;
  t3156 = -1.1135*t3116;
  t3158 = 0. + t3151 + t3156;
  t3451 = -1.*t3004*t3417;
  t3453 = t2990*t3438;
  t3455 = t3451 + t3453;
  t3462 = t2990*t3417;
  t3464 = t3004*t3438;
  t3465 = t3462 + t3464;
  t3500 = t2465*t2028*t2238;
  t3505 = t2465*t2185*t2344;
  t3508 = t3500 + t3505;
  t3524 = -1.*t2395*t2227;
  t3528 = t3508*t2434;
  t3532 = t3524 + t3528;
  t3541 = t2465*t2185*t2028;
  t3544 = -1.*t2465*t2238*t2344;
  t3546 = t3541 + t3544;
  t3549 = t2605*t3532;
  t3552 = t3546*t2640;
  t3553 = t3549 + t3552;
  t3560 = t2605*t3546;
  t3563 = -1.*t3532*t2640;
  t3566 = t3560 + t3563;
  t3571 = -1.*t2750*t3553;
  t3572 = t2717*t3566;
  t3573 = t3571 + t3572;
  t3583 = t2717*t3553;
  t3585 = t2750*t3566;
  t3590 = t3583 + t3585;
  t3594 = t2920*t3573;
  t3596 = t2892*t3590;
  t3605 = t3594 + t3596;
  t3610 = t2892*t3573;
  t3613 = -1.*t2920*t3590;
  t3614 = t3610 + t3613;
  t3622 = -1.*t3004*t3605;
  t3624 = t2990*t3614;
  t3625 = t3622 + t3624;
  t3629 = t2990*t3605;
  t3631 = t3004*t3614;
  t3633 = t3629 + t3631;
  p_output1[0]=0. + t2181*t2255 + t2338*t2361 + t2393*t2442 + 0.1305*(t2393*t2395 - 1.*t2223*t2434*t2465) + t2223*t2465*t2514 + t2599*t2647 + t2664*t2681 + t2773*t2820 + t2852*t2886 + t2923*t2934 + t2950*t2973 + t3019*t3029 + t3049*t3064 + t3134*t3148 + t3158*t3172 - 0.0216*(t3116*t3148 + t3073*t3172) - 1.1135*(t3073*t3148 - 1.*t3116*t3172) + var1[0];
  p_output1[1]=0. + t2186*t2465*t2514 + t2181*t3233 + t2361*t3242 + t2442*t3259 + 0.1305*(-1.*t2186*t2434*t2465 + t2395*t3259) + t2647*t3308 + t2681*t3325 + t2773*t3338 + t2852*t3354 + t2923*t3371 + t2950*t3386 + t3019*t3417 + t3049*t3438 + t3134*t3455 + t3158*t3465 - 0.0216*(t3116*t3455 + t3073*t3465) - 1.1135*(t3073*t3455 - 1.*t3116*t3465) + var1[1];
  p_output1[2]=0. + t2181*t2238*t2465 + t2185*t2361*t2465 - 1.*t2227*t2514 + t2442*t3508 + 0.1305*(t2227*t2434 + t2395*t3508) + t2647*t3532 + t2681*t3546 + t2773*t3553 + t2852*t3566 + t2923*t3573 + t2950*t3590 + t3019*t3605 + t3049*t3614 + t3134*t3625 + t3158*t3633 - 0.0216*(t3116*t3625 + t3073*t3633) - 1.1135*(t3073*t3625 - 1.*t3116*t3633) + var1[2];
}



void LeftToeJoint_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
