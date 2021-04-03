/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:06:09 by echai             #+#    #+#             */
/*   Updated: 2021/04/03 13:49:12 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ERR_TOO_LITTLE "\033[0;31mError\nToo little arguments!\n\033[0m"
# define ERR_TOO_MUCH "\033[0;31mError\nToo many arguments!\n\033[0m"
# define ERR_INVALID "\033[0;31mError\nImpossible combination!\n\033[0m"

void			ft_putstr(char *str);
int				ft_atoi(char *str);
typedef	struct	s_constraints
{
	int	*up;
	int	*down;
	int	*left;
	int	*right;
}				t_border;

#endif
