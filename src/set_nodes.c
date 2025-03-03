/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:58:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/28 13:45:48 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

void	set_target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	target_node = NULL;
	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a ->value > stack_b ->value
					&& current_a -> value < best_match_index)
			{
				best_match_index = current_a ->value;
				target_node->value = current_a -> value;
			}
			current_a = current_a -> next;
		}
		if (LONG_MAX == best_match_index)
			stack_b ->target = find_smallest_value(&stack_a);
		else
			stack_a -> target = target_node;
		stack_b = stack_b ->next;
	}
}

void	set_current_position(t_list *stack)
{
	int i;
	int middle;

	i = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= middle)
			stack ->above_median = true;
		else
			stack ->above_median = false;
		stack = stack ->next;
		i++;
	}
}
void	set_price(t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_a);
	while (stack_b)
	{
		stack_b->price = stack_a->current_pos;
		if (!(stack_b ->above_median))
			stack_b->price = len_b - (stack_b->current_pos);
		if (stack_b->target -> above_median)
			stack_a->price += stack_b->target->current_pos;
		else
			stack_b->price += len_a - (stack_b->target->current_pos);
		stack_b = stack_b -> next;
	}
}

void	set_cheapest(t_list	*stack_b)
{
	long	best_fit_value;
	t_list	*best_fit_node;
	if (stack_b ==  NULL)
		return ;
	best_fit_value = LONG_MAX;
	while(stack_b)
	{
		if (stack_b -> price < best_fit_value)
		{
			best_fit_value = stack_b ->price;
			best_fit_node = stack_b;
		}
		stack_b = stack_b -> next;
	}
	best_fit_node->cheapest = true;
}
