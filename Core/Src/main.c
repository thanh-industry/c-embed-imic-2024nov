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
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include "user_main_init.h"
#include "registers_tools.h"
#include "registers_defs.h"
#include "led_tools.h"
#include "i2c_tools.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define PRINT_UART(f_, ...) 													   	   \
			do {																   	   \
				char _buffer[1024];													   \
				snprintf(_buffer, sizeof(_buffer), (f_), ##__VA_ARGS__); 			   \
				HAL_UART_Transmit(&huart4, (uint8_t *)_buffer, strlen(_buffer), 1000); \
			} while (0)

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
/* USER CODE BEGIN PV */
static bool extiAlarmPA0 = false;
static bool extiButtonToggle = false;
static bool timer6Alarm = false;
static bool timer6LedToggle = false;
static bool timer7Alarm = false;
static bool timer7LedToggle = false;
static bool timer8CaptureAlarm = false;

volatile uint32_t lastCapture = 0;
volatile uint32_t pulsePeriod = 0;
volatile uint32_t pulseFrequency = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */
void EXTI0_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM8_CC_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);
void interferenceCheck(void);

// For RTOS
void startButtonHandleTask(void *argument);
void startButtonExecuteTask(void *argument);
void startRTCTime(void *argument);

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


  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
  userInit();
  // Set priority and enable NVIC (Nested vectored interrupt controller)
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  //HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  // Enable NVIC for EXTI Group 0
  NVIC_EnableIRQ(EXTI0_IRQn);

  // Enable NVIC for Timer 6 and 7
  NVIC_EnableIRQ(TIM6_DAC_IRQn);
  NVIC_EnableIRQ(TIM7_IRQn);

  /*
  // Enable NVIC for Update interrupt in Timer 1
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
  */

  // Enable NVIC for Capture/Compare interrupt in Timer 1
  //NVIC_EnableIRQ(TIM1_CC_IRQn);

  // Enable NVIC for Capture/Compare interrupt in Timer 8
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

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  osThreadId_t buttonHandle;
  const osThreadAttr_t buttonHandle_attributes = {
    .name = "buttonInterference",
    .stack_size = 128 * 4,
    .priority = (osPriority_t) osPriorityNormal1,
  };

  osThreadId_t buttonExecute;
  const osThreadAttr_t buttonExecute_attributes = {
	.name = "buttonExecution",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityNormal,
  };

  osThreadId_t rtcTimeExecute;
  const osThreadAttr_t rtcTimeExecute_attributes ={
	.name = "rtcTimeExecute",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityLow,
  };


  buttonHandle = osThreadNew(startButtonHandleTask, NULL, &buttonHandle_attributes);
  if (NULL == buttonHandle) PRINT_UART("buttonHandle Thread is failed to be created\r\n");
  else PRINT_UART("buttonHandle Thread created successfully\r\n");

  buttonExecute = osThreadNew(startButtonExecuteTask, NULL, &buttonExecute_attributes);
  if (NULL == buttonExecute) PRINT_UART("buttonExecute Thread is failed to be created\r\n");
  else PRINT_UART("buttonExecute Thread created successfully\r\n");

  rtcTimeExecute = osThreadNew(startRTCTime, NULL, &rtcTimeExecute_attributes);
  if (NULL == rtcTimeExecute) PRINT_UART("rtcTimeSet Thread is failed to be created\r\n");
  else PRINT_UART("rtcTimeSet Thread created successfully\r\n");

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

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
		osDelay(100);
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

// Function for NVIC TIM1 Capture/Compare Interrupt
void TIM1_CC_IRQHandler(void) {
	if (registerBitCheck(REG_TIM1_SR, BIT_1)) {
		PRINT_UART("TIMER 1 Pulse is running");
		registerBitClear(REG_TIM1_SR, BIT_1);
	}
}

// Function for NVIC TIM8 Capture/Compare Interrupt
void TIM8_CC_IRQHandler(void) {
	if (registerBitCheck(REG_TIM8_SR, BIT_1)) {
		uint32_t currentCapture = registerRead(REG_TIM8_CCR1);
		if (currentCapture >= lastCapture) {
			pulsePeriod = currentCapture - lastCapture;
		}
		else {
			// This is for the case which the lastCapture is before overflow and currentCapture is after overflow
			pulsePeriod = 0xFFFF - lastCapture + currentCapture +1;
		}
		lastCapture = currentCapture;
		// Clear capture interrupt flag
		registerBitClear(REG_TIM8_SR, BIT_1);

		// Set Alarm of TIM 8
		timer8CaptureAlarm = true;
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

// For RTOS

void startButtonHandleTask(void *argument) {
	for(;;) {
		if(extiAlarmPA0) {
			interferenceCheck();
		}


		osDelay(1);
	}
}

void startButtonExecuteTask(void *argument) {
	for(;;) {
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
}

void startRTCTime(void *argument) {
	uint8_t seconds, minutes, hours, day, date, month, year, isPM;
	char weekDay[8][9] = { "", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	char pm[2][2] = {"AM", "PM"};

	// Set up the RTC DS3231 for the first time
	i2cWrite(DS3231_ADDRESS, DS3231_SECONDS, 0x12); 		// Seconds as 12 seconds
	i2cWrite(DS3231_ADDRESS, DS3231_MINUTES, 0x12); 		// Minutes as 12 minutes
	i2cWrite(DS3231_ADDRESS, DS3231_HOURS, 0x72); 			// Hours as 12 hours, 12h format, PM
	i2cWrite(DS3231_ADDRESS, DS3231_DAY, 0x01);				// Week day as 1 (Sunday)
	i2cWrite(DS3231_ADDRESS, DS3231_DATE, 0x05);			// Date of month (5)
	i2cWrite(DS3231_ADDRESS, DS3231_CEN_MONTH, 0x01);		// Month (1 as January), Century (Bit 7 as 0 for 2000 - 2099)
	i2cWrite(DS3231_ADDRESS, DS3231_2LDIGI_YEAR, 0x25);		// Year (25 as 2 last digit)

	// Infinite loop to read the data every 30s
	for (;;) {
		readDS3231Time(seconds, minutes, hours, day, date, month, year, isPM);
		PRINT_UART("Time: %02d:%02d:%02d %s\n", hours, minutes, seconds, pm[isPM]);
		PRINT_UART("Date: %02d/%02d/20%02d, Day: %s\n", date, month, year, weekDay[day]);
		osDelay(30000);
	}
}


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
	//timer8CaptureAlarm = true;
	if(timer8CaptureAlarm) {
		if(pulsePeriod != 0) {
			pulseFrequency = 1000000 / pulsePeriod; // pulsePeriod is us, need to change to s
		}
		else {
			pulseFrequency = 0;
		}
		//PRINT_UART("The period and frequency of Timer 1 Pulse is : %lu and %lu\r\n", pulsePeriod, pulseFrequency);
		osDelay(1000);
		timer8CaptureAlarm = false;
	}
    osDelay(1);
  }
  /* USER CODE END 5 */
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
