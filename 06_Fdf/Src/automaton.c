#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

t_automaton **assign_automaton() {
  static t_automaton state_automaton_table[state_count][token_count] = {
      {{handle_height, state_height},   // state_start
       {NULL, state_error},             // token_invalid
       {handle_comma, state_error},     // token_comma
       {NULL, state_start},             // token_space
       {handle_space, state_space},     // token_newline
       {handle_newline, state_newline}, // token_eof
       {NULL, state_error}},            // token_invalid

      {{NULL, state_error},          // state_height
       {NULL, state_error},          // token_invalid
       {NULL, state_error},          // token_comma
       {handle_color, state_color},  // token_space
       {NULL, state_error},          // token_newline
       {NULL, state_error},          // token_eof
       {handle_error, state_error}}, // token_invalid

      {{handle_color, state_color},     // state_color
       {NULL, state_error},             // token_invalid
       {handle_error, state_error},     // token_comma
       {NULL, state_space},             // token_space
       {handle_newline, state_newline}, // token_newline
       {handle_eof, state_end},         // token_eof
       {handle_error, state_error}},    // token_invalid

      {{NULL, state_error},          // state_space
       {NULL, state_error},          // token_invalid
       {NULL, state_error},          // token_comma
       {NULL, state_error},          // token_space
       {NULL, state_error},          // token_newline
       {NULL, state_error},          // token_eof
       {handle_error, state_error}}, // token_invalid

      {{NULL, state_error},           // state_newline
       {NULL, state_error},           // token_invalid
       {NULL, state_error},           // token_comma
       {NULL, state_error},           // token_space
       {handle_newline, state_start}, // token_newline
       {NULL, state_error},           // token_eof
       {handle_error, state_error}},  // token_invalid

      {{NULL, state_end},  // state_end
       {NULL, state_end},  // token_invalid
       {NULL, state_end},  // token_comma
       {NULL, state_end},  // token_space
       {NULL, state_end},  // token_newline
       {NULL, state_end},  // token_eof
       {NULL, state_end}}, // token_invalid

      {{NULL, state_error}, // state_error
       {NULL, state_error}, // token_invalid
       {NULL, state_error}, // token_comma
       {NULL, state_error}, // token_space
       {NULL, state_error}, // token_newline
       {NULL, state_error}, // token_eof
       {NULL, state_error}} // token_invalid
  };

  // Retornar un puntero a la tabla de estado
  return (t_automaton **)state_automaton_table;
}

t_automaton **new_automaton() {
  // Reservar memoria para el autómata
  t_automaton **automaton_instance =
      malloc(sizeof(t_automaton *) * state_count);
  if (!automaton_instance)
    return NULL; // Manejo de error en caso de fallo en malloc

  for (int i = 0; i < state_count; i++) {
    automaton_instance[i] = malloc(sizeof(t_automaton) * token_count);
    if (!automaton_instance[i]) {
      // Si falla la asignación, liberar las filas anteriores y retornar NULL
      for (int j = 0; j < i; j++)
        free(automaton_instance[j]);
      free(automaton_instance);
      return NULL;
    }
  }

  // Obtener la tabla de estado y asignarla a la instancia del autómata
  t_automaton **state_automaton_table = assign_automaton();
  for (int i = 0; i < state_count; i++) {
    for (int j = 0; j < token_count; j++) {
      automaton_instance[i][j] = state_automaton_table[i][j];
    }
  }

  return automaton_instance;
}

// Función para liberar la memoria del autómata
void delete_automaton(t_automaton **automaton_instance) {
  if (automaton_instance) {
    // Liberar cada fila de la función de transición de estados
    for (int i = 0; i < state_count; i++) {
      free(automaton_instance[i]);
    }
    // Liberar el puntero de la función de transición de estados
    free(automaton_instance);
  }
}
