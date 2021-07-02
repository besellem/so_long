/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:31:15 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 19:24:16 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fill_texture(t_cub *cub, t_img *tx, char *path)
{
	const int fd = open(path, O_RDONLY);

	if (fd == -1 || close(fd))
		ft_error("Unable to open a texture", cub, __FILE__, __LINE__);
	if (file_got_ext(path, ".xpm"))
	{
		tx->ptr = mlx_xpm_file_to_image(cub->mlx, path, &tx->x, &tx->y);
		if (!tx->ptr)
			ft_error("Unable to open a texture", cub, __FILE__, __LINE__);
	}
	else
		ft_error("Not a valid texture file", cub, __FILE__, __LINE__);
	tx->addr = mlx_get_data_addr(tx->ptr, &tx->bpp, &tx->size_line,
								&tx->endian);
	if (!tx->addr)
		ft_error("Malloc error", cub, __FILE__, __LINE__);
}

static void	load_textures(t_cub *cub)
{
	int i;

	i = 0;
	while (i < TEXTURES_COUNT)
	{
		ft_memset(&cub->txtrs[i], 0, sizeof(t_img));
		++i;
	}
	fill_texture(cub, &cub->txtrs[0], cub->txtr_no);
	fill_texture(cub, &cub->txtrs[1], cub->txtr_so);
	fill_texture(cub, &cub->txtrs[2], cub->txtr_ea);
	fill_texture(cub, &cub->txtrs[3], cub->txtr_we);
	fill_texture(cub, &cub->txtrs[4], cub->txtr_s);
}

static void	set_sprites_oc(t_cub *cub)
{
	size_t i;
	size_t j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (is_sprite(cub->map[i][j]))
				cub->sprites_ocs++;
			++j;
		}
		++i;
	}
}

static void	alloc_sprites(t_cub *cub)
{
	int i;
	int j;
	int k;

	set_sprites_oc(cub);
	cub->sprites = (t_sprite *)malloc(sizeof(t_sprite) * cub->sprites_ocs);
	if (!cub->sprites)
		ft_error("Malloc error", cub, __FILE__, __LINE__);
	k = 0;
	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (is_sprite(cub->map[i][j]))
			{
				ft_memset(&cub->sprites[k], 0, sizeof(t_sprite));
				(&cub->sprites[k])->x = j;
				(&cub->sprites[k])->y = i;
				++k;
			}
		}
	}
}

void		cub_parser(int ac, char **av, t_cub *cub)
{
	const int fd = open(av[1], O_RDWR | O_NOFOLLOW);

	if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
		cub->save_opt = 1;
	else if (ac == 3)
		ft_error("Argument error", cub, __FILE__, __LINE__);
	if (file_got_ext(av[1], ".cub") == 0 || fd == -1)
	{
		ft_putendl_fd(CUB_ERR, 2);
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_error("Unable to start mlx", cub, __FILE__, __LINE__);
	cub_fill_specs(fd, cub);
	load_textures(cub);
	map_parser(fd, cub);
	close(fd);
	map_checker(cub);
	if (!map_validator(cub))
		ft_error("Invalid Map", cub, __FILE__, __LINE__);
	alloc_sprites(cub);
	init_bonus(cub);
}
