/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:53:42 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:45:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Horizontal wall raycasting
*/

static void	wall_raycasting_horizontal(t_cub *cub, t_raycasting *cast)
{
	double x;
	double y;

	cast->horz_x = cast->horz->xintcpt;
	cast->horz_y = cast->horz->yintcpt;
	x = cast->horz->xintcpt;
	y = cast->horz->yintcpt;
	while (in_map_limits(cub, x, y))
	{
		if (cub->map[safe_min(y, !cast->horz->is_down)][(int)x] == '1')
		{
			wall_intersect(cub, cast->horz, x, y);
			return ;
		}
		x += cast->horz->xstep;
		y += cast->horz->ystep;
	}
}

/*
** Vertical wall raycasting
*/

static void	wall_raycasting_vertical(t_cub *cub, t_raycasting *cast)
{
	double x;
	double y;

	cast->vert_x = cast->vert->xintcpt;
	cast->vert_y = cast->vert->yintcpt;
	x = cast->vert->xintcpt;
	y = cast->vert->yintcpt;
	while (in_map_limits(cub, x, y))
	{
		if (cub->map[(int)y][safe_min(x, !cast->vert->is_right)] == '1')
		{
			wall_intersect(cub, cast->vert, x, y);
			return ;
		}
		x += cast->vert->xstep;
		y += cast->vert->ystep;
	}
}

/*
** Cast a ray, get the least distant hit (horizontal / vertical)
** and get the hit direction
*/

static void	set_hit_drxion(t_ray *ray)
{
	if (!ray->hit_vertical && !ray->is_down)
		ray->hit_drxion = HIT_NORTH;
	else if (!ray->hit_vertical && ray->is_down)
		ray->hit_drxion = HIT_SOUTH;
	else if (ray->hit_vertical && ray->is_right)
		ray->hit_drxion = HIT_WEST;
	else if (ray->hit_vertical && !ray->is_right)
		ray->hit_drxion = HIT_EAST;
}

/*
** Cast a ray.
** We keep and then set the new ray pointer (horizontal or vertical)
** with the sprites's ray (cub->rays[i].sp_ray) because otherwise it's lost
** as we memset all rays each time.
*/

static void	cast_ray(t_cub *cub, t_ray *ray, double angle, int ray_nb)
{
	t_raycasting	cast;
	t_ray			hor;
	t_ray			ver;

	ft_memset(&cast, 0, sizeof(t_raycasting));
	init_ray(cub, &hor, angle, 0);
	init_ray(cub, &ver, angle, 1);
	(&hor)->sp_ray = ray->sp_ray;
	(&ver)->sp_ray = ray->sp_ray;
	cast.horz = &hor;
	cast.vert = &ver;
	wall_raycasting_horizontal(cub, &cast);
	wall_raycasting_vertical(cub, &cast);
	if (hor.distance < 0 && ver.distance >= 0)
		*ray = ver;
	else if (ver.distance < 0 && hor.distance >= 0)
		*ray = hor;
	else if (hor.distance >= ver.distance)
		*ray = ver;
	else if (hor.distance < ver.distance)
		*ray = hor;
	if (BONUS && cub->kill_sprite && ray_nb == cub->win_w / 2)
		ray->can_kill_sp = 1;
	sprites_raycasting(cub, &cast, ray);
}

/*
** Cast all rays and update the sprites rays too.
*/

void		cast_all_rays(t_cub *cub)
{
	double	ray_angle;
	double	tmp_angle;
	int		i;

	init_sprites_hit(cub);
	init_sprites_rays(cub);
	ray_angle = cub->drxion - (FOV / 2);
	i = 0;
	while (i < cub->win_w)
	{
		tmp_angle = ft_norm_angle(ray_angle);
		cast_ray(cub, &cub->rays[i], tmp_angle, i);
		set_hit_drxion(&cub->rays[i]);
		ray_angle += (FOV * cub->rays[i].distortion) / cub->win_w;
		++i;
	}
}
