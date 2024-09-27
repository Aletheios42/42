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

// Prototipos de funciones para el archivo fdf.h
// actions.c
int handle_height(char **line, t_map *map, t_dim *dim, int fd);
int handle_color(char **line, t_map *map, t_dim *dim, int fd);
int handle_space(char **line, t_map *map, t_dim *dim, int fd);
int handle_newline(char **line, t_map *map, t_dim *dim, int fd);
int handle_eof(char **line, t_map *map, t_dim *dim, int fd);
int handle_error(char **line, t_map *map, t_dim *dim, int fd);
int handle_comma(char **line, t_map *map, t_dim *dim, int fd);

// automaton.c
t_automaton **assign_automaton();
t_automaton **new_automaton();
void delete_automaton(t_automaton **automaton_instance);

// init.c
t_fdf *init_fdf(void);
int init_window(t_fdf *fdf, const char *map_file);
int init_row_memory(t_map *map, int row, int columns);

// mlx.c
int handle_keypress(int keycode, t_fdf *fdf);
int close_window(t_fdf *fdf);
void render_map(t_fdf *fdf);

// parser.c
int count_columns(char *line);
int determine_token_type(const char *token, int state);
int process_tokens(t_map *map, int fd, t_dim dim,
                   t_automaton **state_automaton);
int parser(t_map *map, char *map_file);

#endif // FDF_H
