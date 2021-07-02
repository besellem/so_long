/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:23:51 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:54:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define GUN_SHOT_SOUND_PATH "./sounds/gun_shot.wav"
#define SHOOTING_FRAMES_DELAY 0.05

static void	set_gun_txtr_idx(t_cub *cub)
{
	clock_t	now;
	double	time_diff;

	if (cub->gun.gun_status != 0)
	{
		now = clock();
		time_diff = (double)(now - cub->gun.last_time) / CLOCKS_PER_SEC;
		if (cub->gun.last_time == 0)
			time_diff = 0.0;
		if (cub->gun.last_time == 0 || time_diff >= SHOOTING_FRAMES_DELAY)
			cub->gun.last_time = now;
		if (cub->gun.gun_status == -1)
		{
			cub->gun.gun_status = 1;
			system(SOUND_CMD" "GUN_SHOT_SOUND_PATH" 2>/dev/null&");
		}
		else if (time_diff >= SHOOTING_FRAMES_DELAY)
			cub->gun.gun_status++;
	}
	if (cub->gun.gun_status > GUN_GIF_NB - 1)
		cub->gun.gun_status = 0;
}

static void	print_gun(t_cub *cub, t_img tx)
{
	uint32_t	clr;
	int			i;
	int			j;

	i = -1;
	while (++i < tx.x)
	{
		j = -1;
		while (++j < tx.y)
		{
			clr = *(uint32_t *)(tx.addr + j * tx.size_line + i * (tx.bpp / 8));
			if (clr != 0U)
				ft_pixel_put(cub, (cub->win_w - tx.x) / 2 + i,
							cub->win_h - tx.y + j, clr);
		}
	}
}

static void	print_target(t_cub *cub, t_img tx)
{
	uint32_t	clr;
	int			i;
	int			j;

	i = -1;
	while (++i < tx.x)
	{
		j = 0;
		while (++j < tx.y)
		{
			clr = *(uint32_t *)(tx.addr + j * tx.size_line + i * (tx.bpp / 8));
			if (clr != 0xFFFFFF)
				ft_pixel_put(cub, (cub->win_w - tx.x) / 2 + i,
							(cub->win_h - tx.y) / 2 + j, clr);
		}
	}
}

/*
** Display gun only when the window is large enough for it and when the gun's
** texture heigh is inferior to the window's heigh divided by 2 (center)
*/

void		display_gun(t_cub *cub)
{
	if (cub->gun.gun_is_printable)
	{
		if (cub->gun.gun_status == -1)
			cub->kill_sprite = 1;
		set_gun_txtr_idx(cub);
		print_gun(cub, cub->txtr_gun[cub->gun.gun_status]);
		print_target(cub, cub->txtr_target);
	}
	else
		cub->gun.gun_status = 0;
}
