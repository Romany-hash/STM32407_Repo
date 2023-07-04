/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Romany Sobhy
 * @brief          : Main program body
 ******************************************************************************/
#include "CortexM4/CortexM4_interface.h"
#include "HAL_Driver/RCC/STM32F4xx_HAL_RCC.h"


static volatile  uint8_t USART1_IRQhANDLER_FLAG=0;
static volatile  uint8_t EXTI15_10_IRQHandler_FLAG=0;
static volatile  uint8_t EXTI17_RTC_Alarm_IRQHandler_FLAG=0;
static volatile  uint8_t USART1_IRQHandler_Active_State_FLAG1=0;
static volatile  uint8_t USART1_IRQHandler_Active_State_FLAG2=0;
static uint32_t Priority_Group=0;
static uint8_t USART1_IRQN_PV=0;

int main(void)
{

	SCB_SetPriorityGrouping (SCB_PRIORITY_GROUP_0);
	SystemClock_Config();
	Priority_Group=SCB_GetPriorityGrouping();
   NVIC_ENABLEIRQ(USART1);
   NVIC_ENABLEIRQ(EXTI15_10);
   NVIC_ENABLEIRQ(RTC_Alarm);
 /*elrakam el2la prioity 22al*/
   NVIC_SetPriority(USART1,0);
   NVIC_SetPriority(EXTI15_10,4);
   NVIC_SetPriority(RTC_Alarm,5);
   /**To disable priority nesting write 16 in all*/

 USART1_IRQN_PV= NVIC_GetPriority(USART1);


  /* NVIC_SETPENDINGIRQ(USART1);
   NVIC_SETPENDINGIRQ(EXTI15_10);
   NVIC_SETPENDINGIRQ(RTC_Alarm);*/
   NVIC_SETPENDINGIRQ(EXTI15_10);




	while(1) {
		USART1_IRQHandler_Active_State_FLAG1=  NVIC_GetActive(USART1);
	};
}


void USART1_IRQHandler (void) {

	USART1_IRQhANDLER_FLAG=1;
	USART1_IRQHandler_Active_State_FLAG2=  NVIC_GetActive(USART1);

};

void EXTI15_10_IRQHandler (void) {

	EXTI15_10_IRQHandler_FLAG=1;
	NVIC_SETPENDINGIRQ(USART1); //kda hero7 llusart1 3chan dah higher priority
};


void EXTI17_RTC_Alarm_IRQHandler  (void) {

	EXTI17_RTC_Alarm_IRQHandler_FLAG=1;
};



void SystemClock_Config(void){
	HAL_StatusTypeDef RetStatus;
	RCC_OscInitTypeDef RCC_OscInitStruct={0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct={0};
	RCC_OscInitStruct.OscillatorType=RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState=RCC_HSE_ON;

	RetStatus=HAL_RCC_OscConfig(&RCC_OscInitStruct);
	//RetStatus=HAL_RCC_OscConfig(&RCC_OscilatorType);

	RCC_ClkInitStruct.AHBCLKDivider=RCC_SYSCLK_AHB_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider=RCC_HCLK_APB1_DIV1 ;
	RCC_ClkInitStruct.APB2CLKDivider=RCC_HCLK_APB2_DIV1 ;

	RetStatus=HAL_RCC_ClockConfig(&RCC_ClkInitStruct);
	if(HAL_ERROR == RetStatus) {

	}
	else {
		/* Nothing */

	}

};
