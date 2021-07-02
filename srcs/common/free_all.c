/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:18:04 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:39:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__free_imgs__(t_so_long *sl)
{
	int	i;

	i = 0;
	while (i < __TXTR_MAX__ && sl->txtrs[i].ptr)
	{
		mlx_destroy_image(sl->mlx, sl->txtrs[i].ptr);
		++i;
	}
	if (sl->img.ptr)
		mlx_destroy_image(sl->mlx, sl->img.ptr);
}

/*
** sl->win pointer is not freed here because it's done by mlx_destroy_window()
*/
void	ft_free_all(t_so_long *sl)
{
	__free_imgs__(sl);
	if (sl->map)
		ft_strsfree(ft_strslen(sl->map), sl->map);
	if (sl->mlx)
		free(sl->mlx);
}
