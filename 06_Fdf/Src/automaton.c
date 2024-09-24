lude "../Inc/automaton.h"
#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.

automaton **assign_automaton() {
  static automaton state_automaton_table[STATE_COUNT][TOKEN_COUNT] = {
      {{handle_height, STATE_HEIGHT}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
       {NULL, STATE_START}, {handle_space, STATE_SPACE}, {handle_newline, 
       STATE_NEWLINE}, {handle_eof, STATE_END}},
      {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
       {NULL, STATE_COLOR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {handle_error, STATE_ERROR}},
      {{handle_color, STATE_COLOR}, {NULL, STATE_ERROR}, {handle_error, 
       STATE_ERROR}, {NULL, STATE_SPACE}, {handle_newline, STATE_NEWLINE}, 
       {handle_eof, STATE_END}, {handle_error, STATE_ERROR}},
      {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {handle_error, STATE_ERROR}},
      {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {NULL, STATE_ERROR}, {handle_newline, STATE_START}, {NULL, 
       STATE_ERROR}, {handle_error, STATE_ERROR}},
      {{NULL, STATE_END}, {NULL, STATE_END}, {NULL, STATE_END}, {NULL, 
       STATE_END}, {NULL, STATE_END}, {NULL, STATE_END}, {NULL, STATE_END}},
      {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, 
       {NULL, STATE_ERROR}}};

  // Retornar un puntero a la tabla de estado
  return (automaton **)state_automaton_table;
}

automaton **new_automaton() {
  // Reservar memoria para el autómata
  automaton **automaton_instance = malloc(sizeof(automaton *) * STATE_COUNT);
  if (!automaton_instance) return NULL; // Manejo de error en caso de fallo en malloc

  for (int i = 0; i < STATE_COUNT; i++) {
    automaton_instance[i] = malloc(sizeof(automaton) * TOKEN_COUNT);
    if (!automaton_instance[i]) {
      // Si falla la asignación, liberar las filas anteriores y retornar NULL
      for (int j = 0; j < i; j++) free(automaton_instance[j]);
      free(automaton_instance);
      return NULL;
    }
  }

  // Obtener la tabla de estado y asignarla a la instancia del autómata
  automaton **state_automaton_table = assign_automaton();
  for (int i = 0; i < STATE_COUNT; i++) {
    for (int j = 0; j < TOKEN_COUNT; j++) {
      automaton_instance[i][j] = state_automaton_table[i][j];
    }
  }

  return automaton_instance;
}

// Función para liberar la memoria del autómata
void delete_automaton(automaton **automaton_instance) {
  if (automaton_instance) {
    // Liberar cada fila de la función de transición de estados
    for (int i = 0; i < STATE_COUNT; i++) {
      free(automaton_instance[i]);
    }
    // Liberar el puntero de la función de transición de estados
    free(automaton_instance);
  }
}

