/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:37:12 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/27 11:13:43 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

int	get_pivot(int *numbers, int highest)
{
	int pivot;

	pivot = numbers[highest];
	return (pivot);
}

int arr_len(int *arr)
{
	int len;

	len = 0;
	while (arr[len])
	{
		len++;
	}
	return (len);
}

void arr_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partion(int *arr, int low, int high)
{
	int pivot;
	int i;
	int j;

	i = low - 1;
	j = low;
	pivot = get_pivot(arr, high);
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			arr_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	arr_swap(&arr[i + 1],&arr[high]);
	return (i + 1);
}


void	quicksort_array(int *arr, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partion(arr, low, high);
		quicksort_array(arr, low, pivot_index - 1);
		quicksort_array(arr, pivot_index + 1, high);
	}
}


// int main()
// {
// 	int numbers[8] = {1, 5, 7, 3, 4, 2, 6, 8};
// 	int len = sizeof(numbers) / sizeof(numbers[0]); // Länge richtig berechnen

// 	quicksort_array(numbers, 0, len - 1); // high = len - 1, nicht len
// 	print_arr(numbers, len); // Hier das Array nach dem Sortieren ausgeben
// }

