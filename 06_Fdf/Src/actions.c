#include "../Inc/fdf.h"


// Function to handle height (receives a token, a map, and the row and column)
void handle_height(char *token, t_map *map, int row, int col) {
  printf("Handling height at row: %d, col: %d...\n", row, col);
(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle color (receives a token, a map, and the row and column)
void handle_color(char *token, t_map *map, int row, int col) {
  printf("Handling color at row: %d, col: %d...\n", row, col);


(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle space (receives token, map, row, and col, but does nothing
// specific here)
void handle_space(char *token, t_map *map, int row, int col) {
  printf("Handling space at row: %d, col: %d...\n", row, col);
  // Space handling logic if necessary
(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle newline
void handle_newline(char *token, t_map *map, int row, int col) {
  printf("Handling newline at row: %d, col: %d...\n", row, col);
  // Newline handling logic if necessary
(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle end of file
void handle_eof(char *token, t_map *map, int row, int col) {
  printf("Handling end of file...\n");
  // End of file handling logic
(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle errors
void handle_error(char *token, t_map *map, int row, int col) {
  printf("Handling error at row: %d, col: %d...\n", row, col);
  // Error handling logic
(void)token;
    (void)map;
    (void)row;
    (void)col;
}

// Function to handle commas (if used in the input)
void handle_comma(char *token, t_map *map, int row, int col) {
  printf("Handling comma at row: %d, col: %d...\n", row, col);
  // Comma handling logic if necessary
(void)token;
    (void)map;
    (void)row;
    (void)col;
}
