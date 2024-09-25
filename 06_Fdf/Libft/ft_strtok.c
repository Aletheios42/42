#include "libft.h"

char *ft_strtok(char *str, const char *delim) {
  static char *last;
  if (str == NULL)
    str = last;
  if (*str == '\0') {
    last = str;
    return NULL;
  }

  char *start = str;
  while (*str && !strchr(delim, *str))
    str++;

  if (*str) {
    *str = '\0';
    last = str + 1;
  } else {
    last = str;
  }

  return start;
}
