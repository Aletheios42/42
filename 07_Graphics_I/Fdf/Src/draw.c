#include "../Inc/fdf.h"

void set_segment(t_pixel **mesh, int i, int j, t_mlx *mlx) {
  t_pixel start = mesh[i][j];
  t_pixel end = mesh[i][j + 1];

  int x0 = start.x;
  int y0 = start.y;
  int x1 = end.x;
  int y1 = end.y;

  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1;
  int sy = (y0 < y1) ? 1 : -1;
  int err = dx - dy;
  int e2;

  while (1) {
    my_mlx_pixel_put(mlx->mlx, x0, y0, C_RED);
    if (x0 == x1 && y0 == y1)
      break;
    e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x0 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y0 += sy;
    }
  }
}
