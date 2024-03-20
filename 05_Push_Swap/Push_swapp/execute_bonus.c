/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:09:04 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:47:16 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_move(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pushtoa_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pushtob_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate_bonus(stack_a);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_reverse_rotate_bonus(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate_bonus(stack_b);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate_bonus(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_doublerotate_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_reverse_doublerotate_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap_bonus(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap_bonus(stack_b);
	else
		ft_error("error1");
}

void	execute_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_move(stack_a, stack_b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}
