#include "gpio.h"

void gpio_init() {
	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/* Config GPIO Port D */
	gpio_mode(GPIO_12, OUTPUT);
	gpio_mode(GPIO_13, OUTPUT);
	gpio_mode(GPIO_14, OUTPUT);
	gpio_mode(GPIO_15, OUTPUT);

	/* Config GPIO Port A */
	gpio_mode(GPIO_0, INPUT);

}

void gpio_mode(uint16_t pin, uint8_t mode) {
	switch (mode) {
	case INPUT:
		// default
		break;

	case OUTPUT:
		// set 01 to config output mode
		bit_set(GPIO_D_MODER, mode << (pin * 2));

		// set 0 to config pull up
		bit_clear(GPIO_D_OTYPER, mode << pin);
		break;

	case ALTER_FUNC:
		// set 10 to config Alternate function mode
		bit_set(GPIO_D_MODER, mode << (pin * 2));

		// set 1 to config open drain
		bit_clear(GPIO_D_OTYPER, mode << (pin - 1));
		break;

	case ANALOG:
		// set 11 to config analog mode
		bit_set(GPIO_D_MODER, mode << (pin * 2));

		break;

	}

	/* Initial status */
	gpio_write(pin, GPIO_OFF);
}

/**
 * @brief This function provides write in gpio
 * @note this function only use for port D
 * @param pin specifies the pin of GPIOx (x = 1:16)
 * @retval None
 */
void gpio_write(uint16_t pin, uint8_t value) {
	// check the pin
	if (!gpio_is_pin(pin))
		return;

	// write value ODR register
	switch (value) {
	case GPIO_OFF:
		bit_clear(GPIO_D_ODR, (1 << pin));
		break;
	case GPIO_ON:
		bit_set(GPIO_D_ODR, (1 << pin));
		break;
	default:
		break;
	}
}

uint8_t gpio_is_pin(uint16_t pin) {
	return (pin < GPIO_NUMBER) ? 1 : 0;
}

/**
 * @brief This function provides toggle the pin of GPIOx (x = 1:16)
 * @note this function only use for port D
 * @param pin specifies the pin of GPIOx
 * @retval None
 */
void gpio_toggle(uint16_t pin) {
	// check the pin
	if (!gpio_is_pin(pin))
		return;

	uint32_t reg = register_read(GPIO_D_ODR);
	reg ^= (1 << pin);
	register_write(GPIO_D_ODR, reg);
}

/**
 * @brief This function provides function read value at GPIOx (x = 1:16)
 * @note this function only use for port D
 * @param pin specifies the pin of GPIOx
 * @retval value at GPIOx
 */
uint16_t gpio_read(uint16_t pin) {
	// check the pin
	if (!gpio_is_pin(pin))
		return 0;

	// read value from IDR register
	volatile uint32_t data = register_read(GPIO_A_IDR);

	return data &= (1 << pin);
}
