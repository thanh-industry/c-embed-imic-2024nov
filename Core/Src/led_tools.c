/*
 * LED_tools.c
 *
 *  Created on: Nov 30, 2024
 *      Author: daoch
 */

#include "stm32f4xx_hal.h"
#include "registers_tools.h"
#include "registers_defs.h"
#include "led_tools.h"
#include <stdbool.h>

bool on = true;
bool off = false;

void ledSet(uint32_t led, bool state) {
	if (state) registerBitSet(GPIO_D_BSRR, led);
	else registerBitSet(GPIO_D_BSRR, led << 16);
}

void ledBlink(uint32_t led, uint32_t delayms) {
	ledSet(led, on);
	HAL_Delay(delayms);
	ledSet(led, off);
}
