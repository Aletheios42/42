/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:20:09 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:28:26 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_move(t_stack **stack_a, t_stack **stack_b, int dst_a, int dst_b)
{
	if (dst_a < 0 && dst_b < 0)
	{
		while (dst_a < 0 && dst_b < 0)
		{
			dst_a++;
			dst_b++;
			ft_reverse_doublerotate(stack_a, stack_b);
		}
	}
	else if (dst_a > 0 && dst_b > 0)
	{
		while (dst_a > 0 && dst_b > 0)
		{
			dst_a--;
			dst_b--;
			ft_doublerotate(stack_a, stack_b);
		}
	}
	loop_rotate(stack_a, stack_b, dst_a, 'a');
	loop_rotate(stack_a, stack_b, dst_b, 'b');
	if (*stack_b)
		ft_pushtoa(stack_a, stack_b);
}

void	get_dst(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stacksize(tmp_a);
	size_b = ft_stacksize(tmp_b);
	while (tmp_b)
	{
		tmp_b->dst_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->dst_b = (size_b - tmp_b->pos) * -1;
		tmp_b->dst_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->dst_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	ft_chooser(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (tmp->dst_a * tmp->dst_b < 0)
		return (ft_absolute_value(tmp->dst_a) + ft_absolute_value(tmp->dst_b));
	else if (tmp->dst_a * tmp->dst_b > 0)
	{
		if (ft_absolute_value(tmp->dst_a) >= ft_absolute_value(tmp->dst_b))
			return (ft_absolute_value(tmp->dst_a));
		else
			return (ft_absolute_value(tmp->dst_b));
	}
	else if (tmp->dst_a == 0)
		return (ft_absolute_value(tmp->dst_b));
	else
		return (ft_absolute_value(tmp->dst_a));
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		p;
	int		dst_a;
	int		dst_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		p = ft_chooser(tmp);
		if (p < ft_absolute_value(cheapest))
		{
			cheapest = p;
			dst_a = tmp->dst_a;
			dst_b = tmp->dst_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, dst_a, dst_b);
}
