#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"
#include "register_defs.h"


void EXTI_Init(void){	
	set_bits(REG_RCC_APB2ENR, BIT_14);                        //Bat xung clock cho SYSCFG vì thanh ghi này dkhien ngat ngoai
	clear_bits(REG_SYSCFG_EXTICR1,BIT_0|BIT_1|BIT_2|BIT_3);   //Cau hinh EXTI0 de su dung chan PA0
	set_bits(REG_EXTI_IMR,BIT_0);                             //kich hoat ngat tu EXTI0 
	set_bits(REG_EXTI_RTSR,BIT_0);                            //Kich hoat ngat suon duong 
	clear_bits(REG_EXTI_FTSR,BIT_0);                          //Ko kích hoat ngat suon am
	set_bits(REG_NVIC_ISER0,BIT_6);                           //kich hoat ngat trong NVIC cho dòng ngat EXTI0-Bit 6 tuong ung ma ngat  EXTI0 trong NVIC
}                                                           
