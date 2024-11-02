/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:53:33 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/18 23:05:19 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 57) || (str[i] < 48))
		{
			return (0);
		}
	i++;
	}
	return (1);
}	

/*int	main(void)
{
	char	str[];

	str[] = "1234a";
	ft_str_is_numeric(str);
	return (0);
}*/
