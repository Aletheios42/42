/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:10:52 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/24 03:26:03 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	divisor;

	divisor = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if ((nb % 2 == 0) && (nb > 2))
		return (0);
	while (divisor <= (nb / divisor))
	{
		if (nb % divisor == 0)
			return (0);
		divisor += 2;
	}
	return (1);
}

/*int	main(void)
{
	int	nb;

	nb = 2147483647;
	printf("%d", ft_is_prime(nb));
	return (0);
}*/
