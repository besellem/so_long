/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 02:08:15 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 19:51:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_cub *cub)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < cub->map_size_y)
	{
		x = 0;
		while (x < cub->map_size_x)
		{
			if (x == (size_t)cub->pos_x && y == (size_t)cub->pos_y)
				ft_printf(B_GREEN"%c"CLR_COLOR, cub->map[y][x]);
			else
				ft_putchar(cub->map[y][x]);
			++x;
		}
		write(1, "\n", 1);
		++y;
	}
}

void	print_specs(t_cub *cub)
{
	printf("-- Specs --\n");
	printf("{\n");
	printf("    Window width:    %d -> %d\n", cub->parsed_w, cub->win_w);
	printf("    Window height:   %d -> %d\n", cub->parsed_h, cub->win_h);
	printf("    Sky color:       %X\n", cub->sky_color);
	printf("    Ground color:    %X\n", cub->grnd_color);
	printf("    North texture:   %s\n", cub->txtr_no);
	printf("    South texture:   %s\n", cub->txtr_so);
	printf("    East texture:    %s\n", cub->txtr_ea);
	printf("    West texture:    %s\n", cub->txtr_we);
	printf("    Sprite texture:  %s\n", cub->txtr_s);
	printf("    Map size (x):    %zu\n", cub->map_size_x);
	printf("    Map size (y):    %zu\n", cub->map_size_y);
	printf("    Player drxion:   %.2f\n", cub->drxion);
	printf("    Player pos (x):  %.1f\n", cub->pos_x);
	printf("    Player pos (y):  %.1f\n", cub->pos_y);
	printf("    Movement speed:  %.2f cubes/frame\n", cub->increment);
	printf("}\n\n");
	print_map(cub);
	printf("\n----\n\n");
}
