/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:22:27 by besellem          #+#    #+#             */
/*   Updated: 2021/02/15 11:22:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check 0 or 2 case
*/

static int	chk_rnd(t_cub *cub, char **map, size_t x, size_t y)
{
	if ((int)x - 1 >= 0 && x + 1 < cub->map_size_x &&
		(int)y - 1 >= 0 && y + 1 < cub->map_size_y)
	{
		if ((map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			return (0);
		if ((map[y - 1][x] == ' ' || map[y + 1][x] == ' '))
			return (0);
	}
	else
		return (0);
	return (1);
}

/*
** Check space case
*/

static int	chk_sp(t_cub *cub, char **map, size_t x, size_t y)
{
	if (((int)x - 1 >= 0 && map[y][x - 1] != ' ' && map[y][x - 1] != '1') ||
		(x + 1 < cub->map_size_x && map[y][x + 1] != ' ' &&
		map[y][x + 1] != '1'))
	{
		return (0);
	}
	if (((int)y - 1 >= 0 && map[y - 1][x] != ' ' && map[y - 1][x] != '1') ||
		(y + 1 < cub->map_size_y && map[y + 1][x] != ' ' &&
		map[y + 1][x] != '1'))
	{
		return (0);
	}
	return (1);
}

static int	check_line(t_cub *cub, char *line, size_t y)
{
	size_t i;

	i = 0;
	while (line[i] && line[i] == ' ')
		++i;
	if (line[i] == '0')
		return (i);
	while (line[i])
	{
		if ((is_sprite(line[i]) || line[i] == '0') &&
			!chk_rnd(cub, cub->map, i, y))
			return (i);
		else if (line[i] == ' ' && !chk_sp(cub, cub->map, i, y))
			return (i);
		if (line[i] == '0')
		{
			while (line[i] && line[i] == '0')
				++i;
			if (!line[i] || line[i] == ' ')
				return (i);
		}
		++i;
	}
	return (-1);
}

static void	map_print_error(t_cub *cub, size_t x, size_t y)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < cub->map_size_y)
	{
		j = 0;
		while (j < cub->map_size_x)
		{
			if (y == i && x == j)
				ft_printf(B_RED"%c"CLR_COLOR, cub->map[i][j]);
			else
				write(1, &cub->map[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		if (i == y)
		{
			ft_printf(B_GREEN"%*.d^ error here\n"CLR_COLOR, x, 0);
			break ;
		}
		++i;
	}
}

int			map_validator(t_cub *cub)
{
	size_t	y;
	int		check;

	y = 0;
	while (cub->map[y] != NULL)
	{
		if ((check = check_line(cub, cub->map[y], y)) != -1)
		{
			map_print_error(cub, check, y);
			return (0);
		}
		++y;
	}
	return (1);
}
