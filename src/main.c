/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/03/04 12:06:30 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void print_list(t_list *stack)
{
	t_list *current = stack;

	printf("Stack: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int main(int argc, char *argv[])
{
	int		size;
	int		*numbers;
	t_list	*stack_a;
	t_list	*stack_b = NULL;

	if (argc < 2)
		printf("Error\n");
	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);
	stack_a = arr_to_list(numbers);
	int len = size;
	free(numbers);
	if (!stack_a)
		return (1);
	printf("Before Sorting: \n");
	print_list(stack_a);
	if (!sorted(stack_a))
	{
		if (size == 3)
			mini_sort(&stack_a);
		else if (size <= 5)
			sort_for_five(&stack_a);
		else
			push_swap(&stack_a, &stack_b, len);
	}
	printf("After Sorting: \n");
	print_list(stack_a);
	free_stack(stack_a);
}
