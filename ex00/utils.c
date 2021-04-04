/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:03:59 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 19:43:49 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

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

void	print_board(t_board obj, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putnbr(obj.board[i][j]);
			if (j != size - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}
