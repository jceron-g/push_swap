/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:18:20 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/15 15:48:16 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_b(t_stack **stack_a, t_stack **stack_b)
{
	int	total_elements;
	int	middle_index;
	int	i;
	
	i = 0;
	assign_index(*stack_a);
	total_elements = stack_size(*stack_a);
	middle_index = total_elements / 2;
	while (stack_size(*stack_a) > 3 && i < middle_index)
	{
		if ((*stack_a)->index <= middle_index)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	while (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
}

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
