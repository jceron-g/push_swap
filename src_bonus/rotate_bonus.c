/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:34 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/27 13:56:32 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rotate_bonus(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rb(stack_b);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(stack_a, stack_b);
}
