/*
 * exti.h
 *
 *  Created on: Dec 8, 2024
 *      Author: Huy
 */

#ifndef LED_H
#define LED_H

#include "my_lib.h"

#define LED_REVERSE 0
#define LED_FORWARD 1

/* prtotype function */
void led_blink(uint16_t pin, uint16_t fre);
void led_blink_all(uint16_t fre);
void led_chase(uint8_t direct, uint16_t fre);

#endif /* LED_H */

