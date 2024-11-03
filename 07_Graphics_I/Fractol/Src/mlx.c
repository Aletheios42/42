
#include "../Inc/fractol.h"
#include <stdlib.h>

int init_window(t_mlx *mlx) {

  t_setting setting;

  setting.width = HEIGHT;
  setting.height = WIDTH;
  setting.title = TITLE;
  mlx->setting = &setting;

  mlx->img = NULL;
  mlx->addr = NULL;
  mlx->bpp = 0;
  mlx->lpl = 0;
  mlx->endian = 0;
  mlx->mlx = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx, mlx->setting->width, mlx->setting->height,
                            mlx->setting->title);
  return 0;
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
