/*
 * STM32F4xx_HAL_RCC.c
 *
 *  Created on: 24 Jun 2023
 *      Author: Romany Sobhy
 */

#include "HAL_Driver/RCC/STM32F4xx_HAL_RCC.h"

/**
  ******************************************************************************
  * @file    STM32F4xx_HAL_RCC.c
  * @brief   Source file for RCC module of STM32F4 HAL.
  *          This file provides functions to manage the RCC (Reset and Clock Control)
  *          peripheral.
*/

/**
  * @brief  Configures the RCC oscillators based on the specified parameters in the RCC_OscInitTypeDef structure.
  * @param  RCC_OscInitStruct: pointer to an RCC_OscInitTypeDef structure that contains the configuration information for the RCC oscillators.
  * @retval HAL_StatusTypeDef: HAL status enumeration value.
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct)
{
  HAL_StatusTypeDef RetStatus = HAL_OK;

  /* Check if RCC_OscInitStruct is NULL */
  if (NULL == RCC_OscInitStruct)
  {
    RetStatus = HAL_ERROR;
  }
  else
  {
    /* Configure HSE oscillator */
    if (RCC_OSCILLATORTYPE_HSE == RCC_OscInitStruct->OscillatorType)
    {
        if (RCC_HSE_ON == RCC_OscInitStruct->HSEState) {
            SET_BIT(RCC->RCC_CR, HSEON_POSITION);

        /*HSE OSCILATOR SELECTED AS SYS CLOCK*/
            SET_BIT(RCC->RCC_CFGR, RCC_CFGR_SW0_POS);
            CLEAR_BIT(RCC->RCC_CFGR, RCC_CFGR_SW1_POS);
        }
        else {
            CLEAR_BIT(RCC->RCC_CR, HSEON_POSITION);
        }
    }
    /* Configure LSE oscillator */
    else if (RCC_OSCILLATORTYPE_LSE == RCC_OscInitStruct->OscillatorType)
    {
        if (RCC_LSE_ON == RCC_OscInitStruct->LSEState) {
            SET_BIT(RCC->RCC_BDCR, LSEON_POSITION);
        }
        else {
            CLEAR_BIT(RCC->RCC_BDCR, LSEON_POSITION);
        }
    }
    /* Configure HSI oscillator */
    else if (RCC_OSCILLATORTYPE_HSI == RCC_OscInitStruct->OscillatorType)
    {
        if (RCC_HSI_ON == RCC_OscInitStruct->HSIState) {
            SET_BIT(RCC->RCC_CR, HSION_POSITION);
        }
        else {
            CLEAR_BIT(RCC->RCC_CR, HSION_POSITION);
        }
    }
    /* Configure LSI oscillator */
    else
    {
        if (RCC_LSI_ON == RCC_OscInitStruct->LSIState) {
            SET_BIT(RCC->RCC_CSR, LSION_POSITION);
        }
        else {
            CLEAR_BIT(RCC->RCC_CSR, LSION_POSITION);
        }
    }
  }

  return RetStatus;
}



HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct){

	HAL_StatusTypeDef RetStatus = HAL_OK;

	  /* Check if RCC_OscInitStruct is NULL */
	  if (NULL == RCC_ClkInitStruct)
	  {
	    RetStatus = HAL_ERROR;
	  }
	  else {
/*
		 RCC ->RCC_CFGR |= (RCC_ClkInitStruct->AHBCLKDivider  << RCC_CFGR_HPRE_Pos);
		 RCC ->RCC_CFGR |= (RCC_ClkInitStruct->APB1CLKDivider << RCC_CFGR_PPRE1_Pos);
		 RCC ->RCC_CFGR |= (RCC_ClkInitStruct->APB2CLKDivider << RCC_CFGR_PPRE2_Pos);
*/
		 MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_PPRE2_Msk, RCC_ClkInitStruct->APB2CLKDivider );
		 MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_PPRE1_Msk, RCC_ClkInitStruct->APB1CLKDivider );
		 MODIFY_REG(RCC->RCC_CFGR, RCC_CFGR_HPRE_Pos, RCC_ClkInitStruct->AHBCLKDivider );
}
 return  RetStatus;
}
