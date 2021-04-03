/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 14:07:34 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	eyesight(int *row, int count)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = 0;
	can_see = 0;
	while (index < 4)
	{
		if (row[index] > max)
		{
			max = row[index];
			can_see++;
		}
		index++;
	}
	if (can_see == count)
		return (1);
	return (0);
}

int	init_board(int **board)
{
	board[0] = malloc(sizeof(int) * 4);
	board[1] = malloc(sizeof(int) * 4);
	board[2] = malloc(sizeof(int) * 4);
	board[3] = malloc(sizeof(int) * 4);
	return (1);
}

int	solve(t_border s)
{
	int board[4][4];

	
	return (1);
}
