/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:35:17 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/24 07:48:01 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>

extern int operation_count;

// Util functions
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

//instruction functions
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		check_duplicate(int *numbers, int len);
int		check_number(char *str);
void	free_tab(char **arr);
int		get_arr_size(char *result);
int		*parsing_str(int *arr_size, char *str);
int		*parsing_args(int *arr_size, int argc, char *argv[]);
int		*convert_and_check(char **result, int *numbers, int *j);
int		check_int_range(char *str);
long	ft_atol(char *str);
int		sorted(t_list *stack);
t_list	*sort_for_three(t_list **stack);
t_list	*arr_to_list(int *numbers);
int		get_size(int *numbers);
t_list	*sort_for_five(t_list **stack_a);
void	move_min_to_top(t_list **stack, int min_pos);
int		find_min_index(t_list *stack);


int		find_pivot(t_list **stack);
int		partition(t_list **stack_a, t_list **stack_b, int pivot);
void	quicksort_stack(t_list **stack_a, t_list **stack_b, int size);
int		*stack_to_array(t_list *stack, int size);
void	free_list(t_list *stack);
void	quicksort_array(int *arr, int left, int right);
t_list	*sort(t_list	**stack_a);
void	increment_operation_count();


//test
void swap_test(int *a, int *b);
int partition_test(int *arr, int low, int high);
void quicksort_array(int *arr, int low, int high);
int *stack_to_array(t_list *stack, int size);
int get_pivot(int *arr, int size, int chunk);
void push_chunks_to_b(t_list **a, t_list **b, int *pivots);
int find_max_index(t_list *stack);
void move_max_to_top(t_list **stack, int max_pos);
void push_sorted_back_to_a(t_list **a, t_list **b);

#endif
