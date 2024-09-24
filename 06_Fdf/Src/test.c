#include "../Inc/fdf.h" // Asegúrate de que este archivo contenga las definiciones necesarias.
#include <stdlib.h> // Para malloc

// Tabla de transiciones
Transition transition_table[STATE_COUNT][TOKEN_COUNT] = {
    {{parse_number, STATE_READ_NUMBER},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_START},
     {handle_newline, STATE_START},
     {handle_eof, STATE_END},
     {handle_error, STATE_ERROR}},
    {{NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_AFTER_NUMBER},
     {NULL, STATE_AFTER_NUMBER},
     {NULL, STATE_ERROR},
     {handle_error, STATE_ERROR}},
    {{parse_number, STATE_READ_NUMBER},
     {NULL, STATE_ERROR},
     {handle_error, STATE_ERROR},
     {NULL, STATE_AFTER_NUMBER},
     {handle_newline, STATE_START},
     {handle_eof, STATE_END},
     {handle_error, STATE_ERROR}},
    {{NULL, STATE_ERROR},
     {parse_hex, STATE_READ_HEX},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {handle_error, STATE_ERROR}},
    {{NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_EXPECT_SPACE_OR_NEWLINE},
     {handle_newline, STATE_START},
     {NULL, STATE_ERROR},
     {handle_error, STATE_ERROR}},
    {{parse_number, STATE_READ_NUMBER},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_EXPECT_SPACE_OR_NEWLINE},
     {handle_newline, STATE_START},
     {handle_eof, STATE_END},
     {handle_error, STATE_ERROR}},
    {{NULL, STATE_END},
     {NULL, STATE_END},
     {NULL, STATE_END},
     {NULL, STATE_END},
     {NULL, STATE_END},
     {NULL, STATE_END},
     {NULL, STATE_END}},
    {{NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR},
     {NULL, STATE_ERROR}}};

// Constructor del autómata
Transition **create_automaton() {
  Transition **automaton_instance = malloc(sizeof(Transition *) * STATE_COUNT);
  for (int i = 0; i < STATE_COUNT; i++) {
    automaton_instance[i] = malloc(sizeof(Transition) * TOKEN_COUNT);
    for (int j = 0; j < TOKEN_COUNT; j++) {
      automaton_instance[i][j] = transition_table[i][j];
    }
  }
  return automaton_instance;
}

