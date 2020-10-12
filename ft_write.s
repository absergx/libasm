; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/10/12 15:04:23 by memilio           #+#    #+#              ;
;    Updated: 2020/10/12 15:06:29 by memilio          ###   ########.fr        ;
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
		mov [rax], rdx
		mov rax, -1
		ret