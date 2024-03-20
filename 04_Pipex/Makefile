# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 20:52:44 by alepinto          #+#    #+#              #
#    Updated: 2023/07/11 10:31:18 by alepinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c 		\
		ft_pipex.c	\
		ft_parser.c	\
		ft_child.c	\
		ft_utils.c	\
		ft_error.c	\

OBJ = $(SRC:%.c=%.o)

####COMPILER
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror 

CFLAGS += -fsanitize=address -g3

####NAME
NAME = pipex

####LIBS
INC_DIR = Libft
INC = -I $(INC_DIR)

####LINKER

LDFLAGS = -LLibft -lft

LDFLAGS += -g3 -fsanitize=address

####RULES

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(LDFLAGS)  -o $(NAME)

clean:
	@$(RM) $(OBJ) || true
	make fclean -sC ./Libft || true

fclean: clean
	$(RM) $(NAME)

bonus:: CFLAGS += -D BONUS=1
bonus: re

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re

