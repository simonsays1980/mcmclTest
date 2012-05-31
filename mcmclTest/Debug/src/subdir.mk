################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/basic_mcmc_bondTest.cpp \
../src/constant_argument_makerTest.cpp \
../src/identity_argument_makerTest.cpp \
../src/mcmc_parameterTest.cpp \
../src/mcmclTest.cpp 

OBJS += \
./src/basic_mcmc_bondTest.o \
./src/constant_argument_makerTest.o \
./src/identity_argument_makerTest.o \
./src/mcmc_parameterTest.o \
./src/mcmclTest.o 

CPP_DEPS += \
./src/basic_mcmc_bondTest.d \
./src/constant_argument_makerTest.d \
./src/identity_argument_makerTest.d \
./src/mcmc_parameterTest.d \
./src/mcmclTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/boost_1_49_0 -I/Users/simonzehnder/Documents/workspace/mcmcl/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


