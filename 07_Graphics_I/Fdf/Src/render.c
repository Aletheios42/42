#include "../Inc/fdf.h"
#include <math.h>

void applyCameraTransform(t_pixel ***mesh, t_cam *camera, t_map *map) {
  int i, j;
  for (i = 0; i < map->rows; i++) {
    for (j = 0; j < map->cols[i]; j++) {
      int originalX = (*mesh)[i][j].x;
      int originalY = (*mesh)[i][j].y;

      // 1. Escalar las coordenadas
      double scaledX = originalX * camera->scale_factor;
      double scaledY = originalY * camera->scale_factor;

      // 2. Rotar usando camera.angle[2] (asumido en radianes)
      double theta = camera->angle[2];
      double rotatedX = scaledX * cos(theta) - scaledY * sin(theta);
      double rotatedY = scaledX * sin(theta) + scaledY * cos(theta);

      // 3. Aplicar offset de la cámara (desplazamiento)
      (*mesh)[i][j].x = (int)(rotatedX + camera->offset[0]);
      (*mesh)[i][j].y = (int)(rotatedY + camera->offset[1]);
    }
  }
}

/*
 * normalizeObject:
 * Recorre todo el mesh para encontrar las coordenadas mínimas (minX y minY)
 * y luego las resta a cada punto, de forma que el objeto quede posicionado
 * con su esquina superior izquierda en (0, 0).
 */
void normalizeObject(t_pixel ***mesh, t_map *map) {
  int i, j;
  int minX = INT_MAX;
  int minY = INT_MAX;

  // Encontrar los valores mínimos de x e y
  for (i = 0; i < map->rows; i++) {
    for (j = 0; j < map->cols[i]; j++) {
      if ((*mesh)[i][j].x < minX)
        minX = (*mesh)[i][j].x;
      if ((*mesh)[i][j].y < minY)
        minY = (*mesh)[i][j].y;
    }
  }

  // Normalizar restando los valores mínimos a cada punto
  for (i = 0; i < map->rows; i++) {
    for (j = 0; j < map->cols[i]; j++) {
      (*mesh)[i][j].x -= minX;
      (*mesh)[i][j].y -= minY;
    }
  }
}

void applyPixelSpacing(t_pixel ***mesh, t_map *map) {
  int i, j;
  int maxCols = 0;

  // Calcular el máximo número de columnas entre todas las filas
  for (i = 0; i < map->rows; i++) {
    if (map->cols[i] > maxCols)
      maxCols = map->cols[i];
  }

  // Calcular márgenes (10% del tamaño de la ventana)
  int marginX = (int)(WIN_WIDTH * 0.1);
  int marginY = (int)(WIN_HEIGHT * 0.1);
  // Calcular área disponible para distribuir los puntos
  int availableWidth = WIN_WIDTH - 2 * marginX;
  int availableHeight = WIN_HEIGHT - 2 * marginY;

  // Calcular el espaciamiento horizontal y vertical
  double spacingX = (maxCols > 1) ? (double)availableWidth / (maxCols - 1) : 0;
  double spacingY =
      (map->rows > 1) ? (double)availableHeight / (map->rows - 1) : 0;

  // Reposicionar cada punto en el mesh basándose en sus índices de fila y
  // columna
  for (i = 0; i < map->rows; i++) {
    for (j = 0; j < map->cols[i]; j++) {
      (*mesh)[i][j].x = marginX + j * spacingX;
      (*mesh)[i][j].y = marginY + i * spacingY;
    }
  }
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
  applyPixelSpacing(&mesh, map);
  /* 3. Normalize object coordinates to start at zero */
  normalizeObject(&mesh, map);
  /* 4. Apply camera transformation (rotation, scaling, offset) */
  applyCameraTransform(&mesh, camera, map);
  /*print_projected_map(mesh, *map);*/

  while (i < map->rows - 1) {
    j = 0;
    while (j < map->cols[i] - 1)
      set_segment(mesh, i, j, mlx);
  }
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
  return 0;
}
