/*
 * exti.c
 *
 *  Created on: Dec 8, 2024
 *      Author: Huy
 */
#include "led.h"

void led_blink(uint16_t pin, uint16_t fre){
	gpio_toggle(pin);
	HAL_Delay(fre);
}

void led_blink_all(uint16_t fre){
	for(uint8_t i =0; i < 4; i++){
		gpio_toggle(GPIO_12 + i);
	}
	HAL_Delay(fre);
}

void led_chase(uint8_t direct, uint16_t fre){
	switch(direct){
		case LED_FORWARD:
				for(uint8_t i =0; i < 4; i++){
		gpio_toggle(GPIO_12 + i);
		HAL_Delay(fre);}
					break;
		case LED_REVERSE:
				gpio_toggle(GPIO_12);
				HAL_Delay(fre);
				for(uint8_t i =0; i < 3; i++){
				gpio_toggle(GPIO_15 - i);
				HAL_Delay(fre);}
					break;
	}
	}

