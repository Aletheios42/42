
#ifndef FDF_H
#define FDF_H

#include "../Libft/libft.h"
#include "../minilibx_linux/mlx.h"
#include "./automata.h"

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "colors.h"
#include "keys.h"

typedef struct s_map {
  int ***map;
  int *columns;
  int rows;
  int max_z;
  int min_z;
} t_map;

typedef struct s_point {
  float x;
  float y;
  float z;
  int color;
} t_point;

typedef struct s_cam {
  int projection;
  int color_pallet;
  float scale_factor;
  float scale_z;
  float move_x;
  float move_y;
  double alpha;
  double beta;
  double gamma;
} t_cam;

typedef struct s_fdf {
  void *mlx;
  int win_x;
  int win_y;
  void *win;
  t_cam *cam;
  t_map *map;
} t_fdf;

#endif
