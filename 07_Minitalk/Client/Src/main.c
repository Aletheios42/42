#include "client.h"

int ft_error(char *msg_error) {
  printf("error: %s \n", msg_error);
  return 0;
}

/*
 * @params: msg, el mensaje para seer envidado al server
 *
 * @notice: esta funcion tiene que enviar señales de SIGUSR 1 y 2
 *  a traves de la funcion kill al server
 */
int client_handler(pid_t server_pid, char *msg) {
  int i;
  unsigned char byte;

  printf("Estoy ejecutando handler\n");

  while (*msg) {
    byte = (unsigned char)(*msg);
    printf("\nel caracter: %c\nen binario:\n", *msg);

    i = -1;
    // TODO hay que cambiar el print por un sistema de
    // if else para mandar SIGUSR(1,2) -> Bin(0,1)
    while (++i <= 7) {
      // printf("%d ", (byte >> i) & 0b1);
      if ((byte >> i) & 0b1)
        return (kill(server_pid, SIGUSR1));
      else
        return (kill(server_pid, SIGUSR2));
    }
    msg++;
  }
  if (0)
    ft_error("Fallo en el handler\n");
  return 0;
}

/*
 * @params: av[1]: pid del server
 *            av[2]: mensaje que hay que enviar
 * @notice: este programa pretender mandar un mensaje por señales a un server
 *
 */
int main(int ac, char **av) {

  printf("Estoy ejecutando el cliente\n");

  if (ac == 3) {
    client_handler(ft_atoi(av[1]), av[2]);
  }
  return 0;
}
