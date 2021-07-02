/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:18:04 by besellem          #+#    #+#             */
/*   Updated: 2021/03/13 21:40:11 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_cub *cub)
{
	if (cub->txtr_no)
		free(cub->txtr_no);
	if (cub->txtr_so)
		free(cub->txtr_so);
	if (cub->txtr_ea)
		free(cub->txtr_ea);
	if (cub->txtr_we)
		free(cub->txtr_we);
	if (cub->txtr_s)
		free(cub->txtr_s);
}

static void	free_imgs(t_cub *cub)
{
	int i;

	if (cub->img.ptr)
		mlx_destroy_image(cub->mlx, cub->img.ptr);
	i = -1;
	while (++i < TEXTURES_COUNT && cub->txtrs[i].ptr)
		mlx_destroy_image(cub->mlx, cub->txtrs[i].ptr);
	i = -1;
	while (++i < GUN_GIF_NB && cub->txtr_gun[i].ptr)
		mlx_destroy_image(cub->mlx, cub->txtr_gun[i].ptr);
	if (cub->txtr_target.ptr)
		mlx_destroy_image(cub->mlx, cub->txtr_target.ptr);
	if (cub->txtr_life.ptr)
		mlx_destroy_image(cub->mlx, cub->txtr_life.ptr);
}

/*
** cub->win pointer is not freed here because it's done by mlx_destroy_window()
*/

void		ft_free_cub(t_cub *cub)
{
	int i;

	free_textures(cub);
	free_imgs(cub);
	if (cub->map)
		ft_free_strs(cub->map);
	if (cub->rays)
	{
		i = -1;
		while (++i < cub->win_w && cub->rays[i].sp_ray)
			free((&cub->rays[i])->sp_ray);
		free(cub->rays);
	}
	if (cub->sprites)
		free(cub->sprites);
	if (cub->mlx)
		free(cub->mlx);
	if (BONUS)
		system("killall "SOUND_CMD" 2>/dev/null");
}

/*
** ! DO NOT CHANGE THE RETURN VALUE: IT'S A NORM TRICK !
*/

int			ft_free_strs(char **strs)
{
	int i;

	if (!strs)
		return (1);
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (1);
}
