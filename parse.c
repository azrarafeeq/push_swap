/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:38:08 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 18:36:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_char(int i, int j, char **array)
{
	if (!(array[i][j] >= 48 && array[i][j] <= 57)
		&& (array[i][j] != '+' && array[i][j] != '-'))
		return (-1);
	else if ((array[i][j] >= 48 && array[i][j] <= 57)
		&& (array[i][j + 1] == '+' || array[i][j + 1] == '-'))
		return (-1);
	else if ((array[i][j] == '-' || array[i][j] == '+')
		&& !(array[i][j + 1] >= 48 && array[i][j + 1] <= 57))
		return (-1);
	return (0);
}

int	valid_int(long *int_array, int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = string_count(argc, argv);
	while (len != 0)
	{
		if (int_array[i] > 2147483647)
			return (-1);
		else if (int_array[i] < -2147483648)
			return (-1);
		i++;
		len--;
	}
	return (0);
}

int	dup_num(long *int_array, int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = -1;
	len = string_count(argc, argv);
	while (++i != len - 1)
	{
		while (++j != len)
		{
			if (i == j)
				j++;
			if (int_array[i] == int_array[j])
				return (-1);
		}
		j = 0;
	}
	return (0);
}

int	ft_parse(int argc, char **argv)
{
	int		i;
	int		j;
	char	**array;
	long	*int_array;

	i = -1;
	j = -1;
	array = ft_split(argc, argv);
	while (array[++i] != NULL)
	{
		while (array[i][++j] != '\0')
			if (valid_char(i, j, array) == -1)
				return (free_array_error(array));
		j = -1;
	}
	int_array = char_to_int_array(array, argc, argv);
	free_array(array);
	if (valid_int(int_array, argc, argv) == -1)
		return (free_int_array(int_array));
	if (dup_num(int_array, argc, argv) == -1)
		return (free_int_array(int_array));
	free(int_array);
	return (0);
}
