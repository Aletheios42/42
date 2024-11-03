/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:50:21 by alepinto          #+#    #+#             */
/*   Updated: 2023/07/11 10:32:48 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_all(int fd, char *temp)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	i = 1;
	while (!(ft_strchr_gnl(temp, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		temp = ft_strjoin_gnl(temp, buff);
	}
	free(buff);
	return (temp);
}

static char	*get_line(char *temp)
{
	char	*newtemp;
	int		len;
	int		j;

	len = 0;
	j = 0;
	if (temp[0] == '\0')
		return (NULL);
	while (temp[len] != '\n' && temp[len] != '\0')
		len++;
	if (temp[len] == '\n')
		len++;
	newtemp = (char *)malloc(len + 1);
	if (!newtemp)
		return (0);
	while (j < len)
	{
		newtemp[j] = temp[j];
		j++;
	}
	newtemp[j] = '\0';
	return (newtemp);
}

static char	*new_temp(char *temp)
{
	char	*newtemp;
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (temp[k] != '\n' && temp[k] != '\0')
		k++;
	if (!temp[k])
	{
		free(temp);
		return (0);
	}
	newtemp = (char *)malloc(ft_strlen(temp) - k + 1);
	if (!newtemp)
	{
		free(temp);
		return (0);
	}
	while (temp[k++])
		newtemp[i++] = temp[k];
	newtemp[i] = '\0';
	free(temp);
	return (newtemp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp[fd] = read_all(fd, temp[fd]);
	if (!temp[fd])
		return (0);
	line = get_line(temp[fd]);
	temp[fd] = new_temp(temp[fd]);
	return (line);
}
