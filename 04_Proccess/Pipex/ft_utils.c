/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:50 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/11 19:04:57 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_heredoc(char *argv1, char *argv2)
{
	char	*line;
	int		temp_fd;

	temp_fd = open(argv1, O_CREAT | O_RDWR | O_TRUNC, 0777);
	while (1)
	{
		ft_putstr_fd("heredoc XD >>", 0);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(argv2, line, ft_strlen(argv2)) == 0)
			break ;
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	close(temp_fd);
	temp_fd = open(argv1, O_RDONLY);
	return (temp_fd);
}

void	ft_unlink(char *file, char **env)
{
	char	*path_fd;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (env && ft_strncmp("PWD=", env[i], 4) == 0)
			path_fd = ft_strjoin(env[i] + 4, file);
	}
	unlink(path_fd);
	free(path_fd);
}

int	ft_relative_path(char *cmd)
{
	int	check;

	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "/", 1) == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	if (!*argv)
		ft_error(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_free_error(cmd, "malloc");
	if (ft_relative_path(cmd[0]) && access(cmd[0], F_OK) == 0)
		path = cmd[0];
	else if (ft_relative_path(cmd[0]) == 1 && access(cmd[0], F_OK))
	{
		perror(cmd[0]);
		ft_free_matrix(cmd);
		exit(errno);
	}
	else
	{	
		path = path_getter(cmd[0], env);
		if (!path)
			ft_error2(cmd[0]);
	}
	if (path && execve(path, cmd, env) == -1)
		ft_free_error(cmd, "exceve");
}

void	ft_waitchid(pid_t child)
{
	int	status;
	int	pid;
	int	exit_status;

	pid = 1;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == child)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	exit(exit_status);
}
