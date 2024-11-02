/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:09:44 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/24 08:21:26 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_spacechecker(char *str, int *flag)
{
	int	i;

	i = 0;
	while (str[i] == '\f' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*flag *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	x;
	int	flag;
	int	i;

	flag = 1;
	x = 0;
	i = ft_spacechecker(str, &flag);
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{		x = (x * 10) + (str[i] - '0');
		i++;
	}
	return (x * flag);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	char str[] = "    --- 3264";
	printf("%d",ft_atoi(argv[1]));

	return (0);
}
