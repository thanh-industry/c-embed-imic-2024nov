/*
 * register_defs.h
 *
 *  Created on: Nov 27, 2024
 *      Author: PC
 */

#ifndef INC_REGISTER_DEFS_H_
#define INC_REGISTER_DEFS_H_


#define GPIO_PORT_B      0x40020400U

#define GPIOxMODER_OFFSET   0x0

#define GPIOxMODER_OFFSET   0x0
#define GPIOx_OTYPER_OFFSET 0x4




#define GPIOB_MODER   ((uint32_t *)(GPIO_PORT_B + GPIOxMODER_OFFSET))
#define GPIOB_TYPER   ((uint32_t *)(GPIO_PORT_B + GPIOx_OTYPER_OFFSET))

#endif /* INC_REGISTER_DEFS_H_ */
