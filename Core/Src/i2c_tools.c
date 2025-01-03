/*
 * i2c_tools.c
 *
 *  Created on: Jan 3, 2025
 *      Author: daoch
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "i2c_tools.h"
#include "registers_tools.h"
#include "registers_defs.h"

#define OK true
#define NOTOK false

bool i2cWrite(uint32_t slaveAddr, uint32_t regAddr, uint32_t data) {
	if ((NULL == REG_I2C1_CR1) | (NULL == REG_I2C1_SR1) | (NULL == REG_I2C1_SR2) | (NULL == REG_I2C1_DR)) return NOTOK;

    // Start condition
    registerBitSet(REG_I2C1_CR1, BIT_8); 					// Generate START condition

    while (!registerBitCheck(REG_I2C1_SR1, BIT_0));			// Wait for SB (start bit)

    uint32_t DRValue = (slaveAddr << 1) + 0x0;
    registerBitSet(REG_I2C1_DR, DRValue);					// Send slave address with write bit

    while(!registerBitCheck(REG_I2C1_SR1, BIT_1));			// Wait for ADDR
    uint32_t temp = registerRead(REG_I2C1_SR2);				// Clear ADDR by reading SR2
    NOUSED(temp);

    registerWrite(REG_I2C1_DR, regAddr);					// Send register address

    while(!registerBitCheck(REG_I2C1_SR1, BIT_7));			// Wait for TXE = 0 (empty)


    registerWrite(REG_I2C1_DR, data);						// Send data
    while(!registerBitCheck(REG_I2C1_SR1, BIT_7));			// Wait for TXE = 0 (empty)


    registerBitSet(REG_I2C1_CR1, BIT_9);					// Stop condition

    return OK;
}

uint8_t i2cRead(uint32_t slaveAddr, uint32_t regAddr) {

	if ((NULL == REG_I2C1_CR1) | (NULL == REG_I2C1_SR1) | (NULL == REG_I2C1_SR2) | (NULL == REG_I2C1_DR)) return 0;

	/*
	 * DS3231 will transmit data back starting with the register address pointed to by the register pointer
	 * If the register pointer is not written to before the initiation of a read mode,
	 * the first address that is read is the last one stored in the register pointer.
	 * */

	// Create a WRITE phase with register address needed then move to the READ phase

    registerBitSet(REG_I2C1_CR1, BIT_8); 					// Generate START condition

    while (!registerBitCheck(REG_I2C1_SR1, BIT_0));			// Wait for SB (start bit)

    uint32_t DRValue = (slaveAddr << 1) + 0x0;
    registerBitSet(REG_I2C1_DR, DRValue);					// Send slave address with write bit

    while(!registerBitCheck(REG_I2C1_SR1, BIT_1));			// Wait for ADDR
    uint32_t temp = registerRead(REG_I2C1_SR2);				// Clear ADDR by reading SR2
    NOUSED(temp);

    registerWrite(REG_I2C1_DR, regAddr);					// Send register address

    while(!registerBitCheck(REG_I2C1_SR1, BIT_7));			// Wait for TXE = 0 (empty)

    // Start the READ phase

    // Restart
    registerBitSet(REG_I2C1_CR1, BIT_8);					// Generate START condition
    while (!registerBitCheck(REG_I2C1_SR1, BIT_0));			// Wait for SB (start bit)

    DRValue = (slaveAddr << 1) + 0x01;
	registerBitSet(REG_I2C1_DR, DRValue);					// Send slave address with read bit

	while(!registerBitCheck(REG_I2C1_SR1, BIT_1));			// Wait for ADDR
    temp = registerRead(REG_I2C1_SR2);				// Clear ADDR by reading SR2
    NOUSED(temp);

    // Read data
    while(!registerBitCheck(REG_I2C1_SR1, BIT_6));			// Wait for RXNE = 1 (not empty)

    uint8_t data = registerRead(REG_I2C1_DR);


    registerBitSet(REG_I2C1_CR1, BIT_9);					// Stop condition

    return data;
}
