/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:03:59 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 14:57:58 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int value;
	int index;
	int multiplier;

	multiplier = 1;
	index = 0;
	value = 0;
	while (str[index] && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-')
			multiplier *= -1;
		index++;
	}
	while (str[index] && str[index] >= '0' && str[index] <= '9')
		value = value * 10 + (str[index++] - '0');
	return (value * multiplier);
}

int		count_spaces(char *str)
{
	int count;
	int i;
	int is_letter;

	is_letter = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_letter && str[i] > 32)
		{
			is_letter = 1;
			count++;
		}
		if (is_letter && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			is_letter = 0;
		i++;
	}
	return (count);
}

char	**fill_lines(char **tab, char *str)
{
	int v_pos;
	int j;

	v_pos = 0;
	while (*str)
	{
		if (*str > 32)
		{
			j = 0;
			tab[v_pos] = malloc(sizeof(char) * 11);
			while (*str > 32)
			{
				tab[v_pos][j] = *str;
				str++;
				j++;
			}
			tab[v_pos++][j] = '\0';
		}
		else
			str++;
	}
	tab[v_pos] = 0;
	return (tab);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		len;
	int		i;
	int		v_pos;

	i = 0;
	v_pos = 0;
	len = count_spaces(str);
	tab = malloc(sizeof(char *) * len + 1);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	tab = fill_lines(tab, str);
	return (tab);
}

int		*get_input(char *argv[], int size)
{
	char	**inputs;
	int		*output;
	int		count;
	int		index;

	index = 0;
	inputs = ft_split(argv[1]);
	count = 0;
	while (inputs[count])
		count++;
	if (count != size * 4)
		return (NULL);
	output = malloc(sizeof(int) * count);
	while (inputs[index])
	{
		output[index] = ft_atoi(inputs[index]);
		index++;
	}
	return (output);
}
