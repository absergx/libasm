section .text
global _ft_strcmp

_ft_strcmp:
		xor rax, rax
loop:
		mov al, byte[rdi]
		mov dl, byte[rsi]
		sub rax, rdx
		jnz finish
		cmp dl, 0
		je finish
		inc rdi
		inc rsi
		jmp loop
finish:
		ret