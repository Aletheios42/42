/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:28:09 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/14 02:53:16 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*straux1;
	const char	*straux2;

	i = 0;
	straux1 = dst;
	straux2 = src;
	if (!straux1 && !straux2)
		return (0);
	while (i < n)
	{
		straux1[i] = straux2[i];
		i++;
	}
	return (dst);
}
