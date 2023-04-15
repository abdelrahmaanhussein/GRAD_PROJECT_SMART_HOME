################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../APP.c \
../DIO.c \
../EEPROM.c \
../Keypad.c \
../LCD.c \
../LED.c \
../SERVO.c \
../SPI.c \
../TIMER0.c \
../TWI.c \
../UART.c \
../main.c 

OBJS += \
./ADC.o \
./APP.o \
./DIO.o \
./EEPROM.o \
./Keypad.o \
./LCD.o \
./LED.o \
./SERVO.o \
./SPI.o \
./TIMER0.o \
./TWI.o \
./UART.o \
./main.o 

C_DEPS += \
./ADC.d \
./APP.d \
./DIO.d \
./EEPROM.d \
./Keypad.d \
./LCD.d \
./LED.d \
./SERVO.d \
./SPI.d \
./TIMER0.d \
./TWI.d \
./UART.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


