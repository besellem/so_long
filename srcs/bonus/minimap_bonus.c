/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:56:58 by besellem          #+#    #+#             */
/*   Updated: 2021/03/13 20:22:22 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_ray(t_cub *cub, t_ray *ray)
{
	double distance;

	distance = ray->distance * cub->cub_size - 1;
	while (distance > 0)
	{
		ft_pixel_put(cub,
					cub->pos_x * cub->cub_size + cos(ray->angle) * distance,
					cub->pos_y * cub->cub_size + sin(ray->angle) * distance,
					0xFFFFFF);
		--distance;
	}
}

/*
** PRINT PLAYER'S DOT
*/

static void	print_player(t_cub *cub)
{
	int size;
	int i;
	int j;

	size = cub->cub_size;
	i = -(size / 2);
	while (++i < size / 2)
	{
		j = -(size / 2);
		while (++j < size / 2)
		{
			ft_pixel_put(cub, cub->pos_x * cub->cub_size + i,
						cub->pos_y * cub->cub_size + j, 0x808080);
		}
	}
}

static void	put_cub(t_cub *cub, int x, int y, uint32_t color)
{
	int i;
	int j;

	i = 0;
	while (i < cub->cub_size)
	{
		j = 0;
		while (j < cub->cub_size)
		{
			ft_pixel_put(cub, x * cub->cub_size + i, y * cub->cub_size + j,
						color);
			++j;
		}
		++i;
	}
}

static void	put_map(t_cub *cub)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < cub->map_size_y)
	{
		j = 0;
		while (j < cub->map_size_x)
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != ' ')
				put_cub(cub, j, i, UCOLOR_GREY);
			else if (cub->map[i][j] == '1')
				put_cub(cub, j, i, UCOLOR_BLACK);
			++j;
		}
		++i;
	}
}

void		display_minimap(t_cub *cub)
{
	int i;

	put_map(cub);
	i = 0;
	while (i < cub->win_w)
	{
		print_ray(cub, &(cub->rays[i]));
		++i;
	}
	print_player(cub);
}
