/*
 * registers_init.c
 *
 *  Created on: Nov 30, 2024
 *      Author: daoch
 */

#include "registers_tools.h"
#include "registers_defs.h"
#include "gpios_init.h"
#include "led_tools.h"

void gpiosInit(void) {
	// Enable clock in AHB1 peripheral for using PORT A, D, H
	registerBitSet(RCC_AHB1ENR, BIT_0 | BIT_3 | BIT_7);

	/* START registers set up for for PIN 12, 13, 14, 15 in PORT A */
	/* END registers set up for for PIN 12, 13, 14, 15 in PORT A */

	/* START registers set up for for PIN 12, 13, 14, 15 in PORT D */

	// For MODER, set mode 01 (General purpose output mode)
	registerBitSet(GPIO_D_MODER, (BIT_24 | BIT_26 | BIT_28 | BIT_30));
	registerBitClear(GPIO_D_MODER, (BIT_25 | BIT_27 | BIT_29 | BIT_31));

	// For OTYPER, using mode 0: Output push-pull
	registerBitClear(GPIO_D_OTYPER, LED_BLUE | LED_RED | LED_GREEN | LED_ORANGE);

	// For OSPEEDR, using mode 00: Low speed
	registerBitClear(GPIO_D_OSPEEDR, (BIT_24 | BIT_25 | BIT_26 | BIT_27 | BIT_28 | BIT_29 | BIT_30 | BIT_31));

	// For PUPDR, using mode 00: No Pull-up/ Pull-down
	registerBitClear(GPIO_D_PUPDR, (BIT_24 | BIT_25 | BIT_26 | BIT_27 | BIT_28 | BIT_29 | BIT_30 | BIT_31));

	/*
	 * For IDR, no input data
	 * Using BSRR instead of ODR for more safer and easier
	 * For AFRL and AFRH, no alternate function used, keep at AF0 (0000) at all pins
	 * */

	/*
	 * LCKR is used to lock the configuration of that PORT
	 * LCKR followed this sequence to enable LOCK:
	 *
	 * WR LCKR = (LCKR[16] = '1') + LCKR[15:0]
	 * WR LCKR = (LCKR[16] = '0') + LCKR[15:0]
	 * WR LCKR = (LCKR[16] = '1') + LCKR[15:0]
	 * RD LCKR
	 * RD (LCKR[16] = ‘1’) Optional, only for checking
	 *
	 * each LCKR[i] = 1 is enabling lock in corresponding pin of that port
	 * the LCKR[15:0] must not be changed while in locking sequence
	 * any error in sequence aborts LOCK
	 * After the first lock sequence on any bit, any read to LCKK (LCKR[16]) bit return '1' until next reset
	 * */

	 //start the lock sequence for
	 registerBitSet(GPIO_D_LCKR, (LOCK_KEY | LED_BLUE | LED_RED | LED_GREEN | LED_ORANGE));
	 registerBitClear(GPIO_D_LCKR, (LED_BLUE | LED_RED | LED_GREEN | LED_ORANGE));
	 registerBitSet(GPIO_D_LCKR, LOCK_KEY | LED_BLUE | LED_RED | LED_GREEN | LED_ORANGE);
	 uint32_t value = registerRead(GPIO_D_LCKR);

	 // Check
	 if (value == (LOCK_KEY)) {
		  ledBlink(LED_ORANGE, 200);
	 }


	 /* END registers set up for for PIN 12, 13, 14, 15 in PORT D */

	 /* START registers set up for for PIN 12, 13, 14, 15 in PORT H */
	 /* END registers set up for for PIN 12, 13, 14, 15 in PORT H */
}
