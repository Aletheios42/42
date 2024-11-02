#OUTPUT
BINARY = so_long

#COMMANDS
CC = gcc
CFLAGS = -O
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -g3 -fsanitize=address
RM = rm -rf

#INCLUDES
DIR_INCLUDES = ./Inc/
FILES_INCLUDES = so_long.h
INCLUDES = $(addprefix -I, $(DIR_INCLUDES))

#LIBRARIES
LINKER =
#LIBFT
DIR_LIBFT = ./Libft/
LIBFT = libft.a
LINKER += -L$(DIR_LIBFT) -lft

#SOURCES
DIR_SOURCES = ./Src/
FILES_SOURCES = main.c \
                render.c \
                parser.c

SOURCES = $(addprefix $(DIR_SOURCES), $(FILES_SOURCES))

#OBJECTS
DIR_OBJ = ./Obj/
OBJECTS = $(addprefix $(DIR_OBJ), $(FILES_SOURCES:.c=.o))

all: $(BINARY)

$(BINARY): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(LINKER) $(OBJECTS) -o $(BINARY)

$(LIBFT):
	make -sC $(DIR_LIBFT)

# Rule to compile .c files to .o files in the Obj directory
$(DIR_OBJ)%.o: $(DIR_SOURCES)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -sC $(DIR_LIBFT) clean
	$(RM) $(DIR_OBJ)

fclean: clean
	$(RM) $(BINARY)
	$(RM) $(DIR_LIBFT)$(LIBFT)

dev: all
	@$(MAKE) clean

re: fclean all

.PHONY: clean fclean re dev

