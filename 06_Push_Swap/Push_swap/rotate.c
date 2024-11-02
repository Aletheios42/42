/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:18:11 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/17 02:00:55 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate(t_stack **stack, char x)
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
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
	else if (x == 'c')
		return ;
	else
		ft_error("ERROR: BAD STACK22\n");
}

void	ft_reverse_rotate(t_stack **stack, char x)
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
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
	else if (x == 'c')
		return ;
	else
		ft_error("ERROR: BAD STACK\n");
}

void	ft_doublerotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'c');
	ft_rotate(stack_b, 'c');
	write(1, "rr\n", 3);
}

void	ft_reverse_doublerotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 'c');
	ft_reverse_rotate(stack_b, 'c');
	write(1, "rrr\n", 4);
}

void	loop_rotate(t_stack **stack_a, t_stack **stack_b, int i, char x)
{
	while (i)
	{
		if (i > 0)
		{
			if (x == 'a')
				ft_rotate(stack_a, 'a');
			if (x == 'b')
				ft_rotate(stack_b, 'b');
			i--;
		}
		else
		{
			if (x == 'a')
				ft_reverse_rotate(stack_a, 'a');
			if (x == 'b')
				ft_reverse_rotate(stack_b, 'b');
			i++;
		}
	}
}
