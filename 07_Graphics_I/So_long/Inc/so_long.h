#ifndef SO_LONG_H
#define SO_LONG_H

// LIBRARIES
#include "../Inc/structs.h"
#include "../Libft/libft.h"
#include "../minilibx_linux/mlx.h"
#include "../minilibx_macos/mlx.h"

// DEFINES
#define WIDTH 800
#define HEIGHT 1200
#define TITLE "ALETHEIOS42"

// FUNTIONS

void ft_error(char *msg);
// Src/parser.c
int line_checker(char *line);
int av_checker(char *map_file, char ***map);
int **parser(char **av);

// Src/render.c
void render(int **data);
void init_mlx(t_mlx *mlx);

// Src/mlx.c
int init_window(t_mlx *mlx);

#endif // SO_LONG_H
