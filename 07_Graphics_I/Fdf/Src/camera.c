#include "../Inc/fdf.h"

void init_camera(t_cam *camera) {
  ft_memset(camera, 0, sizeof(t_cam));
  camera->scale_factor = 1;
}
