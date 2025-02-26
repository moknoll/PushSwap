/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:08 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/26 13:22:51 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

t_list	*sort_for_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && c > a)
		sa(stack);
	else if (a > b && b > c && c < a)
	{
		sa(stack);
		rra(stack);
	}
    else if (a > b && a > c && c > b)
		ra(stack);
	else if (a < b && b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && c < b)
		rra(stack);
	return (*stack);
}

int find_min_index(t_list *stack)
{
	int min_value;
	int min_index;
	int i;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_index = 0; // stack->index
	i = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	move_min_to_top(t_list **stack, int min_pos)
{
	int size;

	size = ft_lstsize(*stack);
	if (min_pos <= size/2)	// If min_index in der oberen hälfte -> rotate a
	{
		while (min_pos > 0)
		{
			ra(stack);
			min_pos--;
		}
	}
	else
	{
		while(min_pos < size)
		{
			rra(stack);
			min_pos++;
		}
	}
}

t_list *sort_for_five(t_list **stack_a)
{
	t_list *stack_b;
	int size;
	int min_pos;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	min_pos = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_pos);
	pb(&stack_b, stack_a);
	if (size == 5)
	{
		min_pos = find_min_index(*stack_a);
		move_min_to_top(stack_a, min_pos);
		pb(&stack_b, stack_a);
	}
	sort_for_three(stack_a);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
	return (*stack_a);
}

void print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", list->value);
		list = list->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int		size;
	int		*numbers;
	t_list	*stack_a;

	if (argc < 2)
		printf("Error\n");
	if (argc == 2)
		numbers = parsing_str(&size, argv[1]);
	else
		numbers = parsing_args(&size, argc, argv);
	stack_a = arr_to_list(numbers);
	size = ft_lstsize(stack_a);
	if (sorted(stack_a) != 1)
	{
		printf("List is not sorted, starting sort...\n");
		if (size == 3)
			sort_for_three(&stack_a);
		else if (size <= 5)
			sort_for_five(&stack_a);
		sort_large(&stack_a);
	}
	printf("Operations used: %d\n", operation_count);
	print_list(stack_a);
	free(numbers);
	return (0);
}




