/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:10:42 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/17 02:00:19 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack **stack, char x)
{
	long	aux1;
	long	aux2;
	long	aux_ind1;
	long	aux_ind2;

	if (*stack == NULL || (*stack)->next == NULL)
		ft_error("ERROR: EMPTY STACK\n");
	aux1 = (*stack)->nbr;
	aux2 = (*stack)->next->nbr;
	aux_ind1 = (*stack)->index;
	aux_ind2 = (*stack)->next->index;
	(*stack)->nbr = aux2;
	(*stack)->next->nbr = aux1;
	(*stack)->index = aux_ind2;
	(*stack)->next->index = aux_ind1;
	if (x == 'a')
		write(1, "sa\n", 3);
	else if (x == 'b')
		write(1, "sb\n", 3);
	else if (x == 'c')
		return ;
	else
		ft_error("ERROR: BAD STACK\n");
}

void	ft_doubleswap(t_stack **stacka, t_stack **stackb)
{
	ft_swap(stacka, 'c');
	ft_swap(stackb, 'c');
	write(1, "ss\n", 3);
}
