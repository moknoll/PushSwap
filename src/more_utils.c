/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:21:11 by mknoll            #+#    #+#             */
/*   Updated: 2025/03/04 13:27:30 by mknoll           ###   ########.fr       */
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

void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
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

int	get_size(int *numbers)
{
	int	len;

	len = 0;
	while (numbers[len])
	{
		len++;
	}
	return (len);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
