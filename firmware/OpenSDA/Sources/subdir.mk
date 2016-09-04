################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/BLDC.c" \
"../Sources/Clock.c" \
"../Sources/CmdProcessing.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/USB.c" \

C_SRCS += \
../Sources/BLDC.c \
../Sources/Clock.c \
../Sources/CmdProcessing.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/USB.c \

OBJS += \
./Sources/BLDC.o \
./Sources/Clock.o \
./Sources/CmdProcessing.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/USB.o \

C_DEPS += \
./Sources/BLDC.d \
./Sources/Clock.d \
./Sources/CmdProcessing.d \
./Sources/Events.d \
./Sources/ProcessorExpert.d \
./Sources/USB.d \

OBJS_QUOTED += \
"./Sources/BLDC.o" \
"./Sources/Clock.o" \
"./Sources/CmdProcessing.o" \
"./Sources/Events.o" \
"./Sources/ProcessorExpert.o" \
"./Sources/USB.o" \

C_DEPS_QUOTED += \
"./Sources/BLDC.d" \
"./Sources/Clock.d" \
"./Sources/CmdProcessing.d" \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/USB.d" \

OBJS_OS_FORMAT += \
./Sources/BLDC.o \
./Sources/Clock.o \
./Sources/CmdProcessing.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/USB.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/BLDC.o: ../Sources/BLDC.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/BLDC.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/BLDC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Clock.o: ../Sources/Clock.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Clock.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Clock.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CmdProcessing.o: ../Sources/CmdProcessing.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CmdProcessing.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CmdProcessing.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/USB.o: ../Sources/USB.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/USB.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/USB.o"
	@echo 'Finished building: $<'
	@echo ' '


