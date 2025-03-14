#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>

typedef struct s_mlx {
  void *mlx;
  void *win;
  void *img;
  void *addr;
  int bpp;
  int lpl;
  int endian;
} t_mlx;

typedef struct s_trgb {
  uint8_t t1;
  uint8_t t2;
  uint8_t r1;
  uint8_t r2;
  uint8_t g1;
  uint8_t g2;
  uint8_t b1;
  uint8_t b2;
  uint8_t t;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint32_t color;
} t_trgb;

#endif // STRUCTS_H
