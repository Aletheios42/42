/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:52:00 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/18 23:37:25 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a') || (str[i] > 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{	
	char	*str;

	str = "asdfas\0";
	printf("%d", ft_str_is_lowercase(argv[1]));
	return (0);
	printf("%c", argv[2][4]);

}*/
