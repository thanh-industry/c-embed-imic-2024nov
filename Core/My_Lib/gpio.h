#ifndef _GPIO_H_
#define _GPIO_H_

//#include "register_defs.h"
//#include "register_helpers.h"
//#include "stm32f4xx_hal.h"
#include "my_lib.h"

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
void gpio_init(void);
void gpio_write(uint32_t pin, uint32_t value);
uint32_t gpio_read(uint32_t pin);
void gpio_toggle(uint32_t pin);

#endif /* _GPIO_H_ */
