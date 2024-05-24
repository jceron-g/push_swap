/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:31:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/24 13:08:06 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	printf("-------Stack %s\n", str);
	while (stack)
	{
		printf("Value: %d\t Index: %d\t Position: %d\t Target Position: %d\t Cost B: %d\t, Cost A: %d\t Cost total: %d\n", 
				stack->data, stack->index, stack->pos, stack->target_pos, stack->cost_b, stack->cost_a, stack->total_cost);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			print_error();
		set_stack_up(argv);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();
}
