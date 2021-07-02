/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:21:18 by besellem          #+#    #+#             */
/*   Updated: 2021/02/24 10:24:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_deg2rad(int deg)
{
	return (deg * (T_PI / 180));
}

double	ft_rad2deg(double rad)
{
	return (rad * (180 / T_PI));
}

double	ft_norm_angle(double angle)
{
	const double new_angle = fmod(angle, T_2PI);

	if (new_angle < 0)
		return (new_angle + T_2PI);
	else if (new_angle >= T_2PI)
		return (new_angle - T_2PI);
	return (new_angle);
}
