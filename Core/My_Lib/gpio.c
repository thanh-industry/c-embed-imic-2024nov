#include "gpio.h"

void gpio_init(){
    /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Config GPIO Port D*/
  bit_set(GPIO_D_MODER, BIT_24);
  bit_clear(GPIO_D_OTYPER, BIT_12);
  bit_clear(GPIO_D_OSPEEDR, BIT_24 | BIT_25);
  bit_clear(GPIO_D_PUPDR, BIT_24 | BIT_25);

  bit_set(GPIO_D_MODER, BIT_26);
  bit_clear(GPIO_D_OTYPER, BIT_13);
  bit_clear(GPIO_D_OSPEEDR, BIT_26 | BIT_27);
  bit_clear(GPIO_D_PUPDR, BIT_26 | BIT_27);

  bit_set(GPIO_D_MODER, BIT_28);
  bit_clear(GPIO_D_OTYPER, BIT_14);
  bit_clear(GPIO_D_OSPEEDR, BIT_28 | BIT_29);
  bit_clear(GPIO_D_PUPDR, BIT_28 | BIT_29);

  bit_set(GPIO_D_MODER, BIT_30);
  bit_clear(GPIO_D_OTYPER, BIT_15);
  bit_clear(GPIO_D_OSPEEDR, BIT_30 | BIT_31);
  bit_clear(GPIO_D_PUPDR, BIT_30 | BIT_31);

  bit_clear(GPIO_A_MODER, BIT_0 | BIT_1);
  bit_clear(GPIO_A_OTYPER, BIT_0 | BIT_1);
  bit_clear(GPIO_A_OSPEEDR, BIT_0 | BIT_1);
  bit_clear(GPIO_A_PUPDR, BIT_1 | BIT_0);
  bit_clear(GPIO_A_IDR, BIT_0 | BIT_1);
}

//void gpio_mode(uint32_t port, uint32_t pin, uint32_t mode){
//	switch(mode){
//	case OUTPUT:
//		bit_set(GPIO_D_MODER, OUTPUT << (pin * 2)); // pin 0 -> set bit 0
//		bit_clear(GPIO_D_OTYPER, BIT_15);
//	}
//}

/**
  * @brief This function provides write in gpio
  * @note this function only use for port D
  * @param pin specifies the pin of GPIOx (x = 1:16)
  * @retval None
  */
void gpio_write(uint32_t pin, uint32_t value){
	switch(value){
	case 0:
		bit_clear(GPIO_D_ODR, pin);
		break;
	case 1:
		bit_set(GPIO_D_ODR, pin);
		break;
	default:
		break;
	}
}

/**
  * @brief This function provides toggle gpio
  * @note this function only use for port D
  * @param pin specifies the pin of GPIOx (x = 1:16)
  * @retval None
  */
void gpio_toggle(uint32_t pin){
	uint32_t reg = register_read(GPIO_D_ODR);
	reg ~= (1 << pin);
}


uint32_t gpio_read(uint32_t pin){
	uint32_t data = register_read(GPIO_A_IDR);
	return data &= pin;
}