/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:58:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/25 11:30:32 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = stack_size(aux_a);
	size_b = stack_size(aux_b);
	while (aux_b)
	{
		if (aux_b->pos <= size_b / 2)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		if (aux_b->target_pos <= size_a / 2)
			aux_b->cost_a = aux_b->target_pos;
		else
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

void	put_total_cost(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux)
	{
		aux->total_cost = total_cost(aux->cost_a, aux->cost_b);
		aux = aux->next;
	}
}

void	smallest_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*lowest_cost_node;
	int		low_cost;
	int		cost;

	aux = *stack_b;
	low_cost = -1;
	cost = 0;
	while (aux)
	{
		cost = total_cost(aux->cost_a, aux->cost_b);
		if (low_cost == -1 || cost < low_cost)
		{
			low_cost = cost;
			lowest_cost_node = aux;
		}
		aux = aux->next;
	}
	loop_moves(stack_a, stack_b, lowest_cost_node);
}
