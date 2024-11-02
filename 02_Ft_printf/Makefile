# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:55:49 by alepinto          #+#    #+#              #
#    Updated: 2023/04/13 07:03:17 by alepinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### NAME #####

NAME = libftprintf.a

##### COMPILER #####

CC = gcc

CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -Wpedantic -Wshadow -fsanitize=address -g3
# -Wconversion 

##### FILES #####

SRC =	ft_printf.c			\
		ft_typechecker.c	\
		ft_putnbr.c			\
		ft_putunbr.c		\
		ft_puthex.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putptr.c			\

OBJ = $(SRC:%.c=%.o)

##### LIBS #####

LFT_NAME = libft.a
LFT_DIR = libft
LFT = $(LFT_DIR)/$(LFT_NAME)

##### RULES #####

all: $(NAME)

$(NAME): $(OBJ) $(LFT)
	cp $(LFT) .
	mv $(LFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LFT):
	make -sC $(LFT_DIR)

clean:
	make fclean -sC $(LFT_DIR)
	rm -f $(OBJ) || true

fclean: clean
	rm -f $(NAME) || true

re: fclean all

.PHONY: all clean fclean re
