/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tu_nombre <tu_email@student.42.fr>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:00:00 by tu_nombre          #+#    #+# */
/*   Updated: 2024/04/27 12:00:00 by tu_nombre         ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <stddef.h>

// Function prototypes for actions
void handle_height(void);  // Handle height input
void handle_color(void);   // Handle color input
void handle_space(void);   // Handle spaces
void handle_newline(void); // Handle newlines
void handle_eof(void);     // Handle end of file
void handle_error(void);   // Handle errors
void handle_comma(void);   // Handle commas

/* Definition of states */
enum e_state {
  STATE_START,
  STATE_HEIGHT,  // State for height
  STATE_COLOR,   // State for color
  STATE_SPACE,   // State for space
  STATE_NEWLINE, // State for newline
  STATE_END,
  STATE_ERROR,
  STATE_COUNT
};

/* Definition of tokens */
enum e_token {
  TOKEN_HEIGHT, // Token for height
  TOKEN_COLOR,  // Token for color
  TOKEN_COMMA,
  TOKEN_SPACE,
  TOKEN_NEWLINE,
  TOKEN_EOF,
  TOKEN_INVALID,
  TOKEN_COUNT
};

/* Transition structure definition */
struct s_automaton {
  void (*action)(void);
  enum e_state next_state;
};

#endif
