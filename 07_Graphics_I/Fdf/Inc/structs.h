#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_map t_map;

typedef struct s_pixel {
  int x;
  int y;
  int color;
} t_pixel;

typedef struct s_point {
  int x;
  int y;
  int height;  // height value associated with the point
  int color;   // Color value associated with the point
  bool native; // If point`s color was specified in source map
} t_point;

struct s_map {
  t_point **coors; // 3D array storing the parsered map data
  int *cols;       // Array of column counts per row
  int rows;        // Total number of rows
  int z_range[2];  // Maximum Z value (height)
};

// Camera settings for rendering the map
typedef struct s_cam {
  int projection;     // Type of projection (e.g., isometric)
  float scale_factor; // Scaling factor for the map
  float scale_z;      // Scaling factor for Z axis
  float offset[2];    // movement offset
  double angle[3];    // Rotation around axis
} t_cam;

typedef struct s_mlx {
  void *mlx;
  void *win;
  void *img;
  void *addr;
  int bpp;
  int lpl;
  int endian;
} t_mlx;

// Define la estructura para almacenar los parámetros de Bresenham
typedef struct s_bresenham {
  int x0;
  int y0;
  int x1;
  int y1;
  int dx;
  int dy;
  int sx;
  int sy;
  int err;
  int e2;
} t_bresenham;

// Main FDF structure representing the entire program state
typedef struct s_fdf {
  t_mlx *mlx; // Pointer to graphic tools
  t_cam *cam; // Pointer to camera settings
  t_map *map; // Pointer to the map data
} t_fdf;

#endif // STRUCTS_H
