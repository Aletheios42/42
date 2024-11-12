#include "../Inc/fdf.h"

void init_camera(t_cam *camera) {
  camera->projection = 0;
  camera->scale_factor = 1;
  camera->offset[0] = 0;
  camera->offset[1] = 0;
  camera->angle[0] = 0;
  camera->angle[1] = 0;
  camera->angle[2] = 0;
}
