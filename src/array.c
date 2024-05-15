/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/15 11:04:04 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_stack_up(char **str)
{
	char	**new_matrix;
	int		*number;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	new_matrix = ft_split(str[1], ' ');
	while (new_matrix[len])
		len++;
	number = (int *)malloc(sizeof(int) * len);
	if (!number)
		return ;
	while (new_matrix[i])
		number[j++] = ft_atol(new_matrix[i++]);
	if (check_dup(number, len) == 0)
	{
		free_matrix(new_matrix);
		print_error();
	}
	create_stack(number, len);
	free_matrix(new_matrix);
}

void	create_stack(int *array, int len)
{
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;

	stack_a = make_stack(array, len);
	//assign_index(stack_a);
	send_b(&stack_a, &stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(array);
}
