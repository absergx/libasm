; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/15 10:42:03 by memilio           #+#    #+#              ;
;    Updated: 2020/09/17 12:26:05 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
		xor rax, rax
strdup:
		push rdi
		call _ft_strlen
		mov rdi, rax
		inc rdi
		call _malloc
		cmp rax, 0
		je finish
		pop rsi
		mov rdi, rax
		call _ft_strcpy
		ret
finish:
		ret