/*
 * timers_init.c
 *
 *  Created on: Dec 10, 2024
 *      Author: daoch
 */


#include "timers_init.h"
#include "registers_tools.h"
#include "registers_defs.h"

void timersInit(void) {
	timersRegisterSetup();
}

void timersRegisterSetup(void) {
	/*
	 * Currently the micro-controller is working on HSE with frequency of 8Mhz
	 * -> APB1_Freq = 8Mhz (with no multiplier and no divider)
	 *
	 * Timer_Cycle_Time = 1 / Timer_Freq
	 *
	 * Timer_Update_Time = Timer_Cycle_Count * Timer_Cycle_Time = Timer_Cycle_Count / Timer_Freq
	 *
	 * Timer_Freq = APB1_Freq / (TIM_PSC + 1)
	 *
	 * -> Timer_Update_Time = Timer_Cycle_Count / [APB1_Freq / (TIM_PSC + 1)]
	 *
	 * -> Timer_Update_Time = Timer_Cycle_Count * (TIM_PSC + 1) / APB1_Freq
	 *
	 * Timer_Cycle_Count = (TIM_ARR + 1) because Timer start counting from 0
	 *
	 * The Timer_Update_Time is based on seconds
	 * -> Timer_Update_Time = (TIM_ARR + 1) * (TIM_PSC + 1) / APB1_Freq
	 *
	 * The Timer_Update_Time is based on milliseconds
	 * -> Timer_Update_Time  = 1000 * (TIM_ARR + 1) * (TIM_PSC + 1) / APB1_Freq
	 * */


	/*----------TIM 6 SET UP----------*/
	registerBitClear(REG_TIM6_CR1, BIT_0);						// Disable counter before setting the parameter
	registerBitSet(REG_TIM6_CR1, (BIT_7 | BIT_2));				// Active Pre-load, update source: only counter
	registerBitSet(REG_TIM6_DIER, BIT_0);						// Enable update interrupt


	// Setting for PSC and ARR to make 100ms timer
	uint32_t timer6_ARR = 0x63;									// HEX value of 99 DEC
	uint32_t timer6_PSC = 0x1F3F;								// HEX value of 7999 DEC

	registerBitSet(REG_TIM6_PSC, timer6_PSC);					// Add new value to PSC register
	registerBitClear(REG_TIM6_ARR, 0xFFFF);						// Clear all value in ARR register after reset
	registerBitSet(REG_TIM6_ARR, timer6_ARR);					// Add new value to ARR register
	registerBitSet(REG_TIM6_CR1, BIT_0);						// Enable counter

	/*----------TIM 6 SET UP----------*/

	/*----------TIM 7 SET UP----------*/
	registerBitClear(REG_TIM7_CR1, BIT_0);						// Disable counter before setting the parameter
	registerBitSet(REG_TIM7_CR1, (BIT_7 | BIT_2));				// Active Pre-load, update source: only counter
	registerBitSet(REG_TIM7_DIER, BIT_0);						// Enable update interrupt


	// Setting for PSC and ARR to make 500ms timer
	uint32_t timer7_ARR = 0x3E7;								// HEX value of 999 DEC
	uint32_t timer7_PSC = 0xF9F;								// HEX value of 3999 DEC

	registerBitSet(REG_TIM7_PSC, timer7_PSC);					// Add new value to PSC register
	registerBitClear(REG_TIM7_ARR, 0xFFFF);						// Clear all value in ARR register after reset
	registerBitSet(REG_TIM7_ARR, timer7_ARR);					// Add new value to ARR register
	registerBitSet(REG_TIM7_CR1, BIT_0);						// Enable counter
	/*----------TIM 7 SET UP----------*/
}
