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
		parser.c			\
		error.c				\
		rotate.c			\
		swap.c				\
		push.c				\
		utils.c				\
		args_checker.c		\
		sort.c				\
		dst.c				\
		weight.c			\
		
SRC_BONUS = main_bonus.c				\
		parser_bonus.c					\
		error_bonus.c					\
		rotate_bonus.c					\
		swap_bonus.c					\
		push_bonus.c					\
		utils_bonus.c					\
		args_checker_bonus.c			\
		execute_bonus.c					\
		

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

#COMPILER
CC = gcc
CFLAGS = -Werror -Wextra -Wall
CFLAGS += -g3 -fsanitize=address

#NAME
NAME = push_swap
NAME_BONUS = $(addprefix $(CHECKER_DIR), "checker")

#INCLUDES
INC_DIR = Libft
INC = -I $(INC_DIR)
CHECKER_DIR = ../Checker/

#LINKER
LINK = -LLibft -lft

all: $(NAME)

$(NAME) :$(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS) :
	make -sC $(CHECKER_DIR)
	
clean:
	@$(RM)  -f $(OBJ)
	
	make fclean -sC $(INC_DIR)
	make fclean -sC $(CHECKER_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) || true

re: fclean all
