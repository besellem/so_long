/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:53:06 by besellem          #+#    #+#             */
/*   Updated: 2021/03/04 10:28:56 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Get the distance between 2 points (Pythagore)
*/

double	ft_pythagore(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

/*
** Pythagore (without sqrt - not needed)
** Used to compare "distances"
*/

double	ft_pyt_like(double x1, double y1, double x2, double y2)
{
	return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

/*
** Get the fractional part of a decimal number (keeping the sign)
** ex: -12.44 -> -0.44
*/

double	get_dec(double n)
{
	return (n - (int)n);
}

/*
** Do 'nb1 - nb2' without being < 0. If this is the case, return 0
** (used in the raycasting calculations - prevents segv from the map)
*/

int		safe_min(double nb1, double nb2)
{
	if (nb1 - nb2 < 0)
		return (0);
	return (nb1 - nb2);
}
