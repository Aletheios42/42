#ifndef FDF_H
#define FDF_H

#include "../Libft/libft.h"
#include "../minilibx_linux/mlx.h"

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "colors.h"
#include "keys.h"
#include "structs.h"

// DEFINES
#define WIN_HEIGHT 600
#define WIN_WIDTH 900

// Prototipos de funciones para el archivo fdf.h

// parser.c
int determine_token_type(const char *token, int state);
int process_tokens(t_map **map, int fd, t_automaton **state_automaton);
int parser(t_map *map, char *map_file);
t_automaton **assign_automaton();

// actions.c
int handle_height(char **line, t_map *map, int fd);
int handle_color(char **line, t_map *map, int fd);
int handle_space(char **line, t_map *map, int fd);
int handle_newline(char **line, t_map *map, int fd);
int handle_eof(char **line, t_map *map, int fd);
int handle_error(char **line, t_map *map, int fd);
int handle_comma(char **line, t_map *map, int fd);

// camera.c
void init_camera(t_cam *camera);

// mlx.c
void init_window(t_mlx *mlx);
int handle_keypress(int keycode, t_mlx *mlx);
int close_window(t_mlx *mlx);

// render.c
int render(t_map *map, t_cam *camera, t_mlx *mlx);

// print.c
void print_int_array(int *arr, int size);

// init.c
t_fdf *init_fdf(void);
int init_row_memory(t_map *map);

// // automaton.c
// t_automaton **assign_automaton();
// t_automaton **new_automaton();
// void delete_automaton(t_automaton **automaton_instance);
#endif // FDF_H
