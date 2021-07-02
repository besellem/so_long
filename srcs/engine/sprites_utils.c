/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 00:58:35 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:58:51 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** REINITIALIZE EACH SPRITE'S STRUCT (EXCEPT ITS COORDINATES)
** The use of memset is useful here in case of modifications on t_sprite struct
*/

void		init_sprites_hit(t_cub *cub)
{
	int tmp_x;
	int tmp_y;
	int i;

	i = 0;
	while (i < cub->sprites_ocs)
	{
		tmp_x = cub->sprites[i].x;
		tmp_y = cub->sprites[i].y;
		ft_memset(&cub->sprites[i], 0, sizeof(t_sprite));
		(&cub->sprites[i])->x = tmp_x;
		(&cub->sprites[i])->y = tmp_y;
		++i;
	}
}

/*
** Re-init sprites rays to 0
*/

void		init_sprites_rays(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->win_w)
	{
		j = 0;
		while (j < cub->win_h)
		{
			cub->rays[i].sp_ray[j] = 0U;
			++j;
		}
		++i;
	}
}
