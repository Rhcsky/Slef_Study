/** @file     TASK_ECU_LIGHT.c
  * 
  * @brief    Task TASK_ECU_LIGHT body
  * 
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  * 
  * @note     Generated by ETAS GmbH  RTA-RTE v5.8.4  (R4.0 backend version: v7.8.7 (Build 46772))
  */

#define RTE_CORE

#include "Rte_Const.h"
#if !defined(RTE_VENDOR_MODE)
#pragma message "Compiling an individual task file but RTE_VENDOR_MODE not defined. Compiling a stale file?"
#endif /* !defined(RTE_VENDOR_MODE) */
#if defined(RTE_USE_TASK_HEADER)
#include "TASK_ECU_LIGHT.h"
#else /* defined(RTE_USE_TASK_HEADER) */
#include "Os.h"
#endif /* defined(RTE_USE_TASK_HEADER) */
#if defined(RTE_REQUIRES_IOC)
#include "Ioc.h"
#endif /* defined(RTE_REQUIRES_IOC) */
#include "Rte.h"
#include "Rte_Intl.h"
#include "Rte_Type.h"
#include "Rte_DataHandleType.h"

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /*lint !e537 permit multiple inclusion */
extern CONST(Rte_QTaskType, RTE_DATA) Rte_Queue_CPT_ECU_ABS_AFS_P_LIGHT_TO_SENSOR_LIGHT_OPER_ECU_TO_SENSOR;
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_START_SEC_VAR_8BIT
#include "MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(uint8, RTE_DATA) Rte_Var_CPT_SENSOR_LIGHT_R_LIGHT_FROM_ECU_ABS_AFS_OPER_ECU_TO_SENSOR_outstanding;
#define RTE_STOP_SEC_VAR_8BIT
#include "MemMap.h" /*lint !e537 permit multiple inclusion */

/* Runnable entity prototypes */
#define ECU_ABS_AFS_START_SEC_CODE
#include "ECU_ABS_AFS_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ECU_ABS_AFS_CODE) RE_ECU_LIGHT(CONSTP2VAR(sint32, AUTOMATIC, RTE_APPL_DATA) ADP_ECU_TO_SENSOR);
#define ECU_ABS_AFS_STOP_SEC_CODE
#include "ECU_ABS_AFS_MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_START_SEC_TASKBODY
#include "MemMap.h" /*lint !e537 permit multiple inclusion */
TASK(TASK_ECU_LIGHT)
{
   /* Box: Implicit Buffer Initialization begin */
   /* Box: Implicit Buffer Initialization end */
   /* Box: Implicit Buffer Fill begin */
   /* Box: Implicit Buffer Fill end */
   {
      /* Box: CPT_ECU_ABS_AFS begin */
      /* P_LIGHT_TO_SENSOR_LIGHT */
      {
         Rte_CPT_ECU_ABS_AFS_P_LIGHT_TO_SENSOR_LIGHT_OPER_ECU_TO_SENSOR_RtnQEType cliQEl;
         Std_ReturnType rtn;
         Rte_CPT_ECU_ABS_AFS_P_LIGHT_TO_SENSOR_LIGHT_OPER_ECU_TO_SENSOR_QEType srvQEl;

         for (;;) {
            rtn = Rte_ReadQueue(&Rte_Queue_CPT_ECU_ABS_AFS_P_LIGHT_TO_SENSOR_LIGHT_OPER_ECU_TO_SENSOR.cmn, &srvQEl);
            if ( ( ((VAR(Std_ReturnType, AUTOMATIC))RTE_E_OK) == rtn ) || ( ((VAR(Std_ReturnType, AUTOMATIC))RTE_E_LOST_DATA) == rtn ) )
            {
               cliQEl.ADP_ECU_TO_SENSOR = srvQEl.ADP_ECU_TO_SENSOR;
               /* SpecReq: Measurement point CS begin */
               /* SpecReq: Measurement point CS end */
               RE_ECU_LIGHT(&cliQEl.ADP_ECU_TO_SENSOR);
               /* SpecReq: Measurement point CS begin */
               /* SpecReq: Measurement point CS end */
               Rte_Var_CPT_SENSOR_LIGHT_R_LIGHT_FROM_ECU_ABS_AFS_OPER_ECU_TO_SENSOR_outstanding = FALSE;
               Rte_WriteQueue(srvQEl.clientQueue, &cliQEl);
            }
            else
            {
               break;
            }
         }
      }
      /* Box: CPT_ECU_ABS_AFS end */
   }
   /* Box: Implicit Buffer Flush begin */
   /* Box: Implicit Buffer Flush end */
   TerminateTask();
} /* TASK_ECU_LIGHT */
#define RTE_STOP_SEC_TASKBODY
#include "MemMap.h" /*lint !e537 permit multiple inclusion */

