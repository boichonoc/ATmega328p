################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../ATmega328p_HAL_Driver/inc/ \
../ATmega328p_HAL_Driver \
../ATmega328p_HAL_Driver/src/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ATmega328p_HAL_Driver.c \
../ATmega328p_HAL_Driver/src/mega328p_hal_cpu.c \
../ATmega328p_HAL_Driver/src/mega328p_hal_gdio.c \
../ATmega328p_HAL_Driver/src/mega328p_hal_exti.c \
../ATmega328p_HAL_Driver/src/mega328p_hal_timer.c \
../ATmega328p_HAL_Driver/src/mega328p_hal_usart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ATmega328p_HAL_Driver.o \
ATmega328p_HAL_Driver/src/mega328p_hal_cpu.o \
ATmega328p_HAL_Driver/src/mega328p_hal_gdio.o \
ATmega328p_HAL_Driver/src/mega328p_hal_exti.o \
ATmega328p_HAL_Driver/src/mega328p_hal_timer.o \
ATmega328p_HAL_Driver/src/mega328p_hal_usart.o

OBJS_AS_ARGS +=  \
ATmega328p_HAL_Driver.o \
ATmega328p_HAL_Driver/src/mega328p_hal_cpu.o \
ATmega328p_HAL_Driver/src/mega328p_hal_gdio.o \
ATmega328p_HAL_Driver/src/mega328p_hal_exti.o \
ATmega328p_HAL_Driver/src/mega328p_hal_timer.o \
ATmega328p_HAL_Driver/src/mega328p_hal_usart.o

C_DEPS +=  \
ATmega328p_HAL_Driver.d \
ATmega328p_HAL_Driver/src/mega328p_hal_cpu.d \
ATmega328p_HAL_Driver/src/mega328p_hal_gdio.d \
ATmega328p_HAL_Driver/src/mega328p_hal_exti.d \
ATmega328p_HAL_Driver/src/mega328p_hal_timer.d \
ATmega328p_HAL_Driver/src/mega328p_hal_usart.d

C_DEPS_AS_ARGS +=  \
ATmega328p_HAL_Driver.d \
ATmega328p_HAL_Driver/src/mega328p_hal_cpu.d \
ATmega328p_HAL_Driver/src/mega328p_hal_gdio.d \
ATmega328p_HAL_Driver/src/mega328p_hal_exti.d \
ATmega328p_HAL_Driver/src/mega328p_hal_timer.d \
ATmega328p_HAL_Driver/src/mega328p_hal_usart.d

OUTPUT_FILE_PATH +=ATmega328p_HAL_Driver.elf

OUTPUT_FILE_PATH_AS_ARGS +=ATmega328p_HAL_Driver.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler













./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"../ATmega328p_HAL_Driver" -I"../ATmega328p_HAL_Driver/inc" -I"../ATmega328p_HAL_Driver/src" -I".."  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

ATmega328p_HAL_Driver/src/%.o: ../ATmega328p_HAL_Driver/src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"../ATmega328p_HAL_Driver" -I"../ATmega328p_HAL_Driver/inc" -I"../ATmega328p_HAL_Driver/src" -I".."  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ATmega328p_HAL_Driver.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ATmega328p_HAL_Driver.elf" "ATmega328p_HAL_Driver.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ATmega328p_HAL_Driver.elf" "ATmega328p_HAL_Driver.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ATmega328p_HAL_Driver.elf" > "ATmega328p_HAL_Driver.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ATmega328p_HAL_Driver.elf" "ATmega328p_HAL_Driver.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "ATmega328p_HAL_Driver.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ATmega328p_HAL_Driver.elf" "ATmega328p_HAL_Driver.a" "ATmega328p_HAL_Driver.hex" "ATmega328p_HAL_Driver.lss" "ATmega328p_HAL_Driver.eep" "ATmega328p_HAL_Driver.map" "ATmega328p_HAL_Driver.srec" "ATmega328p_HAL_Driver.usersignatures"
	