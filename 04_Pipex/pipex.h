/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:33 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:15 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BONUS
#  define BONUS 0
# endif

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>

void	pipex(char **argv, char **env);
void	pipex_bonus(int argc, char **argv, char **env);
void	child_heredoc(int *fd, char **argv, char **env);
int		ft_heredoc(char *argv1, char *argv2);
int		ft_first_child(int *fd, char **argv, char **env);
void	child_input(int *fd, char **argv, char **env);
void	child_middle(int *fd, int pos, char **argv, char **env);
pid_t	child_output(int *fd, int pos, char **argv, char **env);
int		path_checker(char **env);
char	*path_getter(char *cmd, char **env);
void	ft_exec(char *argv, char **env);
void	ft_waitchid(pid_t child);
void	ft_unlink(char *file, char **env);
int		ft_relative_path(char *cmd);
void	ft_error(char *s);
void	ft_error2(char *s);
void	ft_free_error(char **s, char *r);

#endif
