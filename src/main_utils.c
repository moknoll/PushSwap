/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:45 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/18 13:03:15 by mknoll           ###   ########.fr       */
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
			perror("Error\n");
			return (0);
		}
		i++;
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
				perror("Error\n");
			}
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
