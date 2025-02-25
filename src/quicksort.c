/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:25 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/25 10:33:00 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_test(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition_test(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	j = low;
	pivot = arr[high];
	i = low - 1;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_test(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_test(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort_array(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition_test(arr, low, high);

		quicksort_array(arr, low, pivot_index - 1);
		quicksort_array(arr, pivot_index + 1, high);
	}
}

int	*pre_sort_array(int *numbers, int size)
{
	quicksort_array(numbers, 0, size - 1);
	return (numbers);
}

int get_pivot(int *arr, int size, int chunk)
{
	int	index;

	index = (size / 5) * chunk;
	if (chunk == 4)
	{
		return (arr[size - 1]);
	}
	return (arr[index]);
}


void push_chunks_to_b(t_list **a, t_list **b, int *pivots)
{
    int chunk;
    int total_chunks;
	
	chunk = 0;
	total_chunks = 5;
    while (chunk < total_chunks) 
	{
        int pivot = pivots[chunk];  // Aktueller Pivot-Wert

        int i = 0;
        int len = ft_lstsize(*a);
        while (i < len)
		{
			if ((*a)->value <= pivot)
			{
				pb(b, a);
				if ((*b)->value < pivots[chunk - 1])
				{
					rb(b); // Kleinere Werte nach unten
				}
			}
			else
				ra(a);
			i++;
		}
		chunk++;
	}
}

int find_max_index(t_list *stack)
{
    int max = stack->value;
    int index = 0, max_index = 0;
    t_list *temp = stack;

    while (temp) {
        if (temp->value > max)
		{
            max = temp->value;
            max_index = index;
        }
        temp = temp->next;
        index++;
    }
    return max_index;
}

void	move_max_to_top(t_list **stack, int max_pos)
{
	int	size;

	size = ft_lstsize(*stack);
	if (max_pos < size / 2)
	{
		while (max_pos--)
			rb(stack);
	}
	else
	{
		while (max_pos < size)
		{
			rrb(stack);
			max_pos++;
		}
	}
}

void	push_sorted_back_to_a(t_list **a, t_list **b)
{
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_index(*b);
		move_max_to_top(b, max_pos);
		pa(a, b);
	}
}
