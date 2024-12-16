
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "register_helper.h"
#include "register_defs.h"
#include "gpio.h"
#include "exti.h"
#include "basic_timer.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void EXTI0_IRQHandler(void);
void REG_TIM6_DAC_IRQHandler(void);
void REG_TIM7_IRQHandler(void);

static bool alarm_PA0 = false;
static bool alarm_TIM6 = false;
static bool alarm_TIM7 = false;
static bool exti_led = false;
static bool tim6_led = false;
static bool tim7_led = false;

void set_led(uint32_t *address,uint32_t mask,bool state){
	if(state){
		set_bits(address,mask);
	}
	else{
		clear_bits(address,mask);
	}
}

void blink_led(uint32_t *address,uint32_t mask){
	set_led(address,mask,1);
	HAL_Delay(500);
	set_led(address,mask,0);
	HAL_Delay(500);
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
	REG_GPIO_Init();
	EXTI_Init();
	REG_TIMER_Init();
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  NVIC_EnableIRQ(EXTI0_IRQn);
	//set_bits(&NVIC->ISER[0], (1 << EXTI0_IRQn));
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_EnableIRQ(TIM7_IRQn);
  uint32_t *blinking_led_add = REG_GPIOD_ODR;
	uint32_t blinking_led_mask = BIT_12|BIT_13|BIT_14|BIT_15;
	uint32_t blinking_led_mas1 = BIT_12;
	uint32_t blinking_led_mas2 = BIT_13;
	uint32_t blinking_led_mas3 = BIT_14;
	
	//int count=0;
  while (1)
  {
		if(!alarm_PA0){
			blink_led(blinking_led_add,blinking_led_mask);
		  //count++;
		  //if(count==5) break;
		}
		else{
			alarm_PA0=false;
			blink_led(blinking_led_add,blinking_led_mas1);
			while (1) {
         if(alarm_TIM6) {
            alarm_TIM6 = false;
            set_led(blinking_led_add, blinking_led_mas2, !check_bits(blinking_led_add, BIT_13));
         }
         if (alarm_TIM7) {
            alarm_TIM7 = false;
            set_led(blinking_led_add, blinking_led_mas3, !check_bits(blinking_led_add, BIT_14));
         }
      }
		}
  }
}

void EXTI0_IRQHandler(void) {
	if (check_bits(REG_EXTI_PR, BIT_0)) {
		set_bits(REG_EXTI_PR, BIT_0);
		alarm_PA0 = true;
	}
}
// Function for NVIC TIM6 Interrupt
void TIM6_DAC_IRQHandler(void) {
	// Check update interrupt flag
    if (check_bits(REG_TIM6_SR, BIT_0)) {
    	// Clear update interrupt flag
        clear_bits(REG_TIM6_SR, BIT_0);
        // Set Alarm of TIM 6
        alarm_TIM6 = true;
    }
}

// Function for NVIC TIM7 Interrupt
void TIM7_IRQHandler(void) {
	// Check update interrupt flag
	if (check_bits(REG_TIM7_SR, BIT_0)) {
		// Clear update interrupt flag
		clear_bits(REG_TIM7_SR, BIT_0);
		// Set Alarm of TIM 7
		alarm_TIM7 = true;
	}
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
