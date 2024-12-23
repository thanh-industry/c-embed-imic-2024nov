/*
 * exti.c
 *
 *  Created on: Dec 8, 2024
 *      Author: Huy
 */
#include "exti.h"

void exti_init(){
	exti_attach_interrupt (GPIO_0, RISING_MODE);
	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void exti_attach_interrupt(uint32_t pin, uint8_t mode){

	// set 1 to enbale interrupt request
	bit_set(EXTI_IMR, 1 << pin);

	switch (mode)
	{
		case RISING_MODE:
			// set 1 to enable rising trigger selection 
			bit_set(EXTI_RTSR, 1 << pin);	

			// set 0 to disable falling trigger selection
			bit_clear(EXTI_FTSR, 1 << pin);	
			break;

		case FALLING_MODE:
			// set 1 to enable falling trigger selection
			bit_set(EXTI_FTSR, 1 << pin);	

			// set 0 to disable rising trigger selection 
			bit_clear(EXTI_RTSR, 1 << pin);	

			break;
		
		case RISING_FALLING_MODE:
			// set 1 to enable rising trigger selection 
			bit_set(EXTI_RTSR, 1 << pin);
			// set 1 to enable falling trigger selection
			bit_set(EXTI_FTSR, 1 << pin);	
			
			break;
	}
}

void exti_attach_event(uint32_t pin, uint8_t mode){

	// set 1 to enbale interrupt request
	bit_set(EXTI_EMR, 1 << pin);

	switch (mode)
	{
		case RISING_MODE:
			// set 1 to enable rising trigger selection 
			bit_set(EXTI_RTSR, 1 << pin);	

			// set 0 to disable falling trigger selection
			bit_clear(EXTI_FTSR, 1 << pin);	
			break;

		case FALLING_MODE:
			// set 1 to enable falling trigger selection
			bit_set(EXTI_FTSR, 1 << pin);	

			// set 0 to disable rising trigger selection 
			bit_clear(EXTI_RTSR, 1 << pin);	

			break;
		
		case RISING_FALLING_MODE:
			// set 1 to enable rising trigger selection 
			bit_set(EXTI_RTSR, BIT_0 << pin);
			// set 1 to enable falling trigger selection
			bit_set(EXTI_FTSR, BIT_0 << pin);	
			
			break;
	}
}

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler()
{ 
  // set 1 to reset the pending bit corresponding to the interupt line 
  bit_set(EXTI_PR, BIT_0);
	exti_callback();
}


/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin Specifies the pins connected EXTI line
  * @retval None
  */
__weak void exti_callback(){
	(void)0U;
}

