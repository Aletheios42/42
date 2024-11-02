/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:39:47 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/11 09:18:31 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[c] != '\0')
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char *src = "Hola mundo";
	char *dest = "Chao pescao";
	char *dest1 = ft_strcat(dest , src);
	printf("%s\n", dest1);
	return (0);
}
