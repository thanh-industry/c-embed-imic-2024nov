/*
 * register_definition.h
 *
 *  Created on: Nov 29, 2024
 *      Author: daoch
 */

#ifndef INC_REGISTERS_DEFS_H_
#define INC_REGISTERS_DEFS_H_

#include <stdint.h>

// Register base address of GPIO D
#define GPIO_D_BASE 			0x40020C00

/*
 * Each general-purpose I/O port has:
 * 4 32-bit configuration registers (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR)
 * 2 32-bit data registers (GPIOx_IDR and GPIOx_ODR)
 * 1 32-bit set/reset register (GPIOx_BSRR)
 * 1 32-bit locking register (GPIOx_LCKR)
 * 2 32-bit alternate function selection register (GPIOx_AFRH, GPIOx_AFRL)
 * */

/* Register offset BEGIN */

// 4 configuration registers offset
#define GPIOx_MODER_OFFSET		0x00
#define GPIOx_OTYPER_OFFSET		0x04
#define GPIOx_OSPEEDR_OFFSET	0x08
#define GPIOx_PUPDR_OFFSET		0x0C

// 2 data registers offset
#define GPIOx_IDR_OFFSET		0x10
#define GPIOx_ODR_OFFSET		0x14

// 1 set/reset register offset
#define GPIOx_BSRR_OFFSET		0x18

// 1 locking register offset
#define GPIOx_LCKR_OFFSET		0x1C

// 2 alternate function selection register offset
#define GPIOx_AFRL_OFFSET		0x20
#define GPIOx_AFRH_OFFSET		0x24

/* Register offset END */

/* Register port D define BEGIN */

// 4 configuration registers
#define GPIO_D_MODER			((uint32_t *)(GPIO_D_BASE + GPIOx_MODER_OFFSET))
#define GPIO_D_OTYPER			((uint32_t *)(GPIO_D_BASE + GPIOx_OTYPER_OFFSET))
#define GPIO_D_OSPEEDR			((uint32_t *)(GPIO_D_BASE + GPIOx_OSPEEDR_OFFSET))
#define GPIO_D_PUPDR			((uint32_t *)(GPIO_D_BASE + GPIOx_PUPDR_OFFSET))

// 2 data registers
#define GPIO_D_IDR				((uint32_t *)(GPIO_D_BASE + GPIOx_IDR_OFFSET))
#define GPIO_D_ODR				((uint32_t *)(GPIO_D_BASE + GPIOx_ODR_OFFSET))

// 1 set/reset register
#define GPIO_D_BSRR				((uint32_t *)(GPIO_D_BASE + GPIOx_BSRR_OFFSET))

// 1 locking register
#define GPIO_D_LCKR				((uint32_t *)(GPIO_D_BASE + GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define GPIO_D_AFRL				((uint32_t *)(GPIO_D_BASE + GPIOx_AFRL_OFFSET))
#define GPIO_D_AFRH				((uint32_t *)(GPIO_D_BASE + GPIOx_AFRH_OFFSET))

/* Register port D define END */

#endif /* INC_REGISTERS_DEFS_H_ */
