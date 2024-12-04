/*
 * register_setting.c
 *
 *  Created on: Nov 29, 2024
 *      Author: daoch
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "registers_tools.h"

uint32_t registerRead(uint32_t *registerAddress) {
	if (registerAddress == NULL) return 0;
	return *registerAddress;
}

void registerWrite(uint32_t *registerAddress, uint32_t value) {
	if (registerAddress == NULL) return;
	*registerAddress = value;
}

void registerBitSet(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return;
	uint32_t reg = registerRead(registerAddress);
	reg |= mask;
	registerWrite(registerAddress, reg);
}

void registerBitClear(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return;
	uint32_t reg = registerRead(registerAddress);
	reg &= ~mask;
	registerWrite(registerAddress, reg);
}

bool registerBitCheck(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return false;
	if (*registerAddress & mask) return true;
	else return false;
}

