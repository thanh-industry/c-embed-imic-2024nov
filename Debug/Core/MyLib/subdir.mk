################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/My_Lib/InputCapture.c \
../Core/My_Lib/exti.c \
../Core/My_Lib/gpio.c \
../Core/My_Lib/led.c \
../Core/My_Lib/mpu6050.c \
../Core/My_Lib/register_helpers.c \
../Core/My_Lib/timer.c 

OBJS += \
./Core/MyLib/InputCapture.o \
./Core/MyLib/exti.o \
./Core/MyLib/gpio.o \
./Core/MyLib/led.o \
./Core/MyLib/mpu6050.o \
./Core/MyLib/register_helpers.o \
./Core/MyLib/timer.o 

C_DEPS += \
./Core/MyLib/InputCapture.d \
./Core/MyLib/exti.d \
./Core/MyLib/gpio.d \
./Core/MyLib/led.d \
./Core/MyLib/mpu6050.d \
./Core/MyLib/register_helpers.d \
./Core/MyLib/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/MyLib/InputCapture.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/InputCapture.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/exti.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/exti.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/gpio.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/gpio.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/led.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/led.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/mpu6050.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/mpu6050.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/register_helpers.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/register_helpers.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/MyLib/timer.o: C:/Users/Huy/Documents/STM32Project/1_MIC/c-embed-imic-2024nov/Core/My_Lib/timer.c Core/MyLib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-MyLib

clean-Core-2f-MyLib:
	-$(RM) ./Core/MyLib/InputCapture.cyclo ./Core/MyLib/InputCapture.d ./Core/MyLib/InputCapture.o ./Core/MyLib/InputCapture.su ./Core/MyLib/exti.cyclo ./Core/MyLib/exti.d ./Core/MyLib/exti.o ./Core/MyLib/exti.su ./Core/MyLib/gpio.cyclo ./Core/MyLib/gpio.d ./Core/MyLib/gpio.o ./Core/MyLib/gpio.su ./Core/MyLib/led.cyclo ./Core/MyLib/led.d ./Core/MyLib/led.o ./Core/MyLib/led.su ./Core/MyLib/mpu6050.cyclo ./Core/MyLib/mpu6050.d ./Core/MyLib/mpu6050.o ./Core/MyLib/mpu6050.su ./Core/MyLib/register_helpers.cyclo ./Core/MyLib/register_helpers.d ./Core/MyLib/register_helpers.o ./Core/MyLib/register_helpers.su ./Core/MyLib/timer.cyclo ./Core/MyLib/timer.d ./Core/MyLib/timer.o ./Core/MyLib/timer.su

.PHONY: clean-Core-2f-MyLib

