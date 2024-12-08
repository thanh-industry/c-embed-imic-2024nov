/*
 * register_defs.h
 *
 *  Created on: Dec 1, 2024
 *      Author: Huy
 */

#ifndef INC_REGISTER_DEFS_H_
#define INC_REGISTER_DEFS_H_

//---------------------------------- Peripheral memory map----------------------------------//
#define PERIPHERAL_ADDR 0x40000000U
#define AHB1PERIPH_ADDR (PERIPHERAL_ADDR + 0x00020000U)
#define GPIO_EXTI_ADDR 0x40013C00U

#define GPIO_PORT_A_OFFSET 0x0U
#define GPIO_PORT_D_OFFSET 0xC00U

/**
  * Each general-purpose I/O port has:
  * four 32-bit configuration registers (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR and GPIOx_PUPDR) 
  * two 32-bit data registers (GPIOx_IDR and GPIOx_ODR)
  * a 32-bit set/reset register (GPIOx_BSRR)
  * a 32-bit locking register (GPIOx_LCKR)
  * two 32-bit alternate function selection register (GPIOx_AFRH and GPIOx_AFRL)
**/

//----------------------------------AHB1 Peripheral----------------------------------//

#define GPIO_PORT_A (AHB1PERIPH_ADDR + GPIO_PORT_A_OFFSET)
#define GPIO_PORT_D (AHB1PERIPH_ADDR + GPIO_PORT_D_OFFSET)

//----------------------------------Register of GPIO Offset----------------------------------//

/**
  * I/O port control registers:
  * The GPIOx_MODER register is used to select the I/O direction (input, output, AF, analog)
  * The GPIOx_OTYPER registers is used to select the output type (push-pull or open-drain)
  * The GPIOx_OSPEEDR register is used to select the speed
  * The GPIOx_PUPDR register is used to select the pull-up/pull-down whatever the I/O direction
**/

/**
  * MODERy[1:0]: Port x configuration bits (y = 0..15)
  * 00: Input (reset state)
  * 01: General purpose output mode
  * 10: Alternate function mode
  * 11: Analog mode
**/
#define GPIOx_MODER_OFFSET 0x0

/**
  * OTy: Port x configuration bits (y = 0..15)
  * 0: Output push-pull (reset state)
  * 1: Output open-drain
  * Bits 31:16 Reserved, must be kept at reset value
**/
#define GPIOx_OTYPER_OFFSET 0x4

/**
  * OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
  * 00: Low speed
  * 01: Medium speed
  * 10: High speed
  * 11: Very high speed
**/
#define GPIOx_OSPEEDR_OFFSET 0x8


/**
  * PUPDRy[1:0]: Port x configuration bits (y = 0..15)
  * These bits are written by software to configure the I/O pull-up or pull-down
  * 00: No pull-up, pull-down
  * 01: Pull-up
  * 10: Pull-down
  * 11: Reserved
**/
#define GPIOx_PUPDR_OFFSET 0x0C

/**
  * I/O port data registers:
  * Each GPIO has two 16-bit memory-mapped data registers: GPIOx_IDR and GPIOx_ODR
  * GPIOx_ODR stores the data to be output, read/write accessible
  * The data input through the I/O are stored into the input data register (GPIOx_IDR), a read-only register
**/

/**
  * Bits 31:16 Reserved, must be kept at reset value
  * Bits 15:0 IDRy: Port input data (y = 0..15)
  * These bits are read-only and can be accessed in word mode only. They contain the input 
  * value of the corresponding I/O port.
**/
#define GPIOx_IDR_OFFSET 0x10

/**
  * Bits 31:16 Reserved, must be kept at reset value
  * Bits 15:0 ODRy: Port output data (y = 0..15)
  * These bits can be read and written by software.
  * Note: For atomic bit set/reset, the ODR bits can be individually set and reset by writing to the 
  * GPIOx_BSRR register (x = A..I/J/K).
**/
#define GPIOx_ODR_OFFSET 0x14

/**
  * I/O data bitwise handling
  * The bit set reset register is a 32-bit register which allows the application to 
  * set and reset each individual bit in the output data register. The bit set reset 
  * register has twice the size of GPIOx_ODR. To each bit in GPIOx_ODR, correspond two control 
  * bits in GPIOx_BSRR: BSRR(i) and BSRR(i+SIZE). When written to 1, bit BSRR(i) sets the 
  * corresponding ODR(i) bit. When written to 1, bit BSRR(i+SIZE) resets the ODR(i) 
  * corresponding bit.
**/
#define GPIOx_BSRR_OFFSET 0x18

/**
  * GPIO locking mechanism
  * It is possible to freeze the GPIO control registers by applying a specific write sequence 
  * to the GPIOx_LCKR register. The frozen registers are GPIOx_MODER, GPIOx_OTYPER, 
  * GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_AFRL and GPIOx_AFRH.
**/
#define GPIOx_LCKR_OFFSET 0x1C

/**
  * I/O alternate function input/output
  * Two registers are provided to select one out of the sixteen alternate function 
  * inputs/outputs available for each I/O
  * GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_AFRL and GPIOx_AFRH.
**/
#define GPIOx_AFRL_OFFSET 0x20
#define GPIOx_AFRH_OFFSET 0x24

