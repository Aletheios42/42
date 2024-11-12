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

// int handle_newline(char **line, t_map **map, int fd) {
//   int *col;
//   int ***coors;
//   int i;
//
//   *line = get_next_line(fd);
//   if (*line) {
//     // Incrementa el número de filas
//     (*map)->rows++;
//
//     // Realiza realloc de cols
//     col = (int *)malloc(sizeof(int) * (*map)->rows);
//     if (!col)
//       return (printf("FALLO MALLOC\n"), -1);
//
//     // Copia los elementos existentes en cols y agrega el nuevo
//     i = -1;
//     while (++i < (*map)->rows - 1)
//       col[i] = (*map)->cols[i];
//     col[i] = ft_segcount(*line, ' '); // Asigna el nuevo valor al final
//     free((*map)->cols);
//     (*map)->cols = col;
//
//     // Ajusta el tamaño de coors para incluir un puntero más
//     coors = (int ***)malloc(sizeof(int **) * (*map)->rows);
//     if (!coors)
//       return (printf("FALLO MALLOC\n"), -1);
//
//     // Copia los punteros existentes en coors y deja espacio para el nuevo
//     i = -1;
//     while (++i < (*map)->rows - 1)
//       coors[i] = (*map)->coors[i];
//
//     // Deja espacio para el nuevo puntero en coors
//     coors[i] =
//         NULL; // Aquí puedes inicializar con NULL o el valor que necesites
//
//     // Libera la memoria antigua y asigna la nueva a (*map)->coors
//     free((*map)->coors);
//     (*map)->coors = coors;
//   }
//
//   printf("row: %d\n", (*map)->rows);
//   print_int_array(col, (*map)->rows);
//   printf("Ejecutando: handle_newline\n");
//   return 0;
// }

int handle_newline(char **line, t_map *map, int fd) {
  (void)line;
  (void)map;
  (void)fd;
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
