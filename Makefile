# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/01/21 13:33:47 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c \
	  src/buffer.c \
	  src/ft_write_cspdiu.c \
	  src/ft_write_xXpctl.c

INC = inc/ft_printf.h

DBRULE =

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C libft $(DBRULE)
	cp ./libft/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : DBRULE += redebug
debug : main

main : all
	$(CC) $(CFLAGS) ../main.c libftprintf.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	make -C libft/ fclean

re : fclean $(NAME)

redebug : fclean debug

.PHONY :  all debug main clean fclean re redebug
