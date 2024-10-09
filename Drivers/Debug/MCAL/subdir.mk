################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32_F103C6_EXTI_Driver.c \
../MCAL/Stm32_F103C6_GPIO_Driver.c \
../MCAL/Stm32_F103C6_RCC_Driver.c \
../MCAL/Stm32_F103C6_USART_Driver.c 

OBJS += \
./MCAL/Stm32_F103C6_EXTI_Driver.o \
./MCAL/Stm32_F103C6_GPIO_Driver.o \
./MCAL/Stm32_F103C6_RCC_Driver.o \
./MCAL/Stm32_F103C6_USART_Driver.o 

C_DEPS += \
./MCAL/Stm32_F103C6_EXTI_Driver.d \
./MCAL/Stm32_F103C6_GPIO_Driver.d \
./MCAL/Stm32_F103C6_RCC_Driver.d \
./MCAL/Stm32_F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Stm32_F103C6_EXTI_Driver.o: ../MCAL/Stm32_F103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Kerolos Embedded Diploma/Lab/Unit_7/Driver_Project/Stm32_F103C6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_GPIO_Driver.o: ../MCAL/Stm32_F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Kerolos Embedded Diploma/Lab/Unit_7/Driver_Project/Stm32_F103C6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_RCC_Driver.o: ../MCAL/Stm32_F103C6_RCC_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Kerolos Embedded Diploma/Lab/Unit_7/Driver_Project/Stm32_F103C6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_USART_Driver.o: ../MCAL/Stm32_F103C6_USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Kerolos Embedded Diploma/Lab/Unit_7/Driver_Project/Stm32_F103C6_Drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

