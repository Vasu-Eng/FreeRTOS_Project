################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Free_rtos_Drivers/croutine.c \
../Free_rtos_Drivers/event_groups.c \
../Free_rtos_Drivers/list.c \
../Free_rtos_Drivers/queue.c \
../Free_rtos_Drivers/stream_buffer.c \
../Free_rtos_Drivers/tasks.c \
../Free_rtos_Drivers/timers.c 

OBJS += \
./Free_rtos_Drivers/croutine.o \
./Free_rtos_Drivers/event_groups.o \
./Free_rtos_Drivers/list.o \
./Free_rtos_Drivers/queue.o \
./Free_rtos_Drivers/stream_buffer.o \
./Free_rtos_Drivers/tasks.o \
./Free_rtos_Drivers/timers.o 

C_DEPS += \
./Free_rtos_Drivers/croutine.d \
./Free_rtos_Drivers/event_groups.d \
./Free_rtos_Drivers/list.d \
./Free_rtos_Drivers/queue.d \
./Free_rtos_Drivers/stream_buffer.d \
./Free_rtos_Drivers/tasks.d \
./Free_rtos_Drivers/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Free_rtos_Drivers/%.o Free_rtos_Drivers/%.su Free_rtos_Drivers/%.cyclo: ../Free_rtos_Drivers/%.c Free_rtos_Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Drivers/CMSIS/Include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/include" -I"C:/Users/VasudevKesharwani/Documents/Embedded/workspace/17_freeRTOS_Projet_01/17_freeRTOS_Projet_01/Free_rtos_Drivers/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Free_rtos_Drivers

clean-Free_rtos_Drivers:
	-$(RM) ./Free_rtos_Drivers/croutine.cyclo ./Free_rtos_Drivers/croutine.d ./Free_rtos_Drivers/croutine.o ./Free_rtos_Drivers/croutine.su ./Free_rtos_Drivers/event_groups.cyclo ./Free_rtos_Drivers/event_groups.d ./Free_rtos_Drivers/event_groups.o ./Free_rtos_Drivers/event_groups.su ./Free_rtos_Drivers/list.cyclo ./Free_rtos_Drivers/list.d ./Free_rtos_Drivers/list.o ./Free_rtos_Drivers/list.su ./Free_rtos_Drivers/queue.cyclo ./Free_rtos_Drivers/queue.d ./Free_rtos_Drivers/queue.o ./Free_rtos_Drivers/queue.su ./Free_rtos_Drivers/stream_buffer.cyclo ./Free_rtos_Drivers/stream_buffer.d ./Free_rtos_Drivers/stream_buffer.o ./Free_rtos_Drivers/stream_buffer.su ./Free_rtos_Drivers/tasks.cyclo ./Free_rtos_Drivers/tasks.d ./Free_rtos_Drivers/tasks.o ./Free_rtos_Drivers/tasks.su ./Free_rtos_Drivers/timers.cyclo ./Free_rtos_Drivers/timers.d ./Free_rtos_Drivers/timers.o ./Free_rtos_Drivers/timers.su

.PHONY: clean-Free_rtos_Drivers

