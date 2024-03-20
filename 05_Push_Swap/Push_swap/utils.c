/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:08:35 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/05 17:08:38 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	printf("%li----->", stack->nbr);
	printf("%li\n", stack->index);
	print_stack(stack->next);
}

char	**ft_argv_cleaner(int argc, char **argv)
{
	char	**aux;
	int		i;

	aux = (char **)malloc(sizeof(char *) * argc);
	i = -1;
	while (++i < argc - 1)
		aux[i] = ft_strdup(argv[i + 1]);
	aux[i] = NULL;
	return (aux);
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*aux;

	if (*stack == NULL)
		*stack = node;
	else
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
		aux->next->prev = aux;
	}
}
