/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:26 GMT-04:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "RightToeJoint_src.h"

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
  double t2442;
  double t2940;
  double t2963;
  double t2945;
  double t2967;
  double t2545;
  double t2557;
  double t2571;
  double t2690;
  double t2845;
  double t2950;
  double t3024;
  double t3049;
  double t3109;
  double t3182;
  double t3186;
  double t3197;
  double t2481;
  double t3223;
  double t3228;
  double t3277;
  double t3303;
  double t3306;
  double t3310;
  double t3335;
  double t3371;
  double t3383;
  double t3406;
  double t3480;
  double t3484;
  double t3488;
  double t3509;
  double t3518;
  double t3520;
  double t3528;
  double t3548;
  double t3552;
  double t3556;
  double t3614;
  double t3624;
  double t3631;
  double t3639;
  double t3645;
  double t3646;
  double t3656;
  double t3664;
  double t3672;
  double t3673;
  double t3682;
  double t3684;
  double t3688;
  double t3692;
  double t3693;
  double t3697;
  double t3705;
  double t3732;
  double t3740;
  double t3744;
  double t3767;
  double t3775;
  double t3778;
  double t3785;
  double t3787;
  double t3793;
  double t3804;
  double t3813;
  double t3818;
  double t3824;
  double t3839;
  double t3842;
  double t3847;
  double t2664;
  double t2756;
  double t2773;
  double t2923;
  double t2934;
  double t3123;
  double t3150;
  double t3151;
  double t3166;
  double t3206;
  double t3210;
  double t3217;
  double t3875;
  double t3877;
  double t3881;
  double t3883;
  double t3884;
  double t3885;
  double t3325;
  double t3337;
  double t3355;
  double t3888;
  double t3897;
  double t3904;
  double t3472;
  double t3473;
  double t3474;
  double t3523;
  double t3541;
  double t3546;
  double t3906;
  double t3908;
  double t3910;
  double t3935;
  double t3936;
  double t3939;
  double t3572;
  double t3594;
  double t3610;
  double t3649;
  double t3660;
  double t3662;
  double t3943;
  double t3944;
  double t3945;
  double t3949;
  double t3953;
  double t3955;
  double t3678;
  double t3679;
  double t3681;
  double t3703;
  double t3713;
  double t3722;
  double t3960;
  double t3962;
  double t3966;
  double t3970;
  double t3972;
  double t3974;
  double t3756;
  double t3762;
  double t3763;
  double t3794;
  double t3805;
  double t3810;
  double t3978;
  double t3983;
  double t3984;
  double t3988;
  double t3989;
  double t3990;
  double t3831;
  double t3834;
  double t3835;
  double t3993;
  double t3995;
  double t3996;
  double t4001;
  double t4002;
  double t4004;
  double t4024;
  double t4026;
  double t4028;
  double t4031;
  double t4034;
  double t4036;
  double t4049;
  double t4050;
  double t4054;
  double t4057;
  double t4058;
  double t4060;
  double t4063;
  double t4064;
  double t4067;
  double t4072;
  double t4073;
  double t4075;
  double t4077;
  double t4078;
  double t4079;
  double t4082;
  double t4083;
  double t4085;
  double t4090;
  double t4091;
  double t4093;
  double t4095;
  double t4096;
  double t4097;
  double t4099;
  double t4102;
  double t4103;
  t2442 = Cos(var1[3]);
  t2940 = Cos(var1[5]);
  t2963 = Sin(var1[3]);
  t2945 = Sin(var1[4]);
  t2967 = Sin(var1[5]);
  t2545 = Cos(var1[14]);
  t2557 = -1.*t2545;
  t2571 = 1. + t2557;
  t2690 = Sin(var1[14]);
  t2845 = Sin(var1[13]);
  t2950 = t2442*t2940*t2945;
  t3024 = t2963*t2967;
  t3049 = t2950 + t3024;
  t3109 = Cos(var1[13]);
  t3182 = -1.*t2940*t2963;
  t3186 = t2442*t2945*t2967;
  t3197 = t3182 + t3186;
  t2481 = Cos(var1[4]);
  t3223 = t2845*t3049;
  t3228 = t3109*t3197;
  t3277 = t3223 + t3228;
  t3303 = Cos(var1[15]);
  t3306 = -1.*t3303;
  t3310 = 1. + t3306;
  t3335 = Sin(var1[15]);
  t3371 = t3109*t3049;
  t3383 = -1.*t2845*t3197;
  t3406 = t3371 + t3383;
  t3480 = t2545*t2442*t2481;
  t3484 = t2690*t3277;
  t3488 = t3480 + t3484;
  t3509 = Cos(var1[16]);
  t3518 = -1.*t3509;
  t3520 = 1. + t3518;
  t3528 = Sin(var1[16]);
  t3548 = t3335*t3406;
  t3552 = t3303*t3488;
  t3556 = t3548 + t3552;
  t3614 = t3303*t3406;
  t3624 = -1.*t3335*t3488;
  t3631 = t3614 + t3624;
  t3639 = Cos(var1[17]);
  t3645 = -1.*t3639;
  t3646 = 1. + t3645;
  t3656 = Sin(var1[17]);
  t3664 = -1.*t3528*t3556;
  t3672 = t3509*t3631;
  t3673 = t3664 + t3672;
  t3682 = t3509*t3556;
  t3684 = t3528*t3631;
  t3688 = t3682 + t3684;
  t3692 = Cos(var1[18]);
  t3693 = -1.*t3692;
  t3697 = 1. + t3693;
  t3705 = Sin(var1[18]);
  t3732 = t3656*t3673;
  t3740 = t3639*t3688;
  t3744 = t3732 + t3740;
  t3767 = t3639*t3673;
  t3775 = -1.*t3656*t3688;
  t3778 = t3767 + t3775;
  t3785 = Cos(var1[19]);
  t3787 = -1.*t3785;
  t3793 = 1. + t3787;
  t3804 = Sin(var1[19]);
  t3813 = -1.*t3705*t3744;
  t3818 = t3692*t3778;
  t3824 = t3813 + t3818;
  t3839 = t3692*t3744;
  t3842 = t3705*t3778;
  t3847 = t3839 + t3842;
  t2664 = -0.049*t2571;
  t2756 = -0.135*t2690;
  t2773 = 0. + t2664 + t2756;
  t2923 = 0.135*t2845;
  t2934 = 0. + t2923;
  t3123 = -1.*t3109;
  t3150 = 1. + t3123;
  t3151 = -0.135*t3150;
  t3166 = 0. + t3151;
  t3206 = -0.135*t2571;
  t3210 = 0.049*t2690;
  t3217 = 0. + t3206 + t3210;
  t3875 = t2940*t2963*t2945;
  t3877 = -1.*t2442*t2967;
  t3881 = t3875 + t3877;
  t3883 = t2442*t2940;
  t3884 = t2963*t2945*t2967;
  t3885 = t3883 + t3884;
  t3325 = -0.09*t3310;
  t3337 = 0.049*t3335;
  t3355 = 0. + t3325 + t3337;
  t3888 = t2845*t3881;
  t3897 = t3109*t3885;
  t3904 = t3888 + t3897;
  t3472 = -0.049*t3310;
  t3473 = -0.09*t3335;
  t3474 = 0. + t3472 + t3473;
  t3523 = -0.049*t3520;
  t3541 = -0.21*t3528;
  t3546 = 0. + t3523 + t3541;
  t3906 = t3109*t3881;
  t3908 = -1.*t2845*t3885;
  t3910 = t3906 + t3908;
  t3935 = t2545*t2481*t2963;
  t3936 = t2690*t3904;
  t3939 = t3935 + t3936;
  t3572 = -0.21*t3520;
  t3594 = 0.049*t3528;
  t3610 = 0. + t3572 + t3594;
  t3649 = -0.2707*t3646;
  t3660 = 0.0016*t3656;
  t3662 = 0. + t3649 + t3660;
  t3943 = t3335*t3910;
  t3944 = t3303*t3939;
  t3945 = t3943 + t3944;
  t3949 = t3303*t3910;
  t3953 = -1.*t3335*t3939;
  t3955 = t3949 + t3953;
  t3678 = -0.0016*t3646;
  t3679 = -0.2707*t3656;
  t3681 = 0. + t3678 + t3679;
  t3703 = 0.0184*t3697;
  t3713 = -0.7055*t3705;
  t3722 = 0. + t3703 + t3713;
  t3960 = -1.*t3528*t3945;
  t3962 = t3509*t3955;
  t3966 = t3960 + t3962;
  t3970 = t3509*t3945;
  t3972 = t3528*t3955;
  t3974 = t3970 + t3972;
  t3756 = -0.7055*t3697;
  t3762 = -0.0184*t3705;
  t3763 = 0. + t3756 + t3762;
  t3794 = -1.1135*t3793;
  t3805 = 0.0216*t3804;
  t3810 = 0. + t3794 + t3805;
  t3978 = t3656*t3966;
  t3983 = t3639*t3974;
  t3984 = t3978 + t3983;
  t3988 = t3639*t3966;
  t3989 = -1.*t3656*t3974;
  t3990 = t3988 + t3989;
  t3831 = -0.0216*t3793;
  t3834 = -1.1135*t3804;
  t3835 = 0. + t3831 + t3834;
  t3993 = -1.*t3705*t3984;
  t3995 = t3692*t3990;
  t3996 = t3993 + t3995;
  t4001 = t3692*t3984;
  t4002 = t3705*t3990;
  t4004 = t4001 + t4002;
  t4024 = t2481*t2940*t2845;
  t4026 = t3109*t2481*t2967;
  t4028 = t4024 + t4026;
  t4031 = t3109*t2481*t2940;
  t4034 = -1.*t2481*t2845*t2967;
  t4036 = t4031 + t4034;
  t4049 = -1.*t2545*t2945;
  t4050 = t2690*t4028;
  t4054 = t4049 + t4050;
  t4057 = t3335*t4036;
  t4058 = t3303*t4054;
  t4060 = t4057 + t4058;
  t4063 = t3303*t4036;
  t4064 = -1.*t3335*t4054;
  t4067 = t4063 + t4064;
  t4072 = -1.*t3528*t4060;
  t4073 = t3509*t4067;
  t4075 = t4072 + t4073;
  t4077 = t3509*t4060;
  t4078 = t3528*t4067;
  t4079 = t4077 + t4078;
  t4082 = t3656*t4075;
  t4083 = t3639*t4079;
  t4085 = t4082 + t4083;
  t4090 = t3639*t4075;
  t4091 = -1.*t3656*t4079;
  t4093 = t4090 + t4091;
  t4095 = -1.*t3705*t4085;
  t4096 = t3692*t4093;
  t4097 = t4095 + t4096;
  t4099 = t3692*t4085;
  t4102 = t3705*t4093;
  t4103 = t4099 + t4102;
  p_output1[0]=0. + t2442*t2481*t2773 + t2934*t3049 + t3166*t3197 + t3217*t3277 - 0.1305*(-1.*t2442*t2481*t2690 + t2545*t3277) + t3355*t3406 + t3474*t3488 + t3546*t3556 + t3610*t3631 + t3662*t3673 + t3681*t3688 + t3722*t3744 + t3763*t3778 + t3810*t3824 + t3835*t3847 - 0.0216*(t3804*t3824 + t3785*t3847) - 1.1135*(t3785*t3824 - 1.*t3804*t3847) + var1[0];
  p_output1[1]=0. + t2481*t2773*t2963 + t2934*t3881 + t3166*t3885 + t3217*t3904 - 0.1305*(-1.*t2481*t2690*t2963 + t2545*t3904) + t3355*t3910 + t3474*t3939 + t3546*t3945 + t3610*t3955 + t3662*t3966 + t3681*t3974 + t3722*t3984 + t3763*t3990 + t3810*t3996 + t3835*t4004 - 0.0216*(t3804*t3996 + t3785*t4004) - 1.1135*(t3785*t3996 - 1.*t3804*t4004) + var1[1];
  p_output1[2]=0. + t2481*t2934*t2940 - 1.*t2773*t2945 + t2481*t2967*t3166 + t3217*t4028 - 0.1305*(t2690*t2945 + t2545*t4028) + t3355*t4036 + t3474*t4054 + t3546*t4060 + t3610*t4067 + t3662*t4075 + t3681*t4079 + t3722*t4085 + t3763*t4093 + t3810*t4097 + t3835*t4103 - 0.0216*(t3804*t4097 + t3785*t4103) - 1.1135*(t3785*t4097 - 1.*t3804*t4103) + var1[2];
}



void RightToeJoint_src(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}
