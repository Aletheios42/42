
#include "../Inc/fdf.h"

int init_window(t_fdf *fdf, const char *map_file) {
  fdf->mlx = mlx_init(); // Inicializa MiniLibX
  if (!fdf->mlx) {
    free(fdf->map); // Libera la estructura t_map si falla la inicialización
    free(fdf);
    return -1; // Manejo de error en caso de fallo
  }

  fdf->win_x = 800; // Puedes ajustar el tamaño de la ventana
  fdf->win_y = 600; // Puedes ajustar el tamaño de la ventana
  fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y,
                            "FdF"); // Crear la nueva ventana

  // Aquí podrías cargar el archivo del mapa utilizando `map_file`
  int fd = open(map_file, O_RDONLY); // Abrimos el archivo en modo lectura
  if (fd < 0) {
    mlx_destroy_window(
        fdf->mlx,
        fdf->win); // Libera la ventana si no se puede abrir el archivo
    free(fdf->map);
    free(fdf);
    return -1; // Manejo de error si el archivo no se puede abrir
  }

  // Aquí llamarías a una función para parsear el mapa, por ejemplo:
  // if (parse_map(fd, fdf->map) == -1) {
  //     close(fd);
  //     mlx_destroy_window(fdf->mlx, fdf->win); // Libera la ventana si hay
  //     error en el parsing free(fdf->map); free(fdf); return -1;
  // }

  close(fd); // Cerramos el archivo después de cargarlo

  return 0; // Éxito
}

int close_window(t_fdf *fdf) {
  mlx_destroy_window(fdf->mlx, fdf->win);
  exit(0); // Salir del programa
}

int handle_keypress(int keycode, t_fdf *fdf) {
  if (keycode == KEY_ESC) { // Comprobar si la tecla 'ESC' fue presionada
    close_window(fdf);      // Llama a la función para cerrar la ventana
  }
  // Aquí puedes manejar otras teclas según sea necesario
  return (0);
}

void render_map(t_fdf *fdf) {
  (void)fdf; // Esto previene el warning de parámetro no utilizado
  return;
}
