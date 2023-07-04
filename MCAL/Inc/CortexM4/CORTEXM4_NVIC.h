/**
 ******************************************************************************
 * @file           : CORTEXM4_CORE_NVIC.h
 * @brief          : Header file for NVIC (Nested Vectored Interrupt Controller) operations
 *                   on Cortex-M3 core.
 * @author         : Romany Sobhy
 ******************************************************************************
 */


/*------------------ INCLUDES START -------------------------------------*/
#include "Common\Std_Types.h"

/*------------------ INCLUDES END --------------------------------------*/

/*------------------ MACRO DECLARATION ---------------------------------*/

#define NVIC_BASE_ADDR (0xE000E100UL)
#define NVIC ((NVIC_TypeDef *)NVIC_BASE_ADDR)

/*------------------ MACRO DECLARATION END -----------------------------*/



/*------------------ MACRO FUNCTIONS DECLARATION ----------------------*/


/*------------------ MACRO FUNCTIONS DECLARATION END -----------------*/


/*------------------ DATA TYPE DECLARATIONS --------------------------*/

/** NVIC Registers **/
typedef struct
{
    volatile uint32_t ISER[8U];     /* Interrupt Set-enable Registers */
    uint32_t RESERVED1[24U];
    volatile uint32_t ICER[8U];     /* Interrupt Clear-enable Registers */
    uint32_t RESERVED2[24U];
    volatile uint32_t ISPR[8U];     /* Interrupt Set-pending Registers */
    uint32_t RESERVED3[24U];
    volatile uint32_t ICPR[8U];     /* Interrupt Clear-pending Registers */
    uint32_t RESERVED4[24U];
    volatile uint32_t IABR[8U];     /* Interrupt Active Bit Registers */
    uint32_t RESERVED5[56U];
    volatile uint8_t IPR[240U];     /* Interrupt Priority Registers */
    uint32_t RESERVED6[643U];
    volatile uint32_t STIR;
} NVIC_TypeDef;


typedef enum
{
	NMI=-14,
	MemManage=-12,
	BusFault =-11,
	UsageFault =-10,
	SVCall =-5,
	Debug_Monitor=-4,
	PendSV =-2,
	SysTick =-1,
	WWDG = 0,
	PVD = 1,
	TAMP_STAMP = 2,
	RTC_WKUP = 3,
	FLASH = 4,
	RCC = 5,
	EXTI0 = 6,
	EXTI1 = 7,
	EXTI2 = 8,
	EXTI3 = 9,
	EXTI4 = 10,
	DMA1_Stream0 = 11,
	DMA1_Stream1 = 12,
	DMA1_Stream2 = 13,
	DMA1_Stream3 = 14,
	DMA1_Stream4 = 15,
	DMA1_Stream5 = 16,
	DMA1_Stream6 = 17,
	ADC = 18,
	CAN1_TX = 19,
	CAN1_RX0 = 20,
	CAN1_RX1 = 21,
	CAN1_SCE = 22,
	EXTI9_5 = 23,
	TIM1_BRK_TIM9 = 24,
	TIM1_UP_TIM10 = 25,
	TIM1_TRG_COM_TIM11 = 26,
	TIM1_CC = 27,
	TIM2 = 28,
	TIM3 = 29,
	TIM4 = 30,
	I2C1_EV = 31,
	I2C1_ER = 32,
	I2C2_EV = 33,
	I2C2_ER = 34,
	SPI1 = 35,
	SPI2 = 36,
	USART1 = 37,
	USART2 = 38,
	USART3 = 39,
	EXTI15_10 = 40,
	RTC_Alarm = 41,
	OTG_FS_WKUP = 42,
	TIM8_BRK_TIM12 = 43,
	TIM8_UP_TIM13 = 44,
	TIM8_TRG_COM_TIM14 = 45,
	TIM8_CC = 46,
	DMA1_Stream7 = 47,
	FSMC = 48,
	SDIO = 49,
	TIM5 = 50,
	SPI3 = 51,
	UART4 = 52,
	UART5 = 53,
	TIM6_DAC = 54,
	TIM7 = 55,
	DMA2_Stream0 = 56,
	DMA2_Stream1 = 57,
	DMA2_Stream2 = 58,
	DMA2_Stream3 = 59,
	DMA2_Stream4 = 60,
	ETH = 61,
	ETH_WKUP = 62,
	CAN2_TX = 63,
	CAN2_RX0 = 64,
	CAN2_RX1 = 65,
	CAN2_SCE = 66,
	OTG_FS = 67,
	DMA2_Stream5 = 68,
	DMA2_Stream6 = 69,
	DMA2_Stream7 = 70,
	USART6 = 71,
	I2C3_EV = 72,
	I2C3_ER = 73,
	OTG_HS_EP1_OUT = 74,
	OTG_HS_EP1_IN = 75,
	OTG_HS_WKUP = 76,
	OTG_HS = 77,
	DCMI = 78,
	CRYP = 79,
	HASH_RNG = 80,
	FPU = 81
} IRQN_TYPE;


/*------------------ DATA TYPE DECLARATIONS END ---------------------*/


/*------------------ SW INTERFACES DECLARATIONS ---------------------*/

/**
 * @brief Enable the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to enable.
 * @note The input value of IRQN must not be negative.
 */
void NVIC_ENABLEIRQ(IRQN_TYPE IRQN);


/**
 * @brief Disable the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to disable.
 * @note The input value of IRQN must not be negative.
 */
void NVIC_DISABLEIRQ(IRQN_TYPE IRQN);

/**
 * @brief Set the pending status of the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to set pending.
 * @note The input value of IRQN must not be negative.
 */
void NVIC_SETPENDINGIRQ(IRQN_TYPE IRQN);


/**
 * @brief Clear the pending status of the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to clear pending.
 * @note The input value of IRQN must not be negative.
 */
void NVIC_CLEARPENDINGIRQ(IRQN_TYPE IRQN);




/**
 * @brief Get the active status of the NVIC interrupt for the specified IRQ.
 *
 * @param IRQN The IRQ number to check active.
 * @note The input value of IRQN must not be negative.
 */
uint32_t NVIC_GetActive(IRQN_TYPE IRQN);


/**
 * @brief Sets the priority level for a specific interrupt request.
 *
 * @param IRQN     Enumeration value representing the interrupt request number.
 * @param priority Priority level to be set for the specified interrupt request.
 *
 * This function sets the priority level for a specific interrupt request identified by IRQN.
 * Higher numeric values indicate higher priority.
 */
void NVIC_SetPriority(IRQN_TYPE IRQN, uint32_t priority);



/**
 * @brief Retrieves the priority level of a specific interrupt request.
 *
 * @param IRQN Enumeration value representing the interrupt request number.
 *
 * @return The priority level of the specified interrupt request.
 *
 * This function retrieves the priority level of a specific interrupt request identified by IRQN.
 */
 uint32_t NVIC_GetPriority(IRQN_TYPE IRQN);



/*------------------ SW INTERFACES DECLARATIONS END -----------------*/


#ifndef CORTEXM3_CORE_NVIC_H_
#define CORTEXM3_CORE_NVIC_H_

#endif /* CORTEXM3_CORE_NVIC_H_ */
