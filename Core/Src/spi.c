/*
 * spi.c
 *
 *  Created on: Jan 19, 2025
 *      Author: daoch
 */

#include "spi.h"
#include <stdio.h>
#include <stdint.h>
#include "registers_tools.h"
#include "registers_defs.h"

void spiInit(void) {
	spiPinSetup();
	spiRegisterSetup();
}

void spiPinSetup(void) {
	/* START registers set up PSI1 SS on PIN PA4 in PORT A */
	// For MODER, set mode 01 (General purpose output mode)
	registerBitSet(REG_GPIO_A_MODER, BIT_8);
	registerBitClear(REG_GPIO_A_MODER, BIT_9);

	// For OTYPER, set mode 0 (push-pull)
	registerBitClear(REG_GPIO_A_OTYPER, BIT_4);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_A_OSPEEDR, BIT_8);
	registerBitClear(REG_GPIO_A_OSPEEDR, BIT_9);
	// For PUPDR, set mode 01 (pull up)
	registerBitSet(REG_GPIO_A_PUPDR, BIT_8);
	registerBitClear(REG_GPIO_A_PUPDR, BIT_9);
	/* END registers set up PSI1 SS on PIN PA4 in PORT A */



	/* START registers set up PSI1 SCK on PIN PA5 in PORT A */
	// For MODER, set mode 10 (Alternate function mode)
	registerBitClear(REG_GPIO_A_MODER, BIT_10);
	registerBitSet(REG_GPIO_A_MODER, BIT_11);

	// For OTYPER, set mode 0 (push-pull)
	registerBitClear(REG_GPIO_A_OTYPER, BIT_5);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_A_OSPEEDR, BIT_10);
	registerBitClear(REG_GPIO_A_OSPEEDR, BIT_11);

	// For PUPDR, set mode 00 (no push-pull)
	registerBitClear(REG_GPIO_A_PUPDR, (BIT_10 | BIT_11));

	// For AFRL, set mode 0101 (AF5 for SPI1 SCK)
	registerBitSet(REG_GPIO_A_AFRL, (BIT_20 | BIT_22));
	registerBitClear(REG_GPIO_A_AFRL, (BIT_21 | BIT_23));
	/* END registers set up PSI1 SCK on PIN PA5 in PORT A */



	/* START registers set up PSI1 MISO on PIN PA6 in PORT A */
	// For MODER, set mode 10 (Alternate function mode)
	registerBitClear(REG_GPIO_A_MODER, BIT_12);
	registerBitSet(REG_GPIO_A_MODER, BIT_13);

	// For OTYPER, set mode 0 (push-pull)
	registerBitClear(REG_GPIO_A_OTYPER, BIT_6);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_A_OSPEEDR, BIT_12);
	registerBitClear(REG_GPIO_A_OSPEEDR, BIT_13);

	// For PUPDR, set mode 00 (no push-pull)
	registerBitClear(REG_GPIO_A_PUPDR, (BIT_12 | BIT_13));

	// For AFRL, set mode 0101 (AF5 for SPI1 MISO)
	registerBitSet(REG_GPIO_A_AFRL, (BIT_24 | BIT_26));
	registerBitClear(REG_GPIO_A_AFRL, (BIT_25 | BIT_27));
	/* END registers set up PSI1 MISO on PIN PA6 in PORT A */



	/* START registers set up PSI1 MOSI on PIN PA7 in PORT A */
	// For MODER,  set mode 10 (Alternate function mode)
	registerBitClear(REG_GPIO_A_MODER, BIT_14);
	registerBitSet(REG_GPIO_A_MODER, BIT_15);

	// For OTYPER, set mode 0 (push-pull)
	registerBitClear(REG_GPIO_A_OTYPER, BIT_7);

	// For OSPEEDR, set mode 01 (Medium speed)
	registerBitSet(REG_GPIO_A_OSPEEDR, BIT_14);
	registerBitClear(REG_GPIO_A_OSPEEDR, BIT_15);

	// For PUPDR, set mode 00 (no push-pull)
	registerBitClear(REG_GPIO_A_PUPDR, (BIT_14 | BIT_15));

	// For AFRL, set mode 0101 (AF5 for SPI1 MOSI)
	registerBitSet(REG_GPIO_A_AFRL, (BIT_28 | BIT_30));
	registerBitClear(REG_GPIO_A_AFRL, (BIT_29 | BIT_31));
	/* END registers set up PSI1 MOSI on PIN PA7 in PORT A */
}

void spiRegisterSetup(void) {

}
