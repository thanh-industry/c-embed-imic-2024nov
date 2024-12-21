/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include "user_main_init.h"
#include "registers_tools.h"
#include "registers_defs.h"
#include "led_tools.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static bool extiAlarmPA0 = false;
static bool extiButtonToggle = false;
static bool timer6Alarm = false;
static bool timer6LedToggle = false;
static bool timer7Alarm = false;
static bool timer7LedToggle = false;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void EXTI0_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);
void interferenceCheck(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  userInit();
  // Set priority and enable NVIC (Nested vectored interrupt controller)
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  //HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  // Enable NVIC for EXTI Group 0
  NVIC_EnableIRQ(EXTI0_IRQn);

  // Enable NVIC for Timer 6 and 7
  NVIC_EnableIRQ(TIM6_DAC_IRQn);
  NVIC_EnableIRQ(TIM7_IRQn);
  // Enable NVIC for Update interrupt in Timer 1
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
  // Enable NVIC for Capture/Compare interrupt in Timer 1
  NVIC_EnableIRQ(TIM1_CC_IRQn);

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  //MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if(extiAlarmPA0) {
		  interferenceCheck();
	  }

	  if (extiButtonToggle) {

		  if (timer6Alarm) {
			  timer6Alarm = false;
			  timer6LedToggle ^= 1;
			  ledSet(LED_GREEN, timer6LedToggle);
		  }

		  if (timer7Alarm) {
			  timer7Alarm = false;
			  timer7LedToggle ^= 1;
			  ledSet(LED_BLUE, timer7LedToggle);
		  }
	  }
	  else {
		  ledSet(LED_GREEN, 0);
		  ledSet(LED_BLUE, 0);
	  }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, Green_LED_Pin|Orange_LED_Pin|Red_LED_Pin|Blue_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_BUTTON_Pin */
  GPIO_InitStruct.Pin = USER_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Green_LED_Pin Orange_LED_Pin Red_LED_Pin Blue_LED_Pin */
  GPIO_InitStruct.Pin = Green_LED_Pin|Orange_LED_Pin|Red_LED_Pin|Blue_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// Check interference of button
void interferenceCheck(void) {
	if (registerBitCheck(REG_GPIO_A_IDR, BIT_0)) {
		HAL_Delay(100);
		if (registerBitCheck(REG_GPIO_A_IDR, BIT_0)) {
			uint32_t count = 8000000; //count value for 1s based on 8Mhz frequency
			while (registerBitCheck(REG_GPIO_A_IDR, BIT_0) && count >= 0) {
				count--;
			}
			if (count >= 0) {
				ledBlink(LED_ORANGE, 500);
				extiAlarmPA0 = false;
				extiButtonToggle ^= 1;
			}
		}
	}
	else extiAlarmPA0 = false;
}

// Function for NVIC EXTI0 Interrupt
void EXTI0_IRQHandler(void) {
	//Check if pending is at PA0
	if (registerBitCheck(REG_EXTI_PR, BIT_0)) {
		// Clear the pending at PA0
		registerBitSet(REG_EXTI_PR, BIT_0);
		// Set the alarm variable of PA0
		extiAlarmPA0 = true;
	}
}

// Function for NVIC TIM6 Interrupt
void TIM6_DAC_IRQHandler(void) {
	// Check update interrupt flag
    if (registerBitCheck(REG_TIM6_SR, BIT_0)) {
    	// Clear update interrupt flag
        registerBitClear(REG_TIM6_SR, BIT_0);
        // Set Alarm of TIM 6
        timer6Alarm = true;
    }
}

// Function for NVIC TIM7 Interrupt
void TIM7_IRQHandler(void) {
	// Check update interrupt flag
	if (registerBitCheck(REG_TIM7_SR, BIT_0)) {
		// Clear update interrupt flag
		registerBitClear(REG_TIM7_SR, BIT_0);
		// Set Alarm of TIM 7
		timer7Alarm = true;
	}
}

void TIM1_CC_IRQHandler(void) {
	if (registerBitCheck(REG_TIM1_SR, BIT_1)) {
		// Clear update interrupt flag
		registerBitClear(REG_TIM1_SR, BIT_1);
		// Set Alarm for update interrupt of TIM 1(if any)
	}
}

void TIM1_UP_TIM10_IRQHandler(void) {
	if (registerBitCheck(REG_TIM1_SR, BIT_0)) {
		// Clear update interrupt flag
		registerBitClear(REG_TIM1_SR, BIT_0);
		// Set Alarm for compare interrupt of TIM 1(if any)
	}
}
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
