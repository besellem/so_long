/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 00:26:39 by besellem          #+#    #+#             */
/*   Updated: 2021/02/14 18:55:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define POS_ERR "Contains multiple start position"

/*
** +0.5 to be in the center of the cube we're in
*/

static void	update_pos(t_cub *cub, int x, int y, char pos)
{
	cub->pos_x = x + 0.5;
	cub->pos_y = y + 0.5;
	if (pos == 'E')
		cub->drxion = DRXION_E;
	else if (pos == 'N')
		cub->drxion = DRXION_N;
	else if (pos == 'W')
		cub->drxion = DRXION_W;
	else if (pos == 'S')
		cub->drxion = DRXION_S;
}

static int	is_valid_charset(t_cub *cub, int *got_player_pos)
{
	size_t	tst;
	int		i;
	int		j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (DRXIONS[++j])
		{
			if ((tst = ft_stroc(cub->map[i], DRXIONS[j])) > 1)
				ft_error(POS_ERR, cub, __FILE__, 0);
			if (tst == 1)
				(*got_player_pos)++;
			if (tst == 1 && *got_player_pos > 1)
				ft_error(POS_ERR, cub, __FILE__, 0);
			if (tst == 1 && *got_player_pos == 1)
				update_pos(cub, ft_stridx(cub->map[i], DRXIONS), i, DRXIONS[j]);
		}
		j = -1;
		while (cub->map[i][++j])
			if (in_charset(MAP_CHARSET, cub->map[i][j]) == -1)
				return (0);
	}
	return (1);
}

int			map_checker(t_cub *cub)
{
	int got_player_pos;

	got_player_pos = 0;
	if (!is_valid_charset(cub, &got_player_pos))
		ft_error("Invalid charset in map", cub, __FILE__, __LINE__);
	if (got_player_pos == 0)
		ft_error("No starting point found ! [NSEW]", cub, __FILE__, __LINE__);
	cub->map[(int)cub->pos_y][(int)cub->pos_x] = '0';
	return (1);
}
