#include "automaton.h" // Asegúrate de incluir el archivo correcto.
#include "fdf.h"       // Incluye tu estructura t_map.
#include <stdlib.h>
#include <string.h> // Para usar strtok

// Prototipos de funciones
int count_columns(char *line); // Esta función cuenta el número de columnas.
void handle_height(char *token, t_map *map, int row, int col);
void handle_color(char *token, t_map *map, int row, int col);
void handle_space(void);
void handle_newline(void);
void handle_eof(void);
void handle_error(void);

// Función principal de análisis del mapa
int parse_map(int fd, t_map *map) {
  char *line;
  int row = 0;

  while ((line = get_next_line(fd)) != NULL) {
    // Contar las columnas en la línea
    int columns = count_columns(line);

    // Usar el autómata para procesar la línea
    automaton **state_automaton = assign_automaton();
    int state = STATE_START;         // Estado inicial
    char *token = strtok(line, " "); // Tokeniza la línea por espacios
    int j = 0;

    // Inicializa la memoria para la nueva fila
    map->map[row] = malloc(sizeof(int *) * columns);
    if (!map->map[row]) {
      free(line);
      return -1; // Error en la asignación
    }
    map->columns[row] = columns;

    while (token != NULL) {
      // Determina el tipo de token y llama a la función del autómata
      int token_type = determine_token_type(token); // Debes implementar esto
      automaton *current_automaton = state_automaton[state][token_type];

      // Llama a la función correspondiente si no es NULL
      if (current_automaton->action) {
        current_automaton->action(token, map, row, j);
      }
      state = current_automaton->next_state; // Transición al siguiente estado

      // Prepara el siguiente token
      token = strtok(NULL, " ");
      j++;
    }

    row++;
    free(line); // Libera la línea leída
  }

  map->rows = row; // Establece el número total de filas
  return 0;        // Éxito
}
