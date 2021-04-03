/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:52:02 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 14:43:43 by echai            ###   ########.fr       */
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

//int	solve_down(int **board, 

//int populate(int **board, )

int	solve(t_border s)
{
	int **board;
	int index;
	int digit;

	digit = 4;
	index = 0;
	board = malloc(sizeof(*board) * 4);
	board[0] = malloc(sizeof(int) * 4);
	board[1] = malloc(sizeof(int) * 4);
	board[2] = malloc(sizeof(int) * 4);
	board[3] = malloc(sizeof(int) * 4);
	print_board(board, 4);
	while (index < 4)
	{
		while (digit > 0)
		{
			if(s.up[index] == digit)
				printf("hah");	
			digit--;
		}
		index++;
	}
	return (1);
}
