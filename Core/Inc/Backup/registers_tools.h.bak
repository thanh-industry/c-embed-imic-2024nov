/*
 * register_settings.h
 *
 *  Created on: Nov 29, 2024
 *      Author: daoch
 */

#ifndef INC_REGISTERS_TOOLS_H_
#define INC_REGISTERS_TOOLS_H_

#include <stdint.h>
#include <stdbool.h>

// define the bit mask by doing left shift bitwise operator for every bit in a register
#define BIT_0 	(1U << 0)
#define BIT_1 	(1U << 1)
#define BIT_2 	(1U << 2)
#define BIT_3 	(1U << 3)
#define BIT_4 	(1U << 4)
#define BIT_5 	(1U << 5)
#define BIT_6 	(1U << 6)
#define BIT_7 	(1U << 7)
#define BIT_8 	(1U << 8)
#define BIT_9 	(1U << 9)
#define BIT_10 	(1U << 10)
#define BIT_11 	(1U << 11)
#define BIT_12 	(1U << 12)
#define BIT_13 	(1U << 13)
#define BIT_14 	(1U << 14)
#define BIT_15 	(1U << 15)
#define BIT_16 	(1U << 16)
#define BIT_17 	(1U << 17)
#define BIT_18 	(1U << 18)
#define BIT_19 	(1U << 19)
#define BIT_20 	(1U << 20)
#define BIT_21 	(1U << 21)
#define BIT_22 	(1U << 22)
#define BIT_23 	(1U << 23)
#define BIT_24 	(1U << 24)
#define BIT_25 	(1U << 25)
#define BIT_26 	(1U << 26)
#define BIT_27 	(1U << 27)
#define BIT_28 	(1U << 28)
#define BIT_29 	(1U << 29)
#define BIT_30 	(1U << 30)
#define BIT_31 	(1U << 31)

#define NOUSED(x) (void)x

uint32_t registerRead(uint32_t *registerAddress);

uint8_t registerRead_uint8(uint8_t *registerAddress);

void registerWrite(uint32_t *registerAddress, uint32_t value);

void registerWrite_uint8(uint8_t *registerAddress, uint8_t value);

void registerBitSet(uint32_t *registerAddress, uint32_t mask);

void registerBitSet_uint8(uint8_t *registerAddress, uint8_t mask);

void registerBitClear(uint32_t *registerAddress, uint32_t mask);

void registerBitClear_uint8(uint8_t *registerAddress, uint8_t mask);

bool registerBitCheck(uint32_t *registerAddress, uint32_t mask);

bool registerBitCheck_uint8(uint8_t *registerAddress, uint8_t mask);

#endif /* INC_REGISTERS_TOOLS_H_ */
