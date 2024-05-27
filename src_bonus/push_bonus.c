/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:11:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/27 13:56:02 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	push_bonus(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(str, "pb", 2) == 0)
		pb(stack_a, stack_b);
}
