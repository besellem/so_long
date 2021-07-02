/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:10:09 by besellem          #+#    #+#             */
/*   Updated: 2021/03/13 23:18:12 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** -- THESE FUNCTIONS ARE ONLY CALLED WHEN `BONUS` MACRO IS DEFINED --
**
** Set each minimap's cub size in pixels. It will always be maximum 1/3 of the
** screen size
*/

static void	set_minimap_cub_size(t_cub *cub)
{
	int max_w;
	int max_h;

	max_w = (double)(cub->win_w / 3) / cub->map_size_x;
	max_h = (double)(cub->win_h / 3) / cub->map_size_y;
	if (max_w > max_h)
		cub->cub_size = max_h;
	else
		cub->cub_size = max_w;
}

static void	set_gun_txtres(t_cub *cub, int count)
{
	const char	*gun_txtr[GUN_GIF_NB] = {
		"./assets/gun/gun_status_1.xpm",
		"./assets/gun/gun_status_2.xpm",
		"./assets/gun/gun_status_3.xpm",
		"./assets/gun/gun_status_4.xpm",
		"./assets/gun/gun_status_5.xpm"
	};

	fill_texture(cub, &cub->txtr_gun[count], (char *)gun_txtr[count]);
	if (count != 0)
		set_gun_txtres(cub, count - 1);
}

static void	is_gun_printable(t_cub *cub)
{
	int xmax;
	int ymax;
	int i;

	xmax = 0;
	ymax = 0;
	i = 0;
	while (i < GUN_GIF_NB)
	{
		if (xmax < cub->txtr_gun[i].x)
			xmax = cub->txtr_gun[i].x;
		if (ymax < cub->txtr_gun[i].y)
			ymax = cub->txtr_gun[i].y;
		++i;
	}
	cub->gun.gun_is_printable = (cub->win_w >= xmax && cub->win_h / 2 >= ymax);
}

void		init_bonus(t_cub *cub)
{
	if (BONUS)
	{
		set_minimap_cub_size(cub);
		set_gun_txtres(cub, GUN_GIF_NB - 1);
		is_gun_printable(cub);
		if (cub->gun.gun_is_printable)
			fill_texture(cub, &cub->txtr_target, "./assets/gun/target.xpm");
		fill_texture(cub, &cub->txtr_life, "./assets/life_bar.xpm");
		cub->life = 100;
	}
}
