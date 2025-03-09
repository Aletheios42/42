
#include "../Inc/fdf.h"

void init_window(t_mlx *mlx) {
  mlx->mlx = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx, WIN_HEIGHT, WIN_WIDTH, "mlx");
  mlx->img = mlx_new_image(mlx->mlx, WIN_HEIGHT, WIN_WIDTH);
  mlx->addr =
      mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->lpl), &(mlx->endian));
}

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color) {
  char *dst;

  dst = mlx->addr + (y * mlx->lpl + x * (mlx->bpp / 8));
  *(unsigned int *)dst = color;
}

int close_window(t_mlx *mlx) {
  mlx_destroy_window(mlx->mlx, mlx->win);
  exit(0);
}

int handle_keypress(int keycode, t_mlx *mlx) {
  if (keycode == KEY_ESC) {
    close_window(mlx);
  }
  return (0);
}
