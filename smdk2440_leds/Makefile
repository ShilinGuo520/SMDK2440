ARM_CC	:=arm-none-eabi
OBJCOPY	:=$(ARM_CC)-objcopy
LD	:=$(ARM_CC)-ld
OBJDUMP	:=$(ARM_CC)-objdump
GCC	:=$(ARM_CC)-gcc

leds.bin:head.o main.o
	$(LD) -Tsmdk2440.lds -o leds.elf $^
	$(OBJCOPY) -O binary -S leds.elf $@
	$(OBJDUMP) -D -m arm leds.elf > leds.dis

%.o:%.c
	$(GCC) -Wall -O2 -c -o $@ $<

%.o:%.S
	$(GCC) -Wall -O2 -c -o $@ $<

clean:
	rm -f *.bin *.elf *.dis *.o


