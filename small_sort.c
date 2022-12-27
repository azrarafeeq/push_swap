/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:46:06 by arafeeq           #+#    #+#             */
/*   Updated: 2022/10/30 20:34:39 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_min_push(t_node **stack_a, t_node **stack_b)
{
	int		min_num;
	int		index;
	int		length;
	t_node	*temp;

	list_index(*stack_a);
	temp = *stack_a;
	length = ft_lstsize(*stack_a);
	while (temp != NULL && length != 3)
	{
		min_num = list_min_num(stack_a);
		if (temp->number == min_num)
		{
			index = temp->index + 1;
			if (temp->index <= length / 2)
				while (--index != 1)
					ra(stack_a);
			else
				while (++index != length + 3)
					rra(stack_a);
			pb(stack_a, stack_b);
			return ;
		}
		temp = temp->next;
	}
}

void	sort_three(t_node	**stack_a)
{
	t_node	*temp;
	t_node	*temp_2;
	t_node	*temp_3;

	temp = *stack_a;
	temp_2 = temp->next;
	temp_3 = temp_2->next;
	if (temp->number > temp_2->number && temp->number < temp_3->number)
		sa(stack_a);
	else if (temp->number > temp_2->number && temp_2->number > temp_3->number)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (temp->number > temp_3->number)
	{
		if (temp_2->number < temp->number)
			rra(stack_a);
		rra(stack_a);
	}
	else if (temp->number < temp_2->number && temp_2->number > temp_3->number)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	sort_four_five(t_node **stack_a, t_node **stack_b)
{
	int		length;

	length = ft_lstsize(*stack_a);
	if (length == 5)
		list_min_push(stack_a, stack_b);
	list_min_push(stack_a, stack_b);
	list_index(*stack_a);
	sort_three(stack_a);
	if (length == 5)
		pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	list_index(*stack_a);
}

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		list_index(*stack_a);
	}
	else if (ft_lstsize(*stack_a) <= 5)
		sort_four_five(stack_a, stack_b);
}
