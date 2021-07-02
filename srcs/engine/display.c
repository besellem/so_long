/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:56:02 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:08:29 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Print a pixel at the coordinates into mlx->img
*/

void		ft_pixel_put(t_cub *cub, int x, int y, uint32_t color)
{
	char *px;

	px = cub->img.addr + y * cub->img.size_line + x * (cub->img.bpp / 8);
	*(uint32_t *)px = color;
}

/*
** Print a sprite ray
*/

static void	print_sprite_ray(t_cub *cub, t_ray ray, int x)
{
	int y;

	y = 0;
	while (y < cub->win_h)
	{
		if (*ray.sp_ray != 0U)
			ft_pixel_put(cub, x, y, *ray.sp_ray);
		++ray.sp_ray;
		++y;
	}
}

/*
** Print a column of texture defined by a ray
*/

static int	hit_x_calc(t_img tx, t_ray ray)
{
	if (ray.hit_drxion == HIT_NORTH || ray.hit_drxion == HIT_SOUTH)
		return (tx.x * get_dec(ray.hit_wall_x));
	else
		return (tx.x * get_dec(ray.hit_wall_y));
}

static void	print_txtre_ray(t_cub *cub, t_ray ray, int x, double scale)
{
	const t_img	tx = cub->txtrs[ray.hit_drxion];
	double		start;
	double		end;
	int			idx;

	start = 0.0;
	end = tx.y;
	idx = (cub->win_h - scale) / 2 - 0.1;
	if (cub->win_h < scale)
	{
		idx = 0;
		start = (tx.y * (1 - cub->win_h / scale)) / 2;
		end -= start;
	}
	while (start < end && idx < cub->win_h)
	{
		if (ray.sp_ray[idx++] == 0U)
			ft_pixel_put(cub, x, idx - 1, *(uint32_t *)(tx.addr + (int)start * \
						tx.size_line + hit_x_calc(tx, ray) * (tx.bpp / 8)));
		start += tx.y / scale;
	}
}

/*
** Display main function
*/

void		update_cubs(t_cub *cub)
{
	double	scale;
	double	h_start;
	int		x;
	int		y;

	x = -1;
	while (++x < cub->win_w)
	{
		if (cub->rays[x].distance >= 0 && cub->rays[x].distance < 0.0001)
			scale = 0.0001;
		else
			scale = cub->rays[x].distance * cub->rays[x].distortion;
		scale = cub->win_h / scale;
		h_start = (cub->win_h - scale) / 2;
		y = 0;
		while (y < h_start)
			if (cub->rays[x].sp_ray[y++] == 0U)
				ft_pixel_put(cub, x, y - 1, cub->sky_color);
		print_txtre_ray(cub, cub->rays[x], x, scale);
		y = scale + h_start;
		while (y < cub->win_h)
			if (cub->rays[x].sp_ray[y++] == 0U)
				ft_pixel_put(cub, x, y - 1, cub->grnd_color);
		print_sprite_ray(cub, cub->rays[x], x);
	}
}
