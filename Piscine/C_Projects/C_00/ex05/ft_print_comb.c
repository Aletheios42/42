/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:19:52 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/18 16:16:51 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int c, int d, int u)
{
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, &u, 1);
	if (c != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = '0';
	d = '1';
	u = '2';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
			{
				ft_putchar(c, d, u);
				u++;
			}
			d++;
		}
		c++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
