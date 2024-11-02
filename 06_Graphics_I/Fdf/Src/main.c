#include "../Inc/fdf.h"

int main(int ac, char **av) {
  t_fdf *fdf = NULL;

  if (ac == 2) {

    fdf = init_fdf();
    if (!fdf) {
      ft_putstr_fd("Error: Failed to initialize fdf.\n", 2);
      return (1);
    }

    if (parser(&(fdf->map), av[1]) == -1)
      return (free(fdf), 1);

    // Renderizamos el mapa
    render_map(fdf);

    // Configuramos eventos
    mlx_hook(fdf->win, 17, 0, close_window, fdf); // Hook para cerrar la ventana
    mlx_key_hook(fdf->win, handle_keypress, fdf); // Hook para manejar teclas

    // Bucle principal del gráfico
    mlx_loop(fdf->mlx);
  } else
    ft_putstr_fd("Usage: ./fdf <map_file.fdf>\n", 2);

  return (0);
}
