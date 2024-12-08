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

enum{
	GPIO_OFF,
	GPIO_ON
};

// prototype function
void gpio_init(void);
void gpio_write(uint32_t pin, uint32_t value);
uint32_t gpio_read(uint32_t pin);
#endif /* _GPIO_H_ */
