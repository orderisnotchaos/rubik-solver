################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_7seg.c \
../Primitivas/PR_Crono.c \
../Primitivas/PR_Serial.c \
../Primitivas/PR_cube.c \
../Primitivas/PR_stepper.c \
../Primitivas/PR_string.c \
../Primitivas/ProyecInit.c 

OBJS += \
./Primitivas/PR_7seg.o \
./Primitivas/PR_Crono.o \
./Primitivas/PR_Serial.o \
./Primitivas/PR_cube.o \
./Primitivas/PR_stepper.o \
./Primitivas/PR_string.o \
./Primitivas/ProyecInit.o 

C_DEPS += \
./Primitivas/PR_7seg.d \
./Primitivas/PR_Crono.d \
./Primitivas/PR_Serial.d \
./Primitivas/PR_cube.d \
./Primitivas/PR_stepper.d \
./Primitivas/PR_string.d \
./Primitivas/ProyecInit.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Aplicacion" -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Drivers" -I"/home/fede/Documents/LPCXpresso/proyecto/solver3_v005/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


