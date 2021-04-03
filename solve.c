/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 21:31:50 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	left_row_eyesight(t_board board, int row, int col, int digit)
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
	if (row < board.size - 1 && can_see <= board.border[row + (board.size * 2)])
		return (1);
	else if (row == (board.size - 1) && can_see == board.border[row + (board.size * 2)])
		return (1);
	return (0);
}

int	top_col_eyesight(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = 0;
	can_see = 0;
	// printf("TEst: %d\nIndex: %d\nCol: %d\n", board.board[index][col], index, col);
	while (index < row)
	{
		// printf("TEst: %d\nIndex: %d\nRow: %d \nCol: %d\n", board.board[index][col], index, row, col);
		if (board.board[index][col] > max)
		{
			max = board.board[index][col];
			can_see++;
		}
		index++;
	}
	if (digit > max)
		can_see++;
	// printf("Col: %d\nEyesight target: %d\nActual target: %d\n", col, board.border[col], can_see);
	if (col <= board.size - 1 && can_see <= board.border[col])
		return (1);
	else if (col == (board.size - 1) && can_see == board.border[col])
		return (1);
	return (0);
}

int	full_right_check(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = row;
	can_see = 0;
	while (index > -1)
	{
		if (board.board[row][index] > max)
		{
			max = board.board[row][index];
			can_see++;
		}
		index--;
	}
	if (digit > max)
		can_see++;
	if (can_see == board.border[row + (board.size * 3)])
		return (1);
	return (0);
}

int	full_bot_check(t_board board, int row, int col, int digit)
{
	int can_see;
	int index;
	int max;

	max = 0;
	index = col;
	can_see = 0;
	while (index > -1)
	{
		if (board.board[index][col] > max)
		{
			max = board.board[index][col];
			can_see++;
		}
		index--;
	}
	if (digit > max)
		can_see++;
	if (can_see == board.border[col + board.size])
		return (1);
	return (0);
}

int	is_possible(t_board board, int row, int col, int digit)
{
	int initial_row;
	int initial_col;
	int index;

	index = 0;
	initial_row = row;
	initial_col = col;
	while (row >= 0)
		if (board.board[row--][initial_col] == digit)
			return (0);
	while (col >= 0)
		if (board.board[initial_row][col--] == digit)
			return (0);
	if (row == board.size - 1 && !full_right_check(board, initial_row, initial_col, digit))
		return (0);
	if (col == board.size - 1 && !full_bot_check(board, initial_row, initial_col, digit))
		return (0);
	if (!left_row_eyesight(board, initial_row, initial_col, digit))
		return (0);
	if (!top_col_eyesight(board, initial_row, initial_col, digit))
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
