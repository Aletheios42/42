#include "../Inc/fdf.h"

// @TODO
void set_segment(t_pixel **map, int i, int j, t_mlx *mlx) {

  my_mlx_pixel_put(mlx->mlx, i, j, map[i][j].color);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void apply_pespective(t_pixel ***mesh, int proyection, t_map *map) {
  int i;
  int j;

  t_pixel (*pespectives_array[])(t_point, int z_range[2]) = {
      proj_iso, proj_circular, proj_orthogonal};

  i = -1;
  malloc_mesh(mesh, map->rows, map->cols);
  while (++i < map->rows) {
    j = -1;
    while (++j < map->cols[i]) {
      //////////////////// ajustar frame //////////////////////////////
      (*mesh)[i][j] =
          pespectives_array[proyection](map->coors[i][j], map->z_range);
    }
  }
}

int render(t_map *map, t_cam *camera, t_mlx *mlx) {
  int i = 0;
  int j;
  t_pixel **mesh;

  apply_pespective(&mesh, camera->projection, map);
  print_projected_map(*map);

  while (i < map->rows) {
    j = 0;
    while (j < map->cols[i]) {
      set_segment(mesh, i, j, mlx);
    }
  }
  return 0;
}
