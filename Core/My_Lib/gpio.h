#ifndef _GPIO_H_
#define _GPIO_H_

#include "my_lib.h"

/**
  * Each general-purpose I/O port has:
  * four 32-bit configuration registers (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR and GPIOx_PUPDR) 
  * two 32-bit data registers (GPIOx_IDR and GPIOx_ODR)
  * a 32-bit set/reset register (GPIOx_BSRR)
  * a 32-bit locking register (GPIOx_LCKR)
  * two 32-bit alternate function selection register (GPIOx_AFRH and GPIOx_AFRL)
**/

#define INPUT 0U
#define OUTPUT 1U
#define ALTER_FUNC 2U
#define ANALOG 3U

#define GPIO_0  0
#define GPIO_1  1
#define GPIO_2  2
#define GPIO_3  3
#define GPIO_4  4
#define GPIO_5  5
#define GPIO_6  6
#define GPIO_7  7
#define GPIO_8  8
#define GPIO_9  9
#define GPIO_10 10
#define GPIO_11 11
#define GPIO_12 12
#define GPIO_13 13
#define GPIO_14 14
#define GPIO_15 15

#define GPIO_NUMBER 16

enum{
	GPIO_OFF,
	GPIO_ON
};

// prototype function
void gpio_mode(uint16_t pin, uint8_t mode);
void gpio_init(void);
void gpio_write(uint16_t pin, uint8_t value);
uint16_t gpio_read(uint16_t pin);
void gpio_toggle(uint16_t pin);
uint8_t gpio_is_pin(uint16_t pin);

#endif /* _GPIO_H_ */
