/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:45 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/19 14:13:16 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_tab(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putendl_fd("Error not a number", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

long 	ft_atol(char *str)
{
	int i;
	long res;
	int sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign *-1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int check_int_range(char *str)
{
	long num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_putendl_fd("Error", 1);
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
				ft_putendl_fd("Error", 1);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_arr_size(char *str)
{
	char	**result;
	int		len;

	len = 0;
	result = ft_split(str, ' ');
	if (!result)
		return (0);
	while (result[len])
		len++;
	free_tab(result);
	return (len);
}

int get_size(int *numbers)
{
	int len;

	len = 0;
	while (numbers[len])
	{
		len++;
	}
	return (len); 
}
