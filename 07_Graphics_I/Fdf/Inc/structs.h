#ifndef STRUCTS_H
#define STRUCTS_H

// Enumeración de los posibles estados en el autómata
enum e_state {
  state_item,      // 0 Estado valor (height o color)
  state_separator, // 1 Estado separador (coma, espacio, nl)
  state_end,       // 2 Estado final
  state_invalid,   // 3 Estado para manejar entradas inválidas
  state_count      // 4 Número total de estados
};

// Enumeración de los posibles tokens que puede procesar el autómata
enum e_token {
  token_height,  // 0 Token que representa un valor de altura
  token_comma,   // 1 Token que representa una coma (e.g., separa valores)
  token_color,   // 2 Token que representa un valor de color
  token_space,   // 3 Token que representa espacios entre valores
  token_newline, // 4 Token que representa un salto de línea
  token_eof,     // 5 Token que representa el final del archivo
  token_invalid, // 6 Token que representa una entrada inválida
  token_count    // 7 Número total de tipos de tokens
};

typedef struct s_map t_map;

typedef struct s_point {
  int x;
  int y;
  int height;  // height value associated with the point
  int color;   // Color value associated with the point
  bool native; // If point`s color was specified in source map
} t_point;

typedef struct s_pixel {
  int x;
  int y;
  int color;
} t_pixel;

struct s_map {
  t_point **coors;      // 3D array storing the parsered map data
  t_pixel **proj_coors; // 3D array storing the projected map to render
  int *cols;            // Array of column counts per row
  int rows;             // Total number of rows
  int z_range[2];       // Maximum Z value (height)
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

// Main FDF structure representing the entire program state
typedef struct s_fdf {
  t_mlx *mlx; // Pointer to graphic tools
  t_cam *cam; // Pointer to camera settings
  t_map *map; // Pointer to the map data
} t_fdf;

#endif // STRUCTS_H
