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

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <stddef.h>

/* Definición de estados */
enum e_state {
  STATE_START,
  STATE_READ_NUMBER,
  STATE_AFTER_NUMBER,
  STATE_AFTER_COMMA,
  STATE_READ_HEX,
  STATE_EXPECT_SPACE_OR_NEWLINE,
  STATE_END,
  STATE_ERROR,
  STATE_COUNT
};

/* Definición de tokens */
enum e_token {
  TOKEN_NUMBER,
  TOKEN_HEX_COLOR,
  TOKEN_COMMA,
  TOKEN_SPACE,
  TOKEN_NEWLINE,
  TOKEN_EOF,
  TOKEN_INVALID,
  TOKEN_COUNT
};

/* Definición de transición */
struct s_transition {
  void (*action)(void);
  enum e_state next_state;
};

#endif
