/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/07 13:28:04 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*check_and_convert(int argc, char *argv[])
{
	int		size;
	t_list	*stack_a;
	int		*numbers;
	int		lst_size;

	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);
	if (!numbers || size == 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	stack_a = arr_to_list(numbers);
	lst_size = ft_lstsize(stack_a);
	if (lst_size == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	free(numbers);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

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
