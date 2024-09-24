NAME 		= fdf

LFT_PATH 	= ./Libft/
LIBFT 		= libft.a

MLX_PATH 	= ./minilibx_linux/
MLX 		= libmlx_Linux.a
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

INC_DIR 	= ./Inc/
INC_FILES = fdf.h \
						color.h \
						keys.h \
INC = $(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR 		= ./Src/
SRC_FILES 	= main.c \
					init.c \
					init_utils.c \
					parser.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ= $(FILES:.c=.o)

#compilation
CF 			= -Wall -Wextra -Werror
CC 			= gcc
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I$(INCLUDES)

#common commands
RM =rm -f

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "\n$(CY)Generating FdF executable...$(RC)\n"
	$(CC) $(CF) -o $(NAME) $(OBJ) -L $(LFT_PATH) -L $(MLX_PATH) -lft $(MLX_CF)
	mkdir objs
	mv $(OBJ) objs/
	@printf "$(GR)Done!$(RC)\n\n"

$(OBJ): $(SRC)
	@printf "\n$(CY)Compiling source files...$(RC)\n"
	$(CC) $(CF) -c -I ./includes/ $(SRC)
	@printf "$(GR)Objects ready!$(RC)\n\n"

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
	$(RM) -rf $(OBJ) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -sC $(LFT_PATH)
	@make clean -sC $(MLX_PATH)
	@printf "$(GR)All libraries removed!$(RC)\n\n"

print:
	printf $(SRC)

.PHONY: clean fclean re rebonus all bonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
