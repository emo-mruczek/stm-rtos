# all:
# 	arm-none-eabi-gcc -O0 -nostdlib -lgcc -DSTM32F103x6 -mthumb -mcpu=cortex-m3 --specs=nosys.specs -Wall -fmessage-length=0 -T includes/STM32F103VBIx_FLASH.ld includes/startup_stm32f103x6.s main.c -o main.bin
#
# clean:
# 	rm *.bin


TARGET = main

INC = includes

CFLAGS += -mthumb
CFLAGS += -mcpu=cortex-m3
CFLAGS += --specs=nosys.specs
CFLAGS += -Wall
CFLAGS += -fmessage-length=0
CFLAGS += -DSTM32F103x6
CFLAGS += -O0

ASFLAGS = -c
ASFLAGS += -Wall
ASFLAGS += -mcpu=cortex-m3
ASFLAGS += -mthumb

LD_SCRIPT = $(INC)/STM32F103VBIx_FLASH.ld 

LFLAGS = -mcpu=cortex-m3
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += -lgcc
LFLAGS += --specs=nosys.specs
LFLAGS += -fmessage-length=0
LFLAGS += -nostdlib
LFLAGS += -T$(LD_SCRIPT)

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
OC = arm-none-eabi-objcopy
OS = arm-none-eabi-size

C_SRC = main.c
AS_SRC = $(INC)/startup_stm32f103x6.s

OBJS = $(C_SRC:.c=.o)
OBJS += $(AS_SRC:.s=.o) 	

.PHONY: all

all: $(TARGET).bin

%.o: %.s
	$(AS) $(ASFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

