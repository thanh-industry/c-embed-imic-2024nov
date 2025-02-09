/*
 * i2c_init.c
 *
 *  Created on: Jan 3, 2025
 *      Author: daoch
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"
#include "registers_tools.h"
#include "registers_defs.h"

#define OK true
#define NOTOK false
#define DS3231_EOSC_BIT BIT_7

void i2cInit(void) {
	i2cPinSetup();
	i2cRegisterSetup();
	DS3231Init();
}
void i2cPinSetup(void) {
	/* START registers set up I2C1 SCL on PIN PB6 in PORT B */
	// For MODER, set mode 10 (Alternate function mode)
	registerBitClear(REG_GPIO_B_MODER, BIT_12);
	registerBitSet(REG_GPIO_B_MODER, BIT_13);

	// For OTYPER, set mode 1 (open-drain)
	registerBitSet(REG_GPIO_B_OTYPER, BIT_6);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_B_OSPEEDR, BIT_12);
	registerBitClear(REG_GPIO_B_OSPEEDR, BIT_13);

	// For PUPDR, set mode 01 (pull up)
	registerBitSet(REG_GPIO_B_OSPEEDR, BIT_12);
	registerBitClear(REG_GPIO_B_OSPEEDR, BIT_13);

	// For AFRL, set mode 0100 AF4 (I2C1_SCL)
	registerBitClear(REG_GPIO_B_AFRL, (BIT_24 | BIT_25 | BIT_27));
	registerBitSet(REG_GPIO_B_AFRL, BIT_26);
	/* END registers set up I2C1 SCL on PIN PB6 in PORT B */



	/* START registers set up I2C1 SDA on PIN PB7 in PORT B */
	// For MODER, set mode 10 (Alternate function mode)
	registerBitClear(REG_GPIO_B_MODER, BIT_14);
	registerBitSet(REG_GPIO_B_MODER, BIT_15);

	// For OTYPER, set mode 1 (open-drain)
	registerBitSet(REG_GPIO_B_OTYPER, BIT_7);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_B_OSPEEDR, BIT_14);
	registerBitClear(REG_GPIO_B_OSPEEDR, BIT_15);

	// For PUPDR, set mode 01 (pull up)
	registerBitSet(REG_GPIO_B_OSPEEDR, BIT_12);
	registerBitClear(REG_GPIO_B_OSPEEDR, BIT_13);

	// For AFRL, set mode 0100 AF4 (I2C1_SDA)
	registerBitClear(REG_GPIO_B_AFRL, (BIT_28 | BIT_29 | BIT_31));
	registerBitSet(REG_GPIO_B_AFRL, BIT_30);

	/* END registers set up I2C1 SDA on PIN PB7 in PORT B */

}
void i2cRegisterSetup(void) {
	registerBitClear(REG_I2C1_CR1, BIT_0);									// Disable I2C before setting the parameter

	/*
	 * I2C communication speed, F_SCL ~ 1/(T_high + T_low)
	 * As standard mode: T_high = CCR * TPCLK1(APB1 clock period) and T_low = CCR * TPCLK1(APB1 clock period)
	 * -> F_SCL ~ 1/ (2 * CCR * TPCLK1)
	 * -> CCR = 1 / (2 * F_SCL * TPCLK1)
	 * As TPCLK1 = 1 / F_APB1
	 *
	 * -> CCR = F_APB1 / (2 * F_SCL)
	 * */
	uint32_t FREQBit = 0x3F;												// FREQ start from Bit 0 to Bit 5
	uint32_t clockFREQ = 0x08;												// HEX value of DEC 8
	registerBitClear(REG_I2C1_CR2, FREQBit);								// Clear FREQ
	registerBitSet(REG_I2C1_CR2, clockFREQ);								// Set FREQ of 8 for 8Mhz (similar to Bus APB1 clock frequency)

	// CCR is 40, based on the formula with F_APB1 = 8Mhz and F_SCL is default of 100kHz
	uint32_t ccrValue = 0x28;												// HEX value of DEC 40
	registerBitSet(REG_I2C1_CCR, ccrValue);									// Set CCR value of 40

	/*
	 * TRISE = (1 us / (1/APB1_FREQ)) + 1 (As the user manual)
	 * -> TRISE = 9 with APB1_FREQ = 8MHz
	 * */

	uint32_t triseValue = 0x09;												// HEX value of DEC 9
	registerBitSet(REG_I2C1_TRISE, triseValue);								// Set TRISE of 9

	registerBitSet(REG_I2C1_CR1, BIT_0);									// Enable I2C1
}

