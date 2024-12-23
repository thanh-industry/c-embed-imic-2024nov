#include "timer.h"
void timer_basic_6_init() {
	__HAL_RCC_TIM6_CLK_ENABLE();
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	// config TIMx_DIER:
	bit_set(TIM_BASIC_6_CR1, BIT_7);
	// update interrupt enabled
	bit_set(TIM_BASIC_6_DIER, BIT_0);
	bit_clear(TIM_BASIC_6_SR, BIT_0);
	// config TIMx_PSC:
	bit_set(TIM_BASIC_6_PSC, 0x61A7); // PSC = 25 000
	// config TIMx_ARR:
	bit_clear(TIM_BASIC_6_ARR, 0xFFFF);
	bit_set(TIM_BASIC_6_ARR, 0x1324); // ARR = 500

	bit_set(TIM_BASIC_6_CR1, BIT_0);
}

uint16_t get_timer_basic_6() {
	return *(TIM_BASIC_6_CNT);
}
