/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:03:11 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/12 02:24:44 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	new_size;
	size_t	i;

	i = 0;
	new_size = count * size;
	aux = (void *)malloc(new_size);
	if (aux == NULL)
		return (NULL);
	while (i < new_size)
	{
		aux[i] = '\0';
		i++;
	}
	return (aux);
}
