#ifndef FDF_H
#define FDF_H

#include "../Libft/libft.h"
#include "../minilibx_linux/mlx.h"

#include <ctype.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "colors.h"
#include "keys.h"
#include "structs.h"

// DEFINES
#define WIN_HEIGHT 600
#define WIN_WIDTH 900

// Prototipos de funciones para el archivo fdf.h

// parser.c
int parser(t_map *map, char *map_file);

// camera.c
void init_camera(t_cam *camera);

// mlx.c
void init_window(t_mlx *mlx);
void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int handle_keypress(int keycode, t_mlx *mlx);
int close_window(t_mlx *mlx);

// render.c
int render(t_map *map, t_cam *camera, t_mlx *mlx);

// proyec.c
int interpolColor(int height, int z_range[2]);
t_pixel proj_iso(t_point point, int z_range[2]);
t_pixel proj_circular(t_point point, int z_range[2]);
t_pixel proj_orthogonal(t_point point, int z_range[2]);

// print.c
void print_int_array(int *arr, int size);
void print_map(t_map map);

// malloc.c
int realloc_cols(char *line, int **col, int rows);
int realloc_t_point(t_point ***coors, int rows, int ncols);
void ft_free_map(t_map *map);

// utils.c
int ft_atoi_base(char *str, char *base);
bool ft_ishex(char c);
int count_columns(char *line);
int ft_open(int *fd, char *map_file);

#endif
