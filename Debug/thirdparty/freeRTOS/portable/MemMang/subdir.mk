################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/freeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./thirdparty/freeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./thirdparty/freeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/freeRTOS/portable/MemMang/%.o thirdparty/freeRTOS/portable/MemMang/%.su thirdparty/freeRTOS/portable/MemMang/%.cyclo: ../thirdparty/freeRTOS/portable/MemMang/%.c thirdparty/freeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I../Inc -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-thirdparty-2f-freeRTOS-2f-portable-2f-MemMang

clean-thirdparty-2f-freeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./thirdparty/freeRTOS/portable/MemMang/heap_4.cyclo ./thirdparty/freeRTOS/portable/MemMang/heap_4.d ./thirdparty/freeRTOS/portable/MemMang/heap_4.o ./thirdparty/freeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-thirdparty-2f-freeRTOS-2f-portable-2f-MemMang

