/*
 * Model.c
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
#include <math.h>
#include "rtwtypes.h"
#include "Model_private.h"

/* Block signals (default storage) */
B_Model_T Model_B;

/* Continuous states */
X_Model_T Model_X;

/* Disabled State Vector */
XDis_Model_T Model_XDis;

/* Real-time model */
static RT_MODEL_Model_T Model_M_;
RT_MODEL_Model_T *const Model_M = &Model_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Model_step();
  Model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Model_step();
  Model_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Model_step(void)
{
  real_T Product_tmp;
  real_T rtb_Integrator1;
  real_T theta_ddot;
  real_T theta_ddot_tmp;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(Model_M)) {
    /* set solver stop time */
    if (!(Model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Model_M->solverInfo, ((Model_M->Timing.clockTickH0
        + 1) * Model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Model_M->solverInfo, ((Model_M->Timing.clockTick0 +
        1) * Model_M->Timing.stepSize0 + Model_M->Timing.clockTickH0 *
        Model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Model_M)) {
    Model_M->Timing.t[0] = rtsiGetT(&Model_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator1' */
  Model_B.Integrator1 = Model_X.Integrator1_CSTATE;

  /* Integrator: '<Root>/Integrator2' */
  Model_B.Integrator2 = Model_X.Integrator2_CSTATE;

  /* Integrator: '<Root>/Integrator3' */
  Model_B.Integrator3 = Model_X.Integrator3_CSTATE;

  /* Integrator: '<Root>/Integrator4' */
  Model_B.Integrator4 = Model_X.Integrator4_CSTATE;
  tmp = rtmIsMajorTimeStep(Model_M);
  if (tmp) {
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Integrator: '<S3>/Integrator'
   *  Integrator: '<S3>/Integrator1'
   *  Math: '<S3>/Square'
   *  Product: '<S3>/Product1'
   */
  Model_B.Add = ((Model_P.param.Kt / Model_P.param.Jm *
                  Model_X.Integrator_CSTATE - Model_P.param.B / Model_P.param.Jm
                  * Model_X.Integrator1_CSTATE_e) - Model_X.Integrator1_CSTATE_e
                 * Model_X.Integrator1_CSTATE_e * Model_P.param.K_telda) -
    Model_P.Constant2_Value;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  SignalConversion generated from: '<S1>/ SFunction '
   */
  rtb_Integrator1 = sin(Model_B.Integrator1);
  theta_ddot_tmp = Model_B.Integrator4 * Model_B.Integrator4;
  theta_ddot = theta_ddot_tmp * 0.018191409995403637 * 0.3 /
    0.018404999999999998 + -39.975550122249395 * rtb_Integrator1;
  Product_tmp = cos(Model_B.Integrator1);

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain3'
   *  Integrator: '<S3>/Integrator'
   *  Integrator: '<S3>/Integrator1'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  SignalConversion generated from: '<S1>/ SFunction '
   *  Sum: '<S3>/Subtract'
   */
  Model_B.Product = ((((((((((((rtb_Integrator1 * Model_B.Integrator2 -
    Product_tmp * theta_ddot) * 39.975550122249395 - 2.0 * Model_B.Integrator1)
    - 2.0 * Model_B.Integrator2) - 2.0 * theta_ddot) - (0.036382819990807273 *
    Model_B.Integrator4 * Model_B.Add * 0.3 / 0.018404999999999998 +
    -39.975550122249395 * Product_tmp * Model_B.Integrator2) * 2.0) *
    0.061349999999999995 + Model_B.Add * Model_B.Add * -0.036382819990807273) *
    (1.0 / (0.036382819990807273 * Model_B.Integrator4)) * 0.018404999999999998
    + 0.001 * Model_B.Add) + theta_ddot_tmp * 0.02 * Model_B.Add) *
                        0.011520737327188941 + Model_B.Integrator3 * 0.09) +
                       0.00434 * Model_B.Integrator4) - Model_P.param.R *
                      Model_X.Integrator_CSTATE) - Model_P.param.Ke *
                     Model_X.Integrator1_CSTATE_e) * (1.0 / Model_P.param.L);

  /* Gain: '<S4>/Gain' incorporates:
   *  Integrator: '<S2>/Integrator'
   */
  rtb_Integrator1 = Model_P.param.K * Model_X.Integrator_CSTATE_p;
  if (tmp) {
    /* Math: '<S4>/Square1' incorporates:
     *  Constant: '<S4>/Radius of Propeller'
     */
    Model_B.Square1 = Model_P.param.r * Model_P.param.r;
  }

  /* Gain: '<S5>/Gain' incorporates:
   *  Constant: '<S4>/Air density'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Thrust coefficient'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Integrator: '<S5>/Integrator1'
   *  Math: '<S4>/Square'
   *  Product: '<S4>/Product'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Sum: '<S5>/Add'
   *  Trigonometry: '<S5>/Sin'
   */
  Model_B.Gain = (rtb_Integrator1 * rtb_Integrator1 * Model_P.param.C_t *
                  Model_P.param.P * Model_B.Square1 * Model_P.Constant_Value *
                  Model_P.param.l - (Model_P.param.m_rod * 0.5 +
    Model_P.param.m_motor) * sin(Model_X.Integrator1_CSTATE_d) *
                  (Model_P.param.g * Model_P.param.l)) * (1.0 / Model_P.param.J);

  /* Integrator: '<S5>/Integrator' */
  Model_B.Integrator = Model_X.Integrator_CSTATE_a;
  if (rtmIsMajorTimeStep(Model_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Model_M->rtwLogInfo, (Model_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Model_M)!=-1) &&
          !((rtmGetTFinal(Model_M)-(((Model_M->Timing.clockTick1+
               Model_M->Timing.clockTickH1* 4294967296.0)) * 0.0001)) >
            (((Model_M->Timing.clockTick1+Model_M->Timing.clockTickH1*
               4294967296.0)) * 0.0001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Model_M->Timing.clockTick0)) {
      ++Model_M->Timing.clockTickH0;
    }

    Model_M->Timing.t[0] = rtsiGetSolverStopTime(&Model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Model_M->Timing.clockTick1++;
      if (!Model_M->Timing.clockTick1) {
        Model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Model_derivatives(void)
{
  XDot_Model_T *_rtXdot;
  _rtXdot = ((XDot_Model_T *) Model_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Model_B.Product;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Model_B.Integrator;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Model_B.Gain;

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Model_B.Add;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = Model_B.Product;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = Model_B.Add;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = Model_B.Add;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = Model_B.Integrator;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = Model_B.Gain;
}

/* Model initialize function */
void Model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Model_M, 0,
                sizeof(RT_MODEL_Model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Model_M->solverInfo, &Model_M->Timing.simTimeStep);
    rtsiSetTPtr(&Model_M->solverInfo, &rtmGetTPtr(Model_M));
    rtsiSetStepSizePtr(&Model_M->solverInfo, &Model_M->Timing.stepSize0);
    rtsiSetdXPtr(&Model_M->solverInfo, &Model_M->derivs);
    rtsiSetContStatesPtr(&Model_M->solverInfo, (real_T **) &Model_M->contStates);
    rtsiSetNumContStatesPtr(&Model_M->solverInfo, &Model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Model_M->solverInfo,
      &Model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Model_M->solverInfo,
      &Model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Model_M->solverInfo,
      &Model_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Model_M->solverInfo, (boolean_T**)
      &Model_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Model_M->solverInfo, (&rtmGetErrorStatus(Model_M)));
    rtsiSetRTModelPtr(&Model_M->solverInfo, Model_M);
  }

  rtsiSetSimTimeStep(&Model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Model_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Model_M->solverInfo, false);
  Model_M->intgData.y = Model_M->odeY;
  Model_M->intgData.f[0] = Model_M->odeF[0];
  Model_M->intgData.f[1] = Model_M->odeF[1];
  Model_M->intgData.f[2] = Model_M->odeF[2];
  Model_M->contStates = ((X_Model_T *) &Model_X);
  Model_M->contStateDisabled = ((XDis_Model_T *) &Model_XDis);
  Model_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Model_M->solverInfo, (void *)&Model_M->intgData);
  rtsiSetSolverName(&Model_M->solverInfo,"ode3");
  rtmSetTPtr(Model_M, &Model_M->Timing.tArray[0]);
  rtmSetTFinal(Model_M, 10.0);
  Model_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Model_M->rtwLogInfo, (NULL));
    rtliSetLogT(Model_M->rtwLogInfo, "tout");
    rtliSetLogX(Model_M->rtwLogInfo, "");
    rtliSetLogXFinal(Model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Model_M->rtwLogInfo, 1);
    rtliSetLogY(Model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Model_B), 0,
                sizeof(B_Model_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Model_X, 0,
                  sizeof(X_Model_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&Model_XDis, 0,
                  sizeof(XDis_Model_T));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Model_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Model_M), Model_M->Timing.stepSize0, (&rtmGetErrorStatus(Model_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Model_X.Integrator1_CSTATE = Model_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  Model_X.Integrator2_CSTATE = Model_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  Model_X.Integrator3_CSTATE = Model_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  Model_X.Integrator4_CSTATE = Model_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  Model_X.Integrator_CSTATE = Model_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  Model_X.Integrator1_CSTATE_e = Model_P.Integrator1_IC_j;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Model_X.Integrator_CSTATE_p = Model_P.Integrator_IC_o;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  Model_X.Integrator1_CSTATE_d = Model_P.Integrator1_IC_jz;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  Model_X.Integrator_CSTATE_a = Model_P.Integrator_IC_g;
}

/* Model terminate function */
void Model_terminate(void)
{
  /* (no terminate code required) */
}
