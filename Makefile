# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouston <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 13:22:47 by jhouston          #+#    #+#              #
#    Updated: 2019/09/02 13:39:35 by jhouston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CC = gcc -o ft_ls
FLAGS = -Wall -Wextra -Werror
FILES= ft_ls.c
LIBFT= libft/libft.a

all:
	$(CC) $(FILES) $(LIBFT) $(FLAGS)
