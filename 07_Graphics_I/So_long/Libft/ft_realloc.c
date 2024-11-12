#include "libft.h"
#include <stdlib.h>
#include <string.h>

void *ft_realloc(void *ptr, size_t old_size, size_t new_size) {
  // Si ptr es NULL, se comporta como malloc
  if (ptr == NULL) {
    return malloc(new_size);
  }

  // Si el nuevo tamaño es 0, se comporta como free y devuelve NULL
  if (new_size == 0) {
    free(ptr);
    return NULL;
  }

  // Asigna un nuevo bloque de memoria con el tamaño solicitado
  void *new_ptr = malloc(new_size);
  if (new_ptr == NULL) {
    return NULL; // Retorna NULL si malloc falla
  }

  // Copia el contenido de la memoria antigua al nuevo bloque
  // Calcula el tamaño de la copia como el mínimo entre el tamaño antiguo y el
  // nuevo tamaño
  memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);

  // Libera el bloque de memoria original
  free(ptr);

  return new_ptr;
}
