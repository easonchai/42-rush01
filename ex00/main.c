/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:01:34 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 17:10:38 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		validate_inputs(int *inputs, int s)
{
	int i;

	i = 0;
	while (i < s)
	{
		if (inputs[i] < 1 || inputs[i + s] < 1 ||
		inputs[i + (2 * s)] < 1 || inputs[i + (3 * s)] < 1)
			return (0);
		else if ((inputs[i] + inputs[i + s]) > s + 1 ||
				(inputs[i + (2 * s)] + inputs[i + (3 * s)]) > s + 1)
			return (0);
		i++;
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

void	begin(t_board board, int size, char *argv[])
{
	board.border = get_input(argv, board.size);
	if (!board.border)
	{
		ft_putstr(ERR_INVALID_INPUT);
		return ;
	}
	if (validate_inputs(board.border, board.size))
	{
		board.board = init_board(board, size);
		if (solve(board, 0, 0, size))
			print_board(board, size);
		else
			ft_putstr(ERR_INVALID);
	}
	else
		ft_putstr(ERR_INVALID);
}

int		get_size(char *str)
{
	int size;

	size = ft_atoi(str);
	if (size < 4 || size > 9)
	{
		ft_putstr(ERR_INVALID_SIZE);
		return (0);
	}
	return (size);
}

int		main(int argc, char *argv[])
{
	t_board		board;

	board.size = 4;
	if (argc < 2)
		ft_putstr(ERR_TOO_LITTLE);
	else if (argc > 3)
		ft_putstr(ERR_TOO_MUCH);
	else
	{
		if (argv[2])
		{
			board.size = get_size(argv[2]);
			if (board.size < 4)
				return (0);
		}
		begin(board, board.size, argv);
	}
	return (0);
}
