/*
 * register_defs.h
 *
 *  Created on: Dec 1, 2024
 *      Author: Huy
 */

#ifndef INC_REGISTER_DEFS_H_
#define INC_REGISTER_DEFS_H_
//----------------------------------Register of GPIO----------------------------------//
#define GPIO_PORT_D 0x40020C00U

//----------------------------------Register of GPIO Offset----------------------------------//
#define GPIOx_MODER_OFFSET 0x0
#define GPIOx_OTYPER_OFFSET 0x4
#define GPIOx_OSPEEDR_OFFSET 0x8
#define GPIOx_PUPDR_OFFSET 0x0C
#define GPIOx_IDR_OFFSET 0x10
#define GPIOx_ODR_OFFSET 0x14
#define GPIOx_BSRR_OFFSET 0x18
#define GPIOx_LCKR_OFFSET 0x1C
#define GPIOx_AFRL_OFFSET 0x20
#define GPIOx_AFRH_OFFSET 0x24

//----------------------------------Register of GPIO port D----------------------------------//
#define GPIOD_MODER ((uint32_t *)(GPIO_PORT_D + GPIOx_MODER_OFFSET))
#define GPIOD_OTYPER ((uint32_t *)(GPIO_PORT_D + GPIOx_OTYPER_OFFSET))
#define GPIOD_OSPEEDR ((uint32_t *)(GPIO_PORT_D + GPIOx_OSPEEDR_OFFSET))
#define GPIOD_PUPDR ((uint32_t *)(GPIO_PORT_D + GPIOx_PUPDR_OFFSET))
#define GPIOD_IDR ((uint32_t *)(GPIO_PORT_D + GPIOx_IDR_OFFSET))
#define GPIOD_ODR ((uint32_t *)(GPIO_PORT_D + GPIOx_ODR_OFFSET))
#define GPIOD_BSRR ((uint32_t *)(GPIO_PORT_D + GPIOx_BSRR_OFFSET))
#define GPIOD_LCKR ((uint32_t *)(GPIO_PORT_D + GPIOx_LCKR_OFFSET))
#define GPIOD_AFRL ((uint32_t *)(GPIO_PORT_D + GPIOx_AFRL_OFFSET))
#define GPIOD_AFRH ((uint32_t *)(GPIO_PORT_D + GPIOx_AFRH_OFFSET))

#endif /* INC_REGISTER_DEFS_H_ */
