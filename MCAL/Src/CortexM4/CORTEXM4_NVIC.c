/**
 ******************************************************************************
 * @file           : CORTEXM4_NVIC.c
 * @author         : Romany Sobhy
 * @brief          : CORTEXM4_NVIC.c
 ***************************************************************************/

#include "CortexM4\CORTEXM4_NVIC.h"


/**
 * @brief Enables the specified interrupt in the NVIC.
 *
 * @param IRQN The IRQ number of the interrupt to be enabled. (Must not be negative)
 */
void NVIC_ENABLEIRQ(IRQN_TYPE IRQN)
{ /*3mlt explit casting 3chan deh compiler depedenant*/
    if((uint32_t)IRQN>=0) {
    	NVIC ->ISER[(uint32_t)IRQN << 5] = (1UL <<(((uint32_t)IRQN)& 0X1F));
    }
};

/**
 * @brief Disables the specified interrupt in the NVIC.
 *
 * @param IRQN The IRQ number of the interrupt to be disabled. (Must not be negative)
 */
void NVIC_DISABLEIRQ(IRQN_TYPE IRQN)
{
    if((uint32_t)IRQN>=0) {
    	NVIC ->ICER[(uint32_t)IRQN << 5] = (1UL <<(((uint32_t)IRQN)& 0X1F));
    }
};

/**
 * @brief Sets the pending status of the specified interrupt in the NVIC.
 *
 * @param IRQN The IRQ number of the interrupt to set as pending. (Must not be negative)
 */
void NVIC_SETPENDINGIRQ(IRQN_TYPE IRQN)
{
    if((uint32_t)IRQN>=0) {
    	NVIC ->ISPR[(uint32_t)IRQN << 5] = (1UL <<(((uint32_t)IRQN)& 0X1F));
    }
};

/**
 * @brief Clear the pending status of the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to clear pending.
 * @note The input value of IRQN must not be negative.
 */
void NVIC_CLEARPENDINGIRQ(IRQN_TYPE IRQN)
{

	 if((uint32_t)IRQN>=0) {
	    	NVIC ->ICPR[(uint32_t)IRQN << 5] = (1UL <<(((uint32_t)IRQN)& 0X1F));
	    }
	};


/**
 * @brief Gets the active status of the specified interrupt in the NVIC.
 *
 * @param IRQN The IRQ number of the interrupt to check for activity. (Must not be negative)
 */
uint32_t NVIC_GetActive(IRQN_TYPE IRQN)
{
	 if((uint32_t)IRQN>=0) {
		 return ((NVIC->ICPR[(uint32_t)IRQN << 5] & (1UL << (((uint32_t)IRQN) & 0x1F))) != (uint32_t)0) ? 1UL : 0UL;

		    }
	 else {
		 return 0UL;
		}
};



/**
 * @brief Sets the priority level for a specific interrupt request.
 *
 * @param IRQN     Enumeration value representing the interrupt request number.
 * @param priority Priority level to be set for the specified interrupt request.
 *
 * This function sets the priority level for a specific interrupt request identified by IRQN.
 * Higher numeric values indicate higher priority.
 */
void NVIC_SetPriority(IRQN_TYPE IRQN, uint32_t priority) {
	if((uint32_t)IRQN>=0) {
		NVIC->IPR[(uint32_t)IRQN]=(uint8_t)((priority <<4) & (uint32_t)0xFF);
			    }
		 else {

			}
};


/**
 * @brief Retrieves the priority level of a specific interrupt request.
 *
 * @param IRQN Enumeration value representing the interrupt request number.
 *
 * @return The priority level of the specified interrupt request.
 *
 * This function retrieves the priority level of a specific interrupt request identified by IRQN.
 */
uint32_t NVIC_GetPriority(IRQN_TYPE IRQN){
	if((uint32_t)IRQN>=0) {
		return(NVIC ->IPR[(uint32_t)IRQN]) >> 4;
			    }
		 else {

			}
};




