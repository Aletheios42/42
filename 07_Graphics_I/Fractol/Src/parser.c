#include "../Inc/fractol.h"
#include <stdio.h>
#include <stdlib.h>

int check_fractal(int ac, char **av) {
  if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10) && ft_strlen(av[1]) == 10)
    return 0;
  else
    return 1;
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
