/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:48:00 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/19 01:45:40 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	ft_capitalizer(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	ft_letterchecker(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_nonalphanummeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z'))
		return (0);
	else
		return (1);
}

void	ft_lowerizer(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_lowerizer(str);
	while (str[i] != '\0')
	{
		if (ft_letterchecker(str[i]) && ft_nonalphanummeric(str[i -1]))
			str[i] = ft_capitalizer(str[i]);
			i++;
	}
	return (str);
}

/*int main(void)
{
    char	str[]  = "salut, comment tu vas ? 42mots";
    ft_strcapitalize(str);
    return (0);
}*/
