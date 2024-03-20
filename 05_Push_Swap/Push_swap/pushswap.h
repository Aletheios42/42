/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:25:25 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/07 00:28:46 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	int				pos;
	int				target_pos;
	int				dst_a;
	int				dst_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//MOVEMENTS push.c && rotate.c && swap.c
void	ft_rotate(t_stack **stack, char x);
void	ft_reverse_rotate(t_stack **stack, char x);
void	ft_doublerotate(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_doublerotate(t_stack **stack_a, t_stack **stack_b);
void	loop_rotate(t_stack **stack_a, t_stack **stack_b, int i, char x);
void	ft_swap(t_stack **stack, char x);
void	ft_doubleswap(t_stack **stack_a, t_stack **stack_b);
void	ft_pushtoa(t_stack **stack_a, t_stack **stack_b);
void	ft_pushtob(t_stack **stack_a, t_stack **stack_b);

//PARSER parse.c
void	card_to_ord(t_stack **stack);
t_stack	*stack_a_maker(char **nbr);
t_stack	*ft_parser(int argc, char **argv);

//CHECKER args_checker.c
void	valid_int_checker(char *nbr);
void	duplicate_checker(char **nbr);
void	ft_checker(char **nbr);

//SORT  sort.c
int		is_sorted(t_stack *stack);
int		get_lowest_index_position(t_stack **stack);
void	shift_stack(t_stack **stack_a);
int		find_highest_index(t_stack *stack);
void	sort_3(t_stack **stack);
void	push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

//SEGUNDA PARTE ALGORITMO   distancia.c
void	do_move(t_stack **a, t_stack **b, int dst_a, int dst_b);
void	get_dst(t_stack **stack_a, t_stack **stack_b);
int		ft_chooser(t_stack *stack);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//TERCERA PARTE ALGORITMO posicion.c
int		get_lowest_index_position(t_stack **stack);
int		get_target(t_stack **a, int b_idx, int t_idx, int t_pos);
void	get_position(t_stack **stack);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);

//UTILS   utils.c
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);
int		ft_stacksize(t_stack *stack);
char	**ft_argv_cleaner(int argc, char **argv);
void	ft_stackadd_back(t_stack **stack, t_stack *node);

//ERROR   error.c
void	ft_error(char *msg);

//long    weight_stack(t_stack  **stack_a);
//long    weight_calculator(t_stack **stack_a, t_stack **stack_b);
//void    ft_algorithm(t_stack **stack_a);

#endif
