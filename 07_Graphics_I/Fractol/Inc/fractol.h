#ifndef FRACTOL_H
#define FRACTOL_H

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

// Src/parser.c
int **parser(char **av);

// Src/render.c
void render(int **data);
void init_mlx(t_mlx *mlx);

// Src/mlx.c
int init_window(t_mlx *mlx);

#endif // FRACTOL_H
