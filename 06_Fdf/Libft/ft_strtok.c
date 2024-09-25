#include "libft.h"

char *ft_strtok(char *str, const char *delim) {
  static char *last; // Mantiene el estado entre llamadas
  if (str == NULL)
    str = last; // Usa el último estado
  if (*str == '\0') {
    last = str;
    return NULL;
  } // Fin de tokens

  char *start = str; // Inicio del token
  while (*str && !strchr(delim, *str))
    str++; // Busca el final del token

  if (*str) {
    *str = '\0';    // Termina el token
    last = str + 1; // Mueve last al siguiente carácter
  } else {
    last = str; // Actualiza last si llegó al final
  }

  return start; // Devuelve el token encontrado
}
