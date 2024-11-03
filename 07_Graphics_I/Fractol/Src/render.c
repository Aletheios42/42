#include "../Inc/fractol.h"
#include <stdio.h>

void init_mlx(t_mlx **mlx) {
  printf("Initializing Window:\n");

  t_mlx *p_mlx;

  p_mlx = *mlx;
  p_mlx->mlx = mlx_init();
  p_mlx->win = mlx_new_window(p_mlx->mlx, p_mlx->setting->height,
                              p_mlx->setting->width, p_mlx->setting->title);
  mlx_loop(p_mlx->mlx);
}

void render(int **data) {
  printf("Execute called with parsed data:\n");
  for (int i = 0; i < 2; i++) { // Supongamos que es 2x2
    for (int j = 0; j < 2; j++) {
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }
}
