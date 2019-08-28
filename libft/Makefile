# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhouston <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 14:39:17 by jhouston          #+#    #+#              #
#    Updated: 2019/07/08 13:32:39 by jhouston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
CC= gcc
FILES= ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_strdel.c ft_strlen.c ft_strnew.c ft_strtrim.c ft_isascii.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_strdup.c ft_strmap.c ft_strnstr.c ft_tolower.c ft_isdigit.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_strequ.c ft_strmapi.c ft_strrchr.c ft_toupper.c ft_atoi.c ft_isprint.c ft_memdel.c ft_putnbr.c ft_strcmp.c ft_striter.c ft_strncat.c ft_strrev.c ft_wordcount.c ft_bzero.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strcnlen.c ft_striteri.c ft_strncmp.c ft_strsplit.c ft_intlen.c ft_memalloc.c ft_memset.c ft_putstr.c ft_strcpy.c ft_strjoin.c ft_strncpy.c ft_strstr.c ft_isalnum.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c ft_strcreturn.c ft_strlcat.c ft_strnequ.c ft_strsub.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstadd.c ft_lstmap.c
OBJ= $(FILES:.c=.o)
FLAGS= -Wall -Werror -Wextra
LIB= libft.h

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(FILES)
	ar rv $(NAME) $(OBJ) $(LIB)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