//----------------------------------Register of EXTI Offset----------------------------------//

/**
  * Interupt mask register
  * Bit 31:23 reserved
  * Bit 22:0 MRx: interupt mask on line x
  *   0: Interrupt request from line x is masked
  *   1: Interrupt request form line x is not masked
**/
#define EXTI_IMR_OFFSET 0x0U

/**
  * Event mask register
  * Bit 31:23 reserved
  * Bit 22:0 MRx: interupt mask on line x
  *   0: Interrupt request from line x is masked
  *   1: Interrupt request form line x is not masked
**/
#define EXTI_EMR_OFFSET 0x04U

/**
  * Rising trigger selection register
  * Bit 31:23 reserved
  * Bit 22:0: TRx: Rising trigger event configuration bit of line x
  *   0: Rising trigger disabled (for Event and Interrupt) for input line
  *   1: Rising trigger enabled (for Event and Interrupt) for input line
**/
#define EXTI_RTSR_OFFSET 0x08U

/**
  * Falling trigger selection register
  * Bit 31:23 reserved
  * Bit 22:0: TRx: Rising trigger event configuration bit of line x
  *   0: Falling trigger disabled (for Event and Interrupt) for input line
  *   1: Falling trigger enabled (for Event and Interrupt) for input line
**/
#define EXTI_FTSR_OFFSET 0x0CU

/**
  * Software interrupt event register
  * Bit 31:23 reserved
  * Bit 22:0: SWIERx: Software Interrupt on line x
  *   0: Falling trigger disabled (for Event and Interrupt) for input line
  *   1: Falling trigger enabled (for Event and Interrupt) for input line
**/
#define EXTI_SWIER_OFFSET 0x10

/**
  * Pending register
  * Bit 31:23 reserved
  * Bit 22:0: PRx: Pending bit
  *   0: No trigger request occurred
  *   1: Selected trigger request occurred
**/
#define EXTI_PR_OFFSET 0x14
//----------------------------------Register of GPIO port A----------------------------------//

#define GPIO_A_MODER ((uint32_t *)(GPIO_PORT_A + GPIOx_MODER_OFFSET))
#define GPIO_A_OTYPER ((uint32_t *)(GPIO_PORT_A + GPIOx_OTYPER_OFFSET))
#define GPIO_A_OSPEEDR ((uint32_t *)(GPIO_PORT_A + GPIOx_OSPEEDR_OFFSET))
#define GPIO_A_PUPDR ((uint32_t *)(GPIO_PORT_A + GPIOx_PUPDR_OFFSET))
#define GPIO_A_IDR ((uint32_t *)(GPIO_PORT_A + GPIOx_IDR_OFFSET))
#define GPIO_A_ODR ((uint32_t *)(GPIO_PORT_A + GPIOx_ODR_OFFSET))
#define GPIO_A_BSRR ((uint32_t *)(GPIO_PORT_A + GPIOx_BSRR_OFFSET))
#define GPIO_A_LCKR ((uint32_t *)(GPIO_PORT_A + GPIOx_LCKR_OFFSET))
#define GPIO_A_AFRL ((uint32_t *)(GPIO_PORT_A + GPIOx_AFRL_OFFSET))
#define GPIO_A_AFRH ((uint32_t *)(GPIO_PORT_A + GPIOx_AFRH_OFFSET))

//----------------------------------Register of GPIO port D----------------------------------//

#define GPIO_D_MODER ((uint32_t *)(GPIO_PORT_D + GPIOx_MODER_OFFSET))
#define GPIO_D_OTYPER ((uint32_t *)(GPIO_PORT_D + GPIOx_OTYPER_OFFSET))
#define GPIO_D_OSPEEDR ((uint32_t *)(GPIO_PORT_D + GPIOx_OSPEEDR_OFFSET))
#define GPIO_D_PUPDR ((uint32_t *)(GPIO_PORT_D + GPIOx_PUPDR_OFFSET))
#define GPIO_D_IDR ((uint32_t *)(GPIO_PORT_D + GPIOx_IDR_OFFSET))
#define GPIO_D_ODR ((uint32_t *)(GPIO_PORT_D + GPIOx_ODR_OFFSET))
#define GPIO_D_BSRR ((uint32_t *)(GPIO_PORT_D + GPIOx_BSRR_OFFSET))
#define GPIO_D_LCKR ((uint32_t *)(GPIO_PORT_D + GPIOx_LCKR_OFFSET))
#define GPIO_D_AFRL ((uint32_t *)(GPIO_PORT_D + GPIOx_AFRL_OFFSET))
#define GPIO_D_AFRH ((uint32_t *)(GPIO_PORT_D + GPIOx_AFRH_OFFSET))

//----------------------------------EXTI Register----------------------------------//
#define EXTI_IMR ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_IMR_OFFSET))
#define EXTI_EMR ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_EMR_OFFSET))
#define EXTI_RTSR ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_RTSR_OFFSET))
#define EXTI_FTSR ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_FTSR_OFFSET))
#define EXTI_SWIER ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_SWIER_OFFSET))
#define EXTI_PR ((uint32_t *)(GPIO_EXTI_ADDR + EXTI_PR_OFFSET))

#endif /* INC_REGISTER_DEFS_H_ */

