/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:17:22 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:40:53 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err, t_so_long *sl, char *file, int line)
{
	if (sl)
		ft_free_all(sl);
	ft_putendl_fd(ERR, 2);
	if (file && line > 0)
		ft_dprintf(2, B_YELLOW"%s:%d: "CLR_COLOR, file, line);
	else if (file && line <= 0)
		ft_dprintf(2, B_YELLOW"%s: "CLR_COLOR, file);
	else if (!file && line > 0)
		ft_dprintf(2, B_YELLOW"line %d in .ber file: "CLR_COLOR, line);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	ft_quit(t_so_long *sl)
{
	ft_putendl(B_RED"[Quit]"CLR_COLOR);
	if (sl->win)
		mlx_destroy_window(sl->mlx, sl->win);
	ft_free_all(sl);
	exit(EXIT_SUCCESS);
}

int	ft_red_cross(t_so_long *sl)
{
	ft_putendl(B_RED"[Quit]"CLR_COLOR);
	if (sl->win)
		mlx_destroy_window(sl->mlx, sl->win);
	ft_free_all(sl);
	exit(EXIT_SUCCESS);
	return (0);
}
