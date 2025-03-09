#include "../Inc/fdf.h"
#define BASE_HEX "0123456789ABCDEF"

void set_z_range(t_map *map) {
  int max;
  int min;
  int i;
  int j;

  max = INT_MIN;
  min = INT_MAX;
  i = -1;
  while (++i < map->rows) {
    j = -1;
    while (++j < map->cols[i]) {
      if (map->coors[i][j].height < max)
        max = map->coors[i][j].height;
      if (map->coors[i][j].height > min)
        min = map->coors[i][j].height;
    }
  }
}
t_point get_tok(char *str, int x, int y) {
  static char *saveptr;
  t_point point;

  if (str != NULL)
    saveptr = str;
  while (*saveptr && ft_isspace((unsigned char)*saveptr))
    saveptr++;
  point.x = x;
  point.y = y;
  point.height = ft_atoi(saveptr);
  if (*saveptr == '+' || *saveptr == '-')
    saveptr++;
  while (*saveptr >= '0' && *saveptr <= '9')
    saveptr++;
  if (*saveptr == ',') {
    point.native = true;
    saveptr += 3;
    point.color = ft_atoi_base(saveptr, BASE_HEX);
    while (ft_ishex(*saveptr))
      saveptr++;
  } else {
    point.native = false;
    point.color = 0;
  }
  return point;
}

int parser(t_map *map, char *map_file) {
  char *line;
  int fd;
  int i;

  if (!ft_open(&fd, map_file))
    return (1);
  while (42) {
    line = get_next_line(fd);
    if (!line)
      return (close(fd), 1);
    if (!count_columns(line)) { // mirar para las lineas
      free(line);
      continue;
    }
    if (!realloc_cols(line, &(map->cols), map->rows))
      return (close(fd), 1);
    if (!realloc_t_point(&(map->coors), map->rows, map->cols[map->rows]))
      return (close(fd), 1);
    i = -1;
    while (++i < map->cols[map->rows]) {
      if (i == 0)
        map->coors[map->rows][i] = get_tok(line, map->rows, i);
      else
        map->coors[map->rows][i] = get_tok(NULL, map->rows, i);
    }
    map->rows++;
    free(line);
  }
  return (set_z_range(map), close(fd), 0);
}
