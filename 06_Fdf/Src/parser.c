#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

int count_columns(char *line) {
  int count = 0;
  int in_number = 0; // Para detectar si estamos dentro de un número

  while (*line) {
    // Si encontramos un dígito (caracter entre '0' y '9')
    if (*line >= '0' && *line <= '9') {
      if (!in_number) {
        in_number = 1;
        count++; // Contamos el número solo al entrar en él por primera vez
      }
    } else if (*line == ' ' || *line == ',' || *line == '\n' || *line == '\0') {
      // Si encontramos un delimitador, salimos del número
      in_number = 1;
    }

    // Avanzamos al siguiente carácter
    line++;
  }

  return count;
}

// Función para determinar el tipo de token
int determine_token_type(const char *token) {
  // TODO mergear los 2 primeros ifs para dar token value
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

int process_tokens(char *line, t_map *map, int row,
                   t_automaton **state_automaton) {
  int state = state_start;
  int j = 0;

  while (line != NULL) {
    int token_type = determine_token_type(line);
    t_automaton current_automaton = state_automaton[state][token_type];

    if (current_automaton.action &&
        !current_automaton.action(&line, map, row, &j)) {
      return -1;
    }

    state = current_automaton.next_state;
  }
  return 0;
}

// Esta funcion se dedica a leer el mapa a traves de :
//(1) leer a linea,
//(2) contar los temrinos por linea
//(3) allocar memoria con realloc para el mapa y las dimensiones del map
//(4) !! alocar memoria para map->colum
//(5) llenar map->coors con los tokens
int parser(t_map *map, char *map_file) {
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
    if (process_tokens(line, map, row, state_automaton))
      return (free(line), /*liberar todo el mapa*/ -1);
    free(line);
  }
  map->rows = row;
  return close(fd), free(map), 0;
}
