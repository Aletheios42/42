/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:04:19 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/05 17:04:55 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	get_target(t_stack **a, int b_idx, int t_idx, int t_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (t_idx != INT_MAX)
		return (t_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (t_pos);
}

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		t_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	t_pos = 0;
	while (tmp_b)
	{
		t_pos = get_target(stack_a, tmp_b->index, INT_MAX, t_pos);
		tmp_b->target_pos = t_pos;
		tmp_b = tmp_b->next;
	}
}
