/*
 * exti.c
 *
 *  Created on: Dec 8, 2024
 *      Author: Huy
 */
#include "exti.h"

void exti_init(){
	bit_set(EXTI_IMR, BIT_0);
	bit_set(EXTI_RTSR, BIT_0);
	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
