
#include "stm32f4xx_hal.h"
#include "main.h"

#define __KEYPAD_4X4    					1             

#if __KEYPAD_4X4
 
#define R1_Pin GPIO_PIN_0
#define R1_GPIO_Port GPIOD
#define R2_Pin GPIO_PIN_1
#define R2_GPIO_Port GPIOD
#define R3_Pin GPIO_PIN_2
#define R3_GPIO_Port GPIOD
#define R4_Pin GPIO_PIN_3
#define R4_GPIO_Port GPIOD
#define C1_Pin GPIO_PIN_4
#define C1_GPIO_Port GPIOD
#define C2_Pin GPIO_PIN_5
#define C2_GPIO_Port GPIOD
#define C3_Pin GPIO_PIN_6
#define C3_GPIO_Port GPIOD
#define C4_Pin GPIO_PIN_7
#define C4_GPIO_Port GPIOD


void keypad_init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; 
	/********************** Init GPIO Keypad *************************/
 	
	GPIO_InitStructure.Pin = R1_Pin|R2_Pin|R3_Pin|R4_Pin;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
  
  HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.Pin = C1_Pin|C2_Pin|C3_Pin|C4_Pin;
  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	HAL_GPIO_WritePin(GPIOD,R1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,R2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,R3_Pin,GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOD,R4_Pin,GPIO_PIN_SET);
/********************** End GPIO LCD ********************/
}



char keypad_get_key_value(void) {
    const char keymap[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    GPIO_TypeDef *row_ports[4] = {GPIOD, GPIOD, GPIOD, GPIOD}; 
    uint16_t row_pins[4] = {R1_Pin, R2_Pin, R3_Pin, R4_Pin};
    GPIO_TypeDef *col_ports[4] = {GPIOD, GPIOD, GPIOD, GPIOD};
    uint16_t col_pins[4] = {C1_Pin, C2_Pin, C3_Pin, C4_Pin};

    while (1) {
        for (int row = 0; row < 4; row++) {
            HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_RESET);
            HAL_Delay(10);

            for (int col = 0; col < 4; col++) {
                if (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_RESET) {
                    while (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_RESET); 
                    HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_SET); 
                    return keymap[row][col]; 
                }
            }
            HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_SET);
        }
    }
    //return 0; 
}

#endif
