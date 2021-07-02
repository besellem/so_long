/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:50:40 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 19:22:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	window_size_spec(char **split, t_cub *cub)
{
	int x_tmp;
	int y_tmp;

	if (ft_strs_size(split) != 3 || !ft_strisdigit(split[1]) ||
		!ft_strisdigit(split[2]))
		return (!ft_free_strs(split));
	cub->parsed_w = ft_atoi(split[1]);
	cub->parsed_h = ft_atoi(split[2]);
	cub->win_w = cub->parsed_w;
	cub->win_h = cub->parsed_h;
	ft_free_strs(split);
	if (cub->win_w <= 0 || cub->win_h <= 0)
		return (0);
	mlx_get_screen_size(cub->mlx, &x_tmp, &y_tmp);
	if (cub->save_opt == 0 && cub->win_w > x_tmp)
		cub->win_w = x_tmp;
	if (cub->save_opt == 0 && cub->win_h > y_tmp)
		cub->win_h = y_tmp;
	cub->rays = (t_ray *)malloc(sizeof(t_ray) * cub->win_w);
	if (!cub->rays || alloc_sprite_rays(cub))
		return (0);
	return (1);
}

/*
** The rgb variables are int type because we need to know if the rgb color
** from the config overflowed an unsigned char or not
*/

static int	color_specs(char *line, char **split, t_cub *cub)
{
	int32_t	color;
	int		r;
	int		g;
	int		b;

	if (ft_stroc(line, ',') != 2 || ft_strs_size(split) != 3 ||
		!check_rgb(split[0]) || !check_rgb(split[1]) || !check_rgb(split[2]))
		return (!ft_free_strs(split));
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	ft_free_strs(split);
	if (!(is_rgb(r) && is_rgb(g) && is_rgb(b)))
		return (0);
	color = ft_rgb(r, g, b);
	if (!ft_strncmp(line, "F ", 2) && cub->grnd_color == -1)
		cub->grnd_color = color;
	else if (!ft_strncmp(line, "C ", 2) && cub->sky_color == -1)
		cub->sky_color = color;
	else
		return (0);
	return (1);
}

static int	texture_specs(char *line, t_cub *cub)
{
	char	**nfos;
	int		fd;

	nfos = ft_split(line, ' ');
	if (ft_strs_size(nfos) != 2 || !file_got_ext(nfos[1], ".xpm") ||
		(fd = open(nfos[1], O_RDONLY)) == -1 || read(fd, NULL, 0) || close(fd))
		return (!ft_free_strs(nfos));
	if (!ft_strncmp(line, "NO ", 3) && !cub->txtr_no)
		cub->txtr_no = ft_strdup(nfos[1]);
	else if (!ft_strncmp(line, "SO ", 3) && !cub->txtr_so)
		cub->txtr_so = ft_strdup(nfos[1]);
	else if (!ft_strncmp(line, "WE ", 3) && !cub->txtr_we)
		cub->txtr_we = ft_strdup(nfos[1]);
	else if (!ft_strncmp(line, "EA ", 3) && !cub->txtr_ea)
		cub->txtr_ea = ft_strdup(nfos[1]);
	else if (!ft_strncmp(line, "S ", 2) && !cub->txtr_s)
		cub->txtr_s = ft_strdup(nfos[1]);
	else
		return (!ft_free_strs(nfos));
	return (ft_free_strs(nfos));
}

static int	check_line(char *line, t_cub *cub, int *specs_completed)
{
	if (!ft_strncmp(line, "R ", 2) && cub->win_w == -1 && cub->win_h == -1)
	{
		if (!window_size_spec(ft_split(line, ' '), cub))
			return (0);
	}
	else if ((!ft_strncmp(line, "F ", 2) && cub->grnd_color == -1) ||
			(!ft_strncmp(line, "C ", 2) && cub->sky_color == -1))
	{
		if (!color_specs(line, ft_split(line + 2, ','), cub))
			return (0);
	}
	else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
			!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3) ||
			!ft_strncmp(line, "S ", 2))
	{
		if (!texture_specs(line, cub))
			return (0);
	}
	else if (ft_strlen(line) > 0)
		return (0);
	if (are_specs_complete(cub))
		*specs_completed = 1;
	return (1);
}

void		cub_fill_specs(int fd, t_cub *cub)
{
	char	*ret;
	int		check;
	int		line_count;
	int		specs_completed;

	line_count = 0;
	specs_completed = 0;
	while ((check = get_next_line(fd, &ret)) >= 0)
	{
		++line_count;
		if (!check_line(ret, cub, &specs_completed))
		{
			free(ret);
			ft_error("Error in config file", cub, __FILE__, line_count);
		}
		free(ret);
		if (specs_completed == 1)
			break ;
		if (check == 0)
			ft_error("Incomplete configuration", cub, NULL, line_count);
	}
}
