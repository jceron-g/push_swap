/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:11:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 11:41:48 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*aux;

	if (*src != NULL && dest != NULL)
	{
		aux = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = aux;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
/*

void	rotate_a(t_stack **stack)
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
	ft_putstr_fd("ra\n", 1);
}
*/