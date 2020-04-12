################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PruebasTAD_Casilla.cpp \
../src/PruebasTAD_Tablero.cpp \
../src/TAD_Casilla.cpp \
../src/TAD_Juego.cpp \
../src/TAD_Tablero.cpp \
../src/entorno.cpp \
../src/main.cpp 

OBJS += \
./src/PruebasTAD_Casilla.o \
./src/PruebasTAD_Tablero.o \
./src/TAD_Casilla.o \
./src/TAD_Juego.o \
./src/TAD_Tablero.o \
./src/entorno.o \
./src/main.o 

CPP_DEPS += \
./src/PruebasTAD_Casilla.d \
./src/PruebasTAD_Tablero.d \
./src/TAD_Casilla.d \
./src/TAD_Juego.d \
./src/TAD_Tablero.d \
./src/entorno.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


