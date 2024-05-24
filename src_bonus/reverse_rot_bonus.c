/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:51:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/24 15:06:50 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rot(t_stack **stack)
{
	t_stack	*last_stack;
	t_stack	*second_last_stack;
	t_stack	*new_first;

	last_stack = *stack;
	second_last_stack = NULL;
	new_first = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last_stack->next != NULL)
	{
		second_last_stack = last_stack;
		last_stack = last_stack->next;
	}
	second_last_stack->next = NULL;
	last_stack->next = *stack;
	new_first = last_stack;
	*stack = new_first;
}

void	rra(t_stack **stack_a)
{
	rev_rot(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rot(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	ft_printf("rrr\n");
}

void	mov_rrr(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}
