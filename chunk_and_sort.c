/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:43:22 by arafeeq           #+#    #+#             */
/*   Updated: 2022/10/30 19:19:58 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_i_more(t_node **stack_a, t_node **stack_b, int len, int i)
{
	if (i <= len / 2)
	{
		while (--i != 0)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (++i != len + 2)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	chunk_sa_to_sb_hun(t_node **stack_a, t_node **stack_b, int s, int e)
{
	t_node	*temp;
	int		list_size;
	int		len;
	int		i;

	temp = *stack_a;
	list_size = ft_lstsize(*stack_a);
	while (temp != NULL)
	{
		if (temp->position >= s && temp->position <= e)
		{
			i = temp->index;
			len = ft_lstsize(*stack_a);
			chunk_i_more(stack_a, stack_b, len, i);
			if (e == 20 && list_size <= e - 10)
				list_index(*stack_a);
			else if (temp->position <= e - 10)
				rb(stack_b);
			list_index(*stack_a);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
}

void	chunk_sa_to_sb_fi_hun(t_node **stack_a, t_node **stack_b, int s, int e)
{
	t_node	*temp;
	int		list_size;
	int		len;
	int		i;

	temp = *stack_a;
	list_size = ft_lstsize(*stack_a);
	while (temp != NULL)
	{
		if (temp->position >= s && temp->position <= e)
		{
			i = temp->index;
			len = ft_lstsize(*stack_a);
			chunk_i_more(stack_a, stack_b, len, i);
			if (e == 50 && list_size < e - 25)
				list_index(*stack_a);
			else if (temp->position <= e - 25)
				rb(stack_b);
			list_index(*stack_a);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
}

void	sort_push(t_node **stack_a, t_node **stack_b, int *max_position)
{
	pa(stack_a, stack_b);
	(*max_position)--;
	list_index(*stack_b);
}

void	sort_sb_to_sa(t_node **stack_a, t_node **stack_b, int s)
{
	t_node	*temp;
	int		max_position;
	int		index;
	int		len;

	temp = *stack_b;
	max_position = ft_lstsize(*stack_b);
	while (temp != NULL && max_position != s - 1)
	{
		len = ft_lstsize(*stack_b);
		while (temp->position != max_position)
			temp = temp->next;
		if (temp->position == max_position)
		{
			index = temp->index;
			if (index <= len / 2)
				while (--index != 0)
					rb(stack_b);
			else
				while (++index != len + 2)
					rrb(stack_b);
			sort_push(stack_a, stack_b, &max_position);
			temp = *stack_b;
		}
	}
}
