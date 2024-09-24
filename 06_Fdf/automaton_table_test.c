ign_automaton() {
    static automaton state_automaton_table[STATE_COUNT][TOKEN_COUNT] = {
        {{parse_number, STATE_READ_NUMBER}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {NULL, STATE_START}, {handle_newline, STATE_START}, {handle_eof, STATE_END},
         {handle_error, STATE_ERROR}},
        {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {NULL, STATE_AFTER_NUMBER}, {NULL, STATE_AFTER_NUMBER}, {NULL, STATE_ERROR},
         {handle_error, STATE_ERROR}},
        {{parse_number, STATE_READ_NUMBER}, {NULL, STATE_ERROR}, {handle_error, STATE_ERROR},
         {NULL, STATE_AFTER_NUMBER}, {handle_newline, STATE_START}, {handle_eof, STATE_END},
         {handle_error, STATE_ERROR}},
        {{NULL, STATE_ERROR}, {parse_hex, STATE_READ_HEX}, {NULL, STATE_ERROR},
         {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {handle_error, STATE_ERROR}},
        {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {NULL, STATE_EXPECT_SPACE_OR_NEWLINE}, {handle_newline, STATE_START},
         {NULL, STATE_ERROR}, {handle_error, STATE_ERROR}},
        {{parse_number, STATE_READ_NUMBER}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {NULL, STATE_EXPECT_SPACE_OR_NEWLINE}, {handle_newline, STATE_START},
         {handle_eof, STATE_END}, {handle_error, STATE_ERROR}},
        {{NULL, STATE_END}, {NULL, STATE_END}, {NULL, STATE_END}, {NULL, STATE_END},
         {NULL, STATE_END}, {NULL, STATE_END}, {NULL, STATE_END}},
        {{NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR},
         {NULL, STATE_ERROR}, {NULL, STATE_ERROR}, {NULL, STATE_ERROR}}};

    return (automaton **)state_automaton_table;
}


