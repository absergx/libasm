; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/10/12 15:04:30 by memilio           #+#    #+#              ;
;    Updated: 2020/10/12 15:06:25 by memilio          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global _ft_read
extern ___error

_ft_read:
		xor rax, rax
read:
		mov rax, 0x2000003
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