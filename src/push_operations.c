/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:31:21 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/18 09:31:42 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push(t_list **to_stack, t_list **from_stack)
{
	t_list *from_head;

	if (!from_stack  || !*from_stack)	//If from_stack is empty
		return (-1);
	from_head = *from_stack;	// save first element from from_stack
	*from_stack = from_head -> next;	// set from_stack to next element
	ft_lstadd_front(to_stack, from_head);
	return(0);
}

int pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return(-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int pb(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}


