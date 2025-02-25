/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:25 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/25 11:07:29 by moritzknoll      ###   ########.fr       */
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

int get_chunk_count(int size)
{
    if (size <= 100)
        return 5;
    else if (size <= 500)
        return 11;
    return sqrt(size) * 2.2;  // Dynamisch skalieren
}

void calculate_pivots(int *arr, int size, int *pivots, int chunk_count)
{
    for (int i = 0; i < chunk_count; i++)
    {
        pivots[i] = arr[(size / chunk_count) * (i + 1)];
    }
}



void push_chunks_to_b(t_list **a, t_list **b, int *pivots, int chunk_count)
{
    int i = 0, len = ft_lstsize(*a);
    int chunk = 0;

    while (i < len)
    {
        if ((*a)->value <= pivots[chunk])
        {
            pb(b, a);
            if (*b && (*b)->value < pivots[chunk - 1])
                rb(b);  // Nur rotieren, wenn Wert kleiner als vorheriges Pivot
        }
        else
            ra(a);  // Nur wenn nicht in den aktuellen Chunk passt

        if (i % (len / chunk_count) == 0 && chunk < chunk_count - 1)
            chunk++;  // Nächstes Chunk nutzen
        i++;
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
	int	size = ft_lstsize(*stack);

	if (max_pos < size / 2)
		while (max_pos--)
			rb(stack);
	else
		while (max_pos++ < size)
			rrb(stack);
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
