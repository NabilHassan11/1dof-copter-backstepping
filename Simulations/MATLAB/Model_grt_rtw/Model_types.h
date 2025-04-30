/*
 * Model_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun Dec 15 01:55:42 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Model_types_h_
#define Model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_V1cTy8RJ0ZJH1eQsx0XUCC_
#define DEFINED_TYPEDEF_FOR_struct_V1cTy8RJ0ZJH1eQsx0XUCC_

typedef struct {
  real_T m_motor;
  real_T r_propeller;
  real_T Jm;
  real_T R;
  real_T L;
  real_T Ke;
  real_T Kt;
  real_T B;
  real_T m_rod;
  real_T l;
  real_T J_rod;
  real_T m;
  real_T J;
  real_T g;
  real_T C_t;
  real_T P;
  real_T r;
  real_T pitch;
  real_T K;
  real_T K_telda;
} struct_V1cTy8RJ0ZJH1eQsx0XUCC;

#endif

/* Parameters (default storage) */
typedef struct P_Model_T_ P_Model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Model_T RT_MODEL_Model_T;

#endif                                 /* Model_types_h_ */
