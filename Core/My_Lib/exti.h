/*
 * exti.h
 *
 *  Created on: Dec 8, 2024
 *      Author: Huy
 */

#ifndef MY_LIB_EXTI_H
#define MY_LIB_EXTI_H

/**
  * The main features of the EXTI controller are the following:
  * independent trigger and mask on each interrupt/event line
  * dedicated status bit for each interrupt line
  * generation of up to 23 software event/interrupt requests
  * detection of external signals with a pulse width lower than the APB2 clock period
**/

#include "my_lib.h"

/* all mode exti */
#define RISING_MODE 0
#define FALLING_MODE 1
#define RISING_FALLING_MODE 2


/* prototype fuction */
void exti_init(void);
void exti_attach_interrupt(uint32_t pin, uint8_t mode);
void exti_attach_event(uint32_t pin, uint8_t mode);
void EXTI0_IRQHandler(void);
void exti_callback(void);
#endif /* MY_LIB_EXTI_H */
