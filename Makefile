# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouston <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 13:22:47 by jhouston          #+#    #+#              #
#    Updated: 2019/09/14 08:26:55 by jhouston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lib_ls.a
ACC= gcc -c
CC = gcc -o ft_ls
FLAGS = -Wall -Wextra -Werror
FILES= ./srcs/*.c
OBJ= *.o
LIBFT= libft/libft.a
LIB= lib_ls.h

all: $(NAME)

$(NAME):
	make -C "./libft"
	$(ACC) $(FILES) $(FLAGS)
	ar rv $(NAME) $(OBJ) $(LIB)
	ranlib $(NAME)
	$(CC) $(FILES) $(LIBFT) $(FLAGS)


clean:
	make -C "./libft" clean
	rm -f $(OBJ)

fclean: clean
	make -C "./libft" fclean
	rm -f $(NAME)

re: clean all
