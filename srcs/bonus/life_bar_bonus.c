/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:15:02 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:23:58 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SPRITE_HIT_SOUND_PATH "./sounds/monster_bite.wav"
#define SPRITE_HIT_SOUND_DURATION 1

static void	print_life(t_cub *cub, t_img tx)
{
	const int	xmax = (cub->life / 100.0) * tx.x;
	uint32_t	clr;
	int			i;
	int			j;

	i = 0;
	while (i < tx.x && i < xmax)
	{
		j = 0;
		while (j < tx.y)
		{
			clr = *(uint32_t *)(tx.addr + j * tx.size_line + i * (tx.bpp / 8));
			if (clr != 0U)
				ft_pixel_put(cub, i, cub->win_h - tx.y + j, clr);
			++j;
		}
		++i;
	}
}

/*
** Check if the player is near a sprite
** If it's the case, decrease the life and play the corresponding sound
** (if the last one did finish)
*/

static void	update_life(t_cub *cub)
{
	const time_t tm = time(NULL);

	if (is_sprite(cub->map[(int)(cub->pos_y + 0.5)][(int)cub->pos_x]) ||
		is_sprite(cub->map[safe_min(cub->pos_y, 0.5)][(int)cub->pos_x]) ||
		is_sprite(cub->map[(int)cub->pos_y][safe_min(cub->pos_x, 0.5)]) ||
		is_sprite(cub->map[(int)cub->pos_y][(int)(cub->pos_x + 0.5)]))
	{
		cub->life -= 1;
		if (cub->life > 0 && (cub->sounds.sprite_last_hit_time == 0 ||
			tm - cub->sounds.sprite_last_hit_time >= SPRITE_HIT_SOUND_DURATION))
		{
			system(SOUND_CMD" "SPRITE_HIT_SOUND_PATH" 2>/dev/null&");
			cub->sounds.sprite_last_hit_time = tm;
		}
		return ;
	}
}

void		display_life(t_cub *cub)
{
	if (cub->txtr_life.x < cub->win_w / 2 && cub->txtr_life.y < cub->win_h)
	{
		update_life(cub);
		print_life(cub, cub->txtr_life);
	}
}
