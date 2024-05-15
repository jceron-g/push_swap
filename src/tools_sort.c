/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:18:20 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/15 11:38:24 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_b(t_stack **stack_a, t_stack **stack_b)
{
	int	total_elements;
	int	middle_index;

	assign_index(*stack_a);
	total_elements = stack_size(*stack_a);
	middle_index = total_elements / 2;
	while (stack_size(*stack_a) > middle_index)
	{
		if ((*stack_a)->index <= middle_index)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
}
