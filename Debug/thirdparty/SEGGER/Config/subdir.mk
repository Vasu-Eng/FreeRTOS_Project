################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

OBJS += \
./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 

C_DEPS += \
./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/SEGGER/Config/%.o thirdparty/SEGGER/Config/%.su thirdparty/SEGGER/Config/%.cyclo: ../thirdparty/SEGGER/Config/%.c thirdparty/SEGGER/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I../Inc -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/Config" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/OS" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/SEGGER/SEGGER" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-thirdparty-2f-SEGGER-2f-Config

clean-thirdparty-2f-SEGGER-2f-Config:
	-$(RM) ./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d ./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o ./thirdparty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-thirdparty-2f-SEGGER-2f-Config

