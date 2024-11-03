
#include "../Inc/fractol.h"
#include <stdlib.h>

int init_window(t_mlx **mlx) {
  t_mlx *p_mlx;

  p_mlx = *mlx;
  p_mlx->mlx = mlx_init();
  if (!p_mlx->mlx) {
    free(p_mlx);
    return -1;
  }

  p_mlx->setting->width = 800;
  p_mlx->setting->height = 600;
  p_mlx->win = mlx_new_window(p_mlx->mlx, p_mlx->setting->width,
                              p_mlx->setting->height, p_mlx->setting->title);

  return 0;
}

int close_window(t_mlx *mlx) {
  mlx_destroy_window(mlx->mlx, mlx->win);
  exit(0); // Salir del programa
}

int handle_keypress(int keycode, t_mlx *mlx) {
  if (keycode == 0) {  // Comprobar si la tecla 'ESC' fue presionada
    close_window(mlx); // Llama a la función para cerrar la ventana
  }
  // Aquí puedes manejar otras teclas según sea necesario
  return (0);
}
