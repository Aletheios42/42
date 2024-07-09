/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:52:33 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/20 00:14:16 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		aux = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = aux;
		i++;
	}
}

/*int	main(void)
{
	int	i;
	int	size;
	int	arr[];

	arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size = 10;
	i = 0;
	ft_rev_int_tab(arr, size);
	while (i < size)
	{	
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}*/
