
/**
  ******************************************************************************
  * @file    STM32F4xx_HAL_Peripheral_Defs.h
  * @author  Romany Sobhy
  * @brief   Contains data structures and address mapping for all peripherals of STM32F4xx.
  *******************************************************************************
  */

#ifndef HAL_DRIVER_COMMON_STM32F4XX_HAL_Peripheral_DEFS_H
#define HAL_DRIVER_COMMON_STM32F4XX_HAL_Peripheral_DEFS_H


/*------------------ INCLUDES START -------------------------------------*/
#include "Common/Std_Types.h"
#include "Common/Common_macros.h"


/*------------------ INCLUDES END --------------------------------------*/


/*------------------ MACRO DECLARATION START----------------------*/
#define Preph_Base (0x40000000UL)
#define AHB1_Base (Preph_Base+0x00020000UL)
#define RCC_Base (AHB1_Base+0x00003800UL)
#define RCC   ((RCC_Registers*)RCC_Base)

/******************* Bit defination for RCC_AHB1RSTR register************/

#define RCC_AHB1RSTR_GPIOA_Pos    0
#define RCC_AHB1RSTR_GPIOB_Pos    1
#define RCC_AHB1RSTR_GPIOC_Pos    2
#define RCC_AHB1RSTR_GPIOD_Pos    3
#define RCC_AHB1RSTR_GPIOE_Pos    4
#define RCC_AHB1RSTR_GPIOF_Pos    5
#define RCC_AHB1RSTR_GPIOG_Pos    6
#define RCC_AHB1RSTR_GPIOH_Pos    7
#define RCC_AHB1RSTR_GPIOI_Pos    8

#define RCC_AHB1RSTR_GPIOA_Msk    (1U << RCC_AHB1RSTR_GPIOA_Pos)
#define RCC_AHB1RSTR_GPIOB_Msk    (1U << RCC_AHB1RSTR_GPIOB_Pos)
#define RCC_AHB1RSTR_GPIOC_Msk    (1U << RCC_AHB1RSTR_GPIOC_Pos)
#define RCC_AHB1RSTR_GPIOD_Msk    (1U << RCC_AHB1RSTR_GPIOD_Pos)
#define RCC_AHB1RSTR_GPIOE_Msk    (1U << RCC_AHB1RSTR_GPIOE_Pos)
#define RCC_AHB1RSTR_GPIOF_Msk    (1U << RCC_AHB1RSTR_GPIOF_Pos)
#define RCC_AHB1RSTR_GPIOG_Msk    (1U << RCC_AHB1RSTR_GPIOG_Pos)
#define RCC_AHB1RSTR_GPIOH_Msk    (1U << RCC_AHB1RSTR_GPIOH_Pos)
#define RCC_AHB1RSTR_GPIOI_Msk    (1U << RCC_AHB1RSTR_GPIOI_Pos)

/** Description: Definitions for clock bit position*/
#define HSEON_POSITION 16
#define LSEON_POSITION 0
#define HSION_POSITION 0
#define LSION_POSITION 0



/*@defgroup of RCC oscillator types used by the RCC (Reset and Clock Control) peripheral in microcontrollers.
  * The oscillator types define different clock sources for the system.*/

#define RCC_OSCILLATORTYPE_NONE  0x00U
#define RCC_OSCILLATORTYPE_HSE   0x01U
#define RCC_OSCILLATORTYPE_HSI   0x02U
#define RCC_OSCILLATORTYPE_LSE   0x04U
#define RCC_OSCILLATORTYPE_LSI   0x08U

/**
  * @defgroup RCC_Oscillator_Types RCC Oscillator Types
  * @{
  */

/*@ HSE oscillator */
#define RCC_HSE_ON             ((uint8_t)0x01U)  /*!< HSE oscillator ON */
#define RCC_HSE_OFF            ((uint8_t)0x00U)  /*!< HSE oscillator OFF */

/*@ HSI oscillator */
#define RCC_HSI_ON             ((uint8_t)0x01U)  /*!< HSI oscillator ON */
#define RCC_HSI_OFF            ((uint8_t)0x00U)  /*!< HSI oscillator OFF */

/*@ LSE oscillator */
#define RCC_LSE_ON             ((uint8_t)0x01U)  /*!< LSE oscillator ON */
#define RCC_LSE_OFF            ((uint8_t)0x00U)  /*!< LSE oscillator OFF */

/*@ LSI oscillator */
#define RCC_LSI_ON             ((uint8_t)0x01U)  /*!< LSI oscillator ON */
#define RCC_LSI_OFF            ((uint8_t)0x00U)  /*!< LSI oscillator OFF */


#define RCC_CFGR_PPRE2_Pos    13  /* Position of PPRE2 bits */
#define RCC_CFGR_PPRE1_Pos    10  /* Position of PPRE1 bits */
#define RCC_CFGR_HPRE_Pos     4   /* Position of HPRE bits */

#define RCC_CFGR_PPRE2_Msk    (0x7UL << RCC_CFGR_PPRE2_Pos)  /* Mask for PPRE2 bits */
#define RCC_CFGR_PPRE1_Msk    (0x7UL << RCC_CFGR_PPRE1_Pos)  /* Mask for PPRE1 bits */
#define RCC_CFGR_HPRE_Msk     (0xFUL << RCC_CFGR_HPRE_Pos)   /* Mask for HPRE bits */

