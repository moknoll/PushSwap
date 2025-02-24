/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/24 08:20:36 by moritzknoll      ###   ########.fr       */
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

int find_min_index(t_list *stack)
{
	int min_value;
	int min_index;
	int i;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_index = 0; // stack->index
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
	if (min_pos <= size/2)	// If min_index in der oberen hälfte -> rotate a
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

t_list *sort_for_five(t_list **stack_a)
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
	sort_for_three(stack_a);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
	return (*stack_a);
}

t_list	*sort(t_list	**stack_a)
{
	t_list *stack_b;
	int min_pos;

	stack_b = NULL;
	min_pos = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_pos);
	pb(&stack_b, stack_a);
	while (*stack_a)
	{
		min_pos = find_min_index(*stack_a);
		move_min_to_top(stack_a, min_pos);
		pb(&stack_b, stack_a);
	}
	if (!*stack_a)
	{
		while(stack_b)
			pa(stack_a, &stack_b);
	}
	return (*stack_a);
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
    t_list *stack_b = NULL;

    if (argc < 2)
    {
        printf("Error\n");
        return (1);
    }

    // Parsing
    numbers = (argc == 2) ? parsing_str(&size, argv[1]) : parsing_args(&size, argc, argv);
    if (!numbers)
    {
        printf("Error: Parsing failed\n");
        return (1);
    }

    list = arr_to_list(numbers);
    if (!list)
    {
        printf("Error: List creation failed\n");
        free(numbers);
        return (1);
    }

    size = ft_lstsize(list);

    printf("Before sorting:\n");
    print_list(list);

    if (!sorted(list))
    {
        if (size == 3)
            sort_for_three(&list);
        else if (size <= 5)
            sort_for_five(&list);
        else
        {
            // **Sortierprozess mit Chunks**
            int *sorted_arr = stack_to_array(list, size);
            if (!sorted_arr)
            {
                printf("Error: Failed to convert stack to array\n");
                free(numbers);
                return (1);
            }

            quicksort_array(sorted_arr, 0, size - 1);

            int chunks = (size < 5) ? size : 5;
            int pivots[chunks];

            for (int i = 0; i < chunks; i++)
                pivots[i] = get_pivot(sorted_arr, size, i);

            free(sorted_arr);

            if (!list)
            {
                printf("Error: No elements to push to stack B\n");
                free(numbers);
                return (1);
            }

            push_chunks_to_b(&list, &stack_b, pivots);
            push_sorted_back_to_a(&list, &stack_b);
        }

        printf("After sorting:\n");
        print_list(list);
    }

    printf("Operation count: %d\n", operation_count);

    if (numbers)
        free(numbers);

    return 0;
}



