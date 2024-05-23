/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:39:29 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 13:31:11 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	**aux;

	aux = stack;
	while (is_sorted(*aux) == 0)
	{
		if (is_sorted(*aux) == 1)
			return ;
		if ((*aux)->data > (*aux)->next->data
			&& (*aux)->data > (*aux)->next->next->data)
			ra(aux);
		else if ((*aux)->next->data > (*aux)->data
			&& (*aux)->next->data > (*aux)->next->next->data)
			rra(aux);
		if ((*aux)->data > (*aux)->next->data)
			sa(aux);
	}
}

void	loop_moves(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_cost)
{
	int	cost_a;
	int	cost_b;

	cost_a = lowest_cost->cost_a;
	cost_b = lowest_cost->cost_b;
	if (cost_a > 0 && cost_b > 0)
		move_rr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		move_rrr(stack_a, stack_b, &cost_a, &cost_b);
	while (cost_a != 0 || cost_b != 0)
	{
		move_ra(stack_a, &cost_a);
		move_rb(stack_b, &cost_b);
		move_rra(stack_a, &cost_a);
		move_rrb(stack_b, &cost_b);
	}
	pa(stack_a, stack_b);
}


