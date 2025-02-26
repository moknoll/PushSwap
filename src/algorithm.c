/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:30:35 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/26 11:18:14 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int calculate_cost_a(t_list *element_a, t_list **stack_a)
{
	int cost_a;
	int pos_a;
	int size_a;

	size_a = ft_lstsize(*stack_a);
	cost_a = 0;
	pos_a = find_pos_in_stack(*stack_a, element_a->value);
	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	return (cost_a);
}

int calculate_cost_b(t_list *element_a, t_list **stack_b)
{
	int cost_b;
	int pos_b;
	int size_b;

	size_b = ft_lstsize(*stack_b);
	cost_b = 0;
	pos_b = find_pos_in_stack(*stack_b, element_a->value);
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	return (cost_b);
}

t_list	*find_cheapest_cost(t_list **stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*cheapest;
	int min_cost;

	min_cost = 5000;
	current_a = *stack_a;
	cheapest = NULL;
	current_a ->cost = (calculate_cost_a(current_a, stack_a) + calculate_cost_b(current_a, &stack_b) + 1);
	while (current_a)
	{
		if (current_a -> cost < min_cost)
		{
			min_cost = current_a->cost;
			cheapest = current_a;
		}
		current_a = current_a -> next;
	}
	return (cheapest);
}

//finds index of cheapest value
int find_pos_in_stack(t_list *stack_a, int value)
{
	t_list *current;
	int index;

	current = stack_a;
	index = 0;
	while (current)
	{
		if (current->value == value)
		{
			return (index);
		}
		current = current->next;
		index++;
	}
	return (-1);
}

void	move_element_to_top(t_list **stack, t_list *cheapest)
{
	int pos_a;
	int size_a;

	pos_a = find_pos_in_stack(*stack, cheapest -> value);
	size_a = ft_lstsize(*stack);
	if (pos_a <= size_a/2)	// If min_index in der oberen hälfte -> rotate a
	{
		while (pos_a > 0)
		{
			ra(stack);
			pos_a--;
		}
	}
	else
	{
		while(pos_a < size_a)
		{
			rra(stack);
			pos_a++;
		}
	}
}

t_list *find_correct_position(t_list *stack_b, int value)
{
    t_list *current = stack_b;
    t_list *best_fit = NULL;
    t_list *smallest = stack_b; // Speichert das kleinste Element

    while (current)
    {
        if (current->value > value && (!best_fit || current->value < best_fit->value))
            best_fit = current; // Finde das kleinste größere Element

        if (current->value < smallest->value)
            smallest = current; // Speichert das kleinste Element

        current = current->next;
    }

    return (best_fit ? best_fit : smallest); // Falls kein größeres Element, nimm das kleinste
}



void push_cheapest_cost(t_list **stack_a, t_list **stack_b)
{
	t_list *cheapest;
	t_list *target_position;

	cheapest = find_cheapest_cost(stack_a, *stack_b);
	if (!cheapest)
		return;
	move_element_to_top(stack_a, cheapest);
	target_position = find_correct_position(*stack_b, cheapest->value);
	if (target_position)
		move_element_to_top(stack_b, target_position);
	pb(stack_b, stack_a);
}


t_list *sort_large(t_list **stack_a)
{
	t_list *stack_b;
	int size;

	size = ft_lstsize(*stack_a);
	stack_b = NULL;
	pb(&stack_b, stack_a);
	pb(&stack_b, stack_a);
	if (stack_b -> value < stack_b -> next -> value)
			rb(&stack_b);
	while (size != 3)
		push_cheapest_cost(stack_a, &stack_b);
	sort_for_three(stack_a);
	while (stack_b)
		pa(stack_a, &stack_b);
	return (*stack_a);
}



