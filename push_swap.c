/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:42:57 by arafeeq           #+#    #+#             */
/*   Updated: 2022/12/03 20:18:53 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	empty_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argc != 1)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (-1);
		if (letters_count(argv, i, j) == 0)
			return (-1);
		if (letters_count(argv, i, j) == j)
			return (-1);
		i++;
		argc--;
	}
	return (0);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int		list_size;

	list_index(*stack_a);
	list_size = ft_lstsize(*stack_a);
	if (list_size == 1)
	{
		free_list(stack_a);
		return ;
	}
	if (list_sorted(stack_a) == 1)
		return ;
	else if (list_size <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

long	*array_to_int_array(int argc, char **argv)
{
	char	**array;
	long	*int_array;

	array = ft_split(argc, argv);
	int_array = char_to_int_array(array, argc, argv);
	free_array(array);
	return (int_array);
}

int	main(int argc, char **argv)
{
	long	*int_array;
	int		length;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	else
	{
		if (empty_arg(argc, argv) == -1 || ft_parse(argc, argv) == -1)
			return (write (2, "Error\n", 6));
		stack_a = NULL;
		stack_b = NULL;
		length = string_count(argc, argv);
		int_array = array_to_int_array(argc, argv);
		array_to_list(int_array, length, &stack_a);
		list_position(&stack_a);
		push_swap(&stack_a, &stack_b);
		/* t_node	*temp;

		temp = stack_a;
		while (temp != NULL)
		{
			printf("index: %i  position : %i value : %i\n", temp->index, temp->position, temp->number);
			temp = temp->next;
		} */
		/* if(list_sorted(&stack_a) == 1)
		{
			printf("OK\n");
		}
		else{
			printf("KO\n");
		} */
		free(int_array);
		free_list(&stack_a);
		free_list(&stack_b);
	}
	return (0);
}
