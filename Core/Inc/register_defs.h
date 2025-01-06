#ifndef INC_REGISTER_DEFS_H_
#define INC_REGISTER_DEFS_H_


#include <stdint.h>

#define REG_GPIO_PORT_D   0x40020C00                       //address base GPIOD
#define REG_GPIO_PORT_A   0x40020000                       //address base GPIOA
#define REG_GPIO_PORT_H   0x40021C00                       //address base GPIOH
#define REG_GPIO_PORT_C   0x40020800                       //address base GPIOC


#define REG_RCC_AHB1ENR_OFFSET      0X30     
#define REG_RCC_APB1ENR_OFFSET      0X40
#define REG_RCC_APB2ENR_OFFSET      0X44

#define REG_SYSCFG_EXTICR1_OFFSET   0X08
#define REG_EXTI_IMR_OFFSET         0X00
#define REG_EXTI_RTSR_OFFSET        0X08
#define REG_EXTI_FTSR_OFFSET        0X0C
#define REG_EXTI_PR_OFFSET          0X14
#define REG_NVIC_ISER0_OFFSET		    0x100
#define REG_NVIC_ICPR0_OFFSET		    0x280

#define REG_RCC_BASE                0X40023800             //address base RCC (Reset and Clock Control reigister)
#define REG_SYSCFG_BASE             0X40013800             //address base SYSCFG (System configuration register)-cau hinh he thong
#define REG_EXTI_BASE               0x40013C00             //address base EXTI (External Interrupt register)-dieu khien ngat ngoai
#define REG_NVIC_BASE				        0xE000E100             //address base NVIC (Nested Vector Interrupt Controller)-Khoi quan ly, dieu khien ngat

#define REG_TIM6_BASE               0x40001000							
#define REG_TIM7_BASE               0x40001400	
#define REG_TIM1_BASE               0x40010000	
#define REG_TIM8_BASE               0x40010400	


#define REG_RCC_AHB1ENR				      ((uint32_t *)(REG_RCC_BASE + REG_RCC_AHB1ENR_OFFSET))          //set register nay de kich hoat Clock cho PORTA,PORTD
#define REG_RCC_APB1ENR				      ((uint32_t *)(REG_RCC_BASE + REG_RCC_APB1ENR_OFFSET))          //set register nay kich hoat TIMER6,7
#define REG_RCC_APB2ENR				      ((uint32_t *)(REG_RCC_BASE + REG_RCC_APB2ENR_OFFSET))          //set register nay kich hoat SYSCFG 
#define REG_SYSCFG_EXTICR1		      ((uint32_t *)(REG_SYSCFG_BASE + REG_SYSCFG_EXTICR1_OFFSET))    //set register nay cau hinh EXTI dòng 0-3
#define REG_EXTI_IMR                ((uint32_t *)(REG_EXTI_BASE  +  REG_EXTI_IMR_OFFSET))          //set register nay mask dòng ngat
#define REG_EXTI_RTSR               ((uint32_t *)(REG_EXTI_BASE  +  REG_EXTI_RTSR_OFFSET))         //set register nay kich canh lên
#define REG_EXTI_FTSR               ((uint32_t *)(REG_EXTI_BASE  +  REG_EXTI_FTSR_OFFSET))         //set register nay kích canh xuong
#define REG_EXTI_PR                 ((uint32_t *)(REG_EXTI_BASE  +  REG_EXTI_PR_OFFSET))           //set register nay Pending(Flag trang thái ngat)
#define REG_NVIC_ISER0              ((uint32_t *)(REG_NVIC_BASE  +  REG_NVIC_ISER0_OFFSET))        //set register Enable Interrupt Set
#define REG_NVIC_ICPR0              ((uint32_t *)(REG_NVIC_BASE  +  REG_NVIC_ICPR0_OFFSET))        //set register Clear Pending Interrupt

#define REG_GPIOx_MODER_OFFSET      0X00
#define REG_GPIOx_OTYPER_OFFSET     0X04
#define REG_GPIOx_OSPEEDR_OFFSET    0X08
#define REG_GPIOx_PUPDR_OFFSET      0X0C
#define REG_GPIOx_IDR_OFFSET        0X10
#define REG_GPIOx_ODR_OFFSET        0X14
#define REG_GPIOx_BSRR_OFFSET       0X18
#define REG_GPIOx_LCKR_OFFSET       0X1C
#define REG_GPIOx_AFRL_OFFSET       0X20
#define REG_GPIOx_AFRH_OFFSET       0X24

