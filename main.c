/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:01:34 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 19:55:18 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		validate_inputs(int *inputs, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (inputs[index] < 1 || inputs[index + size] < 1 ||
		inputs[index + (2 * size)] < 1 || inputs[index + (3 * size)] < 1)
			return (0);
		else if ((inputs[index] + inputs[index + size]) > size + 1 ||
				(inputs[index + (2 * size)] + inputs[index + (3 * size)]) > size + 1)
			return (0);
		index++;
	}
	return (1);
}

int		**init_board(t_board board, int size)
{
	int i;
	int j;

	i = 0;
	board.board = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		board.board[i] = (int *)malloc(sizeof(int) * size);
		i++;
	}
	while (--i > -1)
	{
		j = 0;
		while (j < size)
			board.board[i][j++] = 0;
	}
	return (board.board);
}

int		main(int argc, char *argv[])
{
	int			i;
	t_board		board;
	int			size;

	size = 4;
	i = 0;
	if (argc < 2)
		ft_putstr(ERR_TOO_LITTLE);
	else if (argc > 3)
		ft_putstr(ERR_TOO_MUCH);
	else
	{
		if (argv[2])
		{
			size = ft_atoi(argv[2]);
			if (size < 4 || size > 9)
			{
				ft_putstr(ERR_INVALID_SIZE);
				size = 4;
			}
		}
		board.border = get_input(argv, size);
		if (!board.border)
		{
			ft_putstr(ERR_INVALID_INPUT);
			return (0);
		}
		if (validate_inputs(board.border, size))
		{
			board.board = init_board(board, size);
			if (solve(board, 0, 0, size))
				print_board(board, size);
		}
		else
			ft_putstr(ERR_INVALID);
	}
	return (0);
}
