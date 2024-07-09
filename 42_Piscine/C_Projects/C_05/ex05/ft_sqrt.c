/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:51:43 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/21 21:52:30 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb <= 0)
		return (0);
	while (n <= nb / n)
	{
		if (n == nb / n && nb % n == 0)
			return (n);
		n++;
	}
	return (0);
}

/*int	main(void)
{
	int	nb;

	nb = 101;
	ft_sqrt(nb);
	printf("%d", ft_sqrt(nb));
	return (0);
}*/
