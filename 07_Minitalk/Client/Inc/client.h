#ifndef CLIENT_H
#define CLIENT_H

#include "../Libft/libft.h"

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int client_handler(pid_t server_pid, char *msg);
int ft_error(char *msg_error);

#endif
