/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:25:56 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/21 10:48:50 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	number;

	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
		number = nb * ft_recursive_factorial(nb - 1);
	return (number);
}

/*int	main(void)
{
	int	nb;

	nb = 9;
	ft_recursive_factorial(nb);
	printf("%d", ft_recursive_factorial(nb));
	return (0);
}*/
