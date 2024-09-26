
#include "../Inc/fdf.h"

// Function to handle height (receives a token, a map, and the row and column)
int handle_height(char *token, t_map *map, int row, int *col) {
  printf("Handling height at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle color (receives a token, a map, and the row and column)
int handle_color(char *token, t_map *map, int row, int *col) {
  printf("Handling color at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle space (receives token, map, row, and col, but does nothing
// specific here)
int handle_space(char *token, t_map *map, int row, int *col) {
  printf("Handling space at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle newline
int handle_newline(char *token, t_map *map, int row, int *col) {
  printf("Handling newline at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle end of file
int handle_eof(char *token, t_map *map, int row, int *col) {
  printf("Handling end of file...\n");
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle errors
int handle_error(char *token, t_map *map, int row, int *col) {
  printf("Handling error at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}

// Function to handle commas (if used in the input)
int handle_comma(char *token, t_map *map, int row, int *col) {
  printf("Handling comma at row: %d, col: %d...\n", row, *col);
  (void)token;
  (void)map;
  (void)row;
  (void)col;
}
