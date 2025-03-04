/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:47:53 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/04 12:09:51 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

int	stack_len(t_list *stack)
{
	int len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack -> next;
	}
	return (len);
}

void	set_nodes(t_list *stack_a, t_list *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

t_list	*find_smallest_value(t_list **stack)
{
	t_list *smallest;
	t_list *current;

	if (!stack || !*stack)
		return (NULL);
	smallest = *stack;
	current = *stack;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_list	*find_biggest(t_list **stack)
{
	t_list *current;
	t_list *biggest;

	if (!stack || !*stack)
		return (NULL);
		biggest = *stack;
		current = *stack;
		while (current)
		{
			if (current -> value > biggest ->value)
				biggest = current;
			current = current ->next;
		}
	return (biggest);

}

void push_swap(t_list **stack_a, t_list **stack_b, int len_a)
{
	t_list	*smallest;

	if (len_a == 5)
		sort_for_five(stack_a);
	else
	{
		while(len_a-- > 3)
			pb(stack_b, stack_a);
	}
	mini_sort(stack_a);
	while(*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		sort_nodes(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	smallest = find_smallest_value(stack_a);
	if (smallest -> above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}

