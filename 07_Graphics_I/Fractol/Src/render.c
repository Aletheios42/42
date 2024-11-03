#include "../Inc/fractol.h"
#include <stdio.h>
#include <stdlib.h>

void render(int **data) {
  printf("Execute called with parsed data:\n");
  for (int i = 0; i < 2; i++) { // Supongamos que es 2x2
    for (int j = 0; j < 2; j++) {
      printf("%d ", data[i][j]);
    }
    printf("\n");
  }
}
