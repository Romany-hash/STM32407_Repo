/**
 ******************************************************************************
 * @file           : CORTEXM4_SCB.c
 *@author         : Romany Sobhy
 * @brief          : Source file for System Control Block (SCB) operations
 *                   on Cortex-M4 core.
 ******************************************************************************
 */

#include "CortexM4\CORTEXM4_SCB.h"



void SCB_SetPriorityGrouping (uint32_t PriorityGroup)
{
	uint32_t Register_value=0;
	uint32_t PriorityGroupTemp=((uint32_t)PriorityGroup|0x07);

	Register_value=SCB->AIRCR;

	Register_value &= ~(SCB_AIRCR_PRIGROUP_Msk | SCB_AIRCR_VECTKEY_Msk);

	Register_value = (Register_value | ((uint32_t)0x5FA << SCB_AIRCR_VECTKEY_Pos)
			       | (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_Pos));


	SCB->AIRCR=Register_value;
};

uint32_t SCB_GetPriorityGrouping (void)
{

	return((SCB->AIRCR)&= ~(0x00000700)>>SCB_AIRCR_PRIGROUP_Pos);
	//return(((SCB->AIRCR)&(uint32_t)SCB_AIRCR_PRIGROUP_Msk)); //tare2t Abd Elghafar
};





