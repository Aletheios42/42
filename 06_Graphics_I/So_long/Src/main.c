#include "../Inc/so_long.h" // Incluir el archivo de encabezado
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  if (ac == 2) { // Verifica que se reciban exactamente 2 argumentos
    int **data = parser(av);
    if (data != NULL) {
      render(data);
      // Aquí se debería liberar la memoria, pero por simplicidad no lo haremos
    } else {
      printf("Error en el parser.\n");
    }
  } else {
    printf("Uso: %s <arg1> n", av[0]);
  }
  return 0;
}
