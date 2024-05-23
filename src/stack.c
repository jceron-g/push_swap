/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:23:27 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 18:22:42 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*make_stack(int *numbers, int len)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = new_stack(numbers[i]);
	i++;
	while (i < len)
	{
		stack_add_back(&stack_a, new_stack(numbers[i]));
		i++;
	}
	return (stack_a);
}

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
	sort_and_init(stack_a, stack_b);
}
