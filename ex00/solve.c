/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 14:50:12 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		is_possible(t_board board, int row, int col, int digit)
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
	if (initial_col == board.size - 1 &&
	!full_right_check(board, initial_row, initial_col, digit))
		return (0);
	if (initial_row == board.size - 1 &&
	!full_bot_check(board, initial_row, initial_col, digit))
		return (0);
	return (1);
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
		return (solve(obj, row, col + 1, size));
	return (0);
}
