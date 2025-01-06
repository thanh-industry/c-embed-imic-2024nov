
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"
#include "register_defs.h"


void REG_GPIO_Init(void){
	set_bits(REG_RCC_AHB1ENR, BIT_0|BIT_3);         //Bat xung clock cho GPIOA, GPIOD, GPIOC,GPIOH 
	//set_bits(REG_RCC_APB2ENR, BIT_14);              //Bat xung clock cho SYSCFG vì thanh ghi này dkhien ngat ngoai
																									//
	clear_bits(REG_GPIOA_MODER,BIT_0|BIT_1);        //Cau hinh GPIO Chan PA0 Input mode
	clear_bits(REG_GPIOA_PUPDR, (BIT_0 | BIT_1));   //Khong kich hoat pull up hay pull down
	
	set_bits(REG_GPIOD_MODER,BIT_24|BIT_26|BIT_28|BIT_30);
	clear_bits(REG_GPIOD_MODER,BIT_25|BIT_27|BIT_29|BIT_31);
	clear_bits(REG_GPIOD_OTYPER,BIT_12|BIT_13|BIT_14|BIT_15);
	clear_bits(REG_GPIOD_PUPDR,BIT_24|BIT_25|BIT_26|BIT_27|BIT_28|BIT_29|BIT_30|BIT_31);
	clear_bits(REG_GPIOD_OSPEEDR,BIT_24|BIT_25|BIT_26|BIT_27|BIT_28|BIT_29|BIT_30|BIT_31);
	
	clear_bits(REG_GPIOA_MODER,BIT_16|BIT_17);
  set_bits(REG_GPIOA_MODER,BIT_17);
  set_bits(REG_GPIOA_AFRH,BIT_0);
  
	clear_bits(REG_GPIOC_MODER,BIT_12|BIT_13);
  set_bits(REG_GPIOC_MODER,BIT_13);
	set_bits(REG_GPIOC_AFRL,BIT_24|BIT_25);

}









