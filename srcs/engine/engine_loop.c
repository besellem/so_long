/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:02:16 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:41:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_frame(t_so_long *sl)
{
	// mlx_get_screen_size(sl->mlx, &sl->win_w, &sl->win_h);
	if ('E' == sl->map[sl->pos_y][sl->pos_x] && 0 == sl->collectibles)
	{
		ft_printf(F_GREEN""B_RED"\nYOU WON in %d moves!"CLR_COLOR"\n",
			sl->move_nbr);
		ft_quit(sl);
	}
	display_minimap(sl);
	if (BONUS)
	{
		if (sl->life <= 0)
		{
			ft_printf(F_RED""B_YELLOW"\nYOU DIED!\nGAME OVER"CLR_COLOR"\n");
			ft_quit(sl);
		}
	}
	mlx_put_image_to_window(sl->mlx, sl->win, sl->img.ptr, 0, 0);
}

int	engine_loop(t_so_long *sl)
{
	update_frame(sl);
	return (0);
}
