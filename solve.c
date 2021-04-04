/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 10:42:23 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int 	left_row_eyesight(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = 0;
	can_see = 0;
	while (index < col)
	{
		if (board.board[row][index] > max)
		{
			max = board.board[row][index];
			can_see++;
		}
		index++;
	}
	if (digit > max)
		can_see++;
	if ((col < board.size - 1) && (can_see <= board.border[row + (board.size * 2)]))
		return (1);
	else if ((col == (board.size - 1)) && (can_see == board.border[row + (board.size * 2)]))
		return (1);
	return (0);
}

int 	top_col_eyesight(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = 0;
	can_see = 0;
	while (index < row)
	{
		if (board.board[index][col] > max)
		{
			max = board.board[index][col];
			can_see++;
		}
		index++;
	}
	if (digit > max)
		can_see++;
	if ((row < board.size - 1) && (can_see <= board.border[col]))
		return (1);
	else if ((row == (board.size - 1)) && (can_see == board.border[col]))
		return (1);
	return (0);
}

int 	full_right_check(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = col;
	can_see = 0;
	if (digit > max)
	{
		max = digit;
		can_see++;
	}
	while (index > -1)
	{
		if (board.board[row][index] > max)
		{
			max = board.board[row][index];
			can_see++;
		}
		index--;
	}
	if (can_see == board.border[row + (board.size * 3)])
		return (1);
	return (0);
}

int 	full_bot_check(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = row;
	can_see = 0;
	if (digit > max)
	{
		max = digit;
		can_see++;
	}
	while (index > -1)
	{
		if (board.board[index][col] > max)
		{
			max = board.board[index][col];
			can_see++;
		}
		index--;
	}
	if (can_see == board.border[col + board.size])
		return (1);
	return (0);
}

int 	is_possible(t_board board, int row, int col, int digit)
{
	int initial_row;
	int initial_col;
	int index;

	index = 0;
	initial_row = row;
	initial_col = col;
	while (index < board.size)
		if (board.board[index++][initial_col] == digit)
			return (0);
	while (index >= 0)
		if (board.board[initial_row][index--] == digit)
			return (0);
	if (!left_row_eyesight(board, initial_row, initial_col, digit))
		return (0);
	if (!top_col_eyesight(board, initial_row, initial_col, digit))
		return (0);
	if (initial_col == board.size - 1 && !full_right_check(board, initial_row, initial_col, digit))
		return (0);
	if (initial_row == board.size - 1 && !full_bot_check(board, initial_row, initial_col, digit))
		return (0);
	return (1);
}

void	fill_row(t_board obj, int row, int size, int direction)
{
	int index;

	if (!direction)
	{
		index = 0;
		while (index < size + 1)
		{
			obj.board[row][index] = index;
			index++;
		}
	}
	else
	{
		index = size;
		while (index >= 0)
		{
			obj.board[row][index] = index;
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
		while (index < size + 1)
		{
			obj.board[index][col] = index;
			index++;
		}
	}
	else
	{
		index = size;
		while (index >= 0)
		{
			obj.board[index][col] = index;
			index--;
		}
	}
}

void	prefill(t_board board, int size)
{
	int index;
	int side;

	side = 0;
	index = 0;
	while (index < size * 4)
	{
		side = index / size;
		if (board.border[index] == 1)
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
		else if (board.border[index] == size)
		{
			if (side == 0)
				fill_col(board, index % size, size, 0);
			else if (side == 1)
				fill_col(board, index % size, size, 1);
			else if (side == 2)
				fill_row(board, index % size, size, 0);
			else if (side == 3)
				fill_row(board, index % size, size, 1);
		}
		index++;
	}
}

int		solve(t_board obj, int row, int col, int size)
{
	int num;

	if (row == size - 1 && col == size)
		return (1);
	if (col == size)
	{
		col = 0;
		row++;
	}
	num = 1;
	if (obj.board[row][col] == 0)
		while (num < size + 1)
		{
			if (is_possible(obj, row, col, num))
			{
				obj.board[row][col] = num;
				if (solve(obj, row, col + 1, size))
					return (1);
				obj.board[row][col] = 0;
			}
			num++;
		}
	else
	{
		if (solve(obj, row, col + 1, size))
			return (1);
	}
	return (0);
}
