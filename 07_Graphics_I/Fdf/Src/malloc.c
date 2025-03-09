#include "../Inc/fdf.h"

void ft_free_map(t_map *map) {
  int i;

  if (!map)
    return;
  if (map->coors) {
    for (i = 0; i < map->rows; i++) {
      if (map->coors[i])
        free(map->coors[i]);
    }
    free(map->coors);
  }
  if (map->cols)
    free(map->cols);
}

int malloc_mesh(t_pixel ***mesh, int rows, int *cols) {
  int i;

  *mesh = (t_pixel **)malloc(sizeof(t_point *) * rows);
  if (!*mesh)
    return 0;

  i = -1;
  while (++i < rows) {
    (*mesh)[i] = (t_pixel *)malloc(sizeof(t_pixel) * cols[i]);
    if (!(*mesh)[i])
      return 0;
  }
  return 1;
}

int realloc_cols(char *line, int **col, int rows) {
  int i;
  int *col_helper;
  int row;
  i = count_columns(line);

  col_helper = *col;
  *col = (int *)malloc(sizeof(int) * (1 + rows));

  row = -1;
  while (++row < rows)
    (*col)[row] = col_helper[row];
  (*col)[rows] = i;
  free(col_helper);
  return 1;
}

int realloc_t_point(t_point ***coors, int rows, int ncols) {
  t_point **new_coors;
  int i;

  new_coors = malloc(sizeof(t_point *) * (rows + 1));
  if (!new_coors)
    return 0;

  i = 0;
  while (i < rows) {
    new_coors[i] = (*coors)[i];
    i++;
  }

  new_coors[rows] = calloc(ncols, sizeof(t_point));
  if (!new_coors[rows]) {
    free(new_coors);
    return 0;
  }

  free(*coors);
  *coors = new_coors;
  return 1;
}
