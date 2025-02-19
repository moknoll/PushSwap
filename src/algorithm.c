/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/19 15:22:16 by moritzknoll      ###   ########.fr       */
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

t_list	*sort_for_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && c > a)
		sa(stack);
	else if (a > b && b > c && c < a)
	{
		sa(stack);
		rra(stack);
	}
    else if (a > b && a > c && c > b)
		ra(stack);
	else if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && c < b)
		rra(stack);
	return (*stack);
}


void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int size;
    int *numbers;
    t_list *list;

    if (argc < 2)
    {
        printf("Error\n");
        return (1);
    }

    if (argc == 2)
        numbers = parsing_str(&size, argv[1]);
    else
        numbers = parsing_args(&size, argc, argv);

    list = arr_to_list(numbers);

    printf("Before sorting:\n");
    print_list(list);  // Zeige die Liste vor der Sortierung

    if (sorted(list) != 1)
    {
        sort_for_three(&list);  // Liste per Referenz übergeben
        printf("After sorting:\n");
        print_list(list);  // Zeige die Liste nach der Sortierung
    }

    printf("all sorted\n");
    print_list(list);  // Zeige die Liste nach der Sortierung

    free(numbers);
    return 0;
}

