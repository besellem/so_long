/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:02:16 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 01:05:22 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_cub *cub)
{
	double step;

	if (cub->turn != 0)
		cub->drxion = ft_norm_angle(cub->drxion + cub->turn * ft_deg2rad(5));
	if (cub->dh != 0)
	{
		step = cub->pos_x + cos(cub->drxion) * cub->dh * cub->increment;
		if (cub->map[(int)cub->pos_y][(int)step] == '0')
			cub->pos_x = step;
		step = cub->pos_y + sin(cub->drxion) * cub->dh * cub->increment;
		if (cub->map[(int)step][(int)cub->pos_x] == '0')
			cub->pos_y = step;
	}
	if (cub->dw != 0)
	{
		step = cub->pos_x + cub->dw * (sin(-cub->drxion) * cub->increment);
		if (cub->map[(int)cub->pos_y][(int)step] == '0')
			cub->pos_x = step;
		step = cub->pos_y + cub->dw * (cos(-cub->drxion) * cub->increment);
		if (cub->map[(int)step][(int)cub->pos_x] == '0')
			cub->pos_y = step;
	}
}

void		update_frame(t_cub *cub)
{
	move_player(cub);
	cast_all_rays(cub);
	update_cubs(cub);
	if (BONUS)
	{
		display_minimap(cub);
		display_life(cub);
		display_gun(cub);
		if (cub->life <= 0)
		{
			printf(F_RED""B_YELLOW"YOU DIED!\nGAME OVER"CLR_COLOR"\n");
			ft_quit(cub);
		}
	}
	if (!cub->save_opt)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
}

int			engine_loop(t_cub *cub)
{
	if (BONUS)
	{
		play_global_music(cub);
	}
	update_frame(cub);
	return (0);
}
