/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:40:02 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 18:34:14 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_node
{
	int				number;
	int				index;
	int				position;
	struct t_node	*next;
}					t_node;

int		ft_parse(int argc, char **argv);
int		ft_strlen(const char *s);
int		valid_char(int i, int j, char **argv);
int		valid_int(long *int_array, int argc, char **argv);
int		dup_num(long *int_array, int argc, char **argv);
int		free_array_error(char **array);

char	**ft_split(int argc, char **argv);
char	*number_append(int argc, char **argv, int i, int *j);
int		string_count(int argc, char **argv);
int		letters_count(char **argv, int i, int j);
void	free_array(char **array);

long	*char_to_int_array(char **array, int argc, char **argv);
void	sign_check(const char *str, int *i, int *ve);
long	ft_atoi(const char *str);
int		free_int_array(long	*int_array);

void	array_to_list(long *int_array, int length, t_node **stack_a);
void	node_by_node(t_node **stack_a, int number);

long	*array_to_int_array(int argc, char **argv);
void	list_position(t_node **stack_a);

void	push_swap(t_node **stack_a, t_node **stack_b);
void	list_index(t_node *stack_a);
int		ft_lstsize(t_node *node);
int		list_sorted(t_node **stack_a);

void	small_sort(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	sort_four_five(t_node **stack_a, t_node **stack_b);
int		list_min_num(t_node **stack_a);
void	list_min_push(t_node **stack_a, t_node **stack_b);

void	big_sort(t_node **stack_a, t_node **stack_b);
void	sort_hundred(t_node **stack_a, t_node **stack_b, int s, int e);
void	chunk_sa_to_sb_hun(t_node **stack_a, t_node **stack_b, int s, int e);
void	sort_five_hundred(t_node **stack_a, t_node **stack_b, int s, int e);
int		nearest_fifty(int size);
void	chunk_sa_to_sb_fi_hun(t_node **stack_a, t_node **stack_b, int s, int e);
void	sort_sb_to_sa(t_node **stack_a, t_node **stack_b, int s);
void	chunk_i_more(t_node **stack_a, t_node **stack_b, int len, int i);
void	free_list(t_node **stack_a);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	ft_lstadd_front(t_node **stack, t_node **new_node);
void	ft_lstadd_back(t_node **stack, t_node **new_node);
void	ft_printf(const char *s);

#endif