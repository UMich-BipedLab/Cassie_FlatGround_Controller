/*
 * Automatically Generated from Mathematica.
 * Mon 25 Jun 2018 14:53:24 GMT-04:00
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
  double t2124;
  double t2089;
  double t2134;
  double t2101;
  double t2138;
  double t328;
  double t2109;
  double t2149;
  double t2160;
  double t2181;
  double t2185;
  double t2186;
  double t2213;
  double t2244;
  double t2249;
  double t2251;
  double t2258;
  double t2238;
  double t2240;
  double t2243;
  double t2324;
  double t2413;
  double t2416;
  double t2421;
  double t2426;
  double t2393;
  double t2395;
  double t2406;
  double t2435;
  double t2439;
  double t2442;
  double t2492;
  double t2496;
  double t2510;
  double t2528;
  double t2555;
  double t2557;
  double t2566;
  double t2605;
  double t2610;
  double t2613;
  double t2621;
  double t2625;
  double t2627;
  double t2635;
  double t2645;
  double t2647;
  double t2652;
  double t2674;
  double t2681;
  double t2689;
  double t2691;
  double t2705;
  double t2710;
  double t2721;
  double t2741;
  double t2750;
  double t2755;
  double t2820;
  double t2824;
  double t2828;
  double t2837;
  double t2839;
  double t2842;
  double t2846;
  double t2871;
  double t2872;
  double t2878;
  double t2903;
  double t2906;
  double t2919;
  double t1962;
  double t2015;
  double t2028;
  double t2050;
  double t2219;
  double t2223;
  double t2963;
  double t2967;
  double t2969;
  double t2982;
  double t2985;
  double t2990;
  double t2255;
  double t2262;
  double t2272;
  double t2338;
  double t2344;
  double t2345;
  double t2998;
  double t3000;
  double t3003;
  double t2424;
  double t2428;
  double t2432;
  double t2454;
  double t2465;
  double t2481;
  double t2514;
  double t2531;
  double t2545;
  double t3030;
  double t3031;
  double t3035;
  double t3049;
  double t3051;
  double t3056;
  double t2583;
  double t2594;
  double t2599;
  double t2631;
  double t2640;
  double t2642;
  double t3064;
  double t3069;
  double t3072;
  double t3080;
  double t3093;
  double t3102;
  double t2661;
  double t2664;
  double t2670;
  double t2717;
  double t2736;
  double t2737;
  double t3115;
  double t3116;
  double t3123;
  double t3137;
  double t3138;
  double t3142;
  double t2773;
  double t2779;
  double t2802;
  double t2845;
  double t2852;
  double t2866;
  double t3150;
  double t3151;
  double t3154;
  double t3158;
  double t3159;
  double t3160;
  double t2890;
  double t2892;
  double t2896;
  double t3169;
  double t3172;
  double t3176;
  double t3182;
  double t3186;
  double t3195;
  double t3239;
  double t3242;
  double t3248;
  double t3280;
  double t3284;
  double t3287;
  double t3296;
  double t3299;
  double t3303;
  double t3308;
  double t3310;
  double t3312;
  double t3316;
  double t3317;
  double t3325;
  double t3334;
  double t3335;
  double t3337;
  double t3341;
  double t3343;
  double t3344;
  double t3354;
  double t3355;
  double t3359;
  double t3365;
  double t3370;
  double t3371;
  double t3378;
  double t3379;
  double t3382;
  double t3386;
  double t3389;
  double t3392;
  t2124 = Cos(var1[3]);
  t2089 = Cos(var1[5]);
  t2134 = Sin(var1[4]);
  t2101 = Sin(var1[3]);
  t2138 = Sin(var1[5]);
  t328 = Cos(var1[6]);
  t2109 = -1.*t2089*t2101;
  t2149 = t2124*t2134*t2138;
  t2160 = t2109 + t2149;
  t2181 = t2124*t2089*t2134;
  t2185 = t2101*t2138;
  t2186 = t2181 + t2185;
  t2213 = Sin(var1[6]);
  t2244 = Cos(var1[7]);
  t2249 = -1.*t2244;
  t2251 = 1. + t2249;
  t2258 = Sin(var1[7]);
  t2238 = t328*t2160;
  t2240 = t2186*t2213;
  t2243 = t2238 + t2240;
  t2324 = Cos(var1[4]);
  t2413 = Cos(var1[8]);
  t2416 = -1.*t2413;
  t2421 = 1. + t2416;
  t2426 = Sin(var1[8]);
  t2393 = t2124*t2324*t2244;
  t2395 = t2243*t2258;
  t2406 = t2393 + t2395;
  t2435 = t328*t2186;
  t2439 = -1.*t2160*t2213;
  t2442 = t2435 + t2439;
  t2492 = Cos(var1[9]);
  t2496 = -1.*t2492;
  t2510 = 1. + t2496;
  t2528 = Sin(var1[9]);
  t2555 = t2413*t2406;
  t2557 = t2442*t2426;
  t2566 = t2555 + t2557;
  t2605 = t2413*t2442;
  t2610 = -1.*t2406*t2426;
  t2613 = t2605 + t2610;
  t2621 = Cos(var1[10]);
  t2625 = -1.*t2621;
  t2627 = 1. + t2625;
  t2635 = Sin(var1[10]);
  t2645 = -1.*t2528*t2566;
  t2647 = t2492*t2613;
  t2652 = t2645 + t2647;
  t2674 = t2492*t2566;
  t2681 = t2528*t2613;
  t2689 = t2674 + t2681;
  t2691 = Cos(var1[11]);
  t2705 = -1.*t2691;
  t2710 = 1. + t2705;
  t2721 = Sin(var1[11]);
  t2741 = t2635*t2652;
  t2750 = t2621*t2689;
  t2755 = t2741 + t2750;
  t2820 = t2621*t2652;
  t2824 = -1.*t2635*t2689;
  t2828 = t2820 + t2824;
  t2837 = Cos(var1[12]);
  t2839 = -1.*t2837;
  t2842 = 1. + t2839;
  t2846 = Sin(var1[12]);
  t2871 = -1.*t2721*t2755;
  t2872 = t2691*t2828;
  t2878 = t2871 + t2872;
  t2903 = t2691*t2755;
  t2906 = t2721*t2828;
  t2919 = t2903 + t2906;
  t1962 = -1.*t328;
  t2015 = 1. + t1962;
  t2028 = 0.135*t2015;
  t2050 = 0. + t2028;
  t2219 = -0.135*t2213;
  t2223 = 0. + t2219;
  t2963 = t2124*t2089;
  t2967 = t2101*t2134*t2138;
  t2969 = t2963 + t2967;
  t2982 = t2089*t2101*t2134;
  t2985 = -1.*t2124*t2138;
  t2990 = t2982 + t2985;
  t2255 = 0.135*t2251;
  t2262 = 0.049*t2258;
  t2272 = 0. + t2255 + t2262;
  t2338 = -0.049*t2251;
  t2344 = 0.135*t2258;
  t2345 = 0. + t2338 + t2344;
  t2998 = t328*t2969;
  t3000 = t2990*t2213;
  t3003 = t2998 + t3000;
  t2424 = -0.049*t2421;
  t2428 = -0.09*t2426;
  t2432 = 0. + t2424 + t2428;
  t2454 = -0.09*t2421;
  t2465 = 0.049*t2426;
  t2481 = 0. + t2454 + t2465;
  t2514 = -0.049*t2510;
  t2531 = -0.21*t2528;
  t2545 = 0. + t2514 + t2531;
  t3030 = t2324*t2244*t2101;
  t3031 = t3003*t2258;
  t3035 = t3030 + t3031;
  t3049 = t328*t2990;
  t3051 = -1.*t2969*t2213;
  t3056 = t3049 + t3051;
  t2583 = -0.21*t2510;
  t2594 = 0.049*t2528;
  t2599 = 0. + t2583 + t2594;
  t2631 = -0.2707*t2627;
  t2640 = 0.0016*t2635;
  t2642 = 0. + t2631 + t2640;
  t3064 = t2413*t3035;
  t3069 = t3056*t2426;
  t3072 = t3064 + t3069;
  t3080 = t2413*t3056;
  t3093 = -1.*t3035*t2426;
  t3102 = t3080 + t3093;
  t2661 = -0.0016*t2627;
  t2664 = -0.2707*t2635;
  t2670 = 0. + t2661 + t2664;
  t2717 = 0.0184*t2710;
  t2736 = -0.7055*t2721;
  t2737 = 0. + t2717 + t2736;
  t3115 = -1.*t2528*t3072;
  t3116 = t2492*t3102;
  t3123 = t3115 + t3116;
  t3137 = t2492*t3072;
  t3138 = t2528*t3102;
  t3142 = t3137 + t3138;
  t2773 = -0.7055*t2710;
  t2779 = -0.0184*t2721;
  t2802 = 0. + t2773 + t2779;
  t2845 = -1.1135*t2842;
  t2852 = 0.0216*t2846;
  t2866 = 0. + t2845 + t2852;
  t3150 = t2635*t3123;
  t3151 = t2621*t3142;
  t3154 = t3150 + t3151;
  t3158 = t2621*t3123;
  t3159 = -1.*t2635*t3142;
  t3160 = t3158 + t3159;
  t2890 = -0.0216*t2842;
  t2892 = -1.1135*t2846;
  t2896 = 0. + t2890 + t2892;
  t3169 = -1.*t2721*t3154;
  t3172 = t2691*t3160;
  t3176 = t3169 + t3172;
  t3182 = t2691*t3154;
  t3186 = t2721*t3160;
  t3195 = t3182 + t3186;
  t3239 = t2324*t328*t2138;
  t3242 = t2324*t2089*t2213;
  t3248 = t3239 + t3242;
  t3280 = -1.*t2244*t2134;
  t3284 = t3248*t2258;
  t3287 = t3280 + t3284;
  t3296 = t2324*t2089*t328;
  t3299 = -1.*t2324*t2138*t2213;
  t3303 = t3296 + t3299;
  t3308 = t2413*t3287;
  t3310 = t3303*t2426;
  t3312 = t3308 + t3310;
  t3316 = t2413*t3303;
  t3317 = -1.*t3287*t2426;
  t3325 = t3316 + t3317;
  t3334 = -1.*t2528*t3312;
  t3335 = t2492*t3325;
  t3337 = t3334 + t3335;
  t3341 = t2492*t3312;
  t3343 = t2528*t3325;
  t3344 = t3341 + t3343;
  t3354 = t2635*t3337;
  t3355 = t2621*t3344;
  t3359 = t3354 + t3355;
  t3365 = t2621*t3337;
  t3370 = -1.*t2635*t3344;
  t3371 = t3365 + t3370;
  t3378 = -1.*t2721*t3359;
  t3379 = t2691*t3371;
  t3382 = t3378 + t3379;
  t3386 = t2691*t3359;
  t3389 = t2721*t3371;
  t3392 = t3386 + t3389;
  p_output1[0]=0. + t2050*t2160 + t2186*t2223 + t2243*t2272 + 0.1305*(t2243*t2244 - 1.*t2124*t2258*t2324) + t2124*t2324*t2345 + t2406*t2432 + t2442*t2481 + t2545*t2566 + t2599*t2613 + t2642*t2652 + t2670*t2689 + t2737*t2755 + t2802*t2828 + t2866*t2878 + t2896*t2919 - 0.0216*(t2846*t2878 + t2837*t2919) - 1.1135*(t2837*t2878 - 1.*t2846*t2919) + var1[0];
  p_output1[1]=0. + t2101*t2324*t2345 + t2050*t2969 + t2223*t2990 + t2272*t3003 + 0.1305*(-1.*t2101*t2258*t2324 + t2244*t3003) + t2432*t3035 + t2481*t3056 + t2545*t3072 + t2599*t3102 + t2642*t3123 + t2670*t3142 + t2737*t3154 + t2802*t3160 + t2866*t3176 + t2896*t3195 - 0.0216*(t2846*t3176 + t2837*t3195) - 1.1135*(t2837*t3176 - 1.*t2846*t3195) + var1[1];
  p_output1[2]=0. + t2050*t2138*t2324 + t2089*t2223*t2324 - 1.*t2134*t2345 + t2272*t3248 + 0.1305*(t2134*t2258 + t2244*t3248) + t2432*t3287 + t2481*t3303 + t2545*t3312 + t2599*t3325 + t2642*t3337 + t2670*t3344 + t2737*t3359 + t2802*t3371 + t2866*t3382 + t2896*t3392 - 0.0216*(t2846*t3382 + t2837*t3392) - 1.1135*(t2837*t3382 - 1.*t2846*t3392) + var1[2];
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

#include "LeftToeJoint_mex.hh"

namespace SymExpression
{

void LeftToeJoint_mex_raw(double *p_output1, const double *var1)
{
  // Call Subroutines
  output1(p_output1, var1);

}

}

#endif // MATLAB_MEX_FILE
