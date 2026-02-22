################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Free_rtos_Drivers/portable/MemMang/heap_4.c 

OBJS += \
./Free_rtos_Drivers/portable/MemMang/heap_4.o 

C_DEPS += \
./Free_rtos_Drivers/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Free_rtos_Drivers/portable/MemMang/%.o Free_rtos_Drivers/portable/MemMang/%.su Free_rtos_Drivers/portable/MemMang/%.cyclo: ../Free_rtos_Drivers/portable/MemMang/%.c Free_rtos_Drivers/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Free_rtos_Drivers-2f-portable-2f-MemMang

clean-Free_rtos_Drivers-2f-portable-2f-MemMang:
	-$(RM) ./Free_rtos_Drivers/portable/MemMang/heap_4.cyclo ./Free_rtos_Drivers/portable/MemMang/heap_4.d ./Free_rtos_Drivers/portable/MemMang/heap_4.o ./Free_rtos_Drivers/portable/MemMang/heap_4.su

.PHONY: clean-Free_rtos_Drivers-2f-portable-2f-MemMang

