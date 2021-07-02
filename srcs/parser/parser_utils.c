/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:22:24 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 19:24:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_specs_complete(t_cub *cub)
{
	return (cub->grnd_color != -1 &&
		cub->sky_color != -1 &&
		cub->win_h != -1 &&
		cub->win_w != -1 &&
		cub->txtr_no &&
		cub->txtr_so &&
		cub->txtr_ea &&
		cub->txtr_we &&
		cub->txtr_s);
}

int	alloc_sprite_rays(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->win_w)
	{
		cub->rays[i].sp_ray = (uint32_t *)malloc(sizeof(uint32_t) * cub->win_h);
		if (!cub->rays[i].sp_ray)
			return (1);
		++i;
	}
	return (0);
}
