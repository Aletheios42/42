/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:47:23 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/13 06:36:23 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int					count;

	count = write(1, "0x", 2);
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}
