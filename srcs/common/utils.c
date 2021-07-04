/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 02:08:15 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 17:03:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_extension(const char *file, const char *extension)
{
	size_t	file_len;
	size_t	ext_len;

	if (!file || !extension)
		return (FALSE);
	file_len = ft_strlen(file);
	ext_len = ft_strlen(extension);
	if (file_len < ext_len)
		return (FALSE);
	return (FALSE == ft_strncmp(file + file_len - ext_len, extension, ext_len));
}

void	print_map(t_so_long *sl)
{
	int	x;
	int	y;

	y = 0;
	while (y < sl->map_size_y)
	{
		x = 0;
		while (x < sl->map_size_x)
		{
			if (x == sl->pos_x && y == sl->pos_y)
				ft_printf(B_GREEN"%c"CLR_COLOR, sl->map[y][x]);
			else
				ft_putchar(sl->map[y][x]);
			++x;
		}
		write(1, "\n", 1);
		++y;
	}
	write(1, "\n", 1);
}
