/*
 * LED_tools.h
 *
 *  Created on: Nov 30, 2024
 *      Author: daoch
 */

#ifndef INC_LED_TOOLS_H_
#define INC_LED_TOOLS_H_

#include "stdint.h"
#include <stdbool.h>

void ledSet(uint32_t led, bool state);
void ledBlink(uint32_t led, uint32_t delayms);

#endif /* INC_LED_TOOLS_H_ */
