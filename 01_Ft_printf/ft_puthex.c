/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:18:44 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/13 06:50:29 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *hexa_base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, hexa_base);
	count += ft_putchar(hexa_base[n % 16]);
	return (count);
}
