/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:56:02 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 17:35:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Print a pixel at the coordinates into mlx->img
*/
void	ft_pixel_put(t_so_long *sl, int x, int y, uint32_t color)
{
	char	*px;

	px = sl->img.addr + y * sl->img.size_line + x * (sl->img.bpp / 8);
	*(uint32_t *)px = color;
}
