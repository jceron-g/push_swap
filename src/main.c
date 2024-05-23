/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:31:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/23 10:42:28 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	leak(void)
{
	system("leaks -q push_swap");
}

void	print_stack(t_stack *stack, char *str)
{
	printf("-------Stack %s\n", str);
	while (stack)
	{
		printf("Value: %d\t Index: %d\t Position: %d\t Target Position: %d\t Cost B: %d\t Total Cost: %d\n", 
				stack->data, stack->index, stack->pos, stack->target_pos, stack->cost_b, stack->total_cost);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	atexit(leak);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			print_error();
		set_stack_up(argv);
	}
	else
		print_error();
}
