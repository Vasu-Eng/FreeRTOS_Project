################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Free_rtos_Drivers/portable/GCC/ARM_CM4F/%.o Free_rtos_Drivers/portable/GCC/ARM_CM4F/%.su Free_rtos_Drivers/portable/GCC/ARM_CM4F/%.cyclo: ../Free_rtos_Drivers/portable/GCC/ARM_CM4F/%.c Free_rtos_Drivers/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Free_rtos_Drivers-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Free_rtos_Drivers-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.cyclo ./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.d ./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.o ./Free_rtos_Drivers/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Free_rtos_Drivers-2f-portable-2f-GCC-2f-ARM_CM4F

