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
	clear_bits(REG_TIM7_ARR,0XFFFF);                  //xóa giá moi giá tri arr cu 
	set_bits(REG_TIM7_ARR,timer7_ARR);                     //pre=999
	set_bits(REG_TIM7_CR1,BIT_0);                     //kích hoat TIMER 7
	
	
  set_bits(REG_RCC_APB2ENR, BIT_0|BIT_1);           //Bat clock TIMER 1,8
  set_bits(REG_RCC_APB2ENR, BIT_14); 
	
	clear_bits(REG_TIM1_CR1, BIT_0);
	set_bits(REG_TIM1_CR1,BIT_2|BIT_7);
	uint32_t timer1_PSC = 0x7; 
	uint32_t timer1_ARR = 0x7CF; 
	clear_bits(REG_TIM1_PSC,0XFFFF);
	set_bits(REG_TIM1_PSC,timer1_PSC);                    
  clear_bits(REG_TIM1_ARR,0XFFFF);
	set_bits(REG_TIM1_ARR,timer1_ARR);   
	uint32_t timer1_CCR1 = 0x1F4;
	set_bits(REG_TIM1_CCR1, timer1_CCR1);
	clear_bits(REG_TIM1_CCMR1,BIT_4|BIT_5|BIT_6);
	set_bits(REG_TIM1_CCMR1,BIT_4|BIT_5);
	set_bits(REG_TIM1_CCMR1,BIT_3);
	set_bits(REG_TIM1_CCER,BIT_0);
	set_bits(REG_TIM1_BDTR,BIT_15);
	set_bits(REG_TIM1_CR1,BIT_0);       
	
	
	clear_bits(REG_TIM8_CR1, BIT_0);
	//set_bits(REG_TIM1_CR1,BIT_2|BIT_7);
	uint32_t timer8_PSC = 0x7; 
	//uint32_t timer8_PSC = 0x3E7; 
	clear_bits(REG_TIM8_PSC,0XFFFF);
	set_bits(REG_TIM8_PSC,timer8_PSC);                    
  //clear_bits(REG_TIM1_ARR,0XFFFF);
	//set_bits(REG_TIM1_ARR,timer1_ARR);   
	//uint32_t timer1_CCR1 = 0x1F4;
	//set_bits(REG_TIM1_CCR1, timer1_CCR1);
	clear_bits(REG_TIM8_CCMR1,BIT_0|BIT_1);
	set_bits(REG_TIM8_CCMR1,BIT_0);
	clear_bits(REG_TIM8_CCER,BIT_1);
	set_bits(REG_TIM8_CCER,BIT_0);
	set_bits(REG_TIM8_DIER,BIT_1);
	set_bits(REG_TIM8_CR1,BIT_0); 	
	
	
	
	
}












