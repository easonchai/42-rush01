/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:03:59 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 13:26:16 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int index;
	
	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
}

int		ft_atoi(char *str)
{
	int value;
	int index;
	int multiplier;

	multiplier = 1;
	index = 0;
	value = 0;
	while (str[index] && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-')
			multiplier *= -1;
		index++;
	}
	while (str[index] && str[index] >= '0' && str[index] <= '9')
		value = value * 10 + (str[index++] - '0');
	return (value * multiplier);
}
