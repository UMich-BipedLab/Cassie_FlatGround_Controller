/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_doFilter2_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 28-May-2019 16:42:10
 */

#ifndef _CODER_DOFILTER2_API_H
#define _CODER_DOFILTER2_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_doFilter2_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void doFilter2(real_T x[100], real_T y[100]);
extern void doFilter2_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void doFilter2_atexit(void);
extern void doFilter2_initialize(void);
extern void doFilter2_terminate(void);
extern void doFilter2_xil_terminate(void);

#endif

/*
 * File trailer for _coder_doFilter2_api.h
 *
 * [EOF]
 */
