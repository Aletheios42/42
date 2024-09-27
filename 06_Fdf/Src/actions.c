
#include "../Inc/fdf.h"

int handle_height(char **line, t_map *map, t_dim *dim, int fd) {
  int result;
  char *endptr;

  // Convertimos el contenido de *line a un entero, detectando cualquier error.
  result = strtol(*line, &endptr, 10); // Usa strtol para manejar errores
  if (*line == endptr) {
    printf("Error: no se pudo convertir la cadena a número en la posición col: "
           "%d\n",
           dim->cols[dim->rows]);
    return -1;
  }

  // Guardamos el resultado en map->map[row][col]
  map->map[dim->rows][dim->cols[dim->rows]][0] = result;

  // Movemos el puntero de *line hasta el final del número convertido
  *line = endptr;

  // Incrementamos la columna
  dim->cols[dim->rows]++;

  printf("Altura procesada: %d en la posición row: %d, col: %d\n", result,
         dim->rows, dim->cols[dim->rows]);

  return 0; // Retorna 0 para indicar éxito
}

int handle_color(char **line, t_map *map, t_dim *dim, int fd) {
  int result;
  char *endptr;

  // Convertimos el contenido de *line a un entero, especificando base 16
  result = strtol(*line, &endptr, 16);
  if (*line == endptr) {
    printf("Error: no se pudo convertir la cadena hexadecimal a número en la "
           "posición col: %d\n",
           dim->cols[dim->rows]);
    return -1;
  }

  // Guardamos el resultado en map->map[row][col]
  map->map[dim->rows][dim->cols[dim->rows]][1] = result;

  // Movemos el puntero de *line hasta el final del número convertido
  *line = endptr;

  // Incrementamos la columna
  dim->cols[dim->rows]++;

  printf("Color procesado: %#x en la posición row: %d, col: %d\n", result,
         dim->rows, dim->cols[dim->rows]);

  return 0; // Retorna 0 para indicar éxito
}

int handle_space(char **line, t_map *map, t_dim *dim, int fd) {
  // Iteramos sobre la cadena hasta que no haya más espacios
  while (**line == ' ' || **line == '\t') {
    (*line)++; // Movemos el puntero para saltar los espacios
  }

  (void)map;
  (void)dim;
  (void)fd;

  printf("Espacios saltados. Nueva posición del puntero: '%c'\n", **line);

  return 0; // Retorna 0 para indicar éxito
}

int handle_newline(char **line, t_map *map, t_dim *dim, int fd) {
  printf("Handling new*line at row: %d, col: %d...\n", dim->rows,
         dim->cols[dim->rows]);

  // Leer nueva línea
  *line = get_next_line(fd);
  if (!*line) {
    return -1; // Error al leer
  }

  // Contar columnas de la nueva línea
  int columns = count_columns(*line);

  // Incrementar fila y ajustar la memoria del mapa
  dim->rows++;
  if (init_row_memory(map, dim->rows, columns) == -1) {
    return (free(*line), close(fd), free(map), -1);
  }

  map->dim.cols[dim->rows] = columns; // Guardamos el número de columnas

  return 0; // Retorna 0 para indicar éxito
}

int handle_eof(char **line, t_map *map, t_dim *dim, int fd) {
  printf("Handling end of file...\n");

  // Limpiamos y cerramos
  (void)*line;
  (void)map;
  (void)dim;
  close(fd);

  return 0; // Retorna 0 para indicar éxito
}

int handle_error(char **line, t_map *map, t_dim *dim, int fd) {
  printf("Handling error at row: %d, col: %d...\n", dim->rows,
         dim->cols[dim->rows]);

  (void)*line;
  (void)map;
  (void)dim;
  close(fd);

  return -1; // Retorna -1 para indicar error
}

int handle_comma(char **line, t_map *map, t_dim *dim, int fd) {
  printf("Handling comma at row: %d, col: %d...\n", dim->rows,
         dim->cols[dim->rows]);

  // Movemos el puntero después de la coma
  if (**line == ',') {
    (*line)++;
  }

  (void)map;
  (void)fd;

  return 0; // Retorna 0 para indicar éxito
}
