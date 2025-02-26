/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:39:38 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/25 12:48:42 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rra(t_list **stack)
{
	if (reverse_rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	increment_operation_count();
	return (0);
}

int	rrb(t_list **stack)
{
	if (reverse_rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	increment_operation_count();
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	increment_operation_count();
	ft_putendl_fd("rrr", 1);
	return (0);
}
