/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/25 11:38:10 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		free_matrix(new_matrix);
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

void	create_stack(int *array, int len)
{
	t_stack	*stack_a;

	stack_a = make_stack(array, len);
}
