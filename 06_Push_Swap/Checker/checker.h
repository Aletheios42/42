/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:10:58 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/08 19:38:48 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//MOVEMENTS push.c && rotate.c && swap.c
void	ft_rotate_bonus(t_stack **stack);
void	ft_reverse_rotate_bonus(t_stack **stack);
void	ft_doublerotate_bonus(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_doublerotate_bonus(t_stack **stack_a, t_stack **stack_b);
void	loop_rotate_bonus(t_stack **stack_a, t_stack **stack_b, int i, char x);
void	ft_swap_bonus(t_stack **stack);
void	ft_doubleswap_bonus(t_stack **stack_a, t_stack **stack_b);
void	ft_pushtoa_bonus(t_stack **stack_a, t_stack **stack_b);
void	ft_pushtob_bonus(t_stack **stack_a, t_stack **stack_b);

//PARSER parse.c
void	card_to_ord(t_stack **stack);
t_stack	*stack_a_maker(char **nbr);
t_stack	*ft_parser(int argc, char **argv);

//CHECKER args_checker.c
void	valid_int_checker(char *nbr);
void	duplicate_checker(char **nbr);
void	ft_checker(char **nbr);

//EXECUTE execute.c
void	execute_move(t_stack **stack_a, t_stack **stack_b, char *line);
void	execute_sort(t_stack **stack_a, t_stack **stack_b);

//UTILS   utils.c
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
int		ft_stacksize(t_stack *stack);
char	**ft_argv_cleaner(int argc, char **argv);
void	ft_stackadd_back(t_stack **stack, t_stack *node);

//ERROR   error.c
void	ft_error(void);

#endif
