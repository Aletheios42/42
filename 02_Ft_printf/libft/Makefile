# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:55:49 by alepinto          #+#    #+#              #
#    Updated: 2023/04/13 07:05:17 by alepinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = libft.a

# COMPILER
CC = gcc

CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -Wpedantic -Wshadow -fsanitize=address -g3
# -Wconversion 

# FILES
SRC =	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c 	\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\

OBJ = $(SRC:%.c=%.o)

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) || true

fclean: clean
	rm -f $(NAME) || true

re: fclean all

.PHONY: all clean fclean re
