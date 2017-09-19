global kernel_stack
global loader
MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 4096
section .text
align 4
	dd MAGIC_NUMBER
	dd FLAGS
	dd CHECKSUM
loader:
	mov eax, 0xCAFEBABE
section .bss
align 4
kernel_stack:
	resb KERNEL_STACK_SIZE
section .data
align 4

mov esp, kernel_stack + KERNEL_STACK_SIZE 

extern sum_of_three

push dword 3
mov esp, kernel_stack + KERNEL_STACK_SIZE
push dword 2 
mov esp, kernel_stack + KERNEL_STACK_SIZE
push dword 1
call sum_of_three
