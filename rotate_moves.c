/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:19:48 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 12:27:30 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*new_node;
	t_node	*temp;

	if (ft_lstsize(*stack_a) == 1)
		return ;
	new_node = (t_node *)malloc (sizeof(t_node));
	temp = *stack_a;
	new_node->number = temp->number;
	new_node->position = temp->position;
	new_node->next = NULL;
	*stack_a = (*stack_a)->next;
	free(temp);
	temp = NULL;
	ft_lstadd_back(stack_a, &new_node);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*new_node;
	t_node	*temp;

	if (ft_lstsize(*stack_b) == 1)
		return ;
	new_node = (t_node *)malloc (sizeof(t_node));
	temp = *stack_b;
	new_node->number = temp->number;
	new_node->position = temp->position;
	new_node->next = NULL;
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
	ft_lstadd_back(stack_b, &new_node);
	write(1, "rb\n", 3);
}

void	rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*previous;

	temp = *stack_a;
	if (temp->next == NULL)
		return ;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*previous;

	temp = *stack_b;
	if (temp->next == NULL)
		return ;
	(*stack_b)->next = temp->next;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrb\n", 4);
}
