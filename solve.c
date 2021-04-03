/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 20:03:34 by echai            ###   ########.fr       */
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

int	is_possible(t_board board, int row, int col, int digit)
{
	int offset;
	int initial_row;
	int index;

	index = 0;
	offset = 0;
	initial_row = row;
	while (row >= 0)
		if (board.board[row--][col] == digit)
			return (0);
	while (col >= 0)
		if (board.board[initial_row][col--] == digit)
			return (0);
	return (1);
}

int	solve(t_board obj, int row, int col, int size)
{
	int num;
	
	if (row == 3 && col == 4)
		return (1);
	if (col == size)
	{
		col = 0;
		row++;
	}
	num = 1;
	while (num < size + 1)
	{
		if (is_possible(obj, row, col, num))
		{
			obj.board[row][col] = num;
			if(solve(obj, row, col + 1, size))
				return (1);
			obj.board[row][col] = 0;			
		}
		num++;
	}
	return (0);
}
