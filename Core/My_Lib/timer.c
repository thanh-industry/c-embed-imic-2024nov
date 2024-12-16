#include "timer.h"
void timer_basic_6_init(){
	__HAL_RCC_TIM6_CLK_ENABLE();
    // config TIMx_DIER:
		bit_set(TIM_BASIC_6_CR1, BIT_7);
    bit_set(TIM_BASIC_6_DIER, BIT_0);
    // config TIMx_PSC:
    bit_set(TIM_BASIC_6_PSC, BIT_2 | BIT_3 | BIT_4 | BIT_5 | BIT_6); // PSC = 124
		// config TIMx_ARR:
		bit_set(TIM_BASIC_6_ARR, BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_8 | BIT_9 | BIT_10 | BIT_13); // ARR = 9999 BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_8 | BIT_9 | BIT_10 | BIT_13
		bit_set(TIM_BASIC_6_CR1, BIT_0);
}

uint16_t get_timer_basic_6(){
    return *(TIM_BASIC_6_CNT);
}
