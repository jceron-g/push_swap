/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:51:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/27 13:56:19 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	rrb(t_stack **stack_b)
{
	rev_rot(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
}

void	rev_rot_bonus(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "rra", 2) == 0)
		rra(stack_a);
	else if (ft_strncmp(str, "rrb", 2) == 0)
		rrb(stack_b);
	else if (ft_strncmp(str, "rrr", 2) == 0)
		rrr(stack_a, stack_b);
}
