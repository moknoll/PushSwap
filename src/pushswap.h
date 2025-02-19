/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:35:17 by moritzknoll       #+#    #+#             */
/*   Updated: 2025/02/19 15:08:04 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>

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

#endif
