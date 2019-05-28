//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: doFilter2_initialize.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 28-May-2019 16:42:10
//

// Include Files
#include "rt_nonfinite.h"
#include "doFilter2.h"
#include "doFilter2_initialize.h"
#include "doFilter2_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void doFilter2_initialize()
{
  int i;
  static const double dv0[16] = { -1.99616346197925, 0.996452021461684,
    -1.98925984173658, 0.989547403252102, -1.98285516002368, 0.983141795697362,
    -1.977217641326, 0.977503462056666, -1.97257906535629, 0.972864215548143,
    -1.96912712676391, 0.969411777953736, -1.96699974562219, 0.967284089284092,
    -0.983140587570102, 0.0 };

  static const signed char iv0[24] = { 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2,
    1, 1, 2, 1, 1, 2, 1, 1, 1, 0 };

  static const double dv1[9] = { 7.2139870607604E-5, 7.18903788798391E-5,
    7.16589184213885E-5, 7.14551826667048E-5, 7.12875479631187E-5,
    7.11627974563878E-5, 7.10859154759187E-5, 0.00842970621494907, 0.0 };

  static const boolean_T bv0[9] = { true, true, true, true, true, true, true,
    true, false };

  rt_InitInfAndNaN(8U);

  //  The following code was used to design the filter coefficients:
  //
  //  Fpass = 5;     % Passband Frequency
  //  Fstop = 10;    % Stopband Frequency
  //  Apass = 1;     % Passband Ripple (dB)
  //  Astop = 80;    % Stopband Attenuation (dB)
  //  Fs    = 2000;  % Sampling Frequency
  //
  //  h = fdesign.lowpass('fp,fst,ap,ast', Fpass, Fstop, Apass, Astop, Fs);
  //
  //  Hd = design(h, 'butter', ...
  //      'MatchExactly', 'stopband', ...
  //      'SystemObject', true);
  // System object Constructor function: dsp.BiquadFilter
  Hd.cSFunObject.P0_ICRTP = 0.0;
  for (i = 0; i < 24; i++) {
    Hd.cSFunObject.P1_RTP1COEFF[i] = iv0[i];
  }

  memcpy(&Hd.cSFunObject.P2_RTP2COEFF[0], &dv0[0], sizeof(double) << 4);
  memcpy(&Hd.cSFunObject.P3_RTP3COEFF[0], &dv1[0], 9U * sizeof(double));
  for (i = 0; i < 9; i++) {
    Hd.cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }

  // System object Initialization function: dsp.BiquadFilter
  for (i = 0; i < 1600; i++) {
    Hd.cSFunObject.W0_FILT_STATES[i] = Hd.cSFunObject.P0_ICRTP;
  }
}

//
// File trailer for doFilter2_initialize.cpp
//
// [EOF]
//
