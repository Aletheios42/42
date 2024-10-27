/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:09:36 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/15 00:34:21 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

/*int	main(void)
{
	char const	s1[] = "queso";
	char const	s2[] = "hola";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
