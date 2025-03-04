/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:56:36 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/04 12:12:51 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	mini_sort(t_list **stack_a)
{
	t_list	*biggest;

	biggest = find_biggest(stack_a);
	if (*stack_a == biggest)
		ra(stack_a);
	else if ((*stack_a) -> next == biggest)
		rra(stack_a);
	if ((*stack_a) -> value > (*stack_a)->next->value)
		sa(stack_a);
}

int find_min_index(t_list *stack)
{
	int min_value;
	int min_index;
	int i;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	move_min_to_top(t_list **stack, int min_pos)
{
	int size;

	size = ft_lstsize(*stack);
	if (min_pos <= size/2)
	{
		while (min_pos > 0)
		{
			ra(stack);
			min_pos--;
		}
	}
	else
	{
		while(min_pos < size)
		{
			rra(stack);
			min_pos++;
		}
	}
}

void sort_for_five(t_list **stack_a)
{
	t_list *stack_b;
	int size;
	int min_pos;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	min_pos = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_pos);
	pb(&stack_b, stack_a);
	if (size == 5)
	{
		min_pos = find_min_index(*stack_a);
		move_min_to_top(stack_a, min_pos);
		pb(&stack_b, stack_a);
	}
	mini_sort(stack_a);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}

