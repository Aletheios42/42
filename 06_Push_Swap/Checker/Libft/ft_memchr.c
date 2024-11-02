/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:52:49 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/14 06:50:21 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char const	*sr;

	i = 0;
	sr = s;
	while (i < n)
	{
		if (sr[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
