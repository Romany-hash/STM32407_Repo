/**
 ******************************************************************************
 * @file           : CORTEXM4_SCB.h
 *@author         : Romany Sobhy
 * @brief          : Header file for System Control Block (SCB) operations
 *                   on Cortex-M4 core.
 ******************************************************************************
 */

#ifndef CORTEXM4_SCB_H_
#define CORTEXM4_SCB_H_

 /*******************************************************************************/

/*------------------ INCLUDES START -------------------------------------*/
#include "Common/Std_Types.h"

/*------------------ INCLUDES END --------------------------------------*/




/*------------------ MACRO DECLARATION ----------------------*/

 /*Memory MApping of core HW*/

#define SCB_BASE (0xE000ED00UL)
#define SCB ((SCB_TYPE*)SCB_BASE)

#define SCB_PRIORITY_GROUP_0  0x00000007U

#define SCB_PRIORITY_GROUP_1  0x00000006U

#define SCB_PRIORITY_GROUP_2  0x00000005U

#define SCB_PRIORITY_GROUP_3  0x00000004U

#define SCB_PRIORITY_GROUP_4  0x00000003U


/*SCB AIRCR DEFENATIONS */
#define SCB_AIRCR_PRIGROUP_Pos 8U
#define SCB_AIRCR_PRIGROUP_Msk (7UL << SCB_AIRCR_PRIGROUP_Pos)


#define SCB_AIRCR_VECTKEY_Pos 16U
#define SCB_AIRCR_VECTKEY_Msk (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)


/*------------------ MACRO DECLARATION END -----------------*/

/*------------------ MACRO FUNCTIONS DECLARATION ----------------------*/




/*------------------ MACRO FUNCTIONS DECLARATION END -----------------*/


/*------------------ DATA TYPE DECLARATIONS --------------------------*/

 typedef struct {
     volatile uint32_t ACTLR;    // Address: 0xE000E008, Name: ACTLR, Type: RW, Required privilege: Privileged
     volatile uint32_t CPUID;    // Address: 0xE000ED00, Name: CPUID, Type: RO, Required privilege: Privileged
     volatile uint32_t ICSR;     // Address: 0xE000ED04, Name: ICSR, Type: RW(1), Required privilege: Privileged
     volatile uint32_t VTOR;     // Address: 0xE000ED08, Name: VTOR, Type: RW, Required privilege: Privileged
     volatile uint32_t AIRCR;    // Address: 0xE000ED0C, Name: AIRCR, Type: RW(1), Required privilege: Privileged
     volatile uint32_t SCR;      // Address: 0xE000ED10, Name: SCR, Type: RW, Required privilege: Privileged
     volatile uint32_t CCR;      // Address: 0xE000ED14, Name: CCR, Type: RW, Required privilege: Privileged
     volatile uint32_t SHPR1;    // Address: 0xE000ED18, Name: SHPR1, Type: RW, Required privilege: Privileged
     volatile uint32_t SHPR2;    // Address: 0xE000ED1C, Name: SHPR2, Type: RW, Required privilege: Privileged
     volatile uint32_t SHPR3;    // Address: 0xE000ED20, Name: SHPR3, Type: RW, Required privilege: Privileged
     volatile uint32_t SHCSR;    // Address: 0xE000ED24, Name: SHCSR, Type: RW, Required privilege: Privileged
     volatile uint32_t CFSR;     // Address: 0xE000ED28, Name: CFSR, Type: RW, Required privilege: Privileged
     volatile uint32_t MMSR;     // Address: 0xE000ED28, Name: MMSR (2), Type: RW, Required privilege: Privileged
     volatile uint32_t BFSR;  // Address: 0xE000ED29, Name: BFSR(2), Type: RW, Required privilege: Privileged
     volatile uint32_t UFSR;  // Address: 0xE000ED2A, Name: UFSR(2), Type: RW, Required privilege: Privileged
     volatile uint32_t HFSR;     // Address: 0xE000ED2C, Name: HFSR, Type: RW, Required privilege: Privileged
     volatile uint32_t MMAR;     // Address: 0xE000ED34, Name: MMAR, Type: RW, Required privilege: Privileged
     volatile uint32_t BFAR;     // Address: 0xE000ED38, Name: BFAR, Type: RW, Required privilege: Privileged
     volatile uint32_t AFSR;     // Address: 0xE000ED3C, Name: AFSR, Type: RW, Required privilege: Privileged
 } SCB_TYPE;



/*------------------ DATA TYPE DECLARATIONS END ---------------------*/


/*------------------ SW INTERFACES DECLARATIONS ---------------------*/
 void SCB_SetPriorityGrouping (uint32_t PriorityGroup);
 uint32_t SCB_GetPriorityGrouping (void);




/*------------------ SW INTERFACES DECLARATIONS END -----------------*/









#endif /* CORTEXM4_SCB_H_ */










