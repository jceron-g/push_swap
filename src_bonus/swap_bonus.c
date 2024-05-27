/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:36:19 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/27 13:56:46 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		third = second->next;
		second->next = first;
		first->next = third;
		*stack = second;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	swap_bonus(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(str, "sb", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(str, "ss", 2) == 0)
		ss(stack_a, stack_b);
}
