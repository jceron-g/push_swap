/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:34 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 11:47:12 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	first_node = *stack;
	last_node = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = first_node;
	*stack = (*stack)->next;
	first_node->next = NULL;
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