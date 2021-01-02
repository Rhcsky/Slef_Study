/** @file     Rte_ACT_UPDOWN_MOTOR.c
  * 
  * @brief    RTE Sample SWC implementation skeleton file
  * 
  * @note     Generated by ETAS GmbH  RTA-RTE v5.8.4  (R4.0 backend version: v7.8.7 (Build 46772))
  */

#include "Rte_ACT_UPDOWN_MOTOR.h"

/* --------------------------------------------------------------------------- */
/* RTE Event: /Components/ACT_UPDOWN_MOTOR/IB_ACT_UPDOWN_MOTOR/DRE_UPDOWNANGLE_RECEIVE */

FUNC(void, ACT_UPDOWN_MOTOR_CODE) RE_UPDOWNANGLE_RECEIVE(void)
{
	int degree = Rte_DRead_R_UPDOWNANGLE_FROM_APP_MOTOR_VDP_APP_TO_ACT();
	Rte_IrvWrite_RE_UPDOWNANGLE_RECEIVE_Explicit_VariableDataPrototype_0(degree);
}

/* --------------------------------------------------------------------------- */
/* RTE Event: /Components/ACT_UPDOWN_MOTOR/IB_ACT_UPDOWN_MOTOR/OIE_UPDOWNANGLE_SEND */

FUNC(void, ACT_UPDOWN_MOTOR_CODE) RE_UPDOWNANGLE_SEND(CONSTP2VAR(sint32, AUTOMATIC, RTE_APPL_DATA) ADP_ACT_TO_ECU)
{
	int degree = Rte_IrvRead_RE_UPDOWNANGLE_SEND_Explicit_VariableDataPrototype_0();
	*ADP_ACT_TO_ECU = degree;
}

