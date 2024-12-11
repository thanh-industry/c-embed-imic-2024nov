/*
 * register_definition.h
 *
 *  Created on: Nov 29, 2024
 *      Author: daoch
 */

#ifndef INC_REGISTERS_DEFS_H_
#define INC_REGISTERS_DEFS_H_

#include <stdint.h>

/*-----------------------------------------CLOCK REG-----------------------------------------*/

/*--------------------BASE--------------------*/
#define REG_RCC_BASE				0x40023800													// Register base address of RCC (Reset and Clock Control register)
/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/
#define REG_RCC_AHB1ENR_OFFSET		0x30														// RCC AHB1 peripheral clock enable register offset
#define REG_RCC_APB1ENR_OFFSET		0x40														// RCC APB1 peripheral clock enable register offset
#define REG_RCC_APB2ENR_OFFSET		0x44														// RCC APB2 peripheral clock enable register offset
/*--------------------OFFSET--------------------*/



/*--------------------FINAL RCC CLOCK--------------------*/
#define REG_RCC_AHB1ENR				((uint32_t *)(REG_RCC_BASE + REG_RCC_AHB1ENR_OFFSET))		// RCC AHB1 peripheral clock enable register
#define REG_RCC_APB1ENR				((uint32_t *)(REG_RCC_BASE + REG_RCC_APB1ENR_OFFSET))		// RCC APB1 peripheral clock enable register
#define REG_RCC_APB2ENR				((uint32_t *)(REG_RCC_BASE + REG_RCC_APB2ENR_OFFSET))		// RCC APB2 peripheral clock enable register
/*--------------------FINAL RCC CLOCK--------------------*/
/*-----------------------------------------CLOCK REG-----------------------------------------*/



/*-----------------------------------------SYSTEM REG-----------------------------------------*/
/*--------------------BASE--------------------*/
#define REG_SYSCFG_BASE				0x40013800													// Register base address of SYSCFG (System Configuration register)
/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/
#define REG_SYSCFG_EXTICR1_OFFSET	0x08														// SYSCFG external interrupt configuration register 1 offset
/*--------------------OFFSET--------------------*/



/*--------------------FINAL--------------------*/
#define REG_SYSCFG_EXTICR1			((uint32_t *)(REG_SYSCFG_BASE + REG_SYSCFG_EXTICR1_OFFSET))	// SYSCFG external interrupt configuration register 1
/*--------------------FINAL--------------------*/
/*-----------------------------------------SYSTEM REG-----------------------------------------*/



/*-----------------------------------------NVIC REG-----------------------------------------*/
/*--------------------BASE--------------------*/
#define REG_NVIC_BASE				0xE000E100													// Register base address of NVIC (Nested vectored interrupt controller register)
/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/
#define REG_NVIC_ISER0_OFFSET		0x100														// NVIC Interrupt set-enable register 0 offset
#define REG_NVIC_ICPR0_OFFSET		0x280														// NVIC Interrupt clear-pending register 0 offset
/*--------------------OFFSET--------------------*/



/*--------------------FINAL--------------------*/
#define REG_NVIC_ISER0				((uint32_t *)(REG_NVIC_BASE + REG_NVIC_ISER0_OFFSET))		// NVIC Interrupt set-enable register 0
#define REG_NVIC_ICPR0				((uint32_t *)(REG_NVIC_BASE + REG_NVIC_ICPR0_OFFSET))		// NVIC Interrupt clear-pending register 0
/*--------------------FINAL--------------------*/
/*-----------------------------------------NVIC REG-----------------------------------------*/



/*-----------------------------------------EXTI REG-----------------------------------------*/
/*--------------------BASE--------------------*/
#define REG_EXTI_BASE				0x40013C00													// Register base address of EXTI (External Interrupt register)
/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/
#define REG_EXTI_IMR_OFFSET			0x00														// EXTI Interrupt mask register offset
#define REG_EXTI_RTSR_OFFSET		0x08														// EXTI Rising trigger selection register offset
#define REG_EXTI_FTSR_OFFSET		0x0C														// EXTI Falling trigger selection register offset
#define REG_EXTI_PR_OFFSET			0x14														// EXTI Pending register offset
/*--------------------OFFSET--------------------*/



