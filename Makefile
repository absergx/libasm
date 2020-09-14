# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 23:56:12 by memilio           #+#    #+#              #
#    Updated: 2020/09/02 00:35:14 by memilio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
FILES =			ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
FILES_BONUS =	
OBJS = $(FILES:.s=.o)
OBJS_BONUS = $(FILES_BONUS:.s=.o)
FLAGS = -Wall -Werror -Wextra
LIBC = ar rcs

.s.o:
	nasm -f macho64 -o $@ $<

$(NAME): ${OBJS}
	@${LIBC} $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_BONUS)
	${LIBC} $(NAME) $(OBJS_BONUS)

clean:
	/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	/bin/rm -f $(NAME) $(bonus)

re: fclean all

test: all
	@gcc $(FLAGS) main.c -L. -lasm -o test $(NAME)
	@./test
	@rm test

.PHONY: all bonus clean fclean re test