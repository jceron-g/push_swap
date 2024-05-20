/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:51:53 by jceron-g          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:42 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_limits(long number)
{
	if (number < -2147483648 || number > 2147483647)
		print_error();
}

int	ft_abs(int a, int b)
{
	int	len;

	len = 0;
	if (a == 0 && b == 0)
		return (0);
	if (a < 0)
	{
		len = a * -1;
	}
	else
		len = a;
	if (b < 0)
	{
		len = len + (b * -1);
	}
	else
		len = len + b;
	return (len);
}

int	check_dup(int *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i + 1] > '9' || str[i + 1] < '0')
			print_error();
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (str[i] != '\0')
		print_error();
	check_limits(sign * result);
	return (sign * result);
}
