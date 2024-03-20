/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:10:42 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:48:16 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_bonus(t_stack **stack)
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
}

void	ft_doubleswap_bonus(t_stack **stacka, t_stack **stackb)
{
	ft_swap_bonus(stacka);
	ft_swap_bonus(stackb);
}
