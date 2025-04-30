/*
 * Model.h
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

#ifndef Model_h_
#define Model_h_
#ifndef Model_COMMON_INCLUDES_
#define Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Model_COMMON_INCLUDES_ */

#include "Model_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T Integrator3;                  /* '<Root>/Integrator3' */
  real_T Integrator4;                  /* '<Root>/Integrator4' */
  real_T Add;                          /* '<S3>/Add' */
  real_T Product;                      /* '<S3>/Product' */
  real_T Square1;                      /* '<S4>/Square1' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T Integrator;                   /* '<S5>/Integrator' */
} B_Model_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_e;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_p;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE_d;         /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S5>/Integrator' */
} X_Model_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_e;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_p;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE_d;         /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S5>/Integrator' */
} XDot_Model_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<Root>/Integrator4' */
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE_e;      /* '<S3>/Integrator1' */
  boolean_T Integrator_CSTATE_p;       /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE_d;      /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE_a;       /* '<S5>/Integrator' */
} XDis_Model_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Model_T_ {
  struct_V1cTy8RJ0ZJH1eQsx0XUCC param; /* Variable: param
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
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Integrator1_IC_j;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.2
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: pi/2
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Integrator1_IC_jz;            /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Model_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Model_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[9];
  real_T odeF[3][9];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Model_T Model_P;

/* Block signals (default storage) */
extern B_Model_T Model_B;

/* Continuous states (default storage) */
extern X_Model_T Model_X;

/* Disabled states (default storage) */
extern XDis_Model_T Model_XDis;

/* Model entry point functions */
extern void Model_initialize(void);
extern void Model_step(void);
extern void Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Model_T *const Model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Model'
 * '<S1>'   : 'Model/MATLAB Function'
 * '<S2>'   : 'Model/Subsystem'
 * '<S3>'   : 'Model/Subsystem/BLDC Motor'
 * '<S4>'   : 'Model/Subsystem/Omega to Thrust Force'
 * '<S5>'   : 'Model/Subsystem/Plant'
 */
#endif                                 /* Model_h_ */
