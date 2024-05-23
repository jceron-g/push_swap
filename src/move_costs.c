/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:16:04 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 11:26:39 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_ra(t_stack **stack, int cost_a)
{
	while (cost_a > 0)
	{
		ra(stack);
		cost_a--;
	}
}

void	move_rb(t_stack **stack, int cost_b)
{
	while (cost_b > 0)
	{
		ra(stack);
		cost_b--;
	}
}

void	move_rra(t_stack **stack, int cost_a)
{
	while (cost_a > 0)
	{
		rra(stack);
		cost_a--;
	}
}

void	move_rrb(t_stack **stack, int cost_b)
{
	while (cost_b > 0)
	{
		rrb(stack);
		cost_b--;
	}
}