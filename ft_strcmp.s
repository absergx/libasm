; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/15 10:42:03 by memilio           #+#    #+#              ;
;    Updated: 2020/09/17 12:25:55 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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