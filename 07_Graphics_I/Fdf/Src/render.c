#include "../Inc/fdf.h"

void apply_perspective(t_pixel ***mesh, t_cam *camera, t_map *map) {
  int i;
  int j;

  t_pixel (*pespectives_array[])(t_point point, int z_scale, int z_range[2]) = {
      proj_iso, proj_circular, proj_orthogonal};

  i = -1;
  while (++i < map->rows) {
    j = -1;
    while (++j < map->cols[i]) {
      (*mesh)[i][j] = pespectives_array[camera->projection](
          map->coors[i][j], camera->scale_z, map->z_range);
    }
  }
}

int render(t_map *map, t_cam *camera, t_mlx *mlx) {
  int i, j;
  t_pixel **mesh;

  /*print_original_map(*map);*/
  malloc_mesh(&mesh, map->rows, map->cols);

  apply_perspective(&mesh, camera, map);
  print_projected_map(mesh, *map);

  // Dibujar segmentos entre los puntos
  for (i = 0; i < map->rows - 1; i++) {
    for (j = 0; j < map->cols[i] - 1; j++) {
      set_segment(mesh, i, j, mlx);
    }
  }
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
  return 0;
}
