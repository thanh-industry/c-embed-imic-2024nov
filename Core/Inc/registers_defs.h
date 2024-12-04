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
#define REG_RCC_BASE				0x40023800
// Register base address of SYSCFG (System Configuration register)
#define REG_SYSCFG_BASE				0x40013800
// Register base address of EXTI (External Interrupt register)
#define REG_EXTI_BASE				0x40013C00
// Register base address of NVIC (Nested vectored interrupt controller register)
#define REG_NVIC_BASE				0xE000E100


// Register base address of GPIO A
#define REG_GPIO_A_BASE				0x40020000
// Register base address of GPIO D
#define REG_GPIO_D_BASE 			0x40020C00
// Register base address of GPIO H
#define REG_GPIO_H_BASE				0x40021C00

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
#define REG_RCC_AHB1ENR_OFFSET		0x30

// RCC APB2 peripheral clock enable register offset
#define REG_RCC_APB2ENR_OFFSET		0x44

// SYSCFG external interrupt configuration register 1 offset
#define REG_SYSCFG_EXTICR1_OFFSET	0x08

// EXTI Interrupt mask register offset
#define REG_EXTI_IMR_OFFSET			0x00

// EXTI Rising trigger selection register offset
#define REG_EXTI_RTSR_OFFSET		0x08

// EXTI Falling trigger selection register offset
#define REG_EXTI_FTSR_OFFSET		0x0C

// EXTI Pending register offset
#define REG_EXTI_PR_OFFSET			0x14

// NVIC Interrupt set-enable register 0 offset
#define REG_NVIC_ISER0_OFFSET		0x100

// NVIC Interrupt clear-pending register 0 offset
#define REG_NVIC_ICPR0_OFFSET		0x280

// 4 GPIOx configuration registers offset
#define REG_GPIOx_MODER_OFFSET		0x00
#define REG_GPIOx_OTYPER_OFFSET		0x04
#define REG_GPIOx_OSPEEDR_OFFSET	0x08
#define REG_GPIOx_PUPDR_OFFSET		0x0C

// 2 GPIOx data registers offset
#define REG_GPIOx_IDR_OFFSET		0x10
#define REG_GPIOx_ODR_OFFSET		0x14

// 1 GPIOx set/reset register offset
#define REG_GPIOx_BSRR_OFFSET		0x18

// 1 GPIOx locking register offset
#define REG_GPIOx_LCKR_OFFSET		0x1C

// 2 GPIOx alternate function selection register offset
#define REG_GPIOx_AFRL_OFFSET		0x20
#define REG_GPIOx_AFRH_OFFSET		0x24

/* Register offset END */




// RCC AHB1 peripheral reset register
//#define RCC_AHB1RSTR			((uint32_t *)(RCC_BASE + RCC_AHB1RSTR_OFFSET))

// RCC AHB1 peripheral clock enable register
#define REG_RCC_AHB1ENR				((uint32_t *)(REG_RCC_BASE + REG_RCC_AHB1ENR_OFFSET))

// RCC APB1 peripheral clock enable register
#define REG_RCC_APB2ENR				((uint32_t *)(REG_RCC_BASE + REG_RCC_APB2ENR_OFFSET))

// SYSCFG external interrupt configuration register 1
#define REG_SYSCFG_EXTICR1			((uint32_t *)(REG_SYSCFG_BASE + REG_SYSCFG_EXTICR1_OFFSET))

// EXTI Interrupt mask register
#define REG_EXTI_IMR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_IMR_OFFSET))

// EXTI Rising trigger selection register
#define REG_EXTI_RTSR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_RTSR_OFFSET))

// EXTI Falling trigger selection register
#define REG_EXTI_FTSR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_FTSR_OFFSET))

// EXTI Pending register
#define REG_EXTI_PR					((uint32_t *)(REG_EXTI_BASE + REG_EXTI_PR_OFFSET))

// NVIC Interrupt set-enable register 0
#define REG_NVIC_ISER0				((uint32_t *)(REG_NVIC_BASE + REG_NVIC_ISER0_OFFSET))

// NVIC Interrupt clear-pending register 0
#define REG_NVIC_ICPR0				((uint32_t *)(REG_NVIC_BASE + REG_NVIC_ICPR0_OFFSET))

/* Register port A define BEGIN */

// 4 configuration registers
#define REG_GPIO_A_MODER			((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_MODER_OFFSET))
#define REG_GPIO_A_OTYPER			((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_OTYPER_OFFSET))
#define REG_GPIO_A_OSPEEDR			((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_OSPEEDR_OFFSET))
#define REG_GPIO_A_PUPDR			((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_PUPDR_OFFSET))

// 2 data registers
#define REG_GPIO_A_IDR				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_IDR_OFFSET))
#define REG_GPIO_A_ODR				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_ODR_OFFSET))

// 1 set/reset register
#define REG_GPIO_A_BSRR				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_BSRR_OFFSET))

// 1 locking register
#define REG_GPIO_A_LCKR				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define REG_GPIO_A_AFRL				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_AFRL_OFFSET))
#define REG_GPIO_A_AFRH				((uint32_t *)(REG_GPIO_A_BASE + REG_GPIOx_AFRH_OFFSET))

/* Register port A define END */

/* Register port D define BEGIN */

// 4 configuration registers
#define REG_GPIO_D_MODER			((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_MODER_OFFSET))
#define REG_GPIO_D_OTYPER			((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_OTYPER_OFFSET))
#define REG_GPIO_D_OSPEEDR			((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_OSPEEDR_OFFSET))
#define REG_GPIO_D_PUPDR			((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_PUPDR_OFFSET))

// 2 data registers
#define REG_GPIO_D_IDR				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_IDR_OFFSET))
#define REG_GPIO_D_ODR				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_ODR_OFFSET))

// 1 set/reset register
#define REG_GPIO_D_BSRR				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_BSRR_OFFSET))

// 1 locking register
#define REG_GPIO_D_LCKR				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define REG_GPIO_D_AFRL				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_AFRL_OFFSET))
#define REG_GPIO_D_AFRH				((uint32_t *)(REG_GPIO_D_BASE + REG_GPIOx_AFRH_OFFSET))

/* Register port D define END */

/* Register port H define BEGIN */

// 4 configuration registers
#define REG_GPIO_H_MODER			((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_MODER_OFFSET))
#define REG_GPIO_H_OTYPER			((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_OTYPER_OFFSET))
#define REG_GPIO_H_OSPEEDR			((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_OSPEEDR_OFFSET))
#define REG_GPIO_H_PUPDR			((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_PUPDR_OFFSET))

// 2 data registers
#define REG_GPIO_H_IDR				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_IDR_OFFSET))
#define REG_GPIO_H_ODR				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_ODR_OFFSET))

// 1 set/reset register
#define REG_GPIO_H_BSRR				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_BSRR_OFFSET))

// 1 locking register
#define REG_GPIO_H_LCKR				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_LCKR_OFFSET))

// 2 alternate function selection register
#define REG_GPIO_H_AFRL				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_AFRL_OFFSET))
#define REG_GPIO_H_AFRH				((uint32_t *)(REG_GPIO_H_BASE + REG_GPIOx_AFRH_OFFSET))

/* Register port H define END */

#endif /* INC_REGISTERS_DEFS_H_ */
