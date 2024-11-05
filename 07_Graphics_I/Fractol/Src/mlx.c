
#include "../Inc/fractol.h"
#include <stdlib.h>

int init_window(t_mlx *mlx) {
  mlx->img = NULL;
  mlx->addr = NULL;
  mlx->bpp = 0;
  mlx->lpl = 0;
  mlx->endian = 0;
  mlx->mlx = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, TITLE);
  return 0;
}
void ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color) {
  char *dst;

  dst = mlx->addr + (y * mlx->lpl + x * (mlx->bpp / 8));
  *(unsigned int *)dst = color;
}
// mlx->mlx = mlx_init();
// if (!mlx->mlx) {
//   free(mlx);
//   return -1;
// }
// mlx->win = mlx_new_window(mlx->mlx, mlx->setting->width,
// mlx->setting->height,
//                           mlx->setting->title);
//        MIRAR ARRIBA                           o
//
//
//
// int close_window(t_mlx *mlx) {
//   mlx_destroy_window(mlx->mlx, mlx->win);
//   exit(0); // Salir del programa
// }
//
// int handle_keypress(int keycode, t_mlx *mlx) {
//   if (keycode == 0) {  // Comprobar si la tecla 'ESC' fue presionada
//     close_window(mlx); // Llama a la función para cerrar la ventana
//   }
//   // Aquí puedes manejar otras teclas según sea necesario
//   return (0);
// }
