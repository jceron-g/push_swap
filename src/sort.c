/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:39:29 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/14 12:00:43 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	**aux;

	aux = stack;
	while (is_sorted(*aux) == 0)
	{
		if (is_sorted(*aux) == 1)
			return ;
		if ((*aux)->data > (*aux)->next->data
			&& (*aux)->data > (*aux)->next->next->data)
			ra(aux);
		else if ((*aux)->next->data > (*aux)->data
			&& (*aux)->next->data > (*aux)->next->next->data)
			rra(aux);
		if ((*aux)->data > (*aux)->next->data)
			sa(aux);
	}
}
