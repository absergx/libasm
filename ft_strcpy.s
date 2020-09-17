; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/15 10:42:03 by memilio           #+#    #+#              ;
;    Updated: 2020/09/17 12:26:02 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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