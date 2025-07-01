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
CFLAGS += -msoft-float
CFLAGS += -mfloat-abi=soft
CFLAGS += -DVVC_F1
CFLAGS += -DVVC_STM32f103C6

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
LFLAGS += -msoft-float
LFLAGS += -mfloat-abi=soft
LFLAGS += --static
LFLAGS += -Wl, -Map=$(TARGET).map
LFLAGS += -Wl, --gc-sections
LFLAGS += -lc
LFLAGS += -T$(LD_SCRIPT)

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
OC = arm-none-eabi-objcopy
OS = arm-none-eabi-size

C_SRC = main.c
C_SRC += ./frtos/portable/GCC/ARM_CM3/port.c
C_SRC += ./frtos/list.c
C_SRC += ./frtos/tasks.c
C_SRC += ./frtos/queue.c
C_SRC += ./frtos/portable/MemMang/heap_4.c

AS_SRC = $(INC)/startup_stm32f103x6.s

INCLUDE = -I./
INCLUDE += -I./includes
INCLUDE += -I./frtos/include
INCLUDE += -I./frtos/portable/GCC/ARM_CM3

OBJS = $(C_SRC:.c=.o)
OBJS += $(AS_SRC:.s=.o) 	

.PHONY: all

all: $(TARGET).bin

%.o: %.s
	$(AS) $(ASFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean

clean:
	rm -f $(OBJS)
	rm -f $(TARGET).elf
	rm -f $(TARGET).bin
	rm -f $(TARGET).map

