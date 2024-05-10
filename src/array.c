/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:03:41 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/10 10:05:06 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	check_dup(number, len);
	make_stack(number, len);
	free_matrix(new_matrix);
	free(number);
}
