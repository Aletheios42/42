/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/11 19:09:24 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_first_child(int *fd[], char **argv, char **env) {
  if (ft_strncmp(argv[1], "here_doc", 9) == 0) {
    child_heredoc(fd, argv, env);
    return (1);
  } else {
    child_input(fd, argv, env);
    return (0);
  }
  return (0);
}

void child_heredoc(int **fd, char **argv, char **env) {
  pid_t child;
  int temp_fd;

  child = fork();
  if (child < 0)
    ft_error("fork");
  if (child == 0) {
    temp_fd = ft_heredoc(argv[1], argv[2]);
    if (temp_fd < 0)
      ft_error(argv[1]);
    close(fd[0]);
    dup2(temp_fd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(temp_fd);
    close(fd[1]);
    ft_exec(argv[3], env);
  }
  wait(&child);
  close(fd[1]);
  dup2(fd[0], STDIN_FILENO);
  close(fd[0]);
}

void child_input(int **fd, char **argv, char **env) {
  pid_t child;
  int fd_input;

  child = fork();
  if (child < 0)
    ft_error("fork");
  if (child == 0) {
    fd_input = open(argv[1], O_RDONLY);
    if (fd_input < 0)
      ft_error(argv[1]);
    close(fd[0]);
    dup2(fd_input, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd_input);
    close(fd[1]);
    ft_exec(argv[2], env);
  }
  close(fd[1]);
  dup2(fd[0], STDIN_FILENO);
  close(fd[0]);
}

void child_middle(int **fd, int pos, char **argv, char **env) {
  pid_t child;

  pipe(fd);
  child = fork();
  if (child < 0)
    ft_error("fork");
  if (child == 0) {
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    ft_exec(argv[pos], env);
  }
  close(fd[1]);
  dup2(fd[0], STDIN_FILENO);
  close(fd[0]);
}

pid_t child_output(int **fd, int pos, char **argv, char **env) {
  pid_t child;
  int fd_output;

  (void)fd;
  child = fork();
  if (child < 0)
    ft_error("fork");
  if (child == 0) {
    fd_output = open(argv[pos + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd_output < 0)
      ft_error(argv[pos + 1]);
    dup2(fd_output, STDOUT_FILENO);
    close(fd_output);
    close(fd[1]);
    close(fd[0]);
    ft_exec(argv[pos], env);
  }
  close(fd[0]);
  close(fd[1]);
  return (child);
}
