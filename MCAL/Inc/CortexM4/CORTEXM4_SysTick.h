/**
 ******************************************************************************
 * @file           : CORTEXM4_SysTick.h
 *@author         : Romany Sobhy

 ******************************************************************************
 */

#ifndef CORTEXM4_CORTEXM4_SYSTICK_H_
#define CORTEXM4_CORTEXM4_SYSTICK_H_

/*------------------ INCLUDES START -------------------------------------*/
#include "Common\Std_Types.h"
#include "CortexM4/CORTEXM4_SysTick_cfg.h"


/*------------------ INCLUDES END --------------------------------------*/


/*------------------ MACRO DECLARATION ----------------------------------*/
#define SYSTICK_BASE_ADDR (0xE000E010UL)
#define SYSTICK ((SYSTICKREG *)SYSTICK_BASE_ADDR) /*!< Pointer to SYSTICKREG structure at base address 0xE000E010 */


#define SYST_CSR_COUNTFLAG_Pos    16U
#define SYST_CSR_COUNTFLAG_Msk    (1UL << SYST_CSR_COUNTFLAG_Pos)  /*!< Bit mask for COUNTFLAG */
/* COUNTFLAG: Returns 1 if timer counted to 0 since last time this was read. */


#define SYST_CSR_CLKSOURCE_Pos    2U
#define SYST_CSR_CLKSOURCE_Msk    (1UL << SYST_CSR_CLKSOURCE_Pos)  /*!< Bit mask for CLKSOURCE */
/* CLKSOURCE: Indicates the clock source:
   0 = external clock
   1 = processor clock. */

#define SYST_CSR_TICKINT_Pos      1U
#define SYST_CSR_TICKINT_Msk      (1UL << SYST_CSR_TICKINT_Pos)    /*!< Bit mask for TICKINT */
/* TICKINT: Enables SysTick exception request:
   0 = counting down to zero does not assert the SysTick exception request
   1 = counting down to zero asserts the SysTick exception request.
   Software can use COUNTFLAG to determine if SysTick has ever counted to zero. */

#define SYST_CSR_ENABLE_Pos       0U
#define SYST_CSR_ENABLE_Msk       (1UL << SYST_CSR_ENABLE_Pos)     /*!< Bit mask for ENABLE */
/* ENABLE: Enables the counter:
   0 = counter disabled
   1 = counter enabled */

#define SYST_RVR_RELOAD_Pos       0U
#define SYST_RVR_RELOAD_Msk       (0xFFFFFFUL << SYST_RVR_RELOAD_Pos)    /*!< Bit mask for RELOAD value in SYST_RVR register */



/*------------------ MACRO DECLARATION END ------------------------------*/


/*------------------ MACRO FUNCTIONS DECLARATION ------------------------*/



/*------------------ MACRO FUNCTIONS DECLARATION END --------------------*/


/*------------------ TYPEDEF STRUCTURE DECLARATION ----------------------*/
typedef struct {
    uint32_t SYST_CSR;    /*> Member representing the System Timer Control and Status Register (SYST_CSR)
                             Offset: 0x010, Privileged: R/W */
    uint32_t SYST_RVR;    /*> Member representing the System Timer Reload Value Register (SYST_RVR)
                             Offset: 0x014, Privileged: R/W */
    uint32_t SYST_CVR;    /*> Member representing the System Timer Current Value Register (SYST_CVR)
                             Offset: 0x018, Privileged: R/W */
    uint32_t SYST_CALIB;  /*> Member representing the System Timer Calibration Value Register (SYST_CALIB)
                             Offset: 0x01C, Privileged: RO */
} SYSTICKREG;

typedef void (*ptrfunction)(void);

/*------------------ SW INTERFACES DECLARATIONS -------------------------*/
/**
 * @brief Initializes the SysTick timer with the specified number of system ticks.
 *
 * @param SysTicks The number of system ticks to set for the SysTick timer.
 * @return The previous value of the SysTick timer control and status register (SYSTICK->SYST_CSR).
 */
uint8_t SysTick_Init(uint32_t SysTicks);

/**
 * @brief Sets the SysTick timer for a single interval and registers a callback function.
 *
 * @param SysTicks The number of system ticks for the interval.
 * @param CallBack Pointer to the callback function to be executed at the end of the interval.
 */
void SysTick_SingleInterval(uint32_t SysTicks, ptrfunction *CallBack);

/**
 * @brief Sets the SysTick timer for periodic intervals and registers a callback function.
 *
 * @param SysTicks The number of system ticks for each interval.
 * @param CallBack Pointer to the callback function to be executed at the end of each interval.
 */
void SysTick_PeriodicInterval(uint32_t SysTicks, ptrfunction *CallBack);

/**
 * @brief Retrieves the remaining number of ticks from the SysTick timer.
 *
 * @return The remaining number of ticks in the SysTick timer.
 */
uint32_t SysTick_GetRemainingTicks(void);

uint8_t SysTick_DeInit(void);
void SysTick_WaitBLocking(uint32_t Systick_Ticks);


/*------------------ SW INTERFACES DECLARATIONS END ---------------------*/


#endif /* CORTEXM4_CORTEXM4_SYSTICK_H_ */
