/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:31:15 by besellem          #+#    #+#             */
/*   Updated: 2021/07/04 00:42:20 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define INITIAL_WIDTH  800
#define INITIAL_HEIGHT 800

#define TEXTURE_WALL        "./assets/stone.xpm"
#define TEXTURE_EMPTY       "./assets/floor.xpm"
#define TEXTURE_COLLECTIBLE "./assets/key.xpm"
#define TEXTURE_EXIT        "./assets/closed_door.xpm"
#define TEXTURE_PLAYER      "./assets/knight.xpm"

static void	fill_texture(t_so_long *sl, t_img *tx, char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (SYSCALL_ERR == fd || close(fd))
		ft_error("Unable to open a texture", sl, __FILE__, __LINE__);
	if (is_extension(path, ".xpm"))
	{
		tx->ptr = mlx_xpm_file_to_image(sl->mlx, path, &tx->x, &tx->y);
		if (!tx->ptr)
			ft_error("Unable to open a texture", sl, __FILE__, __LINE__);
	}
	else
	{
		ft_printf("[%s] ", path);
		ft_error("Not a valid texture file", sl, __FILE__, __LINE__);
	}
	tx->addr = mlx_get_data_addr(tx->ptr, &tx->bpp, &tx->size_line,
			&tx->endian);
	if (!tx->addr)
		ft_error("Malloc error", sl, __FILE__, __LINE__);
}

static int	load_textures(t_so_long *sl)
{
	fill_texture(sl, &sl->txtrs[TXTR_WALL], TEXTURE_WALL);
	fill_texture(sl, &sl->txtrs[TXTR_EMPTY], TEXTURE_EMPTY);
	fill_texture(sl, &sl->txtrs[TXTR_COLLECTIBLE], TEXTURE_COLLECTIBLE);
	fill_texture(sl, &sl->txtrs[TXTR_EXIT], TEXTURE_EXIT);
	fill_texture(sl, &sl->txtrs[TXTR_PLAYER], TEXTURE_PLAYER);
	return (TRUE);
}

static void	__init_sl__(t_so_long *sl)
{
	int	i;

	ft_bzero(sl, sizeof(t_so_long));
	ft_bzero(&sl->img, sizeof(t_img));
	sl->win_w = INITIAL_WIDTH;
	sl->win_h = INITIAL_HEIGHT;
	i = 0;
	while (i < __TXTR_MAX__)
	{
		ft_bzero(&sl->txtrs[i], sizeof(t_img));
		++i;
	}
}

int	ft_parse(t_so_long *sl, char *path)
{
	__init_sl__(sl);
	if (!is_extension(path, ".ber"))
		ft_error("not a .ber file", NULL, NULL, 0);
	if (FALSE == parse_map(sl, path))
		return (FALSE);
	sl->mlx = mlx_init();
	if (!sl->mlx)
		ft_error("Unable to start mlx", sl, __FILE__, __LINE__);
	load_textures(sl);
	return (TRUE);
}
