/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/27 14:00:48 by jceron-g         ###   ########.fr       */
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

void	create_stack(int *array, int len)
{
	t_stack	*stack_a;

	stack_a = make_stack(array, len);
	check_moves(&stack_a);
}


void	input_checker(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_bonus(stack_a, stack_b, "sa");
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_bonus(stack_a, stack_b, "sb");
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		swap_bonus(stack_a, stack_b, "ss");
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate_bonus(stack_a, stack_b, "ra");
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate_bonus(stack_a, stack_b, "rb");
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rotate_bonus(stack_a, stack_b, "rr");
	else if (ft_strncmp(str, "rra\n", 3) == 0)
		rev_rot_bonus(stack_a, stack_b, "rra");
	else if (ft_strncmp(str, "rrb\n", 3) == 0)
		rev_rot_bonus(stack_a, stack_b, "rrb");
	else if (ft_strncmp(str, "rrr\n", 3) == 0)
		rev_rot_bonus(stack_a, stack_b, "rrr");
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push_bonus(stack_a, stack_b, "pa");
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push_bonus(stack_a, stack_b, "pb");
	else
		free_stack_error(stack_a, stack_b);
}

void	check_moves(t_stack **stack_a)
{
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		input_checker(line, stack_a, &stack_b);
		free(line);
	}
	if (is_sorted(*stack_a) == 1 && stack_size(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
}
