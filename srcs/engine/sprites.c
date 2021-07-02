/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:28:26 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:58:48 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	order_and_fill_sprites(t_cub *cub, t_raycasting *cast,
								t_spcasting_vars *tmp)
{
	if (tmp->order)
	{
		if (tmp->horz_printable)
			sprite_intersect(cub, cast->horz,
							cast->horz_x, cast->horz_y - !cast->horz->is_down);
		if (tmp->vert_printable)
			sprite_intersect(cub, cast->vert,
							cast->vert_x - !cast->vert->is_right, cast->vert_y);
	}
	else
	{
		if (tmp->vert_printable)
			sprite_intersect(cub, cast->vert,
							cast->vert_x - !cast->vert->is_right, cast->vert_y);
		if (tmp->horz_printable)
			sprite_intersect(cub, cast->horz,
							cast->horz_x, cast->horz_y - !cast->horz->is_down);
	}
}

static void	sprite_raycasting_z_axis(t_cub *cub, t_raycasting *cast,
							t_ray *valid_ray, t_spcasting_vars *tmp)
{
	tmp->dist_horz = ft_pyt_like(cub->pos_x, cub->pos_y, cast->horz_x,
								cast->horz_y);
	tmp->dist_vert = ft_pyt_like(cub->pos_x, cub->pos_y, cast->vert_x,
								cast->vert_y);
	if (in_map_limits(cub, cast->horz_x, cast->horz_y - !cast->horz->is_down)
		&& tmp->dist_horz < valid_ray->cmp_distance &&
		is_sprite(cub->map[(int)cast->horz_y - \
		!cast->horz->is_down][(int)cast->horz_x]))
		tmp->horz_sp = 1;
	if (in_map_limits(cub, cast->vert_x - !cast->vert->is_right, cast->vert_y)
		&& tmp->dist_vert < valid_ray->cmp_distance &&
		is_sprite(cub->map[(int)cast->vert_y][(int)cast->vert_x - \
		!cast->vert->is_right]))
		tmp->vert_sp = 1;
	if (tmp->horz_sp)
		tmp->horz_printable = 1;
	if (tmp->vert_sp)
		tmp->vert_printable = 1;
	if (tmp->horz_sp && tmp->vert_sp)
		if (tmp->dist_horz < tmp->dist_vert)
			tmp->order = 1;
}

static void	handle_kill(t_cub *cub, t_raycasting *cast, t_ray *valid_ray,
						t_spcasting_vars *tmp)
{
	if (BONUS && cub->kill_sprite && valid_ray->can_kill_sp &&
		tmp->horz_printable)
	{
		cub->map[(int)cast->horz_y - \
				!cast->horz->is_down][(int)cast->horz_x] = '0';
		tmp->horz_printable = 0;
		cub->kill_sprite = 0;
	}
	if (BONUS && cub->kill_sprite && valid_ray->can_kill_sp &&
		tmp->vert_printable)
	{
		cub->map[(int)cast->vert_y][(int)cast->vert_x - \
				!cast->vert->is_right] = '0';
		tmp->vert_printable = 0;
		cub->kill_sprite = 0;
	}
}

void		sprites_raycasting(t_cub *cub, t_raycasting *cast, t_ray *valid_ray)
{
	t_spcasting_vars tmp;

	while (in_map_limits(cub, cast->horz_x, cast->horz_y) ||
			in_map_limits(cub, cast->vert_x, cast->vert_y))
	{
		ft_bzero(&tmp, sizeof(t_spcasting_vars));
		sprite_raycasting_z_axis(cub, cast, valid_ray, &tmp);
		handle_kill(cub, cast, valid_ray, &tmp);
		order_and_fill_sprites(cub, cast, &tmp);
		cast->horz_x += cast->horz->xstep;
		cast->horz_y += cast->horz->ystep;
		cast->vert_x += cast->vert->xstep;
		cast->vert_y += cast->vert->ystep;
	}
}
