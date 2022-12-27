/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:24:20 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 17:12:05 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_node **stack, t_node **new_node)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = *new_node;
		return ;
	}
	temp = *stack;
	*stack = *new_node;
	(*new_node)->next = temp;
}

void	ft_lstadd_back(t_node **stack, t_node **new_node)
{
	t_node	*temp;

	temp = *stack;
	if (!*stack)
	{
		*stack = *new_node;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
}

void	node_by_node(t_node **stack_a, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->number = num;
	new_node->index = 0;
	new_node->position = 0;
	new_node->next = NULL;
	ft_lstadd_back(stack_a, &new_node);
}

void	array_to_list(long *int_array, int length, t_node **stack_a)
{
	int		i;

	i = 0;
	while (i != length)
	{
		node_by_node(stack_a, int_array[i]);
		i++;
	}
}

void	free_list(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free (*stack);
}
