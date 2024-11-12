#ifndef STRUCTS_H
#define STRUCTS_H

// Enumeración de los posibles estados en el autómata
enum e_state {
  state_expect_value,     // 0 Estado valor (height o color)
  state_expect_separator, // 1 Estado separador (coma, espacio, nl)
  state_end,              // 2 Estado final
  state_invalid,          // 3 Estado para manejar entradas inválidas
  state_count             // 4 Número total de estados
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

// Forward declaration of the map structure
typedef struct s_map t_map;

// Forward declaration of the map structure
typedef struct s_dim t_dim;
// Transition structure for the automaton
struct s_automaton {
  int (*action)(char **, t_map *,
                int);      // Pointer to function for token actions
  enum e_state next_state; // The next state after the action
};

// Typedef for easier use of s_automaton structure
typedef struct s_automaton t_automaton;

// Structure representing a point in 3D space
typedef struct s_point {
  int height; // height value associated with the point
  int color;  // Color value associated with the point
} t_point;

// Map structure definition
struct s_map {
  t_point **coors; // 3D array storing the map data
  int *cols;       // Array of column counts per row
  int rows;        // Total number of rows
  int max_z;       // Maximum Z value (height)
  int min_z;       // Minimum Z value (height)
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
  void *mlx; // Pointer to MLX instance
  void *win; // Pointer to the window
} t_mlx;

// Main FDF structure representing the entire program state
typedef struct s_fdf {
  t_mlx *mlx; // Pointer to graphic tools
  t_cam *cam; // Pointer to camera settings
  t_map *map; // Pointer to the map data
} t_fdf;

#endif // STRUCTS_H
