################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/My_Lib/exti.c \
../Core/My_Lib/gpio.c \
../Core/My_Lib/led.c \
../Core/My_Lib/register_helpers.c \
../Core/My_Lib/timer.c 

OBJS += \
./Core/My_Lib/exti.o \
./Core/My_Lib/gpio.o \
./Core/My_Lib/led.o \
./Core/My_Lib/register_helpers.o \
./Core/My_Lib/timer.o 

C_DEPS += \
./Core/My_Lib/exti.d \
./Core/My_Lib/gpio.d \
./Core/My_Lib/led.d \
./Core/My_Lib/register_helpers.d \
./Core/My_Lib/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/My_Lib/%.o Core/My_Lib/%.su Core/My_Lib/%.cyclo: ../Core/My_Lib/%.c Core/My_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-My_Lib

clean-Core-2f-My_Lib:
	-$(RM) ./Core/My_Lib/exti.cyclo ./Core/My_Lib/exti.d ./Core/My_Lib/exti.o ./Core/My_Lib/exti.su ./Core/My_Lib/gpio.cyclo ./Core/My_Lib/gpio.d ./Core/My_Lib/gpio.o ./Core/My_Lib/gpio.su ./Core/My_Lib/led.cyclo ./Core/My_Lib/led.d ./Core/My_Lib/led.o ./Core/My_Lib/led.su ./Core/My_Lib/register_helpers.cyclo ./Core/My_Lib/register_helpers.d ./Core/My_Lib/register_helpers.o ./Core/My_Lib/register_helpers.su ./Core/My_Lib/timer.cyclo ./Core/My_Lib/timer.d ./Core/My_Lib/timer.o ./Core/My_Lib/timer.su

.PHONY: clean-Core-2f-My_Lib

