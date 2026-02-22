################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/freeRTOS/croutine.c \
../thirdparty/freeRTOS/event_groups.c \
../thirdparty/freeRTOS/list.c \
../thirdparty/freeRTOS/queue.c \
../thirdparty/freeRTOS/stream_buffer.c \
../thirdparty/freeRTOS/tasks.c \
../thirdparty/freeRTOS/timers.c 

OBJS += \
./thirdparty/freeRTOS/croutine.o \
./thirdparty/freeRTOS/event_groups.o \
./thirdparty/freeRTOS/list.o \
./thirdparty/freeRTOS/queue.o \
./thirdparty/freeRTOS/stream_buffer.o \
./thirdparty/freeRTOS/tasks.o \
./thirdparty/freeRTOS/timers.o 

C_DEPS += \
./thirdparty/freeRTOS/croutine.d \
./thirdparty/freeRTOS/event_groups.d \
./thirdparty/freeRTOS/list.d \
./thirdparty/freeRTOS/queue.d \
./thirdparty/freeRTOS/stream_buffer.d \
./thirdparty/freeRTOS/tasks.d \
./thirdparty/freeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/freeRTOS/%.o thirdparty/freeRTOS/%.su thirdparty/freeRTOS/%.cyclo: ../thirdparty/freeRTOS/%.c thirdparty/freeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DSTM32F410RBTx -DSTM32 -DNUCLEO_F410RB -DSTM32F4 -c -I../Inc -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/Drivers/CMSIS/Include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/include" -I"C:/Users/kesha/Documents/Embedded Mastering/Git linked project/workspace/Project_freeRTOS_Learning/thirdparty/freeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-thirdparty-2f-freeRTOS

clean-thirdparty-2f-freeRTOS:
	-$(RM) ./thirdparty/freeRTOS/croutine.cyclo ./thirdparty/freeRTOS/croutine.d ./thirdparty/freeRTOS/croutine.o ./thirdparty/freeRTOS/croutine.su ./thirdparty/freeRTOS/event_groups.cyclo ./thirdparty/freeRTOS/event_groups.d ./thirdparty/freeRTOS/event_groups.o ./thirdparty/freeRTOS/event_groups.su ./thirdparty/freeRTOS/list.cyclo ./thirdparty/freeRTOS/list.d ./thirdparty/freeRTOS/list.o ./thirdparty/freeRTOS/list.su ./thirdparty/freeRTOS/queue.cyclo ./thirdparty/freeRTOS/queue.d ./thirdparty/freeRTOS/queue.o ./thirdparty/freeRTOS/queue.su ./thirdparty/freeRTOS/stream_buffer.cyclo ./thirdparty/freeRTOS/stream_buffer.d ./thirdparty/freeRTOS/stream_buffer.o ./thirdparty/freeRTOS/stream_buffer.su ./thirdparty/freeRTOS/tasks.cyclo ./thirdparty/freeRTOS/tasks.d ./thirdparty/freeRTOS/tasks.o ./thirdparty/freeRTOS/tasks.su ./thirdparty/freeRTOS/timers.cyclo ./thirdparty/freeRTOS/timers.d ./thirdparty/freeRTOS/timers.o ./thirdparty/freeRTOS/timers.su

.PHONY: clean-thirdparty-2f-freeRTOS

