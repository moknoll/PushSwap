/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/05 10:17:38 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*check_and_convert(int argc, char *argv[])
{
	int size;
	t_list *stack_a;
	int *numbers;

	if (argc < 2)
		ft_putendl_fd("Error", 1);
	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);
	stack_a = arr_to_list(numbers);
	free(numbers);
	return(stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int size;

	stack_b = NULL;
	stack_a = check_and_convert(argc, argv);
	size = ft_lstsize(stack_a);
	if (!stack_a)
		return (1);
	if (!sorted(stack_a))
	{
		if (size == 2)
			sa(&stack_a);
		else if (size == 3)
			mini_sort(&stack_a);
		else if (size <= 5)
			sort_for_five(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(stack_a);
}
