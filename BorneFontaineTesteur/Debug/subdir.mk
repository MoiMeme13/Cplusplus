################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BorneFontaineTesteur.cpp 

OBJS += \
./BorneFontaineTesteur.o 

CPP_DEPS += \
./BorneFontaineTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
BorneFontaineTesteur.o: ../BorneFontaineTesteur.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/etudiant/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"BorneFontaineTesteur.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


