/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:36:33 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/20 00:13:39 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{	
		div = (*a) / (*b);
		mod = (*a) % (*b);
		*a = div;
		*b = mod;
	}
}

/*int	main(void)
{
	int	i;
	int	j;
	int	*a;
	int	*b;

	i = 10;
	j = 2;
	a = &i;
	b = &j;
	printf("%d /", i);
	printf("%d\n", j);
	ft_ultimate_div_mod(a, b);
	printf("%d", *a);
	printf("%d", *b);
}*/
