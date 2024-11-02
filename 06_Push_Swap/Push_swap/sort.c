/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:13:09 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:50:38 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stacksize(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_reverse_rotate(stack_a, 'a');
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rotate(stack_a, 'a');
			lowest_pos--;
		}
	}
}

int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_3(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ft_rotate(stack, 'a');
	else if ((*stack)->next->index == highest)
		ft_reverse_rotate(stack, 'a');
	if ((*stack)->index > (*stack)->next->index)
		ft_swap(stack, 'a');
}

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stacksize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_pushtob(stack_a, stack_b);
			pushed++;
		}
		else
			ft_rotate(stack_a, 'a');
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_pushtob(stack_a, stack_b);
		pushed++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_dst(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
