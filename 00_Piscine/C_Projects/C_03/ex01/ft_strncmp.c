/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:00:05 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/20 18:43:05 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (c < n && (s1[c] != '\0' || s2[c] != '\0'))
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	return (0);
}
/*int	main(void)
{
	char	s1[] = "alma";
	char	s2[] = "almb";
	unsigned int		n;
	int					x;
	n = 5;
	x = ft_strncmp(s1, s2, n);
	printf("%d",  x);
	return (0);
}*/
