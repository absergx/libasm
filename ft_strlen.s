; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/15 10:42:03 by memilio           #+#    #+#              ;
;    Updated: 2020/09/17 12:26:08 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_strlen

_ft_strlen:
		xor rax, rax
loop:
		cmp byte[rdi + rax], 0
		je finish
		inc rax
		jmp loop
finish:
		ret