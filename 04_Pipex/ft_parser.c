/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:57 by alepinto          #+#    #+#             */
/*   Updated: 2023/07/11 10:40:34 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_checker(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*path_getter(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*path;
	char	*cmd_path;

	i = path_checker(env);
	if (!env[i])
		return (NULL);
	env_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		path = ft_strjoin(env_path[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_matrix(env_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_matrix(env_path);
	return (EXIT_SUCCESS);
}
