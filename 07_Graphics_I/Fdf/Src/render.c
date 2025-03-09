#include "../Inc/fdf.h"

void set_segment(t_pixel **mesh, int i, int j, t_mlx *mlx) {

  /* tengo que dibujar la linea entre el punto que me den y su siguiente */
  // esto solo hace el punto
  my_mlx_pixel_put(mlx->mlx, i, j, mesh[i][j].color);
}

void apply_pespective(t_pixel ***mesh, t_cam *camera, t_map *map) {
  int i;
  int j;

  t_pixel (*pespectives_array[])(t_point, int z_scale, int z_range[2]) = {
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
  int i = 0;
  int j;
  t_pixel **mesh;

  refresh_frame(mlx);
  malloc_mesh(&mesh, map->rows, map->cols);

  /* 1. Escalar la altura y aplicar la proyección */
  apply_pespective(&mesh, camera, map);
  /* 2. Apply pixel spacing to separate points */
  /*applyPixelSpacing(mesh);*/
  /* 3. Normalize object coordinates to start at zero */
  /*normalizeObject();*/
  /* 4. Apply camera transformation (rotation, scaling, offset) */
  /*applyCameraTransform(mesh, camera);*/
  print_projected_map(mesh, *map);

  while (i < map->rows) {
    j = 0;
    while (j < map->cols[i])
      set_segment(mesh, i, j, mlx);
  }
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
  return 0;
}
