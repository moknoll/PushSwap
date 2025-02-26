/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:30:35 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/26 14:29:39 by moritzknoll      ###   ########.fr       */
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
    t_list *target_position;

    size_b = ft_lstsize(*stack_b);
    cost_b = 0;

    // Finde die richtige Position in stack_b für das Element aus stack_a
    target_position = find_correct_position(*stack_b, element_a->value);
    if (!target_position)
    {
        printf("Error: No valid target position found in stack_b!\n");
        return (-1); // Gib einen Fehler zurück
    }

    // Berechne die Kosten, um target_position nach oben zu bringen
    pos_b = find_pos_in_stack(*stack_b, target_position->value);
    if (pos_b == -1)
    {
        printf("Error: Target position not found in stack_b!\n");
        return (-1); // Gib einen Fehler zurück
    }

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

void push_cheapest_cost(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest;
    t_list *target_position;

    // Debug-Ausgabe: Zustand vor der Operation
    printf("Before push_cheapest_cost:\n");
    printf("stack_a: ");
    print_list(*stack_a);
    printf("stack_b: ");
    print_list(*stack_b);

    cheapest = find_cheapest_cost(stack_a, *stack_b);
    if (!cheapest)
    {
        printf("Error: No valid cheapest element found!\n");
        return;
    }

    move_element_to_top(stack_a, cheapest);

    if (*stack_b)
    {
        target_position = find_correct_position(*stack_b, cheapest->value);
        if (target_position)
            move_element_to_top(stack_b, target_position);
    }

    // Debug-Ausgabe: Zustand nach dem Bewegen der Elemente
    printf("After moving elements to top:\n");
    printf("stack_a: ");
    print_list(*stack_a);
    printf("stack_b: ");
    print_list(*stack_b);

    pb(stack_b, stack_a);

    // Debug-Ausgabe: Zustand nach pb
    printf("After pb:\n");
    printf("stack_a: ");
    print_list(*stack_a);
    printf("stack_b: ");
    print_list(*stack_b);
}

t_list *find_correct_position(t_list *stack_b, int value)
{
    t_list *current = stack_b;
    t_list *best_fit = NULL;
    t_list *largest = stack_b;  // Das größte Element speichern

    if (!stack_b)
        return (NULL); // stack_b ist leer

    while (current)
    {
        if (current->value < value && (!best_fit || current->value > best_fit->value))
            best_fit = current; // Finde das größte kleinere Element
        if (current->value > largest->value)
            largest = current; // Finde das größte Element
        current = current->next;
    }

    // Falls kein kleineres Element gefunden wurde, setze das größte oben hin
    return (best_fit ? best_fit : largest);
}


t_list *sort_large(t_list **stack_a)
{
    t_list *stack_b;
    int size;

    stack_b = NULL;
    pb(&stack_b, stack_a);
    pb(&stack_b, stack_a);
    if (stack_b->value < stack_b->next->value)
        rb(&stack_b);

    // Aktualisiere die Größe von stack_a
    size = ft_lstsize(*stack_a);

    // Verwende die aktuelle Größe von stack_a in der Schleifenbedingung
    while (size > 3)
    {
        push_cheapest_cost(stack_a, &stack_b);
        size = ft_lstsize(*stack_a); // Aktualisiere die Größe nach jedem push_cheapest_cost
    }

    // Sortiere die letzten 3 Elemente in stack_a
    sort_for_three(stack_a);

    // Pushe alle Elemente aus stack_b zurück nach stack_a
    while (stack_b)
        pa(stack_a, &stack_b);

    return (*stack_a);
}



