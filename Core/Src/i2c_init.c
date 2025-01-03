/*
 * i2c_init.c
 *
 *  Created on: Jan 3, 2025
 *      Author: daoch
 */

#include "i2c_init.h"
#include "registers_tools.h"
#include "registers_defs.h"

void i2cInit(void) {
	i2cPinSetup();
	i2cRegisterSetup();
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
