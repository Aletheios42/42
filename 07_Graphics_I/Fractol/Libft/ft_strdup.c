/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:31:13 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/14 00:34:54 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;
	int		i;

	i = ft_strlen(s1);
	aux = (char *) malloc(sizeof(char) * (i + 1));
	if (aux == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
