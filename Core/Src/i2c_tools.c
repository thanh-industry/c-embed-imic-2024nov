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

bool i2cWrite(uint8_t slaveAddr, uint8_t regAddr, uint8_t data) {
	if ((NULL == REG_I2C1_CR1) | (NULL == REG_I2C1_SR1) | (NULL == REG_I2C1_SR2) | (NULL == REG_I2C1_DR)) return NOTOK;

    // Start condition
    registerBitSet(REG_I2C1_CR1, BIT_8); 					// Generate START condition

    while (!registerBitCheck(REG_I2C1_SR1, BIT_0));			// Wait for SB (start bit)

    uint8_t DRValue = (slaveAddr << 1) + 0x0;
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

uint8_t i2cRead(uint8_t slaveAddr, uint8_t regAddr) {

	if ((NULL == REG_I2C1_CR1) | (NULL == REG_I2C1_SR1) | (NULL == REG_I2C1_SR2) | (NULL == REG_I2C1_DR)) return 0;

	/*
	 * DS3231 will transmit data back starting with the register address pointed to by the register pointer
	 * If the register pointer is not written to before the initiation of a read mode,
	 * the first address that is read is the last one stored in the register pointer.
	 * */

	// Create a WRITE phase with register address needed then move to the READ phase

    registerBitSet(REG_I2C1_CR1, BIT_8); 					// Generate START condition

    while (!registerBitCheck(REG_I2C1_SR1, BIT_0));			// Wait for SB (start bit)

    uint8_t DRValue = (slaveAddr << 1) + 0x0;
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
    temp = registerRead(REG_I2C1_SR2);						// Clear ADDR by reading SR2
    NOUSED(temp);

    // Read data
    while(!registerBitCheck(REG_I2C1_SR1, BIT_6));			// Wait for RXNE = 1 (not empty)

    uint8_t data = registerRead(REG_I2C1_DR);


    registerBitSet(REG_I2C1_CR1, BIT_9);					// Stop condition

    return data;
}

uint8_t hexToDec(uint8_t hex) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

#include <stdio.h>
#include <stdint.h>

void readDS3231Time(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t day, uint8_t date, uint8_t month, uint8_t year, uint8_t isPM) {

    // Read Seconds
    seconds = i2cRead(DS3231_ADDRESS, DS3231_SECONDS);
    seconds = BinToDec(seconds);							// Transfer the BIN value, which is read from DS3231, to DEC

    // Read Minutes
    minutes = i2cRead(DS3231_ADDRESS, DS3231_MINUTES);
    minutes = BinToDec(minutes);

    // Read Hours (and interpret 12-hour/24-hour format)
    hours = i2cRead(DS3231_ADDRESS, DS3231_HOURS);

    if (hours & 0x40) { 									// Check 12-hour mode (Bit 6 is 1/0 for 12/24h mode))
        isPM = (hours & 0x20) >> 5; 						// Check AM/PM (Bit 5 is 1/0 for PM/AM)
        hours = BinToDec(hours & 0x1F); 					// Mask bits to take only the hour value
    } else {
        hours = BinToDec(hours); 							// 24-hour mode
    }

    // Read the Week day
    day = i2cRead(DS3231_ADDRESS, DS3231_DAY);
    day = BinToDec(day);

    // Read the day of Month
    date = i2cRead(DS3231_ADDRESS, DS3231_DATE);
    date = BinToDec(date);

    // Read the month
    month = i2cRead(DS3231_ADDRESS, DS3231_CEN_MONTH);
    month = BinToDec(month & 0x1F); 						// Mask century bit, take only month value

    // Read the year
    year = i2cRead(DS3231_ADDRESS, DS3231_2LDIGI_YEAR);
    year = BinToDec(year);

}
