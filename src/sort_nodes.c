/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:48:53 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/28 13:46:08 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

t_list *get_cheapest(t_list *stack)
{
	while (stack->cheapest != true)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		rr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void reverse_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		rrr(stack_a, stack_a);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void	finish_sorting(t_list **stack, t_list *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top -> above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top ->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	sort_nodes(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median
			&& cheapest_node -> target ->above_median)
			rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node ->above_median)
			&& !(cheapest_node -> target ->above_median))
			reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_sorting(stack_b, cheapest_node, 'b');
	finish_sorting(stack_a, cheapest_node->target, 'a');
	pa(stack_a, stack_b);
}
