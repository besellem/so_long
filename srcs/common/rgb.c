/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 01:46:24 by besellem          #+#    #+#             */
/*   Updated: 2021/02/14 21:32:15 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check if a line is rgb without any other character than spaces or digits at
** the right places
**
** ex:
** "  0234   " -> 1
** "    0234s" -> 0
** "0"         -> 1
*/

int		check_rgb(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] == ' ')
		++i;
	while (s[i] && ft_isdigit(s[i]))
		++i;
	while (s[i] && s[i] == ' ')
		++i;
	if (s[i])
		return (0);
	return (1);
}

int32_t	ft_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((int32_t)(((r << 8) + g) << 8) + b);
}

int		is_rgb(int color)
{
	return (color >= 0 && color <= 255);
}
