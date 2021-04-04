/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:00:36 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 11:37:49 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		left_row_eyesight(t_board b, int row, int col, int digit)
{
	int see;
	int index;
	int max;

	max = 0;
	index = 0;
	see = 0;
	while (index < col)
	{
		if (b.board[row][index] > max)
		{
			max = b.board[row][index];
			see++;
		}
		index++;
	}
	if (digit > max)
		see++;
	if ((col < b.size - 1) && (see <= b.border[row + (b.size * 2)]))
		return (1);
	else if ((col == (b.size - 1)) && (see == b.border[row + (b.size * 2)]))
		return (1);
	return (0);
}

int		top_col_eyesight(t_board b, int row, int col, int digit)
{
	int see;
	int index;
	int max;

	max = 0;
	index = 0;
	see = 0;
	while (index < row)
	{
		if (b.board[index][col] > max)
		{
			max = b.board[index][col];
			see++;
		}
		index++;
	}
	if (digit > max)
		see++;
	if ((row < b.size - 1) && (see <= b.border[col]))
		return (1);
	else if ((row == (b.size - 1)) && (see == b.border[col]))
		return (1);
	return (0);
}

int		full_right_check(t_board board, int row, int col, int digit)
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

int		full_bot_check(t_board board, int row, int col, int digit)
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
