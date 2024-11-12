#include <stdio.h>

void print_int_array(int *arr, int size) {
  if (arr == NULL) {
    printf("El puntero es NULL\n");
    return;
  }

  printf("Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
