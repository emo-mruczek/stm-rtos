all:
	arm-none-eabi-gcc -O0 -nostdlib -lgcc -DSTM32F103x6 -mthumb -mcpu=cortex-m3 --specs=nosys.specs -Wall -fmessage-length=0 -T STM32F103VBIx_FLASH.ld startup_stm32f103x6.s main.c -o main.bin

clean:
	rm *.bin
