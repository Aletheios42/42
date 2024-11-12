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

  // Inicializa el resto de los miembros del mapa, si es necesario
  fdf->map->coors = NULL; // Inicializa el puntero del coorsa
  fdf->map->cols = NULL;  // Inicializa el arreglo de columnas
  fdf->map->rows = 0;     // Inicializa el número de filas
  fdf->map->max_z = 0;    // Inicializa el valor máximo de Z
  fdf->map->min_z = 0;    // Inicializa el valor mínimo de Z

  return fdf; // Retorna la estructura inicializada
}

// // Función que asigna (o reasigna) memoria para una fila específica en el
// mapa int init_row_memory(t_map *map) {
//   int j;
//
//   // Aumenta la memoria para las filas
//   int ***temp_map =
//       (int ***)realloc(map->coors, sizeof(int **) * (map->rows + 1));
//   if (!temp_map) {
//     return -1; // Manejo de error si realloc falla
//   }
//   // map->coors = temp_map;
//
//   // Aumenta la memoria para las columnas
//   int *temp_cols = realloc(map->cols, sizeof(int) * (map->rows + 1));
//   if (!temp_cols) {
//     return -1; // Manejo de error si realloc falla
//   }
//   map->cols = temp_cols;
//
//   // Aumenta la memoria para la nueva fila
//   map->coors[map->rows] = malloc(sizeof(int *) * map->cols[map->rows]);
//   if (!map->coors[map->rows]) {
//     return -1; // Manejo de error si malloc falla
//   }
//
//   // Inicializa la nueva fila
//   for (j = 0; j < map->cols[map->rows]; j++) {
//     map->coors[map->rows][j] =
//         malloc(sizeof(int) * 2); // Ajustar según el tamaño que necesites
//     if (!map->coors[map->rows][j]) {
//       return -1; // Manejo de error si malloc falla
//     }
//   }
//
//   // Aumentar el número total de filas
//   map->rows++;
//
//   return 0; // Retorna 0 en caso de éxito
// }
