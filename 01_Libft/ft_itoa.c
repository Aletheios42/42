/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:35:25 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/20 00:06:45 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitsize(int n)
{
	int	size;

	size = 1;
	if (n > 0)
		size--;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	int		flag;

	flag = 1;
	size = ft_digitsize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		flag *= -1;
		str[0] = '-';
	}
	else
		str[0] = '+';
	while (size > 0)
	{
		str[--size] = (n % 10) * flag + '0';
		n /= 10;
		if (size == 1 && str[0] == '-')
			return (str);
	}
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = -2147483648;
	printf("%s", ft_itoa(n));
	return (0);
} */
