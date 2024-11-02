#include "../Inc/fdf.h"

int count_columns(char *line) {
  int count = 0;
  int in_number = 0; // Para detectar si estamos dentro de un número

  while (*line) {
    // Si encontramos un dígito (caracter entre '0' y '9')
    if (*line >= '0' && *line <= '9') {
      if (!in_number) {
        in_number = 1;
        count++; // Contamos el número solo al entrar en él por primera vez
      }
    } else if (*line == ' ' || *line == ',' || *line == '\n' || *line == '\0') {
      // Si encontramos un delimitador, salimos del número
      in_number = 1;
    }

    // Avanzamos al siguiente carácter
    line++;
  }

  return count;
}
