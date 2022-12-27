/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:53:45 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/05 19:11:44 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free (array[i]);
	free (array);
	array = NULL;
}

int	string_count(int argc, char **argv)
{
	int	i;
	int	j;
	int	word_count;

	i = 1;
	j = 0;
	word_count = 0;
	while (argc != 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] != ' ' && argv[i][j] != '\0')
			{
				word_count++;
				while (argv[i][j] != ' ' && argv[i][j])
					j++;
			}
		}
		i++;
		argc--;
	}
	return (word_count);
}

int	letters_count(char **argv, int i, int j)
{
	int			letter_count;

	letter_count = 0;
	while (argv[i][j] != '\0')
	{
		while (argv[i][j] == ' ' && argv[i][j] != '\0')
			j++;
		while (argv[i][j] != ' ' && argv[i][j] != '\0')
		{
			letter_count++;
			j++;
		}
		break ;
	}
	return (letter_count);
}

char	*number_append(int argc, char **argv, int i, int *j)
{
	char	*number;
	int		a;

	a = 0;
	number = (char *)malloc(sizeof(char) * (letters_count(argv, i, *j) + 1));
	if (argc != 0)
	{
		if (argv[i][*j] != '\0')
		{
			while (argv[i][*j] == ' ' && argv[i][*j] != '\0')
				(*j)++;
			while (argv[i][*j] != ' ' && argv[i][*j] != '\0')
			{
				number[a] = argv[i][*j];
				a++;
				(*j)++;
			}
		}
	}
	number[a] = '\0';
	return (number);
}

char	**ft_split(int argc, char **argv)
{
	int		i[3];
	char	**string;

	i[0] = 1;
	i[1] = 0;
	i[2] = 0;
	string = (char **) malloc(sizeof(char *) * (string_count(argc, argv) + 1));
	if (!string)
		return (NULL);
	while (--argc)
	{
		while (argv[i[0]][i[1]] != '\0')
		{
			while (argv[i[0]][i[1]] == ' ' && argv[i[0]][i[1]] != '\0')
				i[1]++;
			while (argv[i[0]][i[1]] != ' ' && argv[i[0]][i[1]] != '\0')
				string[i[2]++] = number_append(argc, argv, i[0], &i[1]);
		}
		i[1] = 0;
		i[0]++;
	}
	string[i[2]] = NULL;
	return (string);
}
