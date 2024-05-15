/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:23:27 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/15 15:27:05 by jceron-g         ###   ########.fr       */
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
