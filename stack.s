;Defines stack for use in C programs.

KERNEL_STACK_SIZE equ 4096

section .bss
align 4
kernel_stack:
	resb KERNEL_STACK_ SIZE
	mov esp, kernel_stack + KERNEL_STACK_SIZE
