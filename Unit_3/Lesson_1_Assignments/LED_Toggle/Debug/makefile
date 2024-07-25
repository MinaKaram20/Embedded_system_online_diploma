################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Unit_3_Assignment.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Unit_3_Assignment.list \

OBJCOPY_HEX += \
Unit_3_Assignment.hex \

OBJCOPY_BIN += \
Unit_3_Assignment.bin \


# All Target
all: Unit_3_Assignment.elf secondary-outputs

# Tool invocations
Unit_3_Assignment.elf: $(OBJS) $(USER_OBJS) D:\Kerolos\ Embedded\ Diploma\Lab\Unit_3\Unit_3_Assignment\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Unit_3_Assignment.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Kerolos Embedded Diploma\Lab\Unit_3\Unit_3_Assignment\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Unit_3_Assignment.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Unit_3_Assignment.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Unit_3_Assignment.list"
	@echo 'Finished building: $@'
	@echo ' '

Unit_3_Assignment.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Unit_3_Assignment.hex"
	@echo 'Finished building: $@'
	@echo ' '

Unit_3_Assignment.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Unit_3_Assignment.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
