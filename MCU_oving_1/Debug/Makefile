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
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../switch.c \
../led.c \
../MCU_oving_1.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
switch.o \
led.o \
MCU_oving_1.o

OBJS_AS_ARGS +=  \
switch.o \
led.o \
MCU_oving_1.o

C_DEPS +=  \
switch.d \
led.d \
MCU_oving_1.d

C_DEPS_AS_ARGS +=  \
switch.d \
led.d \
MCU_oving_1.d

OUTPUT_FILE_PATH +=MCU_oving_1.elf

OUTPUT_FILE_PATH_AS_ARGS +=MCU_oving_1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler







./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=at90usb1287 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	$(QUOTE)F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="MCU_oving_1.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=at90usb1287  
	@echo Finished building target: $@
	"F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "MCU_oving_1.elf" "MCU_oving_1.hex"
	"F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "MCU_oving_1.elf" "MCU_oving_1.eep" || exit 0
	"F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "MCU_oving_1.elf" > "MCU_oving_1.lss"
	"F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "MCU_oving_1.elf" "MCU_oving_1.srec"
	"F:\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "MCU_oving_1.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "MCU_oving_1.elf" "MCU_oving_1.a" "MCU_oving_1.hex" "MCU_oving_1.lss" "MCU_oving_1.eep" "MCU_oving_1.map" "MCU_oving_1.srec" "MCU_oving_1.usersignatures"
	