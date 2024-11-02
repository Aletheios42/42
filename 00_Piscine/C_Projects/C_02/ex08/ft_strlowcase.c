/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:46:16 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/19 01:13:10 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

/*int	main(int argc, char **argv)
{
	ft_strlowcase(argv[1]);
	return (0);
}*/
