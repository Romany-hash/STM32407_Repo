
/**
  ******************************************************************************
  * @file    STM32F4xx_Peripheral_Defs.h
  * @author  Romany Sobhy
  * @brief   Contains the decleration of the RCC Module
  *******************************************************************************
  */

#ifndef HAL_DRIVER_RCC_STM32F4XX_HAL_RCC_H_
#define HAL_DRIVER_RCC_STM32F4XX_HAL_RCC_H_

/*------------------ INCLUDES START -------------------------------------*/

#include <HAL_Driver/Common/STM32F4xx_HAL_Def.h>
#include <HAL_Driver/Common/STM32F4xx_HAL_Peripheral_Defs.h>


/*------------------ INCLUDES END --------------------------------------*/


/*------------------ MACRO DECLARATION ----------------------*/





/*------------------ MACRO DECLARATION END -----------------*/


/*------------------ MACRO FUNCTIONS DECLARATION ----------------------*/



/**
  * @defgroup RCC_AHB_Dividers RCC AHB Clock Dividers
  * @{
  */

#define RCC_SYSCLK_AHB_DIV1     RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_AHB_DIV2     RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_AHB_DIV4     RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_AHB_DIV8     RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_AHB_DIV16    RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_AHB_DIV64    RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_AHB_DIV128   RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_AHB_DIV256   RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_AHB_DIV512   RCC_CFGR_HPRE_DIV512


/**
  * @defgroup RCC_APB1_Clock_Dividers RCC APB1 Clock Dividers
  * @{
  */
#define RCC_HCLK_APB1_DIV1     RCC_CFGR_PPRE1_DIV1   /* HCLK not divided */
#define RCC_HCLK_APB1_DIV2     RCC_CFGR_PPRE1_DIV2   /* HCLK divided by 2 */
#define RCC_HCLK_APB1_DIV4     RCC_CFGR_PPRE1_DIV4   /* HCLK divided by 4 */
#define RCC_HCLK_APB1_DIV8     RCC_CFGR_PPRE1_DIV8   /* HCLK divided by 8 */
#define RCC_HCLK_APB1_DIV16    RCC_CFGR_PPRE1_DIV16  /* HCLK divided by 16 */

/**
  * @defgroup RCC_APB2_Clock_Dividers RCC APB2 Clock Dividers
  * @{
  */
#define RCC_HCLK_APB2_DIV1     RCC_CFGR_PPRE2_DIV1   /* HCLK not divided */
#define RCC_HCLK_APB2_DIV2     RCC_CFGR_PPRE2_DIV2   /* HCLK divided by 2 */
#define RCC_HCLK_APB2_DIV4     RCC_CFGR_PPRE2_DIV4   /* HCLK divided by 4 */
#define RCC_HCLK_APB2_DIV8     RCC_CFGR_PPRE2_DIV8   /* HCLK divided by 8 */
#define RCC_HCLK_APB2_DIV16    RCC_CFGR_PPRE2_DIV16  /* HCLK divided by 16 */



/*------------------ MACRO FUNCTIONS DECLARATION END -----------------*/

/**
  ******************************************************************************
  * @defgroup GPIO_Clock_Enable_Disable GPIO Clock Enable/Disable
  * @{
  */
#define HAL_RCC_GPIOA_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOA_Msk))
#define HAL_RCC_GPIOB_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOB_Msk))
#define HAL_RCC_GPIOC_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOC_Msk))
#define HAL_RCC_GPIOD_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOD_Msk))
#define HAL_RCC_GPIOE_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOE_Msk))
#define HAL_RCC_GPIOF_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOF_Msk))
#define HAL_RCC_GPIOG_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOG_Msk))
#define HAL_RCC_GPIOH_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOH_Msk))
#define HAL_RCC_GPIOI_CLK_ENABLE()   (SET_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOI_Msk))

#define HAL_RCC_GPIOA_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOA_Msk))
#define HAL_RCC_GPIOB_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOB_Msk))
#define HAL_RCC_GPIOC_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOC_Msk))
#define HAL_RCC_GPIOD_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOD_Msk))
#define HAL_RCC_GPIOE_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOE_Msk))
#define HAL_RCC_GPIOF_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOF_Msk))
#define HAL_RCC_GPIOG_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOG_Msk))
#define HAL_RCC_GPIOH_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOH_Msk))
#define HAL_RCC_GPIOI_CLK_DISABLE()  (CLEAR_BIT(RCC->RCC_AHB1RSTR, RCC_AHB1RSTR_GPIOI_Msk))


/*------------------ TYPEDEF STRUCTURE DECLARATION ----------------------*/



/**
  * @brief  RCC Oscillator Initialization Structure
  */
typedef struct
{
    uint32_t OscillatorType;  /*!< Specifies the oscillator type */
    uint32_t HSEState;        /*!< Specifies the state of the HSE oscillator */
    uint32_t LSEState;        /*!< Specifies the state of the LSE oscillator */
    uint32_t HSIState;        /*!< Specifies the state of the HSI oscillator */
    uint32_t LSIState;        /*!< Specifies the state of the LSI oscillator */
} RCC_OscInitTypeDef;


typedef struct
{
	uint32_t AHBCLKDivider;
	uint32_t APB1CLKDivider;
	uint32_t APB2CLKDivider;

}RCC_ClkInitTypeDef;


/*------------------ SW INTERFACES DECLARATIONS ---------------------*/

void SystemClock_Config(void);

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscilatorType);

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct);

/*------------------ SW INTERFACES DECLARATIONS END -----------------*/

#endif /* HAL_DRIVER_RCC_STM32F4XX_HAL_RCC_H_ */
