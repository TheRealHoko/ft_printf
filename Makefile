# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 18:10:22 by jzeybel           #+#    #+#              #
#    Updated: 2021/01/08 17:36:29 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC  = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C libft
	cp ./libft/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) ../main.c libftprintf.a

all : $(NAME)
	$(CC) $(CFLAGS) ../main.c libftprintf.a

debug : CFLAGS += -g -fsanitize=address
debug : $(NAME)

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

.PHONY :  all debug clean fclean re redebug
