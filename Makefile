#! Makefile

# set source file and object file
C_SOURCES = $(shell find . name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

# set compiler
CC  = gcc
LD  = ld
ASM = nasm
QEMU = qemu-system-i386

# set compiler flags
# -c for generate object but not link
# -m32 for generate 32 bit
# -ggdb for generate as much debugging information as possible for GDB to use
# -gstabs+ for generate ebugging information in STABS format and contains additional debugging information for use only by GDB.
# -nostdinc no longer used in the default directory of the system header files
# -fno-pic no position-independent code
# -fno-builtin no builtin funciton
# -fno-stack-protector disables stack protection
C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-pic -fno-builtin -fno-stack-protector -I ./include
# -T commandfile
# -m Emulate the emulation linker use i386 means 32 bit
# -nostdlib do not use the standard system startup files or libraries when linking
LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
# -f elf used to specify the format of the compiled.o file is elf
# -g for debug
# -F stabs debug use stabs format
ASM_FLAGS = -f elf -g -F stabs

all: $(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
    @echo compile c source $< ...
    $(CC) $(C_FLAGS) $< -o $@

.s.o:
    @echo compile asm source $< ...
    $(ASM) $(ASM_FLAGS) $<

link:
    @echo link ...
    $(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o tony_kernel

.PHONY:clean
clean:
    $(RM) $(S_OBJECTS) $(C_OBJECTS) hx_kernel

.PHONY:update_image
update_image:
    sudo mount floppy.img /mnt/kernel
    sudo cp hx_kernel /mnt/kernel/hx_kernel
    sleep 1
    sudo umount /mnt/kernel

.PHONY:mount_image
mount_image:
    sudo mount floppy.img /mnt/kernel

.PHONY:umount_image
umount_image:
    sudo umount /mnt/kernel

.PHONY:qemu
qemu:
    $(QEMU) -fda floppy.img -boot a

.PHONY:bochs
bochs:
    bochs -f tools/bochsrc.txt

.PHONY:debug
debug:
    # -S hang CPU wait
    # -s mean -gdb :1234
    $(QEMU) -S -s -fda floppy.img -boot a &
    sleep 1
    cgdb -x tools/gdbinit

.PHONY:clean
    @echo clean