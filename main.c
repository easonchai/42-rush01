/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:01:34 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 13:49:39 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		fill_sides(t_border s, char *argv[])
{
	int index;

	index = 0;
	while (index < 4)
	{
		s.up[index] = ft_atoi(argv[index + 1]);
		s.down[index] = ft_atoi(argv[index + 5]);
		s.left[index] = ft_atoi(argv[index + 9]);
		s.right[index] = ft_atoi(argv[index + 13]);
		index++;
	}
	while (--index > -1)
	{
		if (s.up[index] < 0 || s.down < 0 || s.left < 0 || s.right < 0)
			return (0);
		else if (s.up[index] + s.down[index] > 5 ||
				s.left[index] + s.right[index] > 5)
			return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int			i;
	t_border	sides;

	sides.up = malloc(sizeof(int) * 4);
	sides.down = malloc(sizeof(int) * 4);
	sides.left = malloc(sizeof(int) * 4);
	sides.right = malloc(sizeof(int) * 4);
	i = 0;
	if (argc < 17)
		ft_putstr(ERR_TOO_LITTLE);
	else if (argc > 17)
		ft_putstr(ERR_TOO_MUCH);
	else
	{
		if (fill_sides(sides, argv))
			printf("HI!\n");
		else
			ft_putstr(ERR_INVALID);
	}
	return (0);
}
