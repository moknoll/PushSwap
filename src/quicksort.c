/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:25 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/24 11:45:45 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void swap_test(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_test(int *arr, int low, int high) 
{
    int pivot = arr[high];  // Wähle das letzte Element als Pivot
    int i = low - 1;  // Index des kleineren Elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // Falls aktuelles Element kleiner als Pivot ist
            i++;
            swap_test(&arr[i], &arr[j]);  // Tausche das kleinere Element nach vorne
        }
    }
    swap_test(&arr[i + 1], &arr[high]);  // Setze Pivot an die richtige Position
    return (i + 1);  // Gib den neuen Pivot-Index zurück
}

void quicksort_array(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition_test(arr, low, high);  // Finde den Pivot

        quicksort_array(arr, low, pivot_index - 1);  // Sortiere linke Hälfte
        quicksort_array(arr, pivot_index + 1, high);  // Sortiere rechte Hälfte
    }
}

int *pre_sort_array(int *numbers, int size)
{
    
    quicksort_array(numbers, 0, size - 1);  // Sortiere das Array
    return numbers;
}

int get_pivot(int *arr, int size, int chunk) {
    int index = (size / 10) * chunk;  // Berechnet den Index des Pivots basierend auf Chunk
    if (chunk == 9) {
        return arr[size - 1];  // Das letzte Element ist der Pivot für den letzten Chunk
    }
    return arr[index];
}


void push_chunks_to_b(t_list **a, t_list **b, int *pivots) {
    int chunk = 0;
    int total_chunks = 10;

    while (chunk < total_chunks) {
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

int find_max_index(t_list *stack) {
    int max = stack->value;
    int index = 0, max_index = 0;
    t_list *temp = stack;

    while (temp) {
        if (temp->value > max) {
            max = temp->value;
            max_index = index;
        }
        temp = temp->next;
        index++;
    }
    return max_index;
}

void move_max_to_top(t_list **stack, int max_pos)
{
    int size = ft_lstsize(*stack);

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

void push_sorted_back_to_a(t_list **a, t_list **b) {
    while (*b) {
        int max_pos = find_max_index(*b);
        move_max_to_top(b, max_pos);
        pa(a, b);
    }
}


// 1.1 Stack in array und sortieren

// 1.2 Pivot für die chunks bestimmen

// 1.3 Push chunks to b

// 2.1 Maximale wert finden

// 2.2 Maximalen wert nach oben schieben

// push back to a

// 3.0

// Nutze rr statt ra + rb
// Falls a und b gleichzeitig rotiert werden müssen, nutze rr, um Schritte zu sparen.
// Nutze rrr statt rra + rrb
// Falls du beide Stacks nach unten rotieren musst, nutze rrr.
// Vermeide unnötiges Rotieren
// Falls eine Zahl nur 1–2 Schritte entfernt ist, nutze lieber sa oder sb, statt viele ra oder rra.
