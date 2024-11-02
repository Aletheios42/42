# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 02:37:23 by alepinto          #+#    #+#              #
#    Updated: 2023/10/07 03:54:57 by alepinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.c				\
		parser.c					\
		error.c					\
		rotate.c					\
		swap.c					\
		push.c					\
		utils.c					\
		args_checker.c			\
		execute.c					\
		

OBJ = $(SRC:%.c=%.o)

#COMPILER
CC = gcc
CFLAGS = -Werror -Wextra -Wall
CFLAGS += -g3 -fsanitize=address

#NAME
NAME = checker

#INCLUDES
INC_DIR = Libft
INC = -I $(INC_DIR)

#LINKER
LINK = -LLibft -lft

all: $(NAME)

$(NAME) :$(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

	
clean:
	@$(RM)  -f $(OBJ) $(OBJ_BONUS)|| true
	make fclean -sC Libft || true

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) || true

re: fclean all
