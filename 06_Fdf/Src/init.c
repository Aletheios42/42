#include "../Inc/fdf.h" // Incluimos el archivo de cabecera general

t_fdf *init_fdf(void) {
  t_fdf *fdf =
      malloc(sizeof(t_fdf)); // Reservamos memoria para la estructura fdf
  if (!fdf) {
    return NULL; // Manejo de error en caso de fallo en malloc
  }

  // Inicializa los miembros de la estructura t_fdf
  fdf->map = malloc(sizeof(t_map)); // Inicializa la estructura t_map
  if (!fdf->map) {
    free(fdf); // Libera la memoria si falla la inicialización
    return NULL;
  }

  return fdf; // Retorna la estructura inicializada
}
// Función que asigna (o reasigna) memoria para una fila específica en el mapa
int init_row_memory(t_map *map) {
  int j;

  map->map = (int ***)realloc(map->map, sizeof(int **) * map->dim.rows + 1);
  if (!map->map)
    return -1;

  map->dim.cols =
      (int *)realloc(map->dim.cols, sizeof(int) * map->dim.rows + 1);
  if (!map->dim.cols)
    return -1;

  map->map[map->dim.rows] = (int **)realloc(
      map->map[map->dim.rows], sizeof(int *) * map->dim.cols[map->dim.rows]);
  if (!map->map[map->dim.rows])
    return -1;

  j = -1;
  while (++j < map->dim.cols[map->dim.rows]) {
    map->map[map->dim.rows][j] =
        realloc(map->map[map->dim.rows][j], sizeof(int) * 2);
    if (!map->map[map->dim.rows][j])
      return -1;
  }
  return 0;
}
