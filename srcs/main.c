/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:25:57 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:35:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_start(t_so_long *sl)
{
	mlx_do_key_autorepeaton(sl->mlx);
	sl->win = mlx_new_window(sl->mlx, sl->win_w, sl->win_h, "so_long");
	sl->img.ptr = mlx_new_image(sl->mlx, sl->win_w, sl->win_h);
	sl->img.addr = mlx_get_data_addr(sl->img.ptr,
			&sl->img.bpp,
			&sl->img.size_line,
			&sl->img.endian);
	print_specs(sl);
	update_frame(sl);
	mlx_hook(sl->win, 2, (1L << 0), handle_key_press, sl);
	mlx_hook(sl->win, 3, (1L << 1), handle_key_release, sl);
	mlx_hook(sl->win, EVT_RED_CROSS, (1L << 2), ft_red_cross, sl);
	mlx_loop_hook(sl->mlx, engine_loop, sl);
	mlx_loop(sl->mlx);
}

int	main(int ac, char **av)
{
	t_so_long	sl;

	if (2 == ac)
	{
		if (FALSE == ft_parse(&sl, av[1]))
			return (FALSE);
		ft_putendl(ENV_MSG);
		ft_mlx_start(&sl);
	}
	else
		ft_error("Arguments error", NULL, NULL, 0);
	return (0);
}
