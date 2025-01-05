/*
 * i2c_tools.h
 *
 *  Created on: Jan 3, 2025
 *      Author: daoch
 */

#ifndef INC_I2C_TOOLS_H_
#define INC_I2C_TOOLS_H_

#include <stdbool.h>

//DS3231 Slave address
#define DS3231_ADDRESS				0x68
//DS3231 Registers
#define DS3231_SECONDS  			0x00
#define DS3231_MINUTES  			0x01
#define DS3231_HOURS  				0x02
#define DS3231_DAY 					0x03
#define DS3231_DATE 				0x04
#define DS3231_CEN_MONTH 			0x05
#define DS3231_2LDIGI_YEAR 			0x06
#define DS3231_ALARM1_SECONDS 		0x07
#define DS3231_ALARM1_MINUTES 		0x08
#define DS3231_ALARM1_HOURS 		0x09
#define DS3231_ALARM1_DAY_DATE 		0x0A
#define DS3231_ALARM2_MINUTES 		0x0B
#define DS3231_ALARM2_HOURS 		0x0C
#define DS3231_ALARM2_DAY_DATE 		0x0D
#define DS3231_CONTROL 				0x0E
#define DS3231_CTL_STATUS 			0x0F
#define DS3231_AGING_OFFSET 		0x10
#define DS3231_TEMP_MSB 			0x11
#define DS3231_TEMP_LSB 			0x12

bool i2cWrite(uint8_t slaveAddr, uint8_t regAddr, uint8_t data);
uint8_t i2cRead(uint8_t slaveAddr, uint8_t regAddr);
uint8_t hexToDec(uint8_t hex);
void readDS3231Time(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t day, uint8_t date, uint8_t month, uint8_t year, uint8_t isPM);

#endif /* INC_I2C_TOOLS_H_ */
