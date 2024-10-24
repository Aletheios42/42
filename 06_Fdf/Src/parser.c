#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

t_automaton **assign_automaton() {
  static t_automaton state_automaton_table[state_count][token_count] = {

      // Estado: state_expect_value
      {{handle_height, state_expect_separator}, // token_height
       {NULL, state_invalid},                   // token_comma
       {handle_color, state_expect_separator},  // token_color
       {handle_space, state_expect_value},      // token_space
       {handle_newline, state_expect_value},    // token_newline
       {NULL, state_end},                       // token_eof
       {NULL, state_invalid}},                  // token_invalid

      // Estado: state_expect_separator
      {{NULL, state_invalid},                // token_height
       {handle_comma, state_expect_value},   // token_comma
       {NULL, state_invalid},                // token_color
       {handle_space, state_expect_value},   // token_space
       {handle_newline, state_expect_value}, // token_newline
       {NULL, state_end},                    // token_eof
       {NULL, state_invalid}},               // token_invalid
  };

  // Retornar un puntero a la tabla de estados
  return (t_automaton **)state_automaton_table;
}

// Función para determinar el tipo de token basado en el estado y la línea
int determine_token_type(const char *line, int state) {

  // Determinar si es un token_height (primer carácter es dígito o '-' seguido
  // de dígito)
  if (((line[0] >= '0' && line[0] <= '9') || (line[0] == '-')) &&
      (state == state_expect_value)) {
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

int process_tokens(t_map *map, int fd, t_automaton **state_automaton) {
  t_automaton current_automaton;
  char *line = NULL;
  int state;
  int token_type;

  state = state_expect_value;
  token_type = token_newline;
  while (state != state_end) {
    current_automaton = state_automaton[state][token_type];

    // TODO revisar los limites de este if, creo que estan cambiados
    if (current_automaton.action && !current_automaton.action(&line, map, fd))
      return (free(line), -1);

    state = current_automaton.next_state;
    if (state == state_end)
      break;
    if (state == state_invalid)
      return (free(line), -1);
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

  fd = open(map_file, O_RDONLY);
  if (fd == -1)
    return -1;

  map->dim.rows = -1;
  t_automaton **state_automaton = assign_automaton();
  while (1) {
    // TODO cambiar os codigos de vuellta de process tken para saber
    // cuando termnina bien y cunado es invalid
    // 2 casos, break o return , probablemente gestionar las exits code con
    // un enum sea la mejor opcion
    if (process_tokens(map, fd, state_automaton) == -1)
      return (free(map), close(fd),
              /* TODO liberar todo el mapa*/ -1);
  }
  return (close(fd), 0);
}
