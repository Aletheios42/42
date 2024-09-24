#include <stdlib.h>  // Para malloc y free
#include "../Inc/fdf.h"  // Asegúrate de que este archivo contenga las definiciones necesarias.

// Función para asignar la función de transición de estados
void assign_state_transition_function(Transition (*state_transition_function)[TOKEN_COUNT]) {
    Transition state_transition_table[STATE_COUNT][TOKEN_COUNT] = {
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

    // Asignar la función de transición de estados
    for (int i = 0; i < STATE_COUNT; i++) {
        for (int j = 0; j < TOKEN_COUNT; j++) {
            state_transition_function[i][j] = state_transition_table[i][j];
        }
    }
}

// Constructor puro del autómata
Transition** new_automaton() {
    // Crear una nueva instancia del autómata
    Transition **automaton_instance = malloc(sizeof(Transition*) * STATE_COUNT);
    for (int i = 0; i < STATE_COUNT; i++) {
        automaton_instance[i] = malloc(sizeof(Transition) * TOKEN_COUNT);
    }

    // Asignar la función de transición de estados
    assign_state_transition_function(automaton_instance);
    
    return automaton_instance;
}

// Función para liberar la memoria del autómata
void delete_automaton(Transition **automaton_instance) {
    if (automaton_instance) {
        // Liberar cada fila de la función de transición de estados
        for (int i = 0; i < STATE_COUNT; i++) {
            free(automaton_instance[i]);
        }
        // Liberar el puntero de la función de transición de estados
        free(automaton_instance);
    }
}

