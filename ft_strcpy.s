section .text
global _ft_strcpy

_ft_strcpy:
		xor rax, rax
loop:
		mov cl, byte[rsi + rax]
		cmp cl, 0
		je finish
		mov byte[rdi + rax], cl
		inc rax
		jmp loop
finish:
		mov byte[rdi + rax], 0
		mov rax, rdi
		ret