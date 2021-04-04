/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:06:09 by echai             #+#    #+#             */
/*   Updated: 2021/04/04 10:38:27 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ERR_TOO_LITTLE "\033[0;31mError\nToo little arguments!\n\033[0m"
# define ERR_TOO_MUCH "\033[0;31mError\nToo many arguments!\n\033[0m"
# define ERR_INVALID "\033[0;31mError\nImpossible combination!\n\033[0m"
# define ERR_INVALID_SIZE "\033[0;31mError\nInvalid size, using default 4x4!\n\033[0m"
# define ERR_INVALID_INPUT "\033[0;31mError\nInvalid number of inputs!\n\033[0m"

void			ft_putstr(char *str);
int				ft_atoi(char *str);
typedef	struct	s_board
{
	int **board;
	int *border;
	int	size;
}				t_board;
int				eyesight(int *row, int count);
void			print_board(t_board board, int width);
int				solve(t_board board, int row, int col, int size);
void			prefill(t_board board, int size);
int				*get_input(char *argv[], int size);
#endif
