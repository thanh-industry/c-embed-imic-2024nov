#include "my_lib.h"

extern TIM_HandleTypeDef htim1;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == htim1.Instance){
		
		static uint8_t flag = 0;
		
		// catch the first rising edge
		if (flag == 0){
			ic_value_1 = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_2);
			flag = 1;
		}
		
		// catch the second rising edge
		else{
			ic_value_2 = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_2);
			if ( ic_value_2 > ic_value_1){
				diff = ic_value_2 - ic_value_1;
			}
			// avoid overload size of variable
			else{
				diff = (htim1.Init.Period - ic_value_1) + ic_value_2;
			}
			
			value = diff; // ms
			flag = 0;
		}
	}
}

uint32_t curr = 0, pre = 0, value_exti = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	curr = HAL_GetTick();
	value_exti = curr - pre;
	pre = curr;
}