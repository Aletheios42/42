#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

// Función para contar columnas en una línea
int count_columns(const char *line) {
  int count = 0;
  char *temp = strdup(line); // Crea una copia temporal de la línea
  char *token = strtok(temp, " ");
  while (token) {
    count++;
    token = strtok(NULL, " ");
  }
  free(temp); // Libera la copia temporal
  return count;
}

// Función para determinar el tipo de token
int determine_token_type(const char *token) {
  if (ft_isdigit(token[0]) || (token[0] == '-' && ft_isdigit(token[1]))) {
    return token_height; // Cambiado de TOKEN_HEIGHT a token_height
  }
  if (strncmp(token, "0x", 2) == 0 && strlen(token) == 8) {
    return token_color; // Cambiado de TOKEN_COLOR a token_color
  }
  if (strcmp(token, "\n") == 0) {
    return token_newline; // Cambiado de TOKEN_NEWLINE a token_newline
  }
  if (strcmp(token, " ") == 0) {
    return token_space; // Cambiado de TOKEN_SPACE a token_space
  }
  return token_invalid; // Cambiado de TOKEN_INVALID a token_invalid
}

static void process_tokens(char *line, t_map *map, int row,
                           t_automaton **state_automaton) {
  int state = state_start;         // Cambiado de STATE_START a state_start
  char *token = strtok(line, " "); // Tokeniza la línea por espacios
  int j = 0;

  while (token != NULL) {
    int token_type = determine_token_type(token);
    t_automaton current_automaton =
        state_automaton[state][token_type]; // Corrige el tipo

    if (current_automaton.action) {
      current_automaton.action(token, map, row, j);
    }
    state = current_automaton.next_state; // Transición al siguiente estado
    token = strtok(NULL, " ");
    j++;
  }
}

// Implementación de allocate_row_memory
int allocate_row_memory(t_map *map, int row, int columns) {
  // Asegúrate de que la memoria se haya inicializado
  if (map->map == NULL) {
    map->map =
        malloc(sizeof(int **) * map->rows); // Asigna memoria para las filas
    if (!map->map)
      return -1; // Manejo de error
  }

  // Asigna memoria para las columnas
  map->map[row] = malloc(sizeof(int *) * columns);
  if (!map->map[row])
    return -1; // Manejo de error

  // Inicializa las columnas
  for (int j = 0; j < columns; j++) {
    map->map[row][j] =
        malloc(sizeof(int) * 3); // Asumiendo 3 valores por punto (x, y, z)
    if (!map->map[row][j])
      return -1; // Manejo de error
  }

  return 0; // Éxito
}
int parse_map(int fd, t_map *map) {
  char *line;
  int row = -1;

  while (line != NULL || row == -1) {
    get_next_line(fd);
    int columns = count_columns(line);
    if (allocate_row_memory(map, row, columns) != 0) {
      free(line);
      return -1; // Error en la asignación
    }
    map->columns[row] = columns;

    t_automaton **state_automaton = assign_automaton();
    process_tokens(line, map, row, state_automaton);
    row++;
    free(line); // Libera la línea leída
  }

  map->rows = row; // Establece el número total de filas
  return 0;        // Éxito
}

void parser(t_map *map, char *map_file) {
  int fd = open(map_file, O_RDONLY);
  if (fd < 0) {
    perror("Error al abrir el archivo");
    return;
  }

  if (parse_map(fd, map) != 0) {
    close(fd);
    return;
  }

  close(fd);
}
