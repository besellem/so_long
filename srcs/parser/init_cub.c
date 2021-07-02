/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:39:13 by besellem          #+#    #+#             */
/*   Updated: 2021/02/14 20:15:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** all variables that are not set here will be set in the parser
*/

void	init_cub(t_cub *cub)
{
	ft_memset(cub, 0, sizeof(t_cub));
	ft_memset(&cub->img, 0, sizeof(t_img));
	cub->win_w = -1;
	cub->win_h = -1;
	cub->sky_color = -1;
	cub->grnd_color = -1;
	cub->increment = 0.1;
}
