/**
 ******************************************************************************
 * @file           : CORTEXM4_SysTick.c
 * @brief          : Implementation of SysTick Timer functions for Cortex-M4
 *                   microcontrollers.
 * @author         : Romany Sobhy
 ******************************************************************************
 */
#include "CortexM4/CORTEXM4_SysTick.h"



/**
 * @brief Initializes the SysTick timer with the specified number of system ticks.
 *
 * @param SysTicks The number of system ticks to set for the SysTick timer.
 * @return The previous value of the SysTick timer control and status register (SYSTICK->SYST_CSR).
 */
uint8_t SysTick_Init(uint32_t SysTicks){
	uint8_t Retval=0;
	if(SYST_RVR_RELOAD_Msk==SysTicks) {
		Retval=1;
	}
	else{
	/*Disable SysCounter*/
	CLEAR_BIT(SYSTICK->SYST_CSR, SYST_CSR_ENABLE_Pos);

	/*Set reload register to Systick_ticks*/
	SYSTICK->SYST_RVR = SysTicks;

	/*Reset the SysCounter value*/
	SYSTICK->SYST_CVR= 7; /*ANY VALUE WILL RESET*/

    /*Select Processor clock*/
#if(SYSTICK_CLOCK_SOURCE_DIV_1 == SYSTICK_CLOCK_SOURCE)
	/* WITH THIS YOU DIVIDE BY 8*/
	SET_BIT(SYSTICK->SYST_CSR, SYST_CSR_CLKSOURCE_Pos );
#elif (SYSTICK_CLOCK_SOURCE_DIV_8 == SYSTICK_CLOCK_SOURCE)
	/* WITH THIS YOU DIVIDE BY 8*/
	CLEAR_BIT(SYSTICK->SYST_CSR, SYST_CSR_CLKSOURCE_Pos );
#else
#error("Invalid Clock Source")
#endif
	/*Disable IRQ */
	CLEAR_BIT(SYSTICK->SYST_CSR, SYST_CSR_TICKINT_Pos );

	}
return Retval;

}

uint8_t SysTick_DeInit(void){
	/*Disable SysCounter*/
	CLEAR_BIT(SYSTICK->SYST_CSR, SYST_CSR_ENABLE_Pos);
	/*reset*/
	/*Set reload register to Systick_ticks*/
		SYSTICK->SYST_RVR = 0;

	/*Reset the SysCounter value*/
		SYSTICK->SYST_CVR= 7; /*ANY VALUE WILL RESET*/

		/*Disable IRQ */
		CLEAR_BIT(SYSTICK->SYST_CSR, SYST_CSR_TICKINT_Pos );
}
/**
 * @brief Sets the SysTick timer for a single interval and registers a callback function.
 *
 * @param SysTicks The number of system ticks for the interval.
 * @param CallBack Pointer to the callback function to be executed at the end of the interval.
 */
void SysTick_SingleInterval(uint32_t SysTicks, ptrfunction *CallBack){


}

void SysTick_WaitBLocking(uint32_t Systick_Ticks) {


}

/**
 * @brief Sets the SysTick timer for periodic intervals and registers a callback function.
 *
 * @param SysTicks The number of system ticks for each interval.
 * @param CallBack Pointer to the callback function to be executed at the end of each interval.
 */
void SysTick_PeriodicInterval(uint32_t SysTicks, ptrfunction *CallBack){

}

/**
 * @brief Retrieves the remaining number of ticks from the SysTick timer.
 *
 * @return The remaining number of ticks in the SysTick timer.
 */
uint32_t SysTick_GetRemainingTicks(void){

}

