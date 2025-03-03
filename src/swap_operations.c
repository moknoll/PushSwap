/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:12 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/27 15:19:36 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int operation_count = 0;

void increment_operation_count() {
    operation_count++;  // Zähle die Operationen
}

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
	{
		perror("Smaller then two");
		return (-1);
	}
	head = *stack;
	next = head->next;
	temp_value = head->value;
	temp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp_value;
	next->index = temp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	increment_operation_count();
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	increment_operation_count();
	return (0);
}

int	ss(t_list **stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	increment_operation_count();
	return (1);
}

// void	print_list(t_list *head)
// {
// 	t_list	*tmp = head;
// 	while (tmp)
// 	{
// 		printf("[%d, %d] -> ", tmp->value, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// }

// void test_operations()
// {
// 	// Zwei Stacks initialisieren
// 	t_list *stack_a = ft_lstnew(10);
// 	t_list *node2 = ft_lstnew(20);
// 	t_list *node3 = ft_lstnew(30);
// 	stack_a->next = node2;
// 	node2->next = node3;

// 	t_list *stack_b = NULL;

// 	printf("Initial Stack A:\n");
// 	print_list(stack_a);
//     printf("Initial Stack B:\n");
//     print_list(stack_b);

//     // Swap testen
//     printf("\nSwap A:\n");
//     sa(&stack_a);
//     print_list(stack_a);

//     // Push testen (A -> B)
//     printf("\nPush A -> B:\n");
//     pb(&stack_b, &stack_a);
//     print_list(stack_a);
//     print_list(stack_b);

//     // Push testen (B -> A)
//     printf("\nPush B -> A:\n");
//     pa(&stack_a, &stack_b);
//     print_list(stack_a);
//     print_list(stack_b);

//     // Rotate testen
//     printf("\nRotate A:\n");
//     ra(&stack_a);
//     print_list(stack_a);

//     // Reverse Rotate testen
//     printf("\nReverse Rotate A:\n");
//     rra(&stack_a);
//     print_list(stack_a);

//     // Speicher freigeben
//     free(node3);
//     free(node2);
//     free(stack_a);
//     free(stack_b);
// }

// int main()
// {
//     test_operations();
//     return 0;
// }
