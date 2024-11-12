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
FILES_INCLUDES = so_long.h	\
								 structs.h
INCLUDES = $(addprefix -I, $(DIR_INCLUDES))

#LIBRARIES
LINKER =
#LIBFT
DIR_LIBFT = ./Libft/
LIBFT = libft.a
LINKER += -L$(DIR_LIBFT) -lft
#MLX
MLX_PATH    = ./minilibx_linux/
MLX         = libmlx_Linux.a
ifeq ($(UNAME), Darwin)
	# mac
    FLAGS += -D MAC_OS -Iminilibx_macos
    LINKER += -framework OpenGL -framework AppKit 
    MINILIBX = libmlx.a
    DIR_MLX  = ./minilibx_macos
else
	#Linux and others...
    LINKER += -lbsd  -lXext -lX11
    MLX = libmlx.a
    DIR_MLX = ./minilibx_linux
endif
LINKER += -L$(DIR_MLX) -lmlx

#SOURCES
DIR_SOURCES = ./Src/
FILES_SOURCES = main.c 			\
                render.c 		\
                parser.c		\
								mlx.c				\
								handler.c
SOURCES = $(addprefix $(DIR_SOURCES), $(FILES_SOURCES))

#OBJECTS
DIR_OBJ = ./Obj/
OBJECTS = $(addprefix $(DIR_OBJ), $(FILES_SOURCES:.c=.o))

all: $(BINARY)

$(BINARY): $(LIBFT) $(OBJECTS) $(MLX)
	@printf "\n$(CY)Generating $(NAME) executable...$(RC)\n"
	$(CC) $(CFLAGS)  $(OBJECTS) $(LINKER) -o $(BINARY)
	@printf "$(GR)Done!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	make -sC $(DIR_LIBFT)
	@printf "$(GR)Libft created!$(RC)\n\n"

$(MLX):
	@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
	@make -sC $(MLX_PATH)
	@printf "$(GR)MiniLibX created!$(RC)\n\n"

$(DIR_OBJ)%.o: $(DIR_SOURCES)%.c
	mkdir -p $(DIR_OBJ)
	@printf "\n$(CY)Compiling $<...$(RC)\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GR)Object $@ ready!$(RC)\n"

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

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

