/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:56:58 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:36:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_lookup_texture
{
	int	texture_char;
	int	texture_id;
};

static t_img	__get_texture__(t_so_long *sl, char c)
{
	const struct s_lookup_texture	g_lookup_txtrs[] = {
		{'1', TXTR_WALL},
		{'0', TXTR_EMPTY},
		{'C', TXTR_COLLECTIBLE},
		{'E', TXTR_EXIT},
		{'P', TXTR_PLAYER},
		{0, 0}
	};
	int								i;

	i = 0;
	while (g_lookup_txtrs[i].texture_char)
	{
		if (g_lookup_txtrs[i].texture_char == c)
			return (sl->txtrs[g_lookup_txtrs[i].texture_id]);
		++i;
	}
	return (sl->txtrs[g_lookup_txtrs[0].texture_id]);
}

static void	__put_texture__(t_so_long *sl, int x, int y, t_img txtr)
{
	const double	ratio_x = ((double)sl->win_w / sl->map_size_x) / txtr.x;
	const double	ratio_y = ((double)sl->win_h / sl->map_size_y) / txtr.y;
	char			*ptr;
	int				tx_x;
	int				tx_y;

	tx_y = 0;
	while (tx_y < txtr.y)
	{
		tx_x = 0;
		while (tx_x < txtr.x)
		{
			ptr = txtr.addr + tx_y * txtr.size_line + tx_x * (txtr.bpp / 8);
			ft_pixel_put(
				sl,
				(x * ((double)sl->win_w / sl->map_size_x)) + (tx_x * ratio_x),
				(y * ((double)sl->win_h / sl->map_size_y)) + (tx_y * ratio_y),
				*(uint32_t *)ptr
				);
			++tx_x;
		}
		++tx_y;
	}
}

static void	put_map(t_so_long *sl)
{
	const char	**map = (const char **)sl->map;
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			__put_texture__(sl, x, y, __get_texture__(sl, map[y][x]));
			++x;
		}
		++y;
	}
}

static void	print_player(t_so_long *sl)
{
	__put_texture__(sl, sl->pos_x, sl->pos_y, __get_texture__(sl, 'P'));
}

void	display_minimap(t_so_long *sl)
{
	put_map(sl);
	print_player(sl);
}
