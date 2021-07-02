/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:18:26 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:11:45 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_tmp_keys
{
	char	*key_name;
	int		key_code;
	int		x;
	int		y;
};

const struct s_tmp_keys	g_keys[] = {
	{"up", KEY_W, 0, -1},
	{"down", KEY_S, 0, 1},
	{"right", KEY_D, 1, 0},
	{"left", KEY_A, -1, 0},
	{NULL, -1, 0, 0}
};

static void	__move_player__(t_so_long *sl, const struct s_tmp_keys key)
{
	if ((sl->pos_x + key.x) >= 0 && (sl->pos_x + key.x) < sl->map_size_x
		&& (sl->pos_y + key.y) >= 0 && (sl->pos_y + key.y) < sl->map_size_y)
	{
		if ('1' != sl->map[sl->pos_y + key.y][sl->pos_x + key.x])
		{
			if ('C' == sl->map[sl->pos_y + key.y][sl->pos_x + key.x])
			{
				sl->collectibles--;
				sl->map[sl->pos_y + key.y][sl->pos_x + key.x] = '0';
			}
			sl->pos_x += key.x;
			sl->pos_y += key.y;
			sl->move_nbr++;
		}
	}
	ft_printf("move #%d: %s\n", sl->move_nbr, key.key_name);
}

int	handle_key_press(int key, t_so_long *sl)
{
	int	i;

	if (KEY_ESC == key)
	{
		ft_quit(sl);
		return (0);
	}
	i = 0;
	while (g_keys[i].key_code != -1)
	{
		if (key == g_keys[i].key_code)
		{
			__move_player__(sl, g_keys[i]);
			return (0);
		}
		++i;
	}
	return (1);
}

int	handle_key_release(int key, t_so_long *sl)
{
	(void)key;
	(void)sl;
	return (0);
}
