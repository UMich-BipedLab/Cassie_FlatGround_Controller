/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:25 GMT-04:00
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
  double t640;
  double t2647;
  double t2670;
  double t2657;
  double t2681;
  double t2272;
  double t2389;
  double t2435;
  double t2454;
  double t2555;
  double t2664;
  double t2690;
  double t2756;
  double t2779;
  double t2906;
  double t2923;
  double t2929;
  double t2262;
  double t2963;
  double t2967;
  double t2982;
  double t3030;
  double t3031;
  double t3041;
  double t3064;
  double t3123;
  double t3134;
  double t3150;
  double t3217;
  double t3223;
  double t3227;
  double t3238;
  double t3257;
  double t3276;
  double t3284;
  double t3306;
  double t3310;
  double t3314;
  double t3371;
  double t3377;
  double t3383;
  double t3408;
  double t3425;
  double t3429;
  double t3445;
  double t3464;
  double t3468;
  double t3470;
  double t3484;
  double t3488;
  double t3490;
  double t3499;
  double t3505;
  double t3508;
  double t3512;
  double t3523;
  double t3528;
  double t3533;
  double t3556;
  double t3566;
  double t3570;
  double t3573;
  double t3583;
  double t3585;
  double t3596;
  double t3617;
  double t3624;
  double t3626;
  double t3646;
  double t3649;
  double t3652;
  double t2442;
  double t2481;
  double t2531;
  double t2557;
  double t2571;
  double t2802;
  double t2828;
  double t2834;
  double t2845;
  double t2940;
  double t2945;
  double t2950;
  double t3684;
  double t3685;
  double t3688;
  double t3692;
  double t3693;
  double t3696;
  double t3049;
  double t3069;
  double t3109;
  double t3703;
  double t3705;
  double t3711;
  double t3204;
  double t3206;
  double t3210;
  double t3277;
  double t3290;
  double t3303;
  double t3722;
  double t3725;
  double t3732;
  double t3763;
  double t3767;
  double t3771;
  double t3335;
  double t3337;
  double t3355;
  double t3438;
  double t3457;
  double t3462;
  double t3778;
  double t3783;
  double t3784;
  double t3787;
  double t3788;
  double t3793;
  double t3473;
  double t3474;
  double t3480;
  double t3509;
  double t3518;
  double t3520;
  double t3798;
  double t3804;
  double t3805;
  double t3813;
  double t3818;
  double t3822;
  double t3546;
  double t3548;
  double t3552;
  double t3594;
  double t3610;
  double t3614;
  double t3826;
  double t3831;
  double t3832;
  double t3835;
  double t3837;
  double t3839;
  double t3638;
  double t3639;
  double t3645;
  double t3844;
  double t3847;
  double t3851;
  double t3855;
  double t3858;
  double t3860;
  double t3884;
  double t3885;
  double t3887;
  double t3897;
  double t3899;
  double t3904;
  double t3919;
  double t3920;
  double t3923;
  double t3927;
  double t3928;
  double t3931;
  double t3936;
  double t3937;
  double t3939;
  double t3941;
  double t3943;
  double t3944;
  double t3947;
  double t3949;
  double t3952;
  double t3955;
  double t3958;
  double t3959;
  double t3962;
  double t3965;
  double t3966;
  double t3969;
  double t3970;
  double t3971;
  double t3974;
  double t3975;
  double t3976;
  t640 = Cos(var1[3]);
  t2647 = Cos(var1[5]);
  t2670 = Sin(var1[3]);
  t2657 = Sin(var1[4]);
  t2681 = Sin(var1[5]);
  t2272 = Cos(var1[14]);
  t2389 = -1.*t2272;
  t2435 = 1. + t2389;
  t2454 = Sin(var1[14]);
  t2555 = Sin(var1[13]);
  t2664 = t640*t2647*t2657;
  t2690 = t2670*t2681;
  t2756 = t2664 + t2690;
  t2779 = Cos(var1[13]);
  t2906 = -1.*t2647*t2670;
  t2923 = t640*t2657*t2681;
  t2929 = t2906 + t2923;
  t2262 = Cos(var1[4]);
  t2963 = t2555*t2756;
  t2967 = t2779*t2929;
  t2982 = t2963 + t2967;
  t3030 = Cos(var1[15]);
  t3031 = -1.*t3030;
  t3041 = 1. + t3031;
  t3064 = Sin(var1[15]);
  t3123 = t2779*t2756;
  t3134 = -1.*t2555*t2929;
  t3150 = t3123 + t3134;
  t3217 = t2272*t640*t2262;
  t3223 = t2454*t2982;
  t3227 = t3217 + t3223;
  t3238 = Cos(var1[16]);
  t3257 = -1.*t3238;
  t3276 = 1. + t3257;
  t3284 = Sin(var1[16]);
  t3306 = t3064*t3150;
  t3310 = t3030*t3227;
  t3314 = t3306 + t3310;
  t3371 = t3030*t3150;
  t3377 = -1.*t3064*t3227;
  t3383 = t3371 + t3377;
  t3408 = Cos(var1[17]);
  t3425 = -1.*t3408;
  t3429 = 1. + t3425;
  t3445 = Sin(var1[17]);
  t3464 = -1.*t3284*t3314;
  t3468 = t3238*t3383;
  t3470 = t3464 + t3468;
  t3484 = t3238*t3314;
  t3488 = t3284*t3383;
  t3490 = t3484 + t3488;
  t3499 = Cos(var1[18]);
  t3505 = -1.*t3499;
  t3508 = 1. + t3505;
  t3512 = Sin(var1[18]);
  t3523 = t3445*t3470;
  t3528 = t3408*t3490;
  t3533 = t3523 + t3528;
  t3556 = t3408*t3470;
  t3566 = -1.*t3445*t3490;
  t3570 = t3556 + t3566;
  t3573 = Cos(var1[19]);
  t3583 = -1.*t3573;
  t3585 = 1. + t3583;
  t3596 = Sin(var1[19]);
  t3617 = -1.*t3512*t3533;
  t3624 = t3499*t3570;
  t3626 = t3617 + t3624;
  t3646 = t3499*t3533;
  t3649 = t3512*t3570;
  t3652 = t3646 + t3649;
  t2442 = -0.049*t2435;
  t2481 = -0.135*t2454;
  t2531 = 0. + t2442 + t2481;
  t2557 = 0.135*t2555;
  t2571 = 0. + t2557;
  t2802 = -1.*t2779;
  t2828 = 1. + t2802;
  t2834 = -0.135*t2828;
  t2845 = 0. + t2834;
  t2940 = -0.135*t2435;
  t2945 = 0.049*t2454;
  t2950 = 0. + t2940 + t2945;
  t3684 = t2647*t2670*t2657;
  t3685 = -1.*t640*t2681;
  t3688 = t3684 + t3685;
  t3692 = t640*t2647;
  t3693 = t2670*t2657*t2681;
  t3696 = t3692 + t3693;
  t3049 = -0.09*t3041;
  t3069 = 0.049*t3064;
  t3109 = 0. + t3049 + t3069;
  t3703 = t2555*t3688;
  t3705 = t2779*t3696;
  t3711 = t3703 + t3705;
  t3204 = -0.049*t3041;
  t3206 = -0.09*t3064;
  t3210 = 0. + t3204 + t3206;
  t3277 = -0.049*t3276;
  t3290 = -0.21*t3284;
  t3303 = 0. + t3277 + t3290;
  t3722 = t2779*t3688;
  t3725 = -1.*t2555*t3696;
  t3732 = t3722 + t3725;
  t3763 = t2272*t2262*t2670;
  t3767 = t2454*t3711;
  t3771 = t3763 + t3767;
  t3335 = -0.21*t3276;
  t3337 = 0.049*t3284;
  t3355 = 0. + t3335 + t3337;
  t3438 = -0.2707*t3429;
  t3457 = 0.0016*t3445;
  t3462 = 0. + t3438 + t3457;
  t3778 = t3064*t3732;
  t3783 = t3030*t3771;
  t3784 = t3778 + t3783;
  t3787 = t3030*t3732;
  t3788 = -1.*t3064*t3771;
  t3793 = t3787 + t3788;
  t3473 = -0.0016*t3429;
  t3474 = -0.2707*t3445;
  t3480 = 0. + t3473 + t3474;
  t3509 = 0.0184*t3508;
  t3518 = -0.7055*t3512;
  t3520 = 0. + t3509 + t3518;
  t3798 = -1.*t3284*t3784;
  t3804 = t3238*t3793;
  t3805 = t3798 + t3804;
  t3813 = t3238*t3784;
  t3818 = t3284*t3793;
  t3822 = t3813 + t3818;
  t3546 = -0.7055*t3508;
  t3548 = -0.0184*t3512;
  t3552 = 0. + t3546 + t3548;
  t3594 = -1.1135*t3585;
  t3610 = 0.0216*t3596;
  t3614 = 0. + t3594 + t3610;
  t3826 = t3445*t3805;
  t3831 = t3408*t3822;
  t3832 = t3826 + t3831;
  t3835 = t3408*t3805;
  t3837 = -1.*t3445*t3822;
  t3839 = t3835 + t3837;
  t3638 = -0.0216*t3585;
  t3639 = -1.1135*t3596;
  t3645 = 0. + t3638 + t3639;
  t3844 = -1.*t3512*t3832;
  t3847 = t3499*t3839;
  t3851 = t3844 + t3847;
  t3855 = t3499*t3832;
  t3858 = t3512*t3839;
  t3860 = t3855 + t3858;
  t3884 = t2262*t2647*t2555;
  t3885 = t2779*t2262*t2681;
  t3887 = t3884 + t3885;
  t3897 = t2779*t2262*t2647;
  t3899 = -1.*t2262*t2555*t2681;
  t3904 = t3897 + t3899;
  t3919 = -1.*t2272*t2657;
  t3920 = t2454*t3887;
  t3923 = t3919 + t3920;
  t3927 = t3064*t3904;
  t3928 = t3030*t3923;
  t3931 = t3927 + t3928;
  t3936 = t3030*t3904;
  t3937 = -1.*t3064*t3923;
  t3939 = t3936 + t3937;
  t3941 = -1.*t3284*t3931;
  t3943 = t3238*t3939;
  t3944 = t3941 + t3943;
  t3947 = t3238*t3931;
  t3949 = t3284*t3939;
  t3952 = t3947 + t3949;
  t3955 = t3445*t3944;
  t3958 = t3408*t3952;
  t3959 = t3955 + t3958;
  t3962 = t3408*t3944;
  t3965 = -1.*t3445*t3952;
  t3966 = t3962 + t3965;
  t3969 = -1.*t3512*t3959;
  t3970 = t3499*t3966;
  t3971 = t3969 + t3970;
  t3974 = t3499*t3959;
  t3975 = t3512*t3966;
  t3976 = t3974 + t3975;
  p_output1[0]=0. + t2571*t2756 + t2845*t2929 + t2950*t2982 + t3109*t3150 + t3210*t3227 + t3303*t3314 + t3355*t3383 + t3462*t3470 + t3480*t3490 + t3520*t3533 + t3552*t3570 + t3614*t3626 + t3645*t3652 - 0.0216*(t3596*t3626 + t3573*t3652) - 1.1135*(t3573*t3626 - 1.*t3596*t3652) + t2262*t2531*t640 - 0.1305*(t2272*t2982 - 1.*t2262*t2454*t640) + var1[0];
  p_output1[1]=0. + t2262*t2531*t2670 + t2571*t3688 + t2845*t3696 + t2950*t3711 - 0.1305*(-1.*t2262*t2454*t2670 + t2272*t3711) + t3109*t3732 + t3210*t3771 + t3303*t3784 + t3355*t3793 + t3462*t3805 + t3480*t3822 + t3520*t3832 + t3552*t3839 + t3614*t3851 + t3645*t3860 - 0.0216*(t3596*t3851 + t3573*t3860) - 1.1135*(t3573*t3851 - 1.*t3596*t3860) + var1[1];
  p_output1[2]=0. + t2262*t2571*t2647 - 1.*t2531*t2657 + t2262*t2681*t2845 + t2950*t3887 - 0.1305*(t2454*t2657 + t2272*t3887) + t3109*t3904 + t3210*t3923 + t3303*t3931 + t3355*t3939 + t3462*t3944 + t3480*t3952 + t3520*t3959 + t3552*t3966 + t3614*t3971 + t3645*t3976 - 0.0216*(t3596*t3971 + t3573*t3976) - 1.1135*(t3573*t3971 - 1.*t3596*t3976) + var1[2];
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

#include "RightToeJoint_mex.hh"

namespace SymExpression
{

void RightToeJoint_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
