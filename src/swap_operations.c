/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:12 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/04 13:16:11 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
	{
		perror("Smaller then two");
		return (-1);
	}
	head = *stack;
	next = head->next;
	temp_value = head->value;
	temp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp_value;
	next->index = temp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (1);
}
