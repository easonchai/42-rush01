/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:01:34 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 13:29:10 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		fill_sides(border sides, char *argv[])
{
	int index;

	index = 0;
	while (index < 4)
	{
		sides.up[index] = ft_atoi(argv[index]);
		sides.down[index] = ft_atoi(argv[index + 4]);
		sides.left[index] = ft_atoi(argv[index + 8]);
		sides.right[index] = ft_atoi(argv[index + 12]);
		index++;
	}
	while (index > -1)
	{
		if (sides.up[index] < 0 || sides.down < 0 || sides.left < 0 || sides.right < 0)
			return (0);
		else if (sides.up[index] + sides.down[index] > 5 || 
				sides.left[index] + sides.right[index] > 5)
			return (0);
		index--;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int i;
	border sides;

	sides.up = malloc(sizeof(int) * 4);
	sides.down = malloc(sizeof(int) * 4);
	sides.left = malloc(sizeof(int) * 4);
	sides.right = malloc(sizeof(int) * 4);
	i = 0;
	if (argc != 17)
		ft_putstr(ERR_TOO_LITTLE);
	else
	{
		if(fill_sides(sides, argv))
			printf("HI!\n");
		else
			ft_putstr(ERR_INVALID);
	}
	return (0);
}
