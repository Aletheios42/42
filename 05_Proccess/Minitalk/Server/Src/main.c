#include "../Inc/server.h"

int ft_error(char *msg_error) {
  printf("error: %s \n", msg_error);
  return 0;
}

/*
 * @notice: esta funcion tiene que recibir las señales en 0 y 1, y
 * descodificarlo
 */

void handle() {
  printf("Estoy ejecutando handler en el server\n");
  if (0)
    ft_error("Fallo en el handler en el server\n");
}

/*
 * @notice: este servidor tiene que:
 *               enseñar su pid por terminal
 *               esperar para recibir señales de cliente
 *               Decodificar y enseñar por terminal el mensaje del cliente
 */
int main(int ac, char **av) {
  pid_t server_pid;

  if (ac == 3) {
    server_pid = getpid();
    printf("Estoy ejecutando el server %d\n", server_pid);

    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);

    while (1) {
    }
  } else
    printf("Bad Input\n");
  return 0;
}
