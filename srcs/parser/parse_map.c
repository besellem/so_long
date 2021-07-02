/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:51:13 by besellem          #+#    #+#             */
/*   Updated: 2021/07/02 19:39:43 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	__get_map__(t_so_long *sl, const char *path)
{
	const int	fd = open(path, O_RDONLY | O_NOFOLLOW);
	t_list		*lst;
	char		*ret;
	int			r;

	if (SYSCALL_ERR == fd)
		return (FALSE);
	lst = NULL;
	while (TRUE)
	{
		r = get_next_line(fd, &ret);
		if (r >= 0)
			ft_lstadd_back(&lst, ft_lstnew(ret));
		if (0 == r)
			break ;
		if (r < 0)
		{
			ft_lstclear(&lst, free);
			return (FALSE);
		}
	}
	close(fd);
	sl->map = ft_lst2strs(&lst);
	ft_lstclear(&lst, free);
	return (NULL != sl->map);
}

static int	__check_map__(t_so_long *sl)
{
	const char		**map = (const char **)sl->map;
	const size_t	line_len = ft_strlen(map[0]);
	size_t			i;
	size_t			j;

	if (!ft_incharset(map[ft_strslen((char **)map) - 1], '1')
		|| !ft_incharset(map[0], '1'))
		return (FALSE);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (FALSE);
		if (ft_strlen(map[i]) != line_len)
			return (FALSE);
		j = 0;
		while (map[i][j])
		{
			if (!ft_incharset(MAP_CHARSET, map[i][j]))
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}

struct s_map_validate
{
	int	collectible;
	int	exit;
	int	player_pos;
};

static int	__map_validator__(t_so_long *sl, struct s_map_validate valid)
{
	char	**map;
	int		tmp_pos;
	size_t	i;

	map = sl->map;
	i = 0;
	while (map[i])
	{
		valid.collectible += ft_stroc(map[i], 'C');
		valid.exit += ft_stroc(map[i], 'E');
		valid.player_pos += ft_stroc(map[i], 'P');
		if (valid.player_pos > 1)
			return (FALSE);
		tmp_pos = ft_stridx(map[i], "P");
		if (tmp_pos != -1)
		{
			map[i][tmp_pos] = '0';
			sl->pos_x = tmp_pos;
			sl->pos_y = i;
		}
		++i;
	}
	sl->collectibles = valid.collectible;
	return (valid.collectible >= 1 && valid.exit >= 1 && 1 == valid.player_pos);
}

int	parse_map(t_so_long *sl, const char *path)
{
	struct s_map_validate	valid;

	ft_bzero(&valid, sizeof(struct s_map_validate));
	if (FALSE == __get_map__(sl, path))
		ft_error("cannot parse the file", NULL, NULL, 0);
	if (FALSE == __check_map__(sl) || FALSE == __map_validator__(sl, valid))
		ft_error("not a valid map", NULL, NULL, 0);
	sl->map_size_x = ft_strlen(*sl->map);
	sl->map_size_y = ft_strslen(sl->map);
	return (TRUE);
}
