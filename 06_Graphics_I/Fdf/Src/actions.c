#include "../Inc/fdf.h"

int handle_height(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_height\n");
  return 0;
}

int handle_color(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_color\n");
  return 0;
}

int handle_space(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_space\n");
  return 0;
}

int handle_newline(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_newline\n");
  return 0;
}

int handle_eof(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_eof\n");
  return 0;
}

int handle_error(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_error\n");
  return 0;
}

int handle_comma(char **line, t_map **map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
  printf("Ejecutando: handle_comma\n");
  return 0;
}

//
//
// int handle_height(char **line, t_map **map, int fd) {
//   int result;
//   char *endptr;
//   (void)fd;
//   // Convertimos el contenido de *line a un entero, detectando cualquier
//   error. result = strtol(*line, &endptr, 10); // Usa strtol para manejar
//   errores if (*line == endptr) {
//     printf("Error: no se pudo convertir la cadena a número en la posición
//     col: "
//            "%d\n",
//            (*map)->dim.cols[(*map)->dim.rows]);
//     return -1;
//   }
//
//   // Guardamos el resultado en map->map[row][col]
//   (*map)->(*map)[(*map)->dim.rows][(*map)->dim.cols[(*map)->dim.rows]][0] =
//       result;
//
//   // Movemos el puntero de *line hasta el final del número convertido
//   *line = endptr;
//
//   // Incrementamos la columna
//   (*map)->dim.cols[(*map)->dim.rows]++;
//
//   printf("Altura procesada: %d en la posición row: %d, col: %d\n", result,
//          (*map)->dim.rows, (*map)->dim.cols[(*map)->dim.rows]);
//
//   return 0; // Retorna 0 para indicar éxito
// }
//
// int handle_color(char **line, t_(*map) * *(*map), int fd) {
//   int result;
//   char *endptr;
//   (void)fd;
//   // Convertimos el contenido de *line a un entero, especificando base 16
//   result = strtol(*line, &endptr, 16);
//   if (*line == endptr) {
//     printf("Error: no se pudo convertir la cadena hexadecimal a número en la
//     "
//            "posición col: %d\n",
//            (*map)->dim.cols[(*map)->dim.rows]);
//     return -1;
//   }
//
//   // Guardamos el resultado en (*map)->(*map)[row][col]
//   (*map)->(*map)[(*map)->dim.rows][(*map)->dim.cols[(*map)->dim.rows]][1] =
//       result;
//
//   // Movemos el puntero de *line hasta el final del número convertido
//   *line = endptr;
//
//   // Incrementamos la columna
//   (*map)->dim.cols[(*map)->dim.rows]++;
//
//   printf("Color procesado: %#x en la posición row: %d, col: %d\n", result,
//          (*map)->dim.rows, (*map)->dim.cols[(*map)->dim.rows]);
//
//   return 0; // Retorna 0 para indicar éxito
// }
//
// int handle_space(char **line, t_(*map) * *(*map), int fd) {
//   // Iteramos sobre la cadena hasta que no haya más espacios
//   while (**line == ' ' || **line == '\t') {
//     (*line)++; // Movemos el puntero para saltar los espacios
//   }
//
//   (void)(*map);
//   (void)fd;
//
//   printf("Espacios saltados. Nueva posición del puntero: '%c'\n", **line);
//
//   return 0; // Retorna 0 para indicar éxito
// }
//
// int handle_newline(char **line, t_(*map) * *(*map), int fd) {
//   printf("Handling new line at row: %d, col: %d...\n", (*map)->dim.rows,
//          (*map)->dim.cols[(*map)->dim.rows]);
//
//   // Leer nueva línea
//   *line = get_next_line(fd);
//   if (!*line) {
//     return -1; // Error al leer
//   }
//
//   // Contar columnas de la nueva línea
//   int columns = count_columns(*line);
//
//   // Incrementar fila y ajustar la memoria del (*map)a
//   (*map)->dim.rows++;
//   if (init_row_memory((*map)) == -1) {
//     return (free(*line), close(fd), free((*map)), -1);
//   }
//
//   (*map)->dim.cols[(*map)->dim.rows] =
//       columns; // Guardamos el número de columnas
//
//   return 0; // Retorna 0 para indicar éxito
// }
//
// int handle_comma(char **line, t_(*map) * *(*map), int fd) {
//   printf("Handling comma at row: %d, col: %d...\n", (*map)->dim.rows,
//          (*map)->dim.cols[(*map)->dim.rows]);
//
//   // Movemos el puntero después de la coma
//   if (**line == ',') {
//     (*line)++;
//   }
//
//   (void)(*map);
//   (void)fd;
//
//   return 0;
// }
