
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"
#include "register_defs.h"


void REG_GPIO_Init(void){
	set_bits(REG_RCC_AHB1ENR, BIT_0|BIT_3);         //Bat xung clock cho GPIOA, GPIOD 
	//set_bits(REG_RCC_APB2ENR, BIT_14);              //Bat xung clock cho SYSCFG vì thanh ghi này dkhien ngat ngoai
																									//
	clear_bits(REG_GPIOA_MODER,BIT_0|BIT_1);        //Cau hinh GPIO Chan PA0 Input mode
	clear_bits(REG_GPIOA_PUPDR, (BIT_0 | BIT_1));   //Khong kich hoat pull up hay pull down
}









