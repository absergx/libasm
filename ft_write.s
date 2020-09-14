section .text
global _ft_write
extern __error

_ft_read:
		xor rax, rax
write:
		mov rax, 0x2000004
		syscall
		jc err
		ret
err:
		push rax
		call __error
		pop rdx
		mov [rax], edx
		mov rax, -1
		ret