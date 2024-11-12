
#include "../Inc/fdf.h"

void init_window(t_mlx *mlx) {
  mlx->mlx = mlx_init(); // Inicializa MiniLibX

  mlx->win = mlx_new_window(mlx->mlx, WIN_HEIGHT, WIN_WIDTH,
                            "mlx"); // Crear la nueva ventana
}

// Aquí llamarías a una función para parsear el mapa, por ejemplo:
// if (parse_map(fd, mlx->map) == -1) {
//     close(fd);
//     mlx_destroy_window(fdf->mlx, fdf->win); // Libera la ventana si hay
//     error en el parsing free(fdf->map); free(fdf); return -1;
// }

int close_window(t_mlx *mlx) {
  mlx_destroy_window(mlx->mlx, mlx->win);
  exit(0); // Salir del programa
}

int handle_keypress(int keycode, t_mlx *mlx) {
  if (keycode == KEY_ESC) { // Comprobar si la tecla 'ESC' fue presionada
    close_window(mlx);      // Llama a la función para cerrar la ventana
  }
  // Aquí puedes manejar otras teclas según sea necesario
  return (0);
}

void render_map(t_fdf *fdf) {
  (void)fdf; // Esto previene el warning de parámetro no utilizado
  return;
}
