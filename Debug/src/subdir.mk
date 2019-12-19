################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Archivo.cpp \
../src/Ciudad.cpp \
../src/Estacion.cpp \
../src/Menu.cpp \
../src/Vertice.cpp \
../src/grafo.cpp \
../src/main.cpp 

OBJS += \
./src/Archivo.o \
./src/Ciudad.o \
./src/Estacion.o \
./src/Menu.o \
./src/Vertice.o \
./src/grafo.o \
./src/main.o 

CPP_DEPS += \
./src/Archivo.d \
./src/Ciudad.d \
./src/Estacion.d \
./src/Menu.d \
./src/Vertice.d \
./src/grafo.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


