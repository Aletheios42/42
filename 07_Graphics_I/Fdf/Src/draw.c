#include "../Inc/fdf.h"

// Función para inicializar la estructura con los valores iniciales y calcular
// los parámetros
void bresenham(t_bresenham *b, t_pixel start, t_pixel end) {
  b->x0 = start.x;
  b->y0 = start.y;
  b->x1 = end.x;
  b->y1 = end.y;
  b->dx = abs(b->x1 - b->x0);
  b->dy = abs(b->y1 - b->y0);
  b->sx = (b->x0 < b->x1) ? 1 : -1;
  b->sy = (b->y0 < b->y1) ? 1 : -1;
  b->err = b->dx - b->dy;
}

// Función que dibuja el segmento entre mesh[i][j] y mesh[i][j+1] usando la
// estructura de Bresenham
void set_segment(t_pixel **mesh, int i, int j, t_mlx *mlx) {
  t_bresenham b;
  t_pixel start = mesh[i][j];
  t_pixel end = mesh[i][j + 1];
  bresenham(&b, start, end);

  while (1) {
    my_mlx_pixel_put(mlx->mlx, b.x0, b.y0, 0xFFFF);
    if (b.x0 == b.x1 && b.y0 == b.y1)
      break;
    b.e2 = 2 * b.err;
    if (b.e2 > -b.dy) {
      b.err -= b.dy;
      b.x0 += b.sx;
    }
    if (b.e2 < b.dx) {
      b.err += b.dx;
      b.y0 += b.sy;
    }
  }
}
