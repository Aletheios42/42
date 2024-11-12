#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

// t_automaton **assign_automaton() {
//   static t_automaton state_automaton_table[state_count][token_count] = {
//       // Estado: state_expect_value
//       {{handle_height, state_expect_separator}, // token_height
//        {NULL, state_invalid},                   // token_comma
//        {handle_color, state_expect_separator},  // token_color
//        {handle_space, state_expect_value},      // token_space
//        {handle_newline, state_expect_value},    // token_newline
//        {NULL, state_end},                       // token_eof
//        {NULL, state_invalid}},                  // token_invalid
//
//       // Estado: state_expect_separator
//       {{NULL, state_invalid},                // token_height
//        {handle_comma, state_expect_value},   // token_comma
//        {NULL, state_invalid},                // token_color
//        {handle_space, state_expect_value},   // token_space
//        {handle_newline, state_expect_value}, // token_newline
//        {NULL, state_end},                    // token_eof
//        {NULL, state_invalid}},               // token_invalid
//   };
//   return (t_automaton **)state_automaton_table;
// }

t_automaton **new_automaton() {
  // Reservar memoria para el autómata
  t_automaton **automaton_instance =
      (t_automaton **)malloc(sizeof(t_automaton *) * state_count);
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
