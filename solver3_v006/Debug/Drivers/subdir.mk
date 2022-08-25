################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/FW_7seg.c \
../Drivers/FW_GPIO.c \
../Drivers/FW_Stepper.c \
../Drivers/FW_Systick.c \
../Drivers/FW_Timer.c \
../Drivers/FW_UART.c 

OBJS += \
./Drivers/FW_7seg.o \
./Drivers/FW_GPIO.o \
./Drivers/FW_Stepper.o \
./Drivers/FW_Systick.o \
./Drivers/FW_Timer.o \
./Drivers/FW_UART.o 

C_DEPS += \
./Drivers/FW_7seg.d \
./Drivers/FW_GPIO.d \
./Drivers/FW_Stepper.d \
./Drivers/FW_Systick.d \
./Drivers/FW_Timer.d \
./Drivers/FW_UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Aplicacion" -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Drivers" -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


