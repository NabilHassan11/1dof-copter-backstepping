/*
 * Model_data.c
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

#include "Model.h"

/* Block parameters (default storage) */
P_Model_T Model_P = {
  /* Variable: param
   * Referenced by:
   *   '<S3>/Constant'
   *   '<S3>/Constant1'
   *   '<S3>/Gain'
   *   '<S3>/Gain1'
   *   '<S3>/Gain2'
   *   '<S3>/Gain3'
   *   '<S4>/Air density'
   *   '<S4>/Radius of Propeller'
   *   '<S4>/Thrust coefficient'
   *   '<S4>/Gain'
   *   '<S5>/Constant'
   *   '<S5>/Constant1'
   *   '<S5>/Constant2'
   *   '<S5>/Gain'
   */
  {
    0.052,
    0.15,
    0.00058499999999999991,
    0.09,
    5.0e-5,
    0.00434,
    0.00434,
    0.001,
    0.198,
    0.3,
    0.01782,
    0.25,
    0.018404999999999998,
    9.81,
    1.732,
    1.225,
    0.15,
    0.1143,
    0.018191409995403637,
    0.01
  },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S3>/Constant2'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S4>/Constant'
   */
  1.5707963267948966,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0
};
