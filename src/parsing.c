/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:34:12 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/19 20:29:15 by moritzknoll      ###   ########.fr       */
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

t_list *arr_to_list(int *numbers)
{
    int i;
    t_list *head;
    t_list *new_node;
    t_list *temp;

    head = NULL;
    i = 0;

    while (numbers[i] != '\0')  // Du solltest hier sicherstellen, dass du das Ende des Arrays richtig behandelst.
    {
        new_node = malloc(sizeof(t_list));
        if (!new_node)
            return (NULL);  // Falls malloc fehlschlägt, gib NULL zurück

        new_node->value = numbers[i];
        new_node->index = i;  // Index der Zahl im Array (optional, falls du ihn brauchst)
        new_node->next = NULL;
        // Wenn die Liste leer ist, mache das neue Element zum Kopf
        if (!head)
            head = new_node;
        else
        {
            // Wenn die Liste nicht leer ist, hänge das neue Element ans Ende
            temp = head;
            while (temp->next)  // Finde das letzte Element der Liste
                temp = temp->next;

            temp->next = new_node;  // Hänge das neue Element ans Ende der Liste
        }

        i++;
    }

    return (head);
}