#define RCC_CFGR_PPRE2_DIV1    (0x0U << RCC_CFGR_PPRE2_Pos)  /* AHB clock not divided */
#define RCC_CFGR_PPRE2_DIV2    (0x4U << RCC_CFGR_PPRE2_Pos)  /* AHB clock divided by 2 */
#define RCC_CFGR_PPRE2_DIV4    (0x5U << RCC_CFGR_PPRE2_Pos)  /* AHB clock divided by 4 */
#define RCC_CFGR_PPRE2_DIV8    (0x6U << RCC_CFGR_PPRE2_Pos)  /* AHB clock divided by 8 */
#define RCC_CFGR_PPRE2_DIV16   (0x7U << RCC_CFGR_PPRE2_Pos)  /* AHB clock divided by 16 */

#define RCC_CFGR_PPRE1_DIV1    (0x0U << RCC_CFGR_PPRE1_Pos)  /* AHB clock not divided */
#define RCC_CFGR_PPRE1_DIV2    (0x4U << RCC_CFGR_PPRE1_Pos)  /* AHB clock divided by 2 */
#define RCC_CFGR_PPRE1_DIV4    (0x5U << RCC_CFGR_PPRE1_Pos)  /* AHB clock divided by 4 */
#define RCC_CFGR_PPRE1_DIV8    (0x6U << RCC_CFGR_PPRE1_Pos)  /* AHB clock divided by 8 */
#define RCC_CFGR_PPRE1_DIV16   (0x7U << RCC_CFGR_PPRE1_Pos)  /* AHB clock divided by 16 */

#define RCC_CFGR_HPRE_DIV1     (0x0U << RCC_CFGR_HPRE_Pos)   /* System clock not divided */
#define RCC_CFGR_HPRE_DIV2     (0x8U << RCC_CFGR_HPRE_Pos)   /* System clock divided by 2 */
#define RCC_CFGR_HPRE_DIV4     (0x9U << RCC_CFGR_HPRE_Pos)   /* System clock divided by 4 */
#define RCC_CFGR_HPRE_DIV8     (0xAU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 8 */
#define RCC_CFGR_HPRE_DIV16    (0xBU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 16 */
#define RCC_CFGR_HPRE_DIV64    (0xCU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 64 */
#define RCC_CFGR_HPRE_DIV128   (0xDU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 128 */
#define RCC_CFGR_HPRE_DIV256   (0xEU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 256 */
#define RCC_CFGR_HPRE_DIV512   (0xFU << RCC_CFGR_HPRE_Pos)   /* System clock divided by 512 */

/*@SysClk Switch*/
#define RCC_CFGR_SW0_POS       (0U)
#define RCC_CFGR_SW1_POS       (1U)

/*------------------ MACRO FUNCTIONS DECLARATION END -----------------*/


/*------------------ TYPEDEF STRUCTURE DECLARATION ----------------------*/

/**
 * @brief  RCC Registers structure
 */
typedef struct {
    volatile uint32_t RCC_CR;            // RCC Clock Control Register
    volatile uint32_t RCC_PLLCFGR;       // RCC PLL Configuration Register
    volatile uint32_t RCC_CFGR;          // RCC Clock Configuration Register
    volatile uint32_t RCC_CIR;           // RCC Clock Interrupt Register
    volatile uint32_t RCC_AHB1RSTR;      // RCC AHB1 Peripheral Reset Register
    volatile uint32_t RCC_AHB2RSTR;      // RCC AHB2 Peripheral Reset Register
    volatile uint32_t RCC_AHB3RSTR;      // RCC AHB3 Peripheral Reset Register
    uint32_t Reserved1[2];               // Reserved
    volatile uint32_t RCC_APB1RSTR;      // RCC APB1 Peripheral Reset Register
    volatile uint32_t RCC_APB2RSTR;      // RCC APB2 Peripheral Reset Register
    uint32_t Reserved2;                  // Reserved
    volatile uint32_t RCC_AHB1ENR;       // RCC AHB1 Peripheral Clock Enable Register
    volatile uint32_t RCC_AHB2ENR;       // RCC AHB2 Peripheral Clock Enable Register
    volatile uint32_t RCC_AHB3ENR;       // RCC AHB3 Peripheral Clock Enable Register
    volatile uint32_t RCC_APB1ENR;       // RCC APB1 Peripheral Clock Enable Register
    volatile uint32_t RCC_APB2ENR;       // RCC APB2 Peripheral Clock Enable Register
    uint32_t Reserved3[2];               // Reserved
    volatile uint32_t RCC_AHB1LPENR;     // RCC AHB1 Peripheral Clock Enable in Low Power Mode Register
    volatile uint32_t RCC_AHB2LPENR;     // RCC AHB2 Peripheral Clock Enable in Low Power Mode Register
    volatile uint32_t RCC_AHB3LPENR;     // RCC AHB3 Peripheral Clock Enable in Low Power Mode Register
    uint32_t Reserved4;                  // Reserved
    volatile uint32_t RCC_APB1LPENR;     // RCC APB1 Peripheral Clock Enable in Low Power Mode Register
    volatile uint32_t RCC_APB2LPENR;     // RCC APB2 Peripheral Clock Enable in Low Power Mode Register
    uint32_t Reserved5[2];               // Reserved
    volatile uint32_t RCC_BDCR;          // RCC Backup Domain Control Register
    volatile uint32_t RCC_CSR;           // RCC Control/Status Register
    uint32_t Reserved6[2];               // Reserved
    volatile uint32_t RCC_SSCGR;         // RCC Spread Spectrum Clock Generation Register
    volatile uint32_t RCC_PLLI2SCFGR;    // RCC PLLI2S Configuration Register
} RCC_Registers;


/*------------------ SW INTERFACES DECLARATIONS ---------------------*/



/*------------------ SW INTERFACES DECLARATIONS END -----------------*/






#endif /*HAL_DRIVER_COMMON_STM32F4XX_HAL_Peripheral_H*/
