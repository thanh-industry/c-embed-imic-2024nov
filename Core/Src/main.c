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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include "register_helper.h"
#include "register_defs.h"
#include "gpio.h"
#include "exti.h"
#include "basic_timer.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define PRINT_UART(f_, ...) 													   	\
			do {																   	            \
				char _buffer[1024];													      \
				snprintf(_buffer, sizeof(_buffer), (f_), ##__VA_ARGS__); 			         \
				HAL_UART_Transmit(&huart4, (uint8_t *)_buffer, strlen(_buffer), 1000); \
			} while (0)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart4;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myTask03 */
osThreadId_t myTask03Handle;
const osThreadAttr_t myTask03_attributes = {
  .name = "myTask03",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */
static bool alarm_PA0 = false;
static bool alarm_TIM1 = false;
static bool alarm_TIM6 = false;
static bool alarm_TIM7 = false;
static bool alarm_TIM8 = false;

uint32_t *blinking_led_add = REG_GPIOD_ODR;
volatile uint32_t captured_value = 0;
volatile uint32_t frequency = 0;
volatile uint32_t per = 0;
//volatile bool stop_blinking = false;
enum ledMode{
	LED_MODE_ALL_BLINK,
	LED_MODE_BIT12,
	LED_MODE_TIMER_CONTROL
};
volatile enum ledMode led_mode=LED_MODE_ALL_BLINK;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
void StartDefaultTask(void *argument);
void StartTask04(void *argument);
void StartTask05(void *argument);
void checkMode(void);
/* USER CODE BEGIN PFP */
void EXTI0_IRQHandler(void);
void REG_TIM6_DAC_IRQHandler(void);
void REG_TIM7_IRQHandler(void);
void TIM8_CC_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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
	osDelay(500);
	set_led(address,mask,0);
	osDelay(500);
}

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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
	REG_GPIO_Init();
	EXTI_Init();
	REG_TIMER_Init();
	

	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  NVIC_EnableIRQ(EXTI0_IRQn);
	//set_bits(&NVIC->ISER[0], (1 << EXTI0_IRQn));
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_EnableIRQ(TIM7_IRQn);
	NVIC_EnableIRQ(TIM1_CC_IRQn);
  NVIC_EnableIRQ(TIM8_CC_IRQn);
	
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of myTask02 */
  myTask02Handle = osThreadNew(StartTask04, NULL, &myTask02_attributes);

  /* creation of myTask03 */
  myTask03Handle = osThreadNew(StartTask05, NULL, &myTask03_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void EXTI0_IRQHandler(void) {
	if (check_bits(REG_EXTI_PR, BIT_0)) {
		set_bits(REG_EXTI_PR, BIT_0);
		alarm_PA0 = true;
//		if (led_mode == LED_MODE_ALL_BLINK) {
//            led_mode = LED_MODE_BIT12;
//        } else if (led_mode == LED_MODE_BIT12) {
//            led_mode = LED_MODE_TIMER_CONTROL;
//        } else if (led_mode == LED_MODE_TIMER_CONTROL) {
//            led_mode = LED_MODE_ALL_BLINK;
//        }
	}
}

void TIM6_DAC_IRQHandler(void) {
    if (check_bits(REG_TIM6_SR, BIT_0)) {
        clear_bits(REG_TIM6_SR, BIT_0);
        alarm_TIM6 = true;
    }
}

void TIM7_IRQHandler(void) {
	if (check_bits(REG_TIM7_SR, BIT_0)) {
		clear_bits(REG_TIM7_SR, BIT_0);
		alarm_TIM7 = true;
	}
}

void TIM1_CC_IRQHandler(void){
	
}

void TIM8_CC_IRQHandler(void){
	if(check_bits(REG_TIM8_SR,BIT_1)){
		uint32_t current_capture = read_register(REG_TIM8_CCR1);
		if(current_capture >= captured_value){
			per=current_capture-captured_value;
		}
		else{
			per = (0XFFFF-captured_value+current_capture+1);
		}
		captured_value=current_capture;	
		//frequency=1000000/per;
		clear_bits(REG_TIM8_SR, BIT_1);
		alarm_TIM8=true;
	}
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();

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
//void checkMode(void) {
//	if (check_bits(REG_GPIOA_IDR, BIT_0)) {
//		osDelay(100);
//		if (check_bits(REG_GPIOA_IDR, BIT_0)) {
//			uint32_t count = 8000000; 
//			while (check_bits(REG_GPIOA_IDR, BIT_0) && count >= 0) {
//				count--;
//			}
//			if (count >= 0) {
//				alarm_PA0 = false;
//			}
//		}
//	}
//	else alarm_PA0 = false;
//}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
		//blinkledTask();
		if(alarm_TIM8){
			if(per != 0){
				frequency=1000000/per;
			}
			else{
				frequency=0;			
			}
			//PRINT_UART("The period and frequency of Timer 1 Pulse is : %d and %d\r\n", per, frequency);
			osDelay(1000);	
			alarm_TIM8=false;
		}
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void *argument) {
    uint32_t blinking_led_mask_all = BIT_12 | BIT_13 | BIT_14 | BIT_15;
    uint32_t blinking_led_mask_bit12 = BIT_12;
    for (;;) {
        if (alarm_PA0) {
            if (led_mode == LED_MODE_ALL_BLINK) {
                led_mode = LED_MODE_BIT12;
            } else if (led_mode == LED_MODE_BIT12) {
                led_mode = LED_MODE_TIMER_CONTROL;
            } else if (led_mode == LED_MODE_TIMER_CONTROL) {
                led_mode = LED_MODE_ALL_BLINK;
            }
            alarm_PA0 = false; 
        }

        if (led_mode == LED_MODE_ALL_BLINK) {
            blink_led(blinking_led_add, blinking_led_mask_all);
        } 
				else if (led_mode == LED_MODE_BIT12) {
            blink_led(blinking_led_add, blinking_led_mask_bit12);
        } 
				
        osDelay(1);
    }
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the myTask05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void *argument)
{
  /* USER CODE BEGIN StartTask05 */
  /* Infinite loop */
  for(;;)
  {
		PRINT_UART("Hello from task 5\n");
		if (led_mode == LED_MODE_TIMER_CONTROL) {
    if (alarm_TIM6) {
        alarm_TIM6 = false;
        set_led(blinking_led_add, BIT_13, !check_bits(blinking_led_add, BIT_13));
    }
    if (alarm_TIM7) {
        alarm_TIM7 = false;
        set_led(blinking_led_add, BIT_14, !check_bits(blinking_led_add, BIT_14));
    }
  }
    osDelay(1000);
  }
  /* USER CODE END StartTask05 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
