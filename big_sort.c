/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:50:14 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/02 10:30:26 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_fifty(int size)
{
	int	i;

	i = 0;
	while (size % 50 != 0)
	{
		i++;
		size++;
	}
	return (i);
}

void	sort_hundred(t_node **stack_a, t_node **stack_b, int s, int e)
{
	while (stack_a != NULL && e <= 100)
	{
		chunk_sa_to_sb_hun(stack_a, stack_b, s, e);
		s = s + 20;
		e = e + 20;
	}
	list_index(*stack_b);
	while (s >= 1)
	{
		while (ft_lstsize(*stack_b) >= s)
			sort_sb_to_sa(stack_a, stack_b, s);
		s = s - 20;
	}
}

void	sort_five_hundred(t_node **stack_a, t_node **stack_b, int s, int e)
{
	int	size;
	int	increment;

	size = ft_lstsize(*stack_a);
	increment = nearest_fifty(size);
	while (stack_a != NULL && e <= (size + increment))
	{
		chunk_sa_to_sb_fi_hun(stack_a, stack_b, s, e);
		s = s + 50;
		e = e + 50;
	}
	list_index(*stack_b);
	while (s >= 1)
	{
		while (ft_lstsize(*stack_b) >= s)
			sort_sb_to_sa(stack_a, stack_b, s);
		s = s - 50;
	}
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	increment;

	size = ft_lstsize(*stack_a);
	increment = nearest_fifty(size);
	if (ft_lstsize(*stack_a) <= 100)
		sort_hundred(stack_a, stack_b, 1, 20);
	else if (ft_lstsize(*stack_a) <= (size + increment))
		sort_five_hundred(stack_a, stack_b, 1, 50);
	list_index(*stack_a);
}
