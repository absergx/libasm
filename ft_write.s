; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/15 12:14:36 by memilio           #+#    #+#              ;
;    Updated: 2020/09/17 12:26:10 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_write
extern ___error

_ft_write:
		xor rax, rax
write:
		mov rax, 0x2000004
		syscall
		jc err
		ret
err:
		push rax
		call ___error
		pop rdx
		mov [rax], edx
		mov rax, -1
		ret