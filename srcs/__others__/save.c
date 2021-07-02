/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:33:49 by besellem          #+#    #+#             */
/*   Updated: 2021/02/24 10:24:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_cursor(int current, int max)
{
	int line_length;
	int i;

	line_length = 30;
	i = -1;
	ft_putstr(CLR_LINE);
	write(1, "[", 1);
	while (++i < ((double)current / max) * line_length)
		write(1, "#", 1);
	while (i++ < line_length)
		write(1, " ", 1);
	write(1, "] ", 2);
	ft_printf("%.2f %%", ((double)current / max) * 100);
}

static void	ft_bmp_header(t_cub *cub, int fd)
{
	uint64_t nb;

	write(fd, "BM", 2);
	nb = cub->img.bpp * cub->parsed_h * cub->parsed_w + 54 * 8;
	ft_putn_fd(fd, nb, 4);
	ft_putn_fd(fd, 0, 4);
	ft_putn_fd(fd, 54, 4);
	ft_printf("# Generating "B_GREEN"%s"CLR_COLOR" (%.2f mb) ...\n",
			BMP_FILEPATH, (double)nb / 8000000);
}

static void	ft_bmp_dib_header(t_cub *cub, int fd)
{
	int i;

	ft_putn_fd(fd, 40, 4);
	ft_putn_fd(fd, cub->parsed_w, 4);
	ft_putn_fd(fd, cub->parsed_h, 4);
	ft_putn_fd(fd, 1, 2);
	ft_putn_fd(fd, cub->img.bpp, 2);
	i = -1;
	while (++i < 6)
		ft_putn_fd(fd, 0, 4);
}

static void	ft_bmp_pixel_array(t_cub *cub, int fd)
{
	char	*ptr;
	int		i;
	int		j;

	i = cub->parsed_h;
	while (i-- > 0)
	{
		j = -1;
		while (++j < cub->parsed_w)
		{
			ptr = cub->img.addr;
			ptr += i * cub->img.size_line + j * (cub->img.bpp / 8);
			write(fd, &(*(uint32_t *)ptr), 4);
		}
		update_cursor(cub->parsed_h - i, cub->parsed_h);
	}
	write(1, "\n", 1);
}

int			ft_save(t_cub *cub)
{
	int fd;

	cub->img.ptr = mlx_new_image(cub->mlx, cub->parsed_w, cub->parsed_h);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &(cub->img.bpp),
									&(cub->img.size_line), &(cub->img.endian));
	update_frame(cub);
	print_specs(cub);
	if ((fd = open(BMP_FILEPATH, O_WRONLY | O_CREAT, 0644)) == -1)
		return (0);
	ft_bmp_header(cub, fd);
	update_cursor(0, cub->parsed_h);
	ft_bmp_dib_header(cub, fd);
	ft_bmp_pixel_array(cub, fd);
	close(fd);
	ft_free_cub(cub);
	ft_putendl(B_GREEN"Done !"CLR_COLOR);
	return (1);
}
