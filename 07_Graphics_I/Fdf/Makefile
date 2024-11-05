NAME        = fdf

LFT_PATH    = ./Libft/
LIBFT       = libft.a

MLX_PATH    = ./minilibx_linux/
MLX         = libmlx_Linux.a
ifeq ($(UNAME), Darwin)
	# mac
    FLAGS += -D MAC_OS -Iminilibx_macos
    LD += -framework OpenGL -framework AppKit -L minilibx_macos -lmlx 
    MINILIBX = minilibx_macos/libmlx.a
    MINILIB_PATH = ./minilibx_macos
else
	#Linux and others...
    MLX_CF += -lbsd -L minilibx-linux -lmlx -lXext -lX11
    MLX = minilibx_linux/libmlx.a
    MINILIB_PATH = ./minilibx-linux
endif

INC_DIR     = ./Inc/
INC_FILES   = fdf.h \
               color.h \
               keys.h
INC         = $(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR     = ./Src/
SRC_FILES   = main.c 				\
               init.c 			\
               parser.c 		\
               automaton.c 	\
               actions.c 		\
							 mlx.c				\
							 utils.c			\


SRC         = $(addprefix $(SRC_DIR), $(SRC_FILES))
# Comp# Cambiar para almacenar los archivos .o en el directorio objs/
OBJ_DIR     = ./objs/
OBJ         = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CF          = -Wall -Wextra -Werror

CF					+= -g3 -fsanitize=address

CC          = gcc
MLX_CF      = -lm -lbsd -lmlx -lXext -lX11
CFI         = -I$(INC_DIR)

# Common commands
RM          = rm -f

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "\n$(CY)Generating FdF executable...$(RC)\n"
	$(CC) $(CF) -o $(NAME) $(OBJ) -L $(LFT_PATH) -L $(MLX_PATH) -lft $(MLX_CF)
	@printf "$(GR)Done!$(RC)\n\n"

# Regla para compilar los archivos .c en .o dentro del directorio objs/
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\n$(CY)Compiling $<...$(RC)\n"
	$(CC) $(CF) -c $(CFI) $< -o $@
	@printf "$(GR)Object $@ ready!$(RC)\n"

$(MLX):
	@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
	@make -sC $(MLX_PATH)
	@printf "$(GR)MiniLibX created!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	@make -sC $(LFT_PATH)
	@printf "$(GR)Libft created!$(RC)\n\n"

bonus: all

re: fclean all

rebonus: fclean bonus

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(RC)\n"
	@make clean -sC $(LFT_PATH)
	@printf "$(GR)Libft objects removed!$(RC)\n\n"
	$(RM) -rf objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	$(RM) -rf $(NAME) objs/
	@make fclean -sC $(LFT_PATH)
	@make clean -sC $(MLX_PATH)
	@printf "$(GR)All libraries removed!$(RC)\n\n"

test: $(BINARY) 
	./fdf test_maps/mars.fdf

debug: $(BINARY)
	@echo "Iniciando lldb para el binario $(BINARY)..."
	lldb -- $(BINARY) test_maps/mars.fdf

print:
	@printf $(SRC)

.PHONY: clean fclean re rebonus all bonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

