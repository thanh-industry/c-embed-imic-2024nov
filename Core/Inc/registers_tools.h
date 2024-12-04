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
#define BIT_0 	((uint32_t)(1U << 0))
#define BIT_1 	((uint32_t)(1U << 1))
#define BIT_2 	((uint32_t)(1U << 2))
#define BIT_3 	((uint32_t)(1U << 3))
#define BIT_4 	((uint32_t)(1U << 4))
#define BIT_5 	((uint32_t)(1U << 5))
#define BIT_6 	((uint32_t)(1U << 6))
#define BIT_7 	((uint32_t)(1U << 7))
#define BIT_8 	((uint32_t)(1U << 8))
#define BIT_9 	((uint32_t)(1U << 9))
#define BIT_10 	((uint32_t)(1U << 10))
#define BIT_11 	((uint32_t)(1U << 11))
#define BIT_12 	((uint32_t)(1U << 12))
#define BIT_13 	((uint32_t)(1U << 13))
#define BIT_14 	((uint32_t)(1U << 14))
#define BIT_15 	((uint32_t)(1U << 15))
#define BIT_16 	((uint32_t)(1U << 16))
#define BIT_17 	((uint32_t)(1U << 17))
#define BIT_18 	((uint32_t)(1U << 18))
#define BIT_19 	((uint32_t)(1U << 19))
#define BIT_20 	((uint32_t)(1U << 20))
#define BIT_21 	((uint32_t)(1U << 21))
#define BIT_22 	((uint32_t)(1U << 22))
#define BIT_23 	((uint32_t)(1U << 23))
#define BIT_24 	((uint32_t)(1U << 24))
#define BIT_25 	((uint32_t)(1U << 25))
#define BIT_26 	((uint32_t)(1U << 26))
#define BIT_27 	((uint32_t)(1U << 27))
#define BIT_28 	((uint32_t)(1U << 28))
#define BIT_29 	((uint32_t)(1U << 29))
#define BIT_30 	((uint32_t)(1U << 30))
#define BIT_31 	((uint32_t)(1U << 31))

#define NOUSED(x) (void)x

uint32_t registerRead(uint32_t *registerAddress);

void registerWrite(uint32_t *registerAddress, uint32_t value);

void registerBitSet(uint32_t *registerAddress, uint32_t mask);

void registerBitClear(uint32_t *registerAddress, uint32_t mask);

bool registerBitCheck(uint32_t *registerAddress, uint32_t mask);

#endif /* INC_REGISTERS_TOOLS_H_ */
