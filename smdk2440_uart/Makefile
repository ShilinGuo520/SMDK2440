ARM_CC	:=arm-none-eabi
OBJCOPY	:=$(ARM_CC)-objcopy
LD	:=$(ARM_CC)-ld
OBJDUMP	:=$(ARM_CC)-objdump
GCC	:=$(ARM_CC)-gcc

obj = main
TARGET = main.bin

OBJ +=head.o
OBJ +=main.o
OBJ +=uart.o
OBJ +=lowlevel_init.o

CFLAGS += -I ./include/

$(TARGET):$(OBJ)
	$(LD) -Tsmdk2440.lds -o $(obj).elf $^
	$(OBJCOPY) -O binary -S $(obj).elf $@
	$(OBJDUMP) -D -m arm $(obj).elf > $(obj).dis

%.o:%.c
	$(GCC) $(CFLAGS) -Wall -O2 -c -o $@ $<

%.o:%.S
	$(GCC) $(CFLAGS) -Wall -O2 -c -o $@ $<

clean:
	rm -f *.bin *.elf *.dis *.o


