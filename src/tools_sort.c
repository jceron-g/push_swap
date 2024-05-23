/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:18:20 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 18:34:49 by jceron-g         ###   ########.fr       */
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

int	find_smallest(t_stack **stack)
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
	t_stack	*b;
	t_stack	*a;
	t_stack	*closest;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		closest = NULL;
		while (a)
		{
			if (b->data < a->data
				&& (closest == NULL || closest->data > a->data))
				closest = a;
			a = a->next;
		}
		if (closest == NULL)
			b->target_pos = find_smallest(stack_a);
		else
			b->target_pos = closest->pos;
		b = b->next;
	}
}

void	sort_and_init(t_stack **stack_a, t_stack **stack_b)
{
	int	check;
	int i;

	i = 0;
	while (*stack_b)
	{
		assign_pos(*stack_a);
		assign_pos(*stack_b);
		assign_target_pos(stack_a, stack_b);
		set_costs(stack_a, stack_b);
		put_total_cost(stack_b);
		smallest_cost(stack_a, stack_b);
	}
	assign_pos(*stack_a);
	check = find_smallest(stack_a);
	//printf("%d\n", check);
	if (check <= stack_size(*stack_a) / 2)
	{
		while (i < check)
		{
			ra(stack_a);
			i++;
		}
	}	
	else
	{
		i = check;
		while (i < stack_size(*stack_a))
		{
			rra(stack_a);
			i++;
		}
	}
	print_stack(*stack_a, "A");
}

