################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.c \
../thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.c 

OBJS += \
./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.o \
./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.o 

C_DEPS += \
./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.d \
./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/SEGGER/UART_RECORDER/%.o thirdparty/SEGGER/UART_RECORDER/%.su thirdparty/SEGGER/UART_RECORDER/%.cyclo: ../thirdparty/SEGGER/UART_RECORDER/%.c thirdparty/SEGGER/UART_RECORDER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I../Inc -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Inc" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/Config" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/OS" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/SEGGER" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-thirdparty-2f-SEGGER-2f-UART_RECORDER

clean-thirdparty-2f-SEGGER-2f-UART_RECORDER:
	-$(RM) ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.cyclo ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.d ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.o ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_Config_UART.su ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.cyclo ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.d ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.o ./thirdparty/SEGGER/UART_RECORDER/SEGGER_SYSVIEW_REC.su

.PHONY: clean-thirdparty-2f-SEGGER-2f-UART_RECORDER

