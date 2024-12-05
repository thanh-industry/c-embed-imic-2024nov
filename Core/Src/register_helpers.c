/*
 * register_helpers.c
 *
 *  Created on: Dec 1, 2024
 *      Author: Huy
 */

#include "register_helpers.h"
uint32_t reg = 0;
// Function to read the intire 32-bit register
uint32_t read_register(uint32_t *address) {
	if (address == NULL) {
		return 0;
	}
	return *address;
}

void write_register(uint32_t *address, uint32_t value) {
	if (address == NULL) {
		return;
	}
	*address = value;
}

// Function to write specific bits in the register using masks
void set_bit(uint32_t *address, uint32_t mask){
	if (address == NULL){
		return;
	}
	reg = read_register(address);
	reg |= mask;
	write_register(address, reg);
}

void clear_bit(uint32_t *address, uint32_t mask){
	if (address == NULL){
		return;
	}
	uint32_t reg = read_register(address);
	reg &= ~mask;
	write_register(address, reg);
}


