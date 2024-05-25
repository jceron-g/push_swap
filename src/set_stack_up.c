/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/25 10:04:17 by jceron-g         ###   ########.fr       */
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
		free_matrix_error(new_matrix);
	create_stack(number, len);
	free_matrix(new_matrix);
}

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

void	check_stack_prop(t_stack **stack)
{
	if (is_sorted(*stack) == 1)
	{
		free_stack(stack);
		return ;
	}
	else if (stack_size(*stack) == 2)
		sa(stack);
	else if (stack_size(*stack) == 1)
	{
		free_stack(stack);
		return ;
	}
}

void	create_stack(int *array, int len)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = make_stack(array, len);
	check_stack_prop(&stack_a);
	if (!stack_a)
	{
		free(array);
		return ;
	}
	assign_index(stack_a);
	send_b(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(array);
}
