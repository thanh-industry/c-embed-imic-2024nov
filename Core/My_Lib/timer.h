#ifndef TIMER_H
#define TIMER_H

#include "my_lib.h"

/** 
  * The basic timers TIM6 and TIM7 consist of a 16-bit, feature include:
  * 16-bit auto-reload upcounter.
  * 16-bit programmable prescaler used to divide (also “on the fly”) the counter clock 
  * frequency by any factor between 1 and 65536.
  * Synchronization circuit to trigger the DAC.
  * Interrupt/DMA generation on the update event: counter overflow.

*/

void timer_basic_6_init(void);
uint16_t get_timer_basic_6(void);

#endif /* TIMER_H */
