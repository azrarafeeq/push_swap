/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:17:31 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 12:13:53 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_index(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 1;
	temp = stack;
	if (stack == NULL)
		return ;
	while (temp != NULL)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	list_position(t_node **stack_a)
{
	int		i;
	t_node	*temp;
	t_node	*temp_2;

	i = 0;
	temp = *stack_a;
	temp_2 = *stack_a;
	while (temp_2 != NULL)
	{
		while (temp != NULL)
		{
			if (temp_2->number > temp->number)
				i++;
			temp = temp->next;
		}
		i++;
		temp = *stack_a;
		temp_2->position = i;
		temp_2 = temp_2->next;
		i = 0;
	}
}

int	ft_lstsize(t_node *node)
{
	int		lst_len;
	t_node	*temp;

	lst_len = 0;
	temp = node;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		lst_len++;
	}
	return (lst_len);
}

int	list_sorted(t_node **stack_a)
{
	int		i;
	t_node	*temp;
	t_node	*temp_2;

	i = 0;
	temp = *stack_a;
	temp_2 = temp->next;
	while (temp->number < temp_2->number && i < ft_lstsize(*stack_a))
	{
		temp = temp->next;
		if (temp_2->next != NULL)
			temp_2 = temp_2->next;
		i++;
	}
	if (i == ft_lstsize(*stack_a) - 1)
		return (1);
	return (-1);
}

int	list_min_num(t_node **stack_a)
{
	int		min_num;
	t_node	*temp;

	temp = *stack_a;
	min_num = temp->number;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (min_num > temp->number)
			min_num = temp->number;
	}
	return (min_num);
}