/*--------------------FINAL--------------------*/
#define REG_EXTI_IMR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_IMR_OFFSET))			// EXTI Interrupt mask register
#define REG_EXTI_RTSR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_RTSR_OFFSET))		// EXTI Rising trigger selection register
#define REG_EXTI_FTSR				((uint32_t *)(REG_EXTI_BASE + REG_EXTI_FTSR_OFFSET))		// EXTI Falling trigger selection register
#define REG_EXTI_PR					((uint32_t *)(REG_EXTI_BASE + REG_EXTI_PR_OFFSET))			// EXTI Pending register
/*--------------------FINAL--------------------*/
/*-----------------------------------------EXTI REG-----------------------------------------*/



/*-----------------------------------------TIMER REG-----------------------------------------*/
/*--------------------BASE--------------------*/

/*----BASIC TIMER----*/
#define REG_TIM6_BASE				0x40001000													// Register base address of basic timer TIM6
#define REG_TIM7_BASE				0x40001400													// Register base address of basic timer TIM7
/*----BASIC TIMER----*/

/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/

/*----BASIC TIMER----*/
#define REG_TIM_BSC_CR1_OFFSET		0x00														// TIM6, TIM7 control register 1
#define REG_TIM_BSC_DIER_OFFSET		0x0C														// TIM6, TIM7 DMA/Interrupt enable register
#define REG_TIM_BSC_SR_OFFSET		0x10														// TIM6, TIM7 status register
#define REG_TIM_BSC_CNT_OFFSET		0x24														// TIM6, TIM7 counter register
#define REG_TIM_BSC_PSC_OFFSET		0x28														// TIM6, TIM7 pre-scaler register
#define REG_TIM_BSC_ARR_OFFSET		0x2C														// TIM6, TIM7 auto-reload register
/*----BASIC TIMER----*/

/*--------------------OFFSET--------------------*/



/*--------------------FINAL--------------------*/

/*------BASIC TIMER------*/

/*---TIM 6---*/
#define REG_TIM6_CR1				((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_CR1_OFFSET))
#define REG_TIM6_DIER				((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_DIER_OFFSET))
#define REG_TIM6_SR					((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_SR_OFFSET))
#define REG_TIM6_CNT				((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_CNT_OFFSET))
#define REG_TIM6_PSC				((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_PSC_OFFSET))
#define REG_TIM6_ARR				((uint32_t *)(REG_TIM6_BASE + REG_TIM_BSC_ARR_OFFSET))
/*---TIM 6---*/



/*---TIM 7---*/
#define REG_TIM7_CR1				((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_CR1_OFFSET))
#define REG_TIM7_DIER				((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_DIER_OFFSET))
#define REG_TIM7_SR					((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_SR_OFFSET))
#define REG_TIM7_CNT				((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_CNT_OFFSET))
#define REG_TIM7_PSC				((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_PSC_OFFSET))
#define REG_TIM7_ARR				((uint32_t *)(REG_TIM7_BASE + REG_TIM_BSC_ARR_OFFSET))
/*---TIM 7---*/
/*------BASIC TIMER------*/

/*--------------------FINAL--------------------*/
/*-----------------------------------------TIMER REG-----------------------------------------*/



/*-----------------------------------------GPIO REG-----------------------------------------*/

/*--------------------BASE--------------------*/
#define REG_GPIO_A_BASE				0x40020000													// Register base address of GPIO A
#define REG_GPIO_D_BASE 			0x40020C00													// Register base address of GPIO D
#define REG_GPIO_H_BASE				0x40021C00													// Register base address of GPIO H
/*--------------------BASE--------------------*/



/*--------------------OFFSET--------------------*/

/*
 * Each general-purpose I/O port has:
 * 4 32-bit configuration registers (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR)
 * 2 32-bit data registers (GPIOx_IDR and GPIOx_ODR)
 * 1 32-bit set/reset register (GPIOx_BSRR)
 * 1 32-bit locking register (GPIOx_LCKR)
 * 2 32-bit alternate function selection register (GPIOx_AFRH, GPIOx_AFRL)
 * */

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
/*--------------------OFFSET--------------------*/



/*--------------------FINAL GPIO PORT A--------------------*/

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
/*--------------------FINAL GPIO PORT A--------------------*/



/*--------------------FINAL GPIO PORT D--------------------*/

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
/*--------------------FINAL GPIO PORT D--------------------*/



/*--------------------FINAL GPIO PORT H--------------------*/

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

/*--------------------FINAL GPIO PORT H--------------------*/
/*-----------------------------------------GPIO REG-----------------------------------------*/



#endif /* INC_REGISTERS_DEFS_H_ */
