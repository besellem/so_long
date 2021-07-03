/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:02:16 by besellem          #+#    #+#             */
/*   Updated: 2021/07/04 00:55:13 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_score(t_so_long *sl)
{
	char	*score;

	ft_asprintf(&score, "moves: %d", sl->move_nbr);
	mlx_string_put(sl->mlx, sl->win, 30, 30, 0xffffff, score);
	ft_memdel((void **)&score);
}

void	update_frame(t_so_long *sl)
{
	if ('E' == sl->map[sl->pos_y][sl->pos_x] && 0 == sl->collectibles)
	{
		ft_printf(F_GREEN""B_RED"\nYOU WON in %d moves!"CLR_COLOR"\n",
			sl->move_nbr);
		ft_quit(sl);
	}
	display_minimap(sl);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->img.ptr, 0, 0);
	if (BONUS)
		print_score(sl);
}

int	engine_loop(t_so_long *sl)
{
	update_frame(sl);
	return (0);
}
