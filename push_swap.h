/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:02:14 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 10:17:31 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft.h"

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

// ---------------CHECK ERRORS----------------//
void	print_error(void);
void	check_limits(long number);
int		check_dup(int *numbers, int len);
// -----------------ARRAYS--------------------//
void	set_stack_up(char **str);
long	ft_atol(char *str);
void	free_matrix(char **matrix);
int		ft_abs(int a, int b);
// -----------------STACK--------------------//
t_stack	*make_stack(int *numbers, int len);
t_stack	*new_stack(int content);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **lst);
void	create_stack(int *array, int len);
int		stack_size(t_stack *stack);
void	print_stack(t_stack *stack, char *str);
// -----------------MOVES--------------------//
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rot(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
// --------------ALGORITHM-------------------//
void	assign_index(t_stack *stack);
void	assign_pos(t_stack *stack);
void	assign_target_pos(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	send_b(t_stack **stack_a, t_stack **stack_b);
int		find_smallest(t_stack **stack);
//-------------------COSTS------------------------//
void	set_costs(t_stack **stack_a, t_stack **stack_b);
int		put_abs(int number);
int		total_cost(int a, int b);
void	put_total_cost(t_stack **stack);
t_stack	*smallest_cost(t_stack **stack);

#endif