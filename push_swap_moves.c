/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:24:20 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 12:26:34 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*new_node;
	t_node	*temp;

	if (!stack_a)
		return ;
	new_node = (t_node *)malloc (sizeof(t_node));
	temp = *stack_a;
	new_node->number = temp->number;
	new_node->position = temp->position;
	*stack_a = (*stack_a)->next;
	free(temp);
	temp = NULL;
	temp = *stack_a;
	new_node->next = temp->next;
	temp->next = new_node;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*new_node;
	t_node	*temp;

	if (!stack_b)
		return ;
	new_node = (t_node *)malloc (sizeof(t_node));
	temp = *stack_b;
	new_node->number = temp->number;
	new_node->position = temp->position;
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
	temp = *stack_b;
	new_node->next = temp->next;
	temp->next = new_node;
	write(1, "sb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*new_node;
	t_node	*temp;

	if (!stack_b)
		return ;
	new_node = (t_node *)malloc (sizeof(t_node));
	temp = *stack_b;
	new_node->number = temp->number;
	new_node->position = temp->position;
	new_node->next = NULL;
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
	ft_lstadd_front(stack_a, &new_node);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
