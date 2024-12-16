/*
 * register_helpers.c
 *
 *  Created on: Dec 1, 2024
 *      Author: Huy
 */

#include "register_helpers.h"

// Function to read the intire 32-bit register
uint32_t register_read(uint32_t *address) {
	if (address == NULL) {
		return 0;
	}
	return *address;
}

void register_write(uint32_t *address, uint32_t value) {
	if (address == NULL) {
		return;
	}
	*address = value;
}

// Function to write specific bits in the register using masks
void bit_set(uint32_t *address, uint32_t mask){
	if (address == NULL){
		return;
	}
	volatile uint32_t reg = register_read(address);
	reg |= mask;
	register_write(address, reg);
}

void bit_clear(uint32_t *address, uint32_t mask){
	if (address == NULL){
		return;
	}
	volatile uint32_t reg = register_read(address);
	reg &= ~mask;
	register_write(address, reg);
}


