/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:09:36 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/13 06:52:42 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_nbrlen(long n)
{
	int	count;

	count = 0;
	if (n < 0)
		++count;
	while (n)
	{
		n /= 10;
		++count;
	}
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n >= 10 || n <= -10)
		count += ft_putnbr(n / 10);
	if (n < 0)
	{
		if (n > -10)
			count += ft_putchar('-');
		count += ft_putchar((n % 10) * -1 + '0');
	}
	else
		count += ft_putchar((n % 10) + '0');
	return (count);
}
