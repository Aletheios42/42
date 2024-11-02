/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:58:51 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/15 17:25:12 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_seglen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
				count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		row;
	char	**matrix;

	if (!s)
		return (NULL);
	i = 0;
	row = 0;
	matrix = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (matrix == NULL)
		return (NULL);
	while (row < ft_wordcount(s, c))
	{
		if (s[i] != c)
		{
			matrix[row] = ft_substr(s, i, ft_seglen(s, c, i));
			i += ft_seglen(s, c, i);
			row++;
		}
		else
			i++;
	}
	matrix[ft_wordcount(s, c)] = NULL;
	return (matrix);
}
/*
int main(void)
{
	char const *s = "hola"
	char c = 'b';
	printf("%s", ft_split(s, c));
	return (0);
}*/
