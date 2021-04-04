/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:51:33 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 16:52:08 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_rows(t_board board, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board.board[j][i] != 0)
			{
				k = j + 1;
				while (k < size)
				{
					if (board.board[j][i] == board.board[k][i])
						return (0);
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_cols(t_board board, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board.board[i][j] != 0)
			{
				k = j + 1;
				while (k < size)
				{
					if (board.board[i][j] == board.board[i][k])
						return (0);
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
