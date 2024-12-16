#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"
#include "register_defs.h"
#include "basic_timer.h"


void REG_TIMER_Init(void){
	set_bits(REG_RCC_APB1ENR, BIT_4|BIT_5);           //Bat clock TIMER 6,7
	
	clear_bits(REG_TIM6_CR1,BIT_0);                   //TAT TIMER 6 truoc khi cau hình de dam bao bo dem khong hoat dong khi cac thanh ghi dang dc cau hình
	set_bits(REG_TIM6_CR1, BIT_2|BIT_7);              //kích hoat preload(dam bao gia tri ARR dc nap vào sau moi chu ky) và chi cho phep cap nhat khi counter tràn
	set_bits(REG_TIM6_DIER,BIT_0);                    //CHo phép ngat khi tràn counter             
	uint32_t timer6_ARR = 0x63;									// HEX value of 99 DEC
	uint32_t timer6_PSC = 0x1F3F;								// HEX value of 7999 DEC

	set_bits(REG_TIM6_PSC,timer6_PSC);                    //prescaler=7999
	clear_bits(REG_TIM6_ARR,0XFFFF);                  //xóa giá moi giá tri pre cu 
	set_bits(REG_TIM6_ARR,timer6_ARR);                      //pre=99
	set_bits(REG_TIM6_CR1,BIT_0);                     //kích hoat TIMER 6
	
	clear_bits(REG_TIM7_CR1,BIT_0);                   //TAT TIMER 7 truoc khi cau hình de dam bao bo dem khong hoat dong khi cac thanh ghi dang dc cau hình
	set_bits(REG_TIM7_CR1, BIT_2|BIT_7);              //kích hoat preload(dam bao gia tri ARR dc nap vào sau moi chu ky) và chi cho phep cap nhat khi counter tràn
	set_bits(REG_TIM7_DIER,BIT_0);                    //CHo phép ngat khi tràn counter             
  uint32_t timer7_ARR = 0x3E7;								// HEX value of 999 DEC
	uint32_t timer7_PSC = 0xF9F;								// HEX value of 3999 DEC

	set_bits(REG_TIM7_PSC,timer7_PSC);                    //prescaler=3999
	clear_bits(REG_TIM7_ARR,0XFFFF);                  //xóa giá moi giá tri pre cu 
	set_bits(REG_TIM7_ARR,timer7_ARR);                     //pre=999
	set_bits(REG_TIM7_CR1,BIT_0);                     //kích hoat TIMER 7
	
	
}