/*
 * register_definition.h
 *
 *  Created on: Nov 29, 2024
 *      Author: daoch
 */

#ifndef INC_REGISTERS_DEFS_H_
#define INC_REGISTERS_DEFS_H_

#include <stdint.h>

// Register base address of RCC (Reset and Clock Control register)
#define RCC_BASE				0x40023800
// Register base address of GPIO A
#define GPIO_A_BASE				0x40020000
// Register base address of GPIO D
#define GPIO_D_BASE 			0x40020C00
// Register base address of GPIO H
#define GPIO_H_BASE				0x40021C00

/*
 * Each general-purpose I/O port has:
 * 4 32-bit configuration registers (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR)
 * 2 32-bit data registers (GPIOx_IDR and GPIOx_ODR)
 * 1 32-bit set/reset register (GPIOx_BSRR)
 * 1 32-bit locking register (GPIOx_LCKR)
 * 2 32-bit alternate function selection register (GPIOx_AFRH, GPIOx_AFRL)
 * */

/* Register offset BEGIN */

// RCC AHB1 peripheral clock enable register offset
#define RCC_AHB1ENR_OFFSET		0x30

// 4 GPIOx configuration registers offset
#define GPIOx_MODER_OFFSET		0x00
#define GPIOx_OTYPER_OFFSET		0x04
#define GPIOx_OSPEEDR_OFFSET	0x08
#define GPIOx_PUPDR_OFFSET		0x0C

// 2 GPIOx data registers offset
#define GPIOx_IDR_OFFSET		0x10
#define GPIOx_ODR_OFFSET		0x14

// 1 GPIOx set/reset register offset
#define GPIOx_BSRR_OFFSET		0x18

// 1 GPIOx locking register offset
#define GPIOx_LCKR_OFFSET		0x1C

// 2 GPIOx alternate function selection register offset
#define GPIOx_AFRL_OFFSET		0x20
#define GPIOx_AFRH_OFFSET		0x24

/* Register offset END */




// RCC AHB1 peripheral reset register
#define RCC_AHB1RSTR			((uint32_t *)(RCC_BASE + RCC_AHB1RSTR_OFFSET))

// RCC AHB1 peripheral clock enable register
#define RCC_AHB1ENR				((uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))

/* Register port A define BEGIN */

// 4 configuration registers
#define GPIO_A_MODER			((uint32_t *)(GPIO_A_BASE + GPIOx_MODER_OFFSET))
#define GPIO_A_OTYPER			((uint32_t *)(GPIO_A_BASE + GPIOx_OTYPER_OFFSET))
#define GPIO_A_OSPEEDR			((uint32_t *)(GPIO_A_BASE + GPIOx_OSPEEDR_OFFSET))
#define GPIO_A_PUPDR			((uint32_t *)(GPIO_A_BASE + GPIOx_PUPDR_OFFSET))

// 2 data registers
#define GPIO_A_IDR				((uint32_t *)(GPIO_A_BASE + GPIOx_IDR_OFFSET))
#define GPIO_A_ODR				((uint32_t *)(GPIO_A_BASE + GPIOx_ODR_OFFSET))

// 1 set/reset register
#define GPIO_A_BSRR				((uint32_t *)(GPIO_A_BASE + GPIOx_BSRR_OFFSET))

// 1 locking register
#define GPIO_A_LCKR				((uint32_t *)(GPIO_A_BASE + GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define GPIO_A_AFRL				((uint32_t *)(GPIO_A_BASE + GPIOx_AFRL_OFFSET))
#define GPIO_A_AFRH				((uint32_t *)(GPIO_A_BASE + GPIOx_AFRH_OFFSET))

/* Register port A define END */

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

/* Register port H define BEGIN */

// 4 configuration registers
#define GPIO_H_MODER			((uint32_t *)(GPIO_H_BASE + GPIOx_MODER_OFFSET))
#define GPIO_H_OTYPER			((uint32_t *)(GPIO_H_BASE + GPIOx_OTYPER_OFFSET))
#define GPIO_H_OSPEEDR			((uint32_t *)(GPIO_H_BASE + GPIOx_OSPEEDR_OFFSET))
#define GPIO_H_PUPDR			((uint32_t *)(GPIO_H_BASE + GPIOx_PUPDR_OFFSET))

// 2 data registers
#define GPIO_H_IDR				((uint32_t *)(GPIO_H_BASE + GPIOx_IDR_OFFSET))
#define GPIO_H_ODR				((uint32_t *)(GPIO_H_BASE + GPIOx_ODR_OFFSET))

// 1 set/reset register
#define GPIO_H_BSRR				((uint32_t *)(GPIO_H_BASE + GPIOx_BSRR_OFFSET))

// 1 locking register
#define GPIO_H_LCKR				((uint32_t *)(GPIO_H_BASE + GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define GPIO_H_AFRL				((uint32_t *)(GPIO_H_BASE + GPIOx_AFRL_OFFSET))
#define GPIO_H_AFRH				((uint32_t *)(GPIO_H_BASE + GPIOx_AFRH_OFFSET))

/* Register port H define END */

#endif /* INC_REGISTERS_DEFS_H_ */