void DS3231Init(void) {
	uint8_t controlReg;

	// Disable the oscillator by setting the EOSC bit
	controlReg = i2cRead(DS3231_ADDRESS, DS3231_CONTROL);					// Check the Control register in DS3231
	controlReg |= DS3231_EOSC_BIT;													// Stop oscillator
	i2cWrite(DS3231_ADDRESS, DS3231_CONTROL, controlReg);					// Send the new setting to DS3231

	// Set up the RTC DS3231 for the first time
	i2cWrite(DS3231_ADDRESS, DS3231_SECONDS, DecToBCD(12)); 				// Seconds as 12 seconds
	i2cWrite(DS3231_ADDRESS, DS3231_MINUTES, DecToBCD(12)); 				// Minutes as 12 minutes
	i2cWrite(DS3231_ADDRESS, DS3231_HOURS, 0x72); 							// Hours as 12 hours, 12h format, PM
	i2cWrite(DS3231_ADDRESS, DS3231_DAY, 0x01);								// Week day as 1 (Sunday)
	i2cWrite(DS3231_ADDRESS, DS3231_DATE, DecToBCD(5));						// Date of month (5)
	i2cWrite(DS3231_ADDRESS, DS3231_CEN_MONTH, 0x01);						// Month (1 as January), Century (Bit 7 as 0 for 2000 - 2099)
	i2cWrite(DS3231_ADDRESS, DS3231_2LDIGI_YEAR, DecToBCD(25));				// Year (25 as 2 last digit)

    // Enable the oscillator by clearing the EOSC bit
    controlReg &= ~DS3231_EOSC_BIT;
    i2cWrite(DS3231_ADDRESS, DS3231_CONTROL, controlReg);
}

bool i2cWrite(uint8_t slaveAddr, uint8_t regAddr, uint8_t data) {
	uint32_t timeout;

    // Start condition
    registerBitSet(REG_I2C1_CR1, BIT_8); 						// Generate START condition

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_0)) {			// Wait for SB (start bit)
    	if (--timeout == 0) return NOTOK;
    }

    uint8_t DRValue = (slaveAddr << 1) & ((uint8_t) ~(BIT_0));
    registerBitSet(REG_I2C1_DR, DRValue);						// Send slave address with WRITE bit

    // Check for ACK failure
    if (registerBitCheck(REG_I2C1_SR1, BIT_10)) {  				// AF bit check if the slave send acknowledge
        registerBitSet(REG_I2C1_CR1, BIT_9);  					// Send STOP condition
        registerBitClear(REG_I2C1_SR1, BIT_10);					// Clear the AF bit
        return NOTOK;
    }

    timeout = TIMEOUT_LIMIT;
    while(!registerBitCheck(REG_I2C1_SR1, BIT_1)) {				// Wait for ADDR
    if (--timeout == 0) return NOTOK;
	}
    uint16_t tempSR1 = registerRead(REG_I2C1_SR1);				// Clear ADDR by reading SR1 then SR2
    uint16_t tempSR2 = registerRead(REG_I2C1_SR2);
    NOUSED(tempSR1);
    NOUSED(tempSR2);

    timeout = TIMEOUT_LIMIT;
    while(!registerBitCheck(REG_I2C1_SR1, BIT_7)) {				// Wait for TXE = 1 (empty)
	if (--timeout == 0) return NOTOK;
    }
    registerWrite(REG_I2C1_DR, regAddr);						// Send register address

    timeout = TIMEOUT_LIMIT;
    while(!registerBitCheck(REG_I2C1_SR1, BIT_7)) {				// Wait for TXE = 1 (empty)
    if (--timeout == 0) return NOTOK;
    }
    registerWrite(REG_I2C1_DR, data);							// Send data
    timeout = TIMEOUT_LIMIT;
    while(!registerBitCheck(REG_I2C1_SR1, BIT_7)) {				// Wait for TXE = 1 (empty)
    if (--timeout == 0) return NOTOK;
    }

    timeout = TIMEOUT_LIMIT;
    while(!registerBitCheck(REG_I2C1_SR1, BIT_2)) {  			// Wait for BTF (Byte Transfer Finished) = 1
    if (--timeout == 0) return NOTOK;
	}
    registerBitSet(REG_I2C1_CR1, BIT_9);						// Stop condition

    return OK;
}

