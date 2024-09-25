#include "../Inc/fdf.h" // Incluimos el archivo de cabecera general

t_fdf *init_fdf(void) {
  t_fdf *fdf =
      malloc(sizeof(t_fdf)); // Reservamos memoria para la estructura fdf
  if (!fdf) {
    return NULL; // Manejo de error en caso de fallo en malloc
  }

  // Inicializa los miembros de la estructura t_fdf
  fdf->map = malloc(sizeof(t_map)); // Inicializa la estructura t_map
  if (!fdf->map) {
    free(fdf); // Libera la memoria si falla la inicialización
    return NULL;
  }

  return fdf; // Retorna la estructura inicializada
}
