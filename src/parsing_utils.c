/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:45 by mknoll            #+#    #+#             */
/*   Updated: 2025/03/14 14:08:47 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putendl_fd("Error", 2);
			break ;
		}
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	check_int_range(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		return (0);
	}
	return (1);
}

int	check_duplicate(int *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
			{
				ft_putendl_fd("Error", 2);
				free(numbers);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
