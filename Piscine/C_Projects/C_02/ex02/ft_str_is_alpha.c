/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:50:47 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/19 00:51:10 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 'A') || ((str[c] > 'Z') && (str[c] < 'a'))
			|| (str[c] > 'z'))
			return (0);
		c++;
	}
	return (1);
}	

/*int	main(void)
{	
	char	str[];

	str = "124Afds*^!da2";
	printf("%i ", ft_str_is_alpha(str));
	return (0);
}*/
