#include "../Inc/fdf.h"
#include <math.h>

int interpolColor(int height, int z_range[2]) {
  int min_height = z_range[0];
  int max_height = z_range[1];

  if (max_height == min_height)
    return MIN_COLOR;

  double factor = ((double)height - (double)min_height) /
                  ((double)max_height - (double)min_height);
  return MIN_COLOR + (int)(factor * (MAX_COLOR - MIN_COLOR));
}

// Fórmula isométrica:
//   x' = (x - y) * cos(30°)
//   y' = (x + y) * sin(30°) - height
t_pixel proj_iso(t_point point, int scale_z, int z_range[2]) {

  t_pixel pixel_to_draw;

  pixel_to_draw.x = (int)((point.x - point.y) * cos(30 * M_PI / 180));
  pixel_to_draw.y = (int)((point.x + point.y) * sin(30 * M_PI / 180)) -
                    (point.height * scale_z);
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor((point.height * scale_z), z_range);
  }
  return pixel_to_draw;
}

// Proyección circular (ejemplo)
//   Se calcula la distancia r y el ángulo theta; se ajusta theta según la
//   altura.
t_pixel proj_circular(t_point point, int scale_z, int z_range[2]) {
  t_pixel pixel_to_draw;

  float r = sqrt(point.x * point.x + point.y * point.y);
  float theta = atan2(point.y, point.x) + (point.height * scale_z) * 0.05;
  pixel_to_draw.x = (int)(r * cos(theta));
  pixel_to_draw.y = (int)(r * sin(theta));
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor((point.height * scale_z), z_range);
  }
  return pixel_to_draw;
}

// Proyección ortogonal:
//   Se mantiene la coordenada x original y se ajusta y restando la altura.
t_pixel proj_orthogonal(t_point point, int scale_z, int z_range[2]) {
  t_pixel pixel_to_draw;

  pixel_to_draw.x = point.x;
  pixel_to_draw.y = point.y - (point.height * scale_z);
  if (point.native) {
    pixel_to_draw.color = point.color;
  } else {
    pixel_to_draw.color = interpolColor((point.height * scale_z), z_range);
  }
  return pixel_to_draw;
}