#define REG_GPIOD_MODER             ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_MODER_OFFSET  ))     
#define REG_GPIOD_OTYPER            ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_OTYPER_OFFSET ))     
#define REG_GPIOD_OSPEEDR           ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_OSPEEDR_OFFSET)) 
#define REG_GPIOD_PUPDR             ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_PUPDR_OFFSET  )) 
#define REG_GPIOD_IDR               ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_IDR_OFFSET    )) 
#define REG_GPIOD_ODR               ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_ODR_OFFSET    )) 
#define REG_GPIOD_BSRR              ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_BSRR_OFFSET   )) 
#define REG_GPIOD_LCKR              ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_LCKR_OFFSET   )) 
#define REG_GPIOD_AFRL              ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_AFRL_OFFSET   )) 
#define REG_GPIOD_AFRH              ((uint32_t *)(REG_GPIO_PORT_D + REG_GPIOx_AFRH_OFFSET   )) 

#define REG_GPIOA_MODER             ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_MODER_OFFSET  ))     
#define REG_GPIOA_OTYPER            ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_OTYPER_OFFSET ))     
#define REG_GPIOA_OSPEEDR           ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_OSPEEDR_OFFSET)) 
#define REG_GPIOA_PUPDR             ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_PUPDR_OFFSET  )) 
#define REG_GPIOA_IDR               ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_IDR_OFFSET    )) 
#define REG_GPIOA_ODR               ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_ODR_OFFSET    )) 
#define REG_GPIOA_BSRR              ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_BSRR_OFFSET   )) 
#define REG_GPIOA_LCKR              ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_LCKR_OFFSET   )) 
#define REG_GPIOA_AFRL              ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_AFRL_OFFSET   )) 
#define REG_GPIOA_AFRH              ((uint32_t *)(REG_GPIO_PORT_A + REG_GPIOx_AFRH_OFFSET   )) 

#define REG_GPIOH_MODER             ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_MODER_OFFSET  ))     
#define REG_GPIOH_OTYPER            ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_OTYPER_OFFSET ))     
#define REG_GPIOH_OSPEEDR           ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_OSPEEDR_OFFSET)) 
#define REG_GPIOH_PUPDR             ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_PUPDR_OFFSET  )) 
#define REG_GPIOH_IDR               ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_IDR_OFFSET    )) 
#define REG_GPIOH_ODR               ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_ODR_OFFSET    )) 
#define REG_GPIOH_BSRR              ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_BSRR_OFFSET   )) 
#define REG_GPIOH_LCKR              ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_LCKR_OFFSET   )) 
#define REG_GPIOH_AFRL              ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_AFRL_OFFSET   )) 
#define REG_GPIOH_AFRH              ((uint32_t *)(REG_GPIO_PORT_H + REG_GPIOx_AFRH_OFFSET   )) 

#define REG_GPIOC_MODER             ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_MODER_OFFSET  ))     
#define REG_GPIOC_OTYPER            ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_OTYPER_OFFSET ))     
#define REG_GPIOC_OSPEEDR           ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_OSPEEDR_OFFSET)) 
#define REG_GPIOC_PUPDR             ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_PUPDR_OFFSET  )) 
#define REG_GPIOC_IDR               ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_IDR_OFFSET    )) 
#define REG_GPIOC_ODR               ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_ODR_OFFSET    )) 
#define REG_GPIOC_BSRR              ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_BSRR_OFFSET   )) 
#define REG_GPIOC_LCKR              ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_LCKR_OFFSET   )) 
#define REG_GPIOC_AFRL              ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_AFRL_OFFSET   )) 
#define REG_GPIOC_AFRH              ((uint32_t *)(REG_GPIO_PORT_C + REG_GPIOx_AFRH_OFFSET   )) 


//TIMER6 AND TIMER7
#define REG_TIMx_CR1_OFFSET         0X00
#define REG_TIMx_CR2_OFFSET         0X04
#define REG_TIMx_SMCR_OFFSET        0X08
#define REG_TIMx_DIER_OFFSET        0X0C
#define REG_TIMx_SR_OFFSET          0X10
#define REG_TIMx_EGR_OFFSET         0X14
#define REG_TIMx_CCMR1_OFFSET       0X18
#define REG_TIMx_CCMR2_OFFSET       0X1C
#define REG_TIMx_CCER_OFFSET        0X20
#define REG_TIMx_CNT_OFFSET         0X24
#define REG_TIMx_PSC_OFFSET         0X28
#define REG_TIMx_ARR_OFFSET         0X2C
#define REG_TIMx_RCR_OFFSET         0X30
#define REG_TIMx_CCR1_OFFSET        0X34
#define REG_TIMx_CCR2_OFFSET        0X38
#define REG_TIMx_CCR3_OFFSET        0X3C
#define REG_TIMx_CCR4_OFFSET        0X40
#define REG_TIMx_BDTR_OFFSET        0X44
#define REG_TIMx_DCR_OFFSET         0X48
#define REG_TIMx_DMAR_OFFSET        0X4C


