/*
 * bus_init.c
 *
 *  Created on: Dec 10, 2024
 *      Author: daoch
 */


#include "registers_tools.h"
#include "registers_defs.h"
#include "bus_init.h"

void busInit(void) {
	busRegisterSetup();
}
void busRegisterSetup(void) {
	// Enable clock in AHB1
	registerBitSet(REG_RCC_AHB1ENR, (BIT_0 | BIT_2 | BIT_3 | BIT_7)); 	// For using general purpose I/O function PORT A, C, D, H

	// Enable clock in APB1
	registerBitSet(REG_RCC_APB1ENR, (BIT_4 | BIT_5)); 					// For using basic timer 6, 7


	// Enable clock in APB2
	registerBitSet(REG_RCC_APB2ENR, BIT_14); 							// For using system configuration function in PORT A
	registerBitSet(REG_RCC_APB2ENR, (BIT_0 | BIT_1)); 					// For using advanced timer 1 and timer 8

}
