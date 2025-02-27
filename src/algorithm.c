/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:30:35 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/27 11:08:15 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


// Function to find the median of the stack
int	get_median(t_list *stack, int len)
{
	int *numbers;
	int i;
	int median;
	t_list *temp;

	i = 0;
	temp = stack;
	numbers = malloc(sizeof(int) * len);
	if (!numbers)
		return (-1);
	while(i < len)
	{
		numbers[i] = temp ->value;
		i++;
		temp = temp ->next;
	}
	quicksort_array(numbers, 0, len - 1);
	median = numbers[len / 2];
	return(free(numbers), median);
}

int	quick_sort_a(t_list **stack_a, t_list **stack_b, int len)
{
	int median;
	int nb_elem;
	int pushed_under = 0;

	if (sorted(*stack_a))
		return (1);
	if (len == 3)
		sort_for_three(stack_a);
	median = get_median(*stack_a, len);
	nb_elem = len;
	while (len != nb_elem /2 + nb_elem %2)
	{
		if ((*stack_a) -> value < median)
		{
			pb(stack_b, stack_a);
			len--;
		}
		else
		{
			ra(stack_a);
			pushed_under++;
		}
	}
	while (nb_elem / 2 + nb_elem % 2 != ft_lstsize(*stack_a) && pushed_under--)
		rra(stack_a);
	return (quick_sort_a(stack_a, stack_b, nb_elem / 2 + nb_elem % 2) && quick_sort_b(stack_a, stack_b, nb_elem / 2));
}

int sorted_descending(t_list *stack)
{
    if (!stack || !stack->next)
        return (1);
    while (stack->next)
    {
        if (stack->value < stack->next->value)  // Wir überprüfen, ob das aktuelle Element kleiner als das nächste ist (absteigend)
            return (0);
        stack = stack->next;
    }
    return (1);
}


int quick_sort_b(t_list **stack_a, t_list **stack_b, int len)
{
    int median;
    int nb_elem;
    int pushed_under = 0;

    // Wenn stack_b bereits sortiert ist, verschiebe alle Elemente zurück in stack_a
    if (sorted_descending(*stack_b)) // Verwendung der sorted() Funktion
    {
        while (len--)
            pa(stack_a, stack_b);
        return (1);
    }

    // Wenn die Länge von stack_b <= 3 ist, sortiere es mit einer speziellen Funktion für 3 Elemente
    if (len <= 3)
    {
        sort_for_three(stack_b);
        return (1);
    }

    // Bestimme den Median von stack_b
    median = get_median(*stack_b, len);
    if (median == -1)
        return (0);

    nb_elem = len;

    // Teile stack_b in zwei Teile auf
    while (len != nb_elem / 2)
    {
        if ((*stack_b)->value >= median)
        {
            pa(stack_a, stack_b);
            len--;  // Reduziere die Anzahl der Elemente, die noch bearbeitet werden müssen
        }
        else
        {
            rb(stack_b);
            pushed_under++;
        }
    }

    // Sobald die Hälfte der Elemente nach stack_a verschoben wurde, rotiere die restlichen Elemente nach oben
    while (nb_elem / 2 != ft_lstsize(*stack_b) && pushed_under--)
        rrb(stack_b);

    // Rufe quick_sort_a und quick_sort_b rekursiv für die beiden Teile auf
    return (quick_sort_a(stack_a, stack_b, nb_elem / 2 + nb_elem % 2) &&
            quick_sort_b(stack_a, stack_b, nb_elem / 2));
}

