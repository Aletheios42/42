/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:14:10 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/07 03:36:40 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_typechecker(char format, va_list ap)
{
	if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (format == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

	// printf("%c\n", format);
	// write (1, "HOLA\n",5);
	// write (1, &format, 1);
	// return 0;