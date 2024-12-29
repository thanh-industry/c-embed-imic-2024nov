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


	/*--------------------BASIC TIMER SET UP--------------------*/
	/*----------TIM 6 SET UP----------*/
	registerBitClear(REG_TIM6_CR1, BIT_0);						// Disable counter before setting the parameter


	registerBitSet(REG_TIM6_CR1, (BIT_7 | BIT_2));				// Active Pre-load, update source: only counter
	registerBitSet(REG_TIM6_DIER, BIT_0);						// Enable update interrupt


	// Setting for PSC and ARR to make 100ms timer
	uint32_t timer6_PSC = 0x1F3F;								// HEX value of 7999 DEC
	uint32_t timer6_ARR = 0x63;									// HEX value of 99 DEC

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
	uint32_t timer7_PSC = 0xF9F;								// HEX value of 3999 DEC
	uint32_t timer7_ARR = 0x3E7;								// HEX value of 999 DEC

	registerBitSet(REG_TIM7_PSC, timer7_PSC);					// Add new value to PSC register
	registerBitClear(REG_TIM7_ARR, 0xFFFF);						// Clear all value in ARR register after reset
	registerBitSet(REG_TIM7_ARR, timer7_ARR);					// Add new value to ARR register
	registerBitSet(REG_TIM7_CR1, BIT_0);						// Enable counter
	/*----------TIM 7 SET UP----------*/
	/*--------------------BASIC TIMER SET UP--------------------*/



	/*--------------------ADVANCED TIMER SET UP--------------------*/

	/*----------TIM 1 SET UP----------*/
	registerBitClear(REG_TIM1_CR1, BIT_0);						// Disable counter before setting any parameter
	registerBitSet(REG_TIM1_CR1, (BIT_7 | BIT_2));				// Active Pre-load, update source: only counter

	// Setting for PSC and ARR to make 1KHz (1ms) timer
	uint32_t timer1_PSC = 0x7;									// HEX value of 7 DEC
	uint32_t timer1_ARR = 0x3E7;								// HEX value of 999 DEC

	registerBitSet(REG_TIM1_PSC, timer1_PSC);					// Add new value to PSC register
	registerBitClear(REG_TIM1_ARR, 0xFFFF);						// Clear all value in ARR register after reset
	registerBitSet(REG_TIM1_ARR, timer1_ARR);					// Add new value to ARR register


	// Setting the CCR1 for duty cycle
	/*
	 * Duty_Cycle_Percentage = [Time_Signal_High / Total_Time_period] * 100%
	 * -> Duty_Cycle_Fraction = Time_Signal_High / Total_Time_period
	 *
	 * Total_Time_period = Timer_Update_Time = Timer_Cycle_Count * Timer_Cycle_Time
	 *
	 * While: Timer_Cycle_Count = (TIM_ARR + 1)
	 *
	 * -> Total_Time_period = (TIM_ARR + 1) * Timer_Cycle_Time
	 *
	 * While: Time_Signal_High = TIM_CCR1 * Timer_Cycle_Time
	 *
	 * -> Duty_Cycle_Fraction = [TIM_CCR1 * Timer_Cycle_Time] / [(TIM_ARR + 1) * Timer_Cycle_Time]
	 * 				 = TIM_CCR1 / (TIM_ARR + 1)
	 *
	 * The CCR1 value is based on Duty_Cycle and ARR value
	 * -> TIM_CCR1 = Duty_Cycle_Fraction * (TIM_ARR + 1)
	 * */
	// CCR1 value is 500 with 50% duty cycle (0.5) and ARR value of 999 DEC
	uint32_t timer1_CCR1 = 0x1F4;								// HEX value of 500 DEC

	registerBitSet(REG_TIM1_CCR1, timer1_CCR1);					// Add new value to CCR1 register


	// Setting for Channel 1 of PA8 (TIM1_CH1)
	registerBitClear(REG_TIM1_CCMR1, (BIT_4 | BIT_5 | BIT_6));	// Clear OC1M bit (Output compare 1 mode)
	registerBitSet(REG_TIM1_CCMR1, (BIT_4 | BIT_5));			// Set the OC1M bit to 011 (toggle mode)
	registerBitSet(REG_TIM1_CCMR1, BIT_3);						// Enable OC1PE (Output compare 1 preload) for ability to change CCR1 value on the fly
	registerBitSet(REG_TIM1_CCER, BIT_0);						// Enable capture/compare (compare mode)

	/*
	// Enable interrupt for both Update Interrupt and Compare Interrupt
	registerBitSet(REG_TIM1_DIER, BIT_0);						// Enable UIE bit for Update Interrupt every time counter reach ARR
	*/
	//registerBitSet(REG_TIM1_DIER, BIT_1);						// Enable CC1IE bit for Compare Interrupt every time counter match CCR1

	// Set up BDTR, TIM1 and TIM8 output pin will remain inactive until BDTR is set up
	registerBitSet(REG_TIM1_BDTR, BIT_15);						// Enable Main output function of TIM1 Pin (currently PA8)


	registerBitSet(REG_TIM1_CR1, BIT_0);						// Enable counter
	/*----------TIM 1 SET UP----------*/



	/*----------TIM 8 SET UP----------*/
	registerBitClear(REG_TIM8_CR1, BIT_0);						// Disable counter before setting any parameter

	// Setting for PSC and ARR to make 1KHz (1ms) timer
	uint32_t timer8_PSC = 0x7;									// HEX value of 7 DEC
	uint32_t timer8_ARR = 0xFFFF;								// HEX value of max 32 bit of TIM8 ARR register

	registerBitSet(REG_TIM8_PSC, timer8_PSC);					// Add new value to PSC register
	registerBitSet(REG_TIM8_ARR, timer8_ARR);					// Add new value to ARR register

	// Setting for Channel 1 of PC6 (TIM8_CH1)
	registerBitClear(REG_TIM8_CCMR1, (BIT_0 | BIT_1));			// Clear CC1S bit (Capture/Compare 2 selection)
	registerBitSet(REG_TIM8_CCMR1, BIT_0);						// Set the CC1S bit to 01 (CC1 channel is configured as input, IC1 is mapped on TI1)
	registerBitClear(REG_TIM8_CCER, BIT_1);						// Set the CC1P bit to 00 (non-inverted/rising edge for input mode)
	registerBitSet(REG_TIM8_CCER, BIT_0);						// Set the CC1E bit to 01 (Capture mode)

	// Enable interrupt for Capture Interrupt
	registerBitSet(REG_TIM8_DIER, BIT_1);						// Enable CC1IE bit for Capture Interrupt every time CCR1 latch counter value (signal captured)


	registerBitSet(REG_TIM8_CR1, BIT_0);						// Enable counter
	/*----------TIM 8 SET UP----------*/

	/*--------------------ADVANCED TIMER SET UP--------------------*/


}
