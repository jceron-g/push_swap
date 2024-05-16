/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:58:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/16 13:58:20 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_costs(t_stack **stack)
{
	int		middle_pos;
	int		max_pos;
	t_stack	*aux;

	aux = *stack;
	max_pos = stack_size(*stack);
	middle_pos = stack_size(*stack) / 2;
	while (aux)
	{
		if ((aux)->pos > middle_pos)
		{
			aux->cost_b = ((max_pos - aux->pos) + 1) * -1;
		}
		else
			aux->cost_b = (max_pos - aux->pos) - 1;
		aux = aux->next;
	}
}
