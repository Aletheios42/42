#ifndef STRUCTS_H
#define STRUCTS_H

// Enumeración de los posibles estados en el autómata
enum e_state {
  state_start,            // Estado inicial
  state_expect_value,     // Estado esperando un valor (height o color)
  state_expect_separator, // Estado esperando un separador (coma, espacio, o
                          // nueva línea)
  state_end,              // Estado final
  state_invalid,          // Estado para manejar entradas inválidas
  state_count             // Número total de estados
};

// Enumeración de los posibles tokens que puede procesar el autómata
enum e_token {
  token_height,  // Token que representa un valor de altura
  token_comma,   // Token que representa una coma (e.g., separa valores)
  token_color,   // Token que representa un valor de color
  token_space,   // Token que representa espacios entre valores
  token_newline, // Token que representa un salto de línea
  token_eof,     // Token que representa el final del archivo
  token_invalid, // Token que representa una entrada inválida
  token_count    // Número total de tipos de tokens
};

// Forward declaration of the map structure
typedef struct s_map t_map;

// Forward declaration of the map structure
typedef struct s_dim t_dim;
// Transition structure for the automaton
struct s_automaton {
  int (*action)(char **, t_map *, t_dim *,
                int);      // Pointer to function for token actions
  enum e_state next_state; // The next state after the action
};

// Typedef for easier use of s_automaton structure
typedef struct s_automaton t_automaton;

struct s_dim {
  int *cols; // Array of column counts per row
  int rows;  // Total number of rows
};

// Map structure definition
struct s_map {
  int ***map; // 3D array storing the map data
  s_dim dim;
  int max_z; // Maximum Z value (height)
  int min_z; // Minimum Z value (height)
};

// Structure representing a point in 3D space
typedef struct s_point {
  float x;   // X coordinate
  float y;   // Y coordinate
  float z;   // Z coordinate (height)
  int color; // Color value associated with the point
} t_point;

// Camera settings for rendering the map
typedef struct s_cam {
  int projection;     // Type of projection (e.g., isometric)
  int color_pallet;   // Color pallet to use
  float scale_factor; // Scaling factor for the map
  float scale_z;      // Scaling factor for Z axis
  float move_x;       // Horizontal movement
  float move_y;       // Vertical movement
  double alpha;       // Rotation around X axis
  double beta;        // Rotation around Y axis
  double gamma;       // Rotation around Z axis
} t_cam;

// Main FDF structure representing the entire program state
typedef struct s_fdf {
  void *mlx;  // Pointer to MLX instance
  int win_x;  // Window width
  int win_y;  // Window height
  void *win;  // Pointer to the window
  t_cam *cam; // Pointer to camera settings
  t_map *map; // Pointer to the map data
} t_fdf;

#endif // STRUCTS_H
