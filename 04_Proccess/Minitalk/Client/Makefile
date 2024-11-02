# BINARY
NAME=client

# COMPILATION FLAGS
CF = -O0
# CF += -Wall -Wextra -Werror
# CF += -g3 -address=fsanitize
CF += -I$(INC_DIR)

# SOURCES
SRC_DIR=Src/
SRC_FILES = main.c \

SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECTS
OBJ_DIR=Obj/
OBJ_FILES=$(SRC_FILES:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# INCLUDES
INC_DIR=Inc/
INC_FILES = client.h
INC=$(addprefix $(INC_DIR), $(INC_FILES))

# LINKER
LINKER= $(LIBFT)

# LIBFT
LIBFT_DIR=Libft/
LIBFT_BIN=libft.a
LIBFT=$(addprefix $(LIBFT_DIR), $(LIBFT_BIN))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	gcc $(CF) $(OBJ) -o $(NAME)  $(LINKER)

$(LIBFT):
	make -sC Libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c  # Generar los archivos objeto en $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	gcc $(CF) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

