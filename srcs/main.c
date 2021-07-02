/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:25:57 by besellem          #+#    #+#             */
/*   Updated: 2021/03/14 00:15:33 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define GAME_STARTING_SOUND_PATH "./sounds/game_starting.wav"

static void	ft_mlx_start(t_cub *cub)
{
	mlx_do_key_autorepeaton(cub->mlx);
	cub->win = mlx_new_window(cub->mlx, cub->win_w, cub->win_h, "cub3D");
	cub->img.ptr = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr,
										&(cub->img.bpp),
										&(cub->img.size_line),
										&(cub->img.endian));
	print_specs(cub);
	if (BONUS)
		system(SOUND_CMD" "GAME_STARTING_SOUND_PATH" 2>/dev/null&");
	update_frame(cub);
	mlx_hook(cub->win, 2, (1L << 0), handle_key_press, cub);
	mlx_hook(cub->win, 3, (1L << 1), handle_key_release, cub);
	mlx_hook(cub->win, EVT_RED_CROSS, (1L << 2), ft_red_cross, cub);
	mlx_loop_hook(cub->mlx, engine_loop, cub);
	mlx_loop(cub->mlx);
}

int			main(int ac, char **av)
{
	t_cub cub;

	if (ac >= 2 && ac <= 3)
	{
		init_cub(&cub);
		cub_parser(ac, av, &cub);
		if (cub.save_opt && ft_save(&cub))
			return (0);
		else if (cub.save_opt)
			ft_error("Enable to create a .bmp file", &cub, NULL, 0);
		ft_putendl(ENV_MSG);
		ft_mlx_start(&cub);
	}
	else
		ft_error("Arguments error", NULL, NULL, 0);
	return (0);
}
