/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/04 13:30:11 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	int		size;
	int		*numbers;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		printf("Error\n");
	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);
	stack_a = arr_to_list(numbers);
	free(numbers);
	if (!stack_a)
		return (1);
	if (!sorted(stack_a))
	{
		if (size == 3)
			mini_sort(&stack_a);
		else if (size <= 5)
			sort_for_five(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(stack_a);
}
