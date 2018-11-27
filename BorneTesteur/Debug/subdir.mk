################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BorneTesteur.cpp 

OBJS += \
./BorneTesteur.o 

CPP_DEPS += \
./BorneTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
BorneTesteur.o: ../BorneTesteur.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/etudiant/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"BorneTesteur.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


