#include "../Inc/fdf.h"

void print_int_array(int *arr, int size) {
  if (arr == NULL) {
    printf("El puntero es NULL\n");
    return;
  }
  printf("Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void print_original_map(t_map map) {
  int i = -1;

  printf("map dimensions: rows: %i\n", map.rows);
  printf("Ancho de las columnas: ");
  while (++i < map.rows) {
    printf("%i  ", map.cols[i]);
  }
  printf("\n");
  printf("map height range: %i - %i\n", map.z_range[0], map.z_range[1]);
  while (++i < map.rows) {
    int j = -1;
    while (++j < map.cols[i])
      printf("%i,0x%06X ", map.coors[i][j].height,
             (unsigned)map.coors[i][j].color);
    printf("\n");
  }
}

void print_projected_map(t_pixel **mesh, t_map map) {
  int i = -1;

  while (++i < map.rows) {
    int j = -1;
    while (++j < map.cols[i])
      printf("%i,%i, 0x%06X ", mesh[i][j].x, mesh[i][j].y,
             (unsigned)mesh[i][j].color);
    printf("\n");
  }
}
