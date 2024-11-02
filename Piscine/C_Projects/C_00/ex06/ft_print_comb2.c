/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:55:41 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/18 15:03:37 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int num1, int num2)
{
	int	d1;
	int	u1;
	int	d2;
	int	u2;

	d1 = num1 / 10 + '0';
	u1 = num1 % 10 + '0';
	d2 = num2 / 10 + '0';
	u2 = num2 % 10 + '0';
	if (num1 < num2)
	{	
		if (num1 < 99)
		{
			write(1, &d1, 1);
			write(1, &u1, 1);
			write(1, " ", 1);
			write(1, &d2, 1);
			write(1, &u2, 1);
		}
		if (num1 < 98)
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 0;
	while (num1 <= 99)
	{
		while (num2 <= 99)
		{	
			ft_putchar(num1, num2);
			num2++;
		}
		num2 = ++num1 + 1;
	}
}	

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
