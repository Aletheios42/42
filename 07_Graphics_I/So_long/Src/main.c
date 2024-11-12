#include "../Inc/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void ft_error(char *msg) {
  ft_putstr_fd(msg, 2);
  exit(0);
}
int main(int ac, char **av) {
  if (ac == 2) {

    t_mlx mlx;
    char **map;

    if (av_checker(av[1], &map))
      return (ft_error("Invalid map"), 1);
    parser(av);
    init_window(&mlx);
    // render();
    mlx_loop(mlx.mlx);
  }
  return 0;
}
