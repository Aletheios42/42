#include "../Inc/fractol.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  if (ac == 2) {

    t_mlx mlx;

    init_window(&mlx);
    int **data = parser(av);
    render(data);
    mlx_loop(mlx.mlx);
  }
  return 0;
}
