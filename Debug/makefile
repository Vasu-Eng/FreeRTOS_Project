################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include thirdparty/freeRTOS/portable/MemMang/subdir.mk
-include thirdparty/freeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include thirdparty/freeRTOS/subdir.mk
-include thirdparty/SEGGER/UART_RECORDER/subdir.mk
-include thirdparty/SEGGER/SEGGER/Syscalls/subdir.mk
-include thirdparty/SEGGER/SEGGER/subdir.mk
-include thirdparty/SEGGER/OS/subdir.mk
-include thirdparty/SEGGER/Config/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Project_freeRTOS_Learning
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Project_freeRTOS_Learning.elf \

MAP_FILES += \
Project_freeRTOS_Learning.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Project_freeRTOS_Learning.list \


# All Target
all: main-build

# Main-build Target
main-build: Project_freeRTOS_Learning.elf secondary-outputs

# Tool invocations
Project_freeRTOS_Learning.elf Project_freeRTOS_Learning.map: $(OBJS) $(USER_OBJS) C:\Users\kesha\Documents\Embedded\ Mastering\Git\ linked\ project\workspace\Project_freeRTOS_Learning\STM32F410RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Project_freeRTOS_Learning.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\kesha\Documents\Embedded Mastering\Git linked project\workspace\Project_freeRTOS_Learning\STM32F410RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Project_freeRTOS_Learning.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Project_freeRTOS_Learning.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Project_freeRTOS_Learning.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Project_freeRTOS_Learning.elf Project_freeRTOS_Learning.list Project_freeRTOS_Learning.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
