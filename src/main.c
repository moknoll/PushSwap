/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:34:12 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/19 10:34:37 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*parsing_str(int *arr_size, char *str)
{
	char	**result;
	int		*numbers;
	int		i;

	*arr_size = get_arr_size(str);
	i = 0;
	result = ft_split(str, ' ');
	if (!result)
		return (NULL);
	numbers = malloc(sizeof(int) * (*arr_size));
	if (! numbers)
		return (free_tab(result), NULL);
	while (i < *arr_size)
	{
		if (!check_number(result[i]))
			return (free_tab(result), free(numbers), NULL);
		numbers[i] = ft_atoi(result[i]);
		free (result[i]);
		i++;
	}
	free(result);
	check_duplicate(numbers, *arr_size);
	return (numbers);
}

int *convert_and_check(char **result, int *numbers, int *j)
{
	int k;

	k = 0;
	while (result[k])
	{
		if (!check_number(result[k])
				|| !check_int_range(result[k]))
			return (free_tab(result), free(numbers), NULL);
		numbers[*j] = ft_atoi(result[k]);
		free(result[k]);
		(*j)++;
		k++;
	}
	free(result);
	return (numbers);
}

int	*parsing_args(int *arr_size, int argc, char *argv[])
{
	char	**result;
	int		*numbers;
	int		i;
	int		j;

	i = 1;
	j = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		numbers = convert_and_check(result, numbers, &j);
		if (!result || !(numbers))
			return (NULL);
		i++;
	}
	*arr_size = j;
	check_duplicate(numbers, *arr_size);
	return (numbers);
}


int main(int argc, char *argv[])
{
	int size;
	int *numbers;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}

	// Prüfen, ob die Eingabe ein einzelner String ist oder mehrere Argumente
	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);

	// Debug-Ausgabe
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", numbers[i]);
	// printf("\n");

	free(numbers);
	return 0;
}
