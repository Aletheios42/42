/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:37:54 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/15 19:51:14 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!s && !d)
		return (0);
	if (src < dst)
	{
		while (0 < len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*		GLOBAL*
 *		werwerwer              	|
 *		                     	|
 *		HEAP
 *		......................
 *		                     	|
 *		                     	|
 *		                     	|
 *		                    main|
 *		STACK
 *

const char *g_var;

int	main(void)
{

	int i = 0;
	char src[] = "Hola";
	char dst[] = "Queso";
	long a = 1214341985;

	int *nb = (int *)src;
	char *ptr = (char *)&ptr;


	printf("queso = %u\n", nb);

	printf("%p: ", ptr);

	while (i < 64)
	{
		if (ft_isprint(ptr[i]))
			printf("%c", ptr[i]);
		else
			printf(".");
		++i;
	}

	printf("\n");
	i = 0;
	while (i < 64)
	{
		printf("%hhu = %c\n", ptr[i], ptr[i]);
		++i;
	}

	printf("\n");
//	size_t	len;


//	dst = "Queso";
//	src = "Hola";
//	len = 2;
//	printf("%s", ft_memmove(dst, src, len));
	return (0);
}*/
