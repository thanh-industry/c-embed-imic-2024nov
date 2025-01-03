/*
 * i2c_tools.h
 *
 *  Created on: Jan 3, 2025
 *      Author: daoch
 */

#ifndef INC_I2C_TOOLS_H_
#define INC_I2C_TOOLS_H_

#include <stdbool.h>

bool i2cWrite(uint32_t slaveAddr, uint32_t regAddr, uint32_t data);
uint8_t i2cRead(uint32_t slaveAddr, uint32_t regAddr);

#endif /* INC_I2C_TOOLS_H_ */
