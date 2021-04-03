/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:06:09 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 13:26:08 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ERR_TOO_LITTLE "\033[0;31mError\nToo lttle arguments!\n\033[0m"
# define ERR_INVALID "\033[0;31mError\nImpossible combination!\n\033[0m"

void	ft_putstr(char *str);
int		ft_atoi(char *str);
typedef	struct	constraints
{
	int	*up;
	int	*down;
	int	*left;
	int	*right;
}				border;

#endif
