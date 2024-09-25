#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

// Función para contar columnas en una línea
int count_columns(char *line) {
  int count = 0;
  char *token = ft_strtok(line, " ");
  while (token) {
    count++;
    token = ft_strtok(NULL, " ");
  }
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
  int state = state_start;
  char *token = ft_strtok(line, " ");
  int j = 0;

  while (token != NULL) {
    int token_type = determine_token_type(token);
    t_automaton current_automaton = state_automaton[state][token_type];

    if (current_automaton.action) {
      current_automaton.action(token, map, row, j);
    }
    state = current_automaton.next_state;
    token = strtok(NULL, " ");
    j++;
  }
}

// Esta funcion se dedica a leer el mapa a traves de :
//(1) leer a linea,
//(2) contar los temrinos por linea
//(3) allocar memoria con realloc para el mapa y las dimensiones del map
//(4) !! alocar memoria para map->colum
//(5) llenar map->coors con los tokens
int parse(t_map *map, char *map_file) {
  char *line;
  int fd;
  int row = -1;

  fd = open(map_file, O_RDONLY);
  if (fd == -1)
    return -1;

  t_automaton **state_automaton = assign_automaton();
  while (1) {
    line = get_next_line(fd);
    if (!line)
      break;
    int columns = count_columns(line);
    if (init_row_memory(map, ++row, columns) == -1)
      return (free(line), close(fd), free(map), 1);
    map->columns[row] = columns;
    process_tokens(line, map, row, state_automaton);
    free(line);
  }
  map->rows = row;
  return close(fd), free(map), 0;
}
