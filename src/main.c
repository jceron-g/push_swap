/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:31:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 12:55:42 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	leak(void)
{
	system("leaks -q push_swap");
}

void	print_stack(t_stack **stack)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->data);
		*stack = (*stack)->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	//atexit(leak);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			print_error();
		make_array(argv);
	}
	else
		print_error();
}
