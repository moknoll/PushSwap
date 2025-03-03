/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:31:56 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/28 13:49:56 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (!stack || !*stack)
		return (-1);
	*stack = (*stack)-> next;
	temp ->next = NULL;
	ft_lstadd_back(stack, temp);
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stack;
	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}


int	ra(t_list **stack)
{
	if (rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	increment_operation_count();
	return (0);
}

int	rb(t_list **stack)
{
	if (rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	increment_operation_count();
	return (0);
}

int rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	increment_operation_count();
	return (0);
}

