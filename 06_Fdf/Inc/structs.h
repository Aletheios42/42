#ifndef STRUCTS_H
#define STRUCTS_H

// Enumeration of possible states in the automaton
enum e_state {
  state_start,
  state_height,  // State to process height values
  state_color,   // State to process color values
  state_space,   // State to process spaces
  state_newline, // State to process newlines
  state_end,     // Final state
  state_error,   // Error state
  state_count    // Total number of states
};

// Enumeration of possible tokens the automaton can process
enum e_token {
  token_height,  // Token representing a height value
  token_color,   // Token representing a color value
  token_comma,   // Token representing a comma (e.g., separating values)
  token_space,   // Token representing spaces between values
  token_newline, // Token representing a newline
  token_eof,     // Token representing end-of-file
  token_invalid, // Token representing an invalid input
  token_count    // Total number of token types
};

// Forward declaration of the map structure
typedef struct s_map t_map;

// Transition structure for the automaton
struct s_automaton {
  void (*action)(char *, t_map *, int,
                 int);     // Pointer to function for token actions
  enum e_state next_state; // The next state after the action
};

// Typedef for easier use of s_automaton structure
typedef struct s_automaton t_automaton;

// Map structure definition
struct s_map {
  int ***map;   // 3D array storing the map data
  int *columns; // Array of column counts per row
  int rows;     // Total number of rows
  int max_z;    // Maximum Z value (height)
  int min_z;    // Minimum Z value (height)
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

