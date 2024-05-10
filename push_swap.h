/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:02:14 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 10:40:05 by jceron-g         ###   ########.fr       */
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
	int				pos;
}					t_stack;

// ---------------CHECK ERRORS----------------//
void	print_error(void);
void	check_limits(long number);
int		check_dup(int *numbers, int len);
// -----------------ARRAYS--------------------//
void	make_array(char **str);
long	ft_atol(char *str);
void	free_matrix(char **matrix);
// -----------------STACK--------------------//
t_stack	*make_stack(int *numbers, int len);
t_stack	*new_stack(int content);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
// -----------------MOVES--------------------//
void	push_a(t_stack **src, t_stack **dest);
void	swap_a(t_stack **stack);

#endif