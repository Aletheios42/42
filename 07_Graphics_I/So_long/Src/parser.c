#include "../Inc/so_long.h"
#include <stdio.h>
#include <stdlib.h>

int line_checker(char *line) {
  while (*line) {
    if (*line != 'C' || *line != 'E' || *line != 'P' || *line != '1' ||
        *line != '0' || *line != '\n')
      return 1;
    line++;
  }
  return 0;
}
int av_checker(char *map_file, char ***map) {
  int fd;
  int i;
  char *line;

  fd = open(map_file, 0b100);
  if (fd == -1)
    return (ft_error("Open Error"), 1);

  i = 0;
  while (1) {
    line = get_next_line(fd);
    if (!line)
      break;
    if (!line_checker(line))
      ft_error("Invalid Syntax");
    *map = ft_realloc(*map, i * sizeof(char *), (i + 1) * sizeof(char *));
    (*map)[i++] = line;
  }
  *map = ft_realloc(map, i * sizeof(char *), (i + 1) * sizeof(char *));
  (*map)[i] = NULL;
  if (!navigate_checker(*map))
    ft_error("No Way to navigate this map");
  return (0);
}

int **parser(char **av) {
  printf("Parser called with arguments: %s, \n", av[1]);

  // Simulamos la creación de una matriz de enteros
  int **data = malloc(sizeof(int *) * 2); // Por ejemplo, matriz de 2x2
  for (int i = 0; i < 2; i++) {
    data[i] = malloc(sizeof(int) * 2);
    for (int j = 0; j < 2; j++) {
      data[i][j] = i + j; // Ejemplo de inicialización
    }
  }

  return data; // Devolver la matriz
}
