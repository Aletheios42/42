/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:47 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/21 10:45:44 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	while (1 < nb)
	{
		nb--;
		result *= nb;
	}
	return (result);
}

/*int	main(void)
{
	int	nb;

	nb = 6;
	ft_iterative_factorial(nb);
	printf("%d", ft_iterative_factorial(nb));
	return (0);
}*/
