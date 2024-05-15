/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:18:20 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/15 17:32:40 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*min_value;
	int		index;

	aux = stack;
	index = 1;
	while (aux)
	{
		while (aux && aux->index != -1)
			aux = aux->next;
		if (!aux)
			return ;
		min_value = aux;
		while (aux)
		{
			if (aux->data < min_value->data && aux->index == -1)
				min_value = aux;
			aux = aux->next;
		}
		min_value->index = index;
		index++;
		aux = stack;
	}
}

void	assign_pos(t_stack *stack)
{
	t_stack	*aux;
	int		position;

	position = 0;
	aux = stack;
	while (aux)
	{
		aux->pos = position;
		aux = aux->next;
		position++;
	}
}

void	find_smallest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*smallest;
	int		position;

	aux = *stack;
	smallest = *stack;
	position = 0;
	while (aux)
	{
		if (smallest->index > aux->index)
		{
			position = aux->pos;
			smallest = aux;
		}
		aux = aux->next;
	}
	return (position);
}

void	assign_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack *node;
	while (stack_b != NULL)
	{	
	}
}
