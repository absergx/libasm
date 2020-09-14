; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/01 23:59:24 by memilio           #+#    #+#              ;
;    Updated: 2020/09/02 11:50:59 by memilio          ###   ########.fr        ;
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