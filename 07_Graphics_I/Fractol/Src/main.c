#include "../Inc/fractol.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  if (ac == 2) {

    t_mlx *mlx;

    init_window(&mlx);
    int **data = parser(av);
    if (data != NULL) {
      render(data);
    } else {
      printf("Error en el parser.\n");
    }
  } else {
    printf("Uso: %s <arg1> n", av[0]);
  }
  return 0;
}
