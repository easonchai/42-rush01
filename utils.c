/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:03:59 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 14:44:36 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
}

void	ft_putnbr(int num)
{
	char digit;

	digit = num + '0';
	write(1, &digit, 1);
}

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

void	print_board(int **board, int width)
{
	int i;
	int j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < width)
		{
			ft_putnbr(board[i][j]);
			if (j != width - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}
