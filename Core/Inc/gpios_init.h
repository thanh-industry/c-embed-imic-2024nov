/*
 * registers_init.h
 *
 *  Created on: Nov 30, 2024
 *      Author: daoch
 */

#ifndef INC_GPIOS_INIT_H_
#define INC_GPIOS_INIT_H_

#define LED_GREEN 	BIT_12
#define LED_ORANGE	BIT_13
#define LED_RED 	BIT_14
#define LED_BLUE 	BIT_15
#define LOCK_KEY	BIT_16

void gpiosInit(void);

void gpioRegisterSetup(void);

#endif /* INC_GPIOS_INIT_H_ */
