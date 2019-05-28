//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: doFilter2_types.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 28-May-2019 16:42:10
//
#ifndef DOFILTER2_TYPES_H
#define DOFILTER2_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_dsp_BiquadFilter_0
#define struct_dsp_BiquadFilter_0

struct dsp_BiquadFilter_0
{
  int S0_isInitialized;
  double W0_FILT_STATES[1600];
  int W1_PreviousNumChannels;
  double P0_ICRTP;
  double P1_RTP1COEFF[24];
  double P2_RTP2COEFF[16];
  double P3_RTP3COEFF[9];
  boolean_T P4_RTP_COEFF3_BOOL[9];
};

#endif                                 //struct_dsp_BiquadFilter_0

typedef struct {
  dsp_BiquadFilter_0 cSFunObject;
} dspcodegen_BiquadFilter;

#endif

//
// File trailer for doFilter2_types.h
//
// [EOF]
//
