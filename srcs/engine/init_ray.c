/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:43:57 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 18:45:46 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Init a ray struct.
** Use of memset to (re)set all variables to 0.
*/

void	init_ray(t_cub *cub, t_ray *ray, double angle, int is_vertical)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ray->angle = angle;
	ray->tan_ngl = tan(angle);
	ray->is_down = angle >= 0 && angle <= T_PI;
	ray->is_right = !(angle >= T_PI_2 && angle <= T_3PI_2);
	ray->distance = -1.0;
	ray->distortion = cos(angle - cub->drxion);
	if (is_vertical && (ray->hit_vertical = 1))
	{
		ray->xintcpt = (int)cub->pos_x + ray->is_right;
		ray->yintcpt = cub->pos_y + (ray->xintcpt - cub->pos_x) * ray->tan_ngl;
		ray->xstep = ray->is_right ? 1 : -1;
		ray->ystep = ray->tan_ngl;
		ray->ystep *= (!ray->is_down && ray->ystep > 0 ? -1 : 1);
		ray->ystep *= (ray->is_down && ray->ystep < 0 ? -1 : 1);
	}
	else
	{
		ray->yintcpt = (int)cub->pos_y + ray->is_down;
		ray->xintcpt = cub->pos_x + (ray->yintcpt - cub->pos_y) / ray->tan_ngl;
		ray->ystep = ray->is_down ? 1 : -1;
		ray->xstep = 1 / ray->tan_ngl;
		ray->xstep *= (!ray->is_right && ray->xstep > 0 ? -1 : 1);
		ray->xstep *= (ray->is_right && ray->xstep < 0 ? -1 : 1);
	}
}
