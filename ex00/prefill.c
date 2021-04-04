/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:39 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 16:51:41 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	fill_row(t_board obj, int row, int size, int direction)
{
	int index;

	if (!direction)
	{
		index = 0;
		while (index < size)
		{
			obj.board[row][index] = index + 1;
			index++;
		}
	}
	else
	{
		index = size - 1;
		while (index >= 0)
		{
			obj.board[row][index] = index + 1;
			index--;
		}
	}
}

void	fill_col(t_board obj, int col, int size, int direction)
{
	int index;

	if (!direction)
	{
		index = 0;
		while (index < size)
		{
			obj.board[index][col] = index + 1;
			index++;
		}
	}
	else
	{
		index = size - 1;
		while (index >= 0)
		{
			obj.board[index][col] = index + 1;
			index--;
		}
	}
}

void	handle_edge(t_board board, int size, int side, int index)
{
	if (side == 0)
		board.board[0][index % size] = size;
	else if (side == 1)
		board.board[size - 1][index % size] = size;
	else if (side == 2)
		board.board[index % size][0] = size;
	else if (side == 3)
		board.board[index % size][size - 1] = size;
}

void	prefill(t_board board, int size)
{
	int index;
	int side;

	index = 0;
	while (index < (size * 4))
	{
		side = index / size;
		if (board.border[index] == 1)
			handle_edge(board, size, side, index);
		else if (board.border[index] == size)
		{
			if (side == 0 || side == 1)
				fill_col(board, index % size, size, side);
			else if (side == 2 || side == 3)
				fill_row(board, index % size, size, side - 2);
		}
		index++;
	}
}
