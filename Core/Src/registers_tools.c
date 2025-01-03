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

uint8_t registerRead_uint8(uint8_t *registerAddress) {
	if (registerAddress == NULL) return 0;
	return *registerAddress;
}

void registerWrite(uint32_t *registerAddress, uint32_t value) {
	if (registerAddress == NULL) return;
	*registerAddress = value;
}

void registerWrite_uint8(uint8_t *registerAddress, uint8_t value) {
	if (registerAddress == NULL) return;
	*registerAddress = value;
}

void registerBitSet(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return;
	uint32_t reg = registerRead(registerAddress);
	reg |= mask;
	registerWrite(registerAddress, reg);
}

void registerBitSet_uint8(uint8_t *registerAddress, uint8_t mask) {
	if (registerAddress == NULL) return;
	uint8_t reg = registerRead_uint8(registerAddress);
	reg |= mask;
	registerWrite_uint8(registerAddress, reg);
}

void registerBitClear(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return;
	uint32_t reg = registerRead(registerAddress);
	reg &= ~mask;
	registerWrite(registerAddress, reg);
}

void registerBitClear_uint8(uint8_t *registerAddress, uint8_t mask) {
	if (registerAddress == NULL) return;
	uint8_t reg = registerRead_uint8(registerAddress);
	reg &= ~mask;
	registerWrite_uint8(registerAddress, reg);
}


bool registerBitCheck(uint32_t *registerAddress, uint32_t mask) {
	if (registerAddress == NULL) return false;
	if (*registerAddress & mask) return true;
	else return false;
}

bool registerBitCheck_uint8(uint8_t *registerAddress, uint8_t mask) {
	if (registerAddress == NULL) return false;
	if (*registerAddress & mask) return true;
	else return false;
}
