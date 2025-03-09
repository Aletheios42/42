#include "../Inc/fdf.h"

int count_columns(char *line) {
  int count = 0;
  int in_number = 0;

  while (*line) {
    if (*line >= '0' && *line <= '9' && !in_number) {
      count++;
      in_number = 1;
    }
    if (*line == ' ' || *line == '\n')
      in_number = 0;
    line++;
  }
  return count;
}

int ft_open(int *fd, char *map_file) {
  *fd = open(map_file, 0644);
  if (*fd == -1)
    return 0;
  else
    return 1;
}
bool ft_ishex(char c) {
  if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
      (c >= 'a' && c <= 'f'))
    return true;
  return false;
}

static int ft_get_int_from_base(char c, char *base) {
  int i;

  i = 0;
  while (base[i]) {
    if (base[i] == c)
      return (i);
    i++;
  }
  return (-1);
}

int ft_atoi_base(char *str, char *base) {
  int result;
  int base_divider;
  int digit;

  base_divider = (int)ft_strlen(base);
  result = 0;
  while (*str && !ft_isspace(*str)) {
    if (*str == '\n')
      return result;
    result *= base_divider;
    digit = ft_get_int_from_base(*str, base);
    if (digit < 0)
      return (-1);
    result += digit;
    str++;
  }
  return (result);
}
