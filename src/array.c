/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/13 13:10:17 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
	Esto deberia ser un int puntero porque queremos que nos devuelva
	el array de int para poder trabajar con ellas y el stack.
*/
/*
t_stack	**make_stack(char **str)
{
	int		i;
	int		j;
	char	*aux;
	t_stack	**stack;

	i = 0;
	j = 0;
	aux = ft_split(str[1], ' ');
	while (str[i])
		i++;
	(*stack)->size = i;
	while ((*stack)->next != NULL)
	{
		
	}
}
*/
void	make_array(char **str)
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

void	create_stack(int *array, int len)
{
	t_stack	*stack;

	stack = make_stack(array, len);
	print_stack(stack);
	free_stack(&stack);
	free(array);
}