#define REG_TIM6_CR1                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_CR1_OFFSET))
#define REG_TIM6_CR2                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_CR2_OFFSET))
#define REG_TIM6_DIER               ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_DIER_OFFSET))
#define REG_TIM6_SR                 ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_SR_OFFSET))
#define REG_TIM6_EGR                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_EGR_OFFSET))
#define REG_TIM6_CNT                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_CNT_OFFSET))
#define REG_TIM6_PSC                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_PSC_OFFSET))
#define REG_TIM6_ARR                ((uint32_t*)(REG_TIM6_BASE + REG_TIMx_ARR_OFFSET))
	
	
#define REG_TIM7_CR1                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_CR1_OFFSET))
#define REG_TIM7_CR2                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_CR2_OFFSET))
#define REG_TIM7_DIER               ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_DIER_OFFSET))
#define REG_TIM7_SR                 ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_SR_OFFSET))
#define REG_TIM7_EGR                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_EGR_OFFSET))
#define REG_TIM7_CNT                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_CNT_OFFSET))
#define REG_TIM7_PSC                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_PSC_OFFSET))
#define REG_TIM7_ARR                ((uint32_t*)(REG_TIM7_BASE + REG_TIMx_ARR_OFFSET))


#define REG_TIM1_CR1                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CR1_OFFSET  ))
#define REG_TIM1_CR2                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CR2_OFFSET  ))
#define REG_TIM1_SMCR               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_SMCR_OFFSET ))
#define REG_TIM1_DIER               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_DIER_OFFSET ))
#define REG_TIM1_SR                 ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_SR_OFFSET   ))
#define REG_TIM1_EGR                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_EGR_OFFSET  ))
#define REG_TIM1_CCMR1              ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCMR1_OFFSET))
#define REG_TIM1_CCMR2              ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCMR2_OFFSET))
#define REG_TIM1_CCER               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCER_OFFSET ))
#define REG_TIM1_CNT                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CNT_OFFSET  ))
#define REG_TIM1_PSC                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_PSC_OFFSET  ))
#define REG_TIM1_ARR                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_ARR_OFFSET  ))
#define REG_TIM1_RCR                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_RCR_OFFSET  ))
#define REG_TIM1_CCR1               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCR1_OFFSET ))
#define REG_TIM1_CCR2               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCR2_OFFSET ))
#define REG_TIM1_CCR3               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCR3_OFFSET ))
#define REG_TIM1_CCR4               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_CCR4_OFFSET ))
#define REG_TIM1_BDTR               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_BDTR_OFFSET ))
#define REG_TIM1_DCR                ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_DCR_OFFSET  ))
#define REG_TIM1_DMAR               ((uint32_t*)(REG_TIM1_BASE +	REG_TIMx_DMAR_OFFSET ))
                                    
#define REG_TIM8_CR1                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CR1_OFFSET  ))
#define REG_TIM8_CR2                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CR2_OFFSET  ))
#define REG_TIM8_SMCR               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_SMCR_OFFSET ))
#define REG_TIM8_DIER               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_DIER_OFFSET ))
#define REG_TIM8_SR                 ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_SR_OFFSET   ))
#define REG_TIM8_EGR                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_EGR_OFFSET  ))
#define REG_TIM8_CCMR1              ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCMR1_OFFSET))
#define REG_TIM8_CCMR2              ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCMR2_OFFSET))
#define REG_TIM8_CCER               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCER_OFFSET ))
#define REG_TIM8_CNT                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CNT_OFFSET  ))
#define REG_TIM8_PSC                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_PSC_OFFSET  ))
#define REG_TIM8_ARR                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_ARR_OFFSET  ))
#define REG_TIM8_RCR                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_RCR_OFFSET  ))
#define REG_TIM8_CCR1               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCR1_OFFSET ))
#define REG_TIM8_CCR2               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCR2_OFFSET ))
#define REG_TIM8_CCR3               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCR3_OFFSET ))
#define REG_TIM8_CCR4               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_CCR4_OFFSET ))
#define REG_TIM8_BDTR               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_BDTR_OFFSET ))
#define REG_TIM8_DCR                ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_DCR_OFFSET  ))
#define REG_TIM8_DMAR               ((uint32_t*)(REG_TIM8_BASE +	REG_TIMx_DMAR_OFFSET ))



#endif /* INC_REGISTER_DEFS_H_ */