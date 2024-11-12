#include "../Inc/fdf.h"
/*
 * @notice:
 * @params:
 * @return:
 * @bug_log: da segfault
 */
int handle_height(char **line, t_map *map, int fd) {
  (void)fd;
  (void)line;
  (void)map;
  // static int x;
  // static int y;
  // static int z;

  // este while da segfault bro..
  // mirar, que probablemente tenga que mallocquear coors[x] y
  //(*coors)->col[row] en acction new_line
  // while (*(*line)) {
  //   (*coors)->coors[x][y][z] = ft_atoi(*line);
  //   while (ft_isdigit(**line))
  //     (**line)++;
  // }
  // printf("coors[%d[%d][%d] = %d  ", x, y, z, (*map)->coors[x][y][z]);
  printf("Ejecutando: handle_height\n");
  return 0;
}

int handle_color(char **line, t_map *map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_color\n");
  return 0;
}

int handle_space(char **line, t_map *map, int fd) {
  (void)map;
  (void)fd;
  while (ft_isspace(*(*line))) {
    (*line)++;
  }
  printf("Ejecutando: handle_space\n");
  return 0;
}

int handle_newline(char **line, t_map *map, int fd) {
  (void)map;

  int x;
  int y;

  *line = get_next_line(fd);
  if (!*line)
    return -1;

  x = 0;
  y = 0;
  x = x + y;
  printf("Ejecutando: handle_newline\n");
  return 0;
}

int handle_eof(char **line, t_map *map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_eof\n");
  return 0;
}

int handle_error(char **line, t_map *map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_error\n");
  return 0;
}

int handle_comma(char **line, t_map *map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_comma\n");
  return 0;
}
