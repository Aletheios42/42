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

// Función para determinar el tipo de token basado en el estado y la línea
int determine_token_type(const char *line, int state) {

  // Determinar si es un token_height (primer carácter es dígito o '-' seguido
  // de dígito)
  if (((line[0] >= '0' && line[0] <= '9') || (line[0] == '-')) &&
      (state == state_start || state == state_expect_value)) {
    return token_height;
  }

  // Determinar si es un token_color (valor hexadecimal) y si el estado anterior
  // era expect_separator
  else if (ft_strncmp(line, "0x", 2) == 0) {
    return token_color;
  }

  // Determinar si es un token_comma y el estado anterior era expect_value
  else if (line[0] == ',' && state == state_expect_value) {
    return token_comma;
  }

  // Determinar si es un token_space y el estado anterior era expect_separator
  else if (line[0] == ' ' && state == state_expect_separator) {
    return token_space;
  }

  // Determinar si es un token_newline y el estado anterior era expect_separator
  else if (line[0] == '\n' && state == state_expect_separator) {
    return token_newline;
  }

  // Si ninguna de las condiciones anteriores se cumple, es un token_invalid
  return token_invalid;
}

int process_tokens(t_map *map, int fd, t_dim dim,
                   t_automaton **state_automaton) {
  int state = state_start;
  t_automaton current_automaton;
  char *line = NULL;
  int token_type;

  token_type = token_newline;
  while (state != state_end || state != state_invalid) {
    current_automaton = state_automaton[state][token_type];

    if (current_automaton.action &&
        !current_automaton.action(&line, map, &dim, fd))
      return -1;

    state = current_automaton.next_state;
    if (state == state_end)
      break;
    if (state == state_invalid)
      return -1;
    token_type = determine_token_type(line, state);
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
  int fd;
  t_dim dim;

  fd = open(map_file, O_RDONLY);
  if (fd == -1)
    return -1;

  dim.rows = -1;
  t_automaton **state_automaton = assign_automaton();
  while (1) {
    if (process_tokens(map, fd, dim, state_automaton) == -1)
      return (free(map), close(fd),
              /* TODO liberar todo el mapa*/ -1);
  }
  map->dim = dim;
  return (close(fd), 0);
}