uint8_t i2cRead(uint8_t slaveAddr, uint8_t regAddr) {

    /*
     * DS3231 will transmit data back starting with the register address pointed to by the register pointer
     * If the register pointer is not written to before the initiation of a read mode,
     * the first address that is read is the last one stored in the register pointer.
     * */

    // Create a WRITE phase with register address needed then move to the READ phase

    uint32_t timeout;
    uint8_t data;
    uint8_t DRValue;
    uint16_t tempSR1, tempSR2;

    // Start condition (WRITE Phase)
    registerBitSet(REG_I2C1_CR1, BIT_8); // Generate START condition

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_0)) { // Wait for SB (start bit)
        if (--timeout == 0) return -1;
    }

    DRValue = (slaveAddr << 1) & ~BIT_0;
    registerWrite(REG_I2C1_DR, DRValue); // Send slave address with WRITE bit

    // Check for ACK failure
    if (registerBitCheck(REG_I2C1_SR1, BIT_10)) { // AF bit check if the slave sends acknowledge
        registerBitSet(REG_I2C1_CR1, BIT_9); // Send STOP condition
        registerBitClear(REG_I2C1_SR1, BIT_10); // Clear the AF bit
        return NOTOK;
    }

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_1)) { // Wait for ADDR
        if (--timeout == 0) return -1;
    }

    tempSR1 = registerRead(REG_I2C1_SR1); // Clear ADDR by reading SR1 then SR2
    tempSR2 = registerRead(REG_I2C1_SR2);
    NOUSED(tempSR1);
    NOUSED(tempSR2);

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_7)) { // Wait for TXE = 1 (empty)
        if (--timeout == 0) return -1;
    }

    registerWrite(REG_I2C1_DR, regAddr); // Send register address

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_7)) { // Wait for TXE = 1 (empty)
        if (--timeout == 0) return -1;
    }

    // Start the READ phase

    // Restart
    registerBitSet(REG_I2C1_CR1, BIT_8); // Generate START condition

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_0)) { // Wait for SB (start bit)
        if (--timeout == 0) return -1;
    }

    DRValue = (slaveAddr << 1) | BIT_0;
    registerWrite(REG_I2C1_DR, DRValue); // Send slave address with READ bit

    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_1)) { // Wait for ADDR
        if (--timeout == 0) return -1;
    }

    tempSR1 = registerRead(REG_I2C1_SR1); // Clear ADDR by reading SR1 then SR2
    tempSR2 = registerRead(REG_I2C1_SR2);
    NOUSED(tempSR1);
    NOUSED(tempSR2);

    // Read data
    timeout = TIMEOUT_LIMIT;
    while (!registerBitCheck(REG_I2C1_SR1, BIT_6)) { // Wait for RXNE = 1 (not empty)
        if (--timeout == 0) return -1;
    }

    data = registerRead(REG_I2C1_DR);

    registerBitSet(REG_I2C1_CR1, BIT_9); // Stop condition

    return data;
}

uint8_t BCDToDec(uint8_t BCD) {
    return ((BCD >> 4) * 10) + (BCD & 0x0F);
}

uint8_t DecToBCD(uint8_t Dec) {
    return ((Dec / 10) << 4) | (Dec % 10);
}

void readDS3231Time(uint8_t *seconds, uint8_t *minutes, uint8_t *hours, uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year, uint8_t *isPM) {

    // Read Seconds
    *seconds = BCDToDec(i2cRead(DS3231_ADDRESS, DS3231_SECONDS));	// Read n Transfer the BIN value, which is read from DS3231, to DEC

    // Read Minutes
    *minutes = BCDToDec(i2cRead(DS3231_ADDRESS, DS3231_MINUTES));

    // Read Hours (and interpret 12-hour/24-hour format)
    *hours = i2cRead(DS3231_ADDRESS, DS3231_HOURS);

    if ((*hours & 0x40) >> 6) { 								// Check 12-hour mode (Bit 6 is 1/0 for 12/24h mode))
        *isPM = (*hours & 0x20) >> 5; 						// Get AM/PM (Bit 5 is 0/1 for AM/PM)
        *hours = BCDToDec(*hours & 0x1F); 					// Mask bits to take only the hour value
    } else {
        *hours = BCDToDec(*hours & 0x3F); 					// 24-hour mode. Mask bits to take only the hour value
    }

    // Read the Week day
    *day = i2cRead(DS3231_ADDRESS, DS3231_DAY);
    *day = BCDToDec(*day);

    // Read the day of Month
    *date = i2cRead(DS3231_ADDRESS, DS3231_DATE);
    *date = BCDToDec(*date);

    // Read the month
    *month = i2cRead(DS3231_ADDRESS, DS3231_CEN_MONTH);
    *month = BCDToDec(*month & 0x1F); 						// Mask century bit, take only month value

    // Read the year
    *year = i2cRead(DS3231_ADDRESS, DS3231_2LDIGI_YEAR);
    *year = BCDToDec(*year);

}
