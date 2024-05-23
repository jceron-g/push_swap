/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:34 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 11:34:13 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first_stack;
	t_stack	*last_stack;

	first_stack = *stack;
	last_stack = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last_stack->next != NULL)
	{
		last_stack = last_stack->next;
	}
	last_stack->next = first_stack;
	*stack = (*stack)->next;
	first_stack->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	move_rr(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
}
