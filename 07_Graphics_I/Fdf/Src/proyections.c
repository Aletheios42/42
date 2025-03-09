#include "../Inc/fdf.h"
#include <math.h>

int interpolColor(int height, int z_range[2]) {
  int min_height;
  int max_height;

  min_height = z_range[0];
  max_height = z_range[1];
  if (max_height == min_height)
    return MIN_COLOR;
  float factor = (float)(height - min_height) / (max_height - min_height);
  return MIN_COLOR + (int)(factor * (MAX_COLOR - MIN_COLOR));
}

t_pixel proj_iso(t_point point, int z_range[2]) {
  t_pixel pixel_to_draw;
  // Fórmula isométrica:
  //   x' = (x - y) * cos(30°)
  //   y' = (x + y) * sin(30°) - height
  pixel_to_draw.x = (int)((point.x - point.y) * cos(30 * M_PI / 180));
  pixel_to_draw.y =
      (int)((point.x + point.y) * sin(30 * M_PI / 180)) - point.height;
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor(point.height, z_range);
  }
  return pixel_to_draw;
}

t_pixel proj_circular(t_point point, int z_range[2]) {
  t_pixel pixel_to_draw;
  // Proyección circular (ejemplo):
  //   Se calcula la distancia r y el ángulo theta; se ajusta theta según la
  //   altura.
  float r = sqrt(point.x * point.x + point.y * point.y);
  float theta = atan2(point.y, point.x) + point.height * 0.05;
  pixel_to_draw.x = (int)(r * cos(theta));
  pixel_to_draw.y = (int)(r * sin(theta));
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor(point.height, z_range);
  }
  return pixel_to_draw;
}

t_pixel proj_orthogonal(t_point point, int z_range[2]) {
  t_pixel pixel_to_draw;
  // Proyección ortogonal:
  //   Se mantiene la coordenada x original y se ajusta y restando la altura.
  pixel_to_draw.x = point.x;
  pixel_to_draw.y = point.y - point.height;
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor(point.height, z_range);
  }
  return pixel_to_draw;
}

