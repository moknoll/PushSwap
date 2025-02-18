/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:31:56 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/18 09:32:11 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int rotate(t_list **stack)
{
	t_list *temp;

	temp = *stack;
	if (!stack || !*stack)
		return (-1);
	*stack = (*stack) -> next;
	temp ->next = NULL;
	ft_lstadd_back(stack, temp);
	return (0);
}

int reverseRotate(t_list **stack)
{
	t_list *last;
	t_list *prev;

	if (!stack || !*stack)
		return (-1);
	last = *stack;
	while (last->next->next) // Finde das vorletzte Element (3)
		last = last->next;
	prev = last;          // Vorletztes Element speichern
	last = last->next;    // Letztes Element holen (4)
	prev->next = NULL;    // Vorletztes Element (3) wird zum letzten Element
	ft_lstadd_front(stack, last); // 4 wird an den Anfang gesetzt
	return (0);
}


int ra(t_list **stack)
{
	if(rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int rb(t_list **stack)
{
	if(rotate(stack) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int rra(t_list **stack)
{
	if (reverseRotate(stack) == -1)
		return(-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int rrb(t_list **stack)
{
	if (reverseRotate(stack) == -1)
		return(-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || (ft_lstsize(*stack_b) < 2))
		return(-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
