/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:02:14 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/25 12:01:39 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				data;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				pos;
}					t_stack;

/*--------------CREATE AND PARSE----------------*/

void	set_stack_up(char **str);
t_stack	*make_stack(int *numbers, int len);
void	create_stack(int *array, int len);
/*-------------------MOVES-----------------------*/
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rev_rot(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/*-------------------TOOLS------------------------*/
void	check_limits(long number);
int		check_dup(int *numbers, int len);
int		is_spaces(char	*str);
long	ft_atol(char *str);
void	free_matrix(char **matrix);
void	free_matrix_error(char **matrix);
void	free_stack(t_stack **lst);
void	print_error(void);
/*-----------------TOOLS STACK---------------------*/
t_stack	*new_stack(int number);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);

#endif