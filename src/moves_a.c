/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:11:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 10:09:29 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **src, t_stack **dest)
{
	t_stack	*aux;

	if (*src != NULL && dest != NULL)
	{
		aux = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = aux;
		ft_putstr_fd("pa", 1);
	}
}

void	swap_a(t_stack **stack)
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
		ft_putstr_fd("sa", 1);
	}
}
