/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:46:42 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/06 18:37:15 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sign_check(const char *str, int *i, int *ve)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*ve = -1;
		(*i)++;
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	int		ve;
	long	num;

	i = 0;
	ve = 1;
	num = 0;
	sign_check(str, &i, &ve);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * ve);
}

long	*char_to_int_array(char **array, int argc, char **argv)
{
	int		a;
	long	*int_array;
	int		len;

	a = 0;
	len = string_count(argc, argv);
	int_array = (long *)malloc(sizeof(long) * len);
	while (a != len && array[a] != NULL)
	{
		int_array[a] = ft_atoi(array[a]);
		a++;
	}
	return (int_array);
}

int	free_array_error(char **array)
{
	free_array(array);
	array = NULL;
	return (-1);
}

int	free_int_array(long	*int_array)
{
	free(int_array);
	int_array = NULL;
	return (-1);
}
