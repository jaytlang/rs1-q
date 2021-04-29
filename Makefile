SRC = $(shell find src/ -iname "*.c")
ASRC = $(shell find src/ -iname "*.S")

OBJ = $(SRC:.c=.o)
AOBJ = $(ASRC:.S=.o)

DEP = $(OBJ:.o=.d)
ADEP = $(AOBJ:.o=.d)

ELF = kernel8.elf
IMG = kernel8.img
MAP = kernel8.map

CC = clang
CFLAGS = --target=aarch64-elf -Wall -Wextra -Werror
CFLAGS += -O2 -g -MD -mcpu=cortex-a53
CFLAGS += -ffreestanding -nostdinc -nostdlib
CFLAGS += -pedantic -ansi -Iinclude

LD = ld.lld
LDSCRIPT = rs1.ld
LDFLAGS = -m aarch64elf -nostdlib
LDFLAGS += -T $(LDSCRIPT) --Map $(MAP)

OBJCOPY = llvm-objcopy
OBJCOPYFLAGS = -O binary

QEMU = qemu-system-aarch64
QEMUFLAGS = -M raspi3 -kernel $(IMG)
QEMUFLAGS += -serial null -serial stdio

.PHONY: all
all: $(IMG)

$(IMG): $(ELF)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(ELF): $(OBJ) $(AOBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

-include $(DEP) $(ADEP)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.S
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: sim
sim: $(IMG)
	@echo "Now run 'target remote localhost:1234' in gdb-multiarch"
	$(QEMU) $(QEMUFLAGS)

.PHONY: clean format
clean:
	$(RM) $(IMG) $(ELF) $(MAP) $(OBJ) $(DEP) $(AOBJ) $(ADEP)

format:
	find . -iname *.h -o -iname *.c | xargs clang-format -i
	find . -iname *.h -o -iname *.c | xargs sed -i 's/\ {/{/'
	find . -iname *.h -o -iname *.c | xargs sed -i 's/}\ /}/'	
