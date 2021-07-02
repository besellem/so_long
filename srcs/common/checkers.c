/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:05:19 by besellem          #+#    #+#             */
/*   Updated: 2021/03/07 18:32:21 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check the extension name of a file
*/

int	file_got_ext(char *file, char *extension)
{
	size_t file_len;
	size_t ext_len;

	if (!file || !extension)
		return (0);
	file_len = ft_strlen(file);
	ext_len = ft_strlen(extension);
	if (file_len < ext_len)
		return (0);
	return (ft_strncmp(file + file_len - ext_len, extension, ext_len) == 0);
}

int	in_charset(char *charset, int c)
{
	int i;

	if (!charset)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (charset[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}

int	charset_in_line(char *line, char *charset)
{
	int i;

	if (!line || !charset)
		return (0);
	i = 0;
	while (line[i])
		if (in_charset(charset, line[i++]) == -1)
			return (0);
	return (1);
}

/*
** Check if coordinates (x, y) are in the map's range (avoid segv errors)
*/

int	in_map_limits(t_cub *cub, double x, double y)
{
	return (x >= 0 && x < cub->map_size_x &&
			y >= 0 && y < cub->map_size_y);
}

/*
** Useful for bonuses, instead of checking if `map[i][j] == '2'`
** Thus, I can add as much sprites as I want
*/

int	is_sprite(int c)
{
	return (c != ' ' && c != '0' && c != '1');
}
