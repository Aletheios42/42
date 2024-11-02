/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:18:11 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:47:34 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_bonus(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *stack;
	if (first_node == NULL || first_node->next == NULL)
		return ;
	second_node = first_node->next;
	last_node = second_node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	first_node->next = NULL;
	second_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = second_node;
}

void	ft_reverse_rotate_bonus(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = *stack;
	while (aux->next)
		aux = aux->next;
	if (aux->prev)
		aux->prev->next = NULL;
	aux->next = *stack;
	(*stack)->prev = aux;
	aux->prev = NULL;
	*stack = aux;
}

void	ft_doublerotate_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_bonus(stack_a);
	ft_rotate_bonus(stack_b);
}

void	ft_reverse_doublerotate_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_bonus(stack_a);
	ft_reverse_rotate_bonus(stack_b);
}

void	loop_rotate_bonus(t_stack **stack_a, t_stack **stack_b, int i, char x)
{
	while (i)
	{
		if (i > 0)
		{
			if (x == 'a')
				ft_rotate_bonus(stack_a);
			if (x == 'b')
				ft_rotate_bonus(stack_b);
			i--;
		}
		else
		{
			if (x == 'a')
				ft_reverse_rotate_bonus(stack_a);
			if (x == 'b')
				ft_reverse_rotate_bonus(stack_b);
			i++;
		}
	}
}
