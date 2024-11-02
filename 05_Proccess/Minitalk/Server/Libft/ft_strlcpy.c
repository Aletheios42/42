/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 04:53:35 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/14 23:13:26 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char *dst;
	size_t dstsize;
	char *src;
	int x;

	dst = (char *) malloc(sizeof(char)*4);
	src = (char *) malloc(sizeof(char)*4);

	dst[0] = 'a';
	dst[1] = 'b';
	dst[2] = 'c';

	src[0] = '1';
	src[1] = '2';

	dstsize = 5;
	printf("%zu", ft_strlcpy(dst, src, dstsize));
	return (0);
}*/
