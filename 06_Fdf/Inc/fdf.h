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

void handle_height(char *token, t_map *map, int row, int col);
void handle_color(char *token, t_map *map, int row, int col);
void handle_space(char *token, t_map *map, int row, int col);
void handle_newline(char *token, t_map *map, int row, int col);
void handle_eof(char *token, t_map *map, int row, int col);
void handle_error(char *token, t_map *map, int row, int col);
void handle_comma(char *token, t_map *map, int row, int col);

t_automaton **assign_automaton();
t_automaton **new_automaton();
void delete_automaton(t_automaton **automaton_instance);

t_fdf *init_fdf(void);
int init_window(t_fdf *fdf, const char *map_file);

int handle_keypress(int keycode, t_fdf *fdf);
int close_window(t_fdf *fdf);
void render_map(t_fdf *fdf);
int count_columns(const char *line);
int determine_token_type(const char *token);
int parse_map(int fd, t_map *map);
void parser(t_map *map, char *map_file);

#endif // FDF_H
