/*
 * interrupts_init.c
 *
 *  Created on: Dec 4, 2024
 *      Author: daoch
 */


#include "registers_tools.h"
#include "registers_defs.h"
#include "interrupts_init.h"

void interruptsInit(void) {
	interruptRegisterSetup();
}

void interruptRegisterSetup(void) {
	// Enable clock in APB2 peripheral for using system configuration function in PORT A
	registerBitSet(REG_RCC_APB2ENR, BIT_14);


	/* registers set up for Extend Interrupt in PORT A*/

	// Enable EXTI0 group for PA0 button PIN (Mode 0000) in SYSCFG external interrupt configuration register 1
	registerBitClear(REG_SYSCFG_EXTICR1, (BIT_0 | BIT_1 | BIT_2 | BIT_3));
	// Un-mask EXTI0 group in Interrupt mask register (EXTI_IMR) for enabling detecting interrupt
	registerBitClear(REG_EXTI_IMR, BIT_0);
	// Disable Rising trigger selection register (EXTI_RTSR) for rising edge at EXTI0 group
	registerBitClear(REG_EXTI_RTSR, BIT_0);
	// Enable Falling trigger selection register (EXTI_FTSR) for falling edge at EXTI0 group
	registerBitSet(REG_EXTI_FTSR, BIT_0);
	// Set Interrupt set-enable register 0 (NVIC_ISERx) enable interrupt number 0
	//registerBitSet(REG_NVIC_ISER0, BIT_0);
}
