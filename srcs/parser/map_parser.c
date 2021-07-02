/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:41:58 by besellem          #+#    #+#             */
/*   Updated: 2021/03/11 19:25:13 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** cub->map_size_x => max size of columns in the map
** cub->map_size_y => max size of rows in the map
*/

static int	convert_map(t_list *lst, t_cub *cub)
{
	t_list	*head;
	int		i;

	head = lst;
	if (!(cub->map = (char **)malloc(sizeof(char *) * (cub->map_size_y + 1))))
	{
		ft_lstclear(&lst, free);
		ft_error("Malloc error in map conversion", cub, __FILE__, __LINE__);
		return (1);
	}
	i = 0;
	while (head)
	{
		if (!(cub->map[i] = (char *)malloc(cub->map_size_x + 1)))
			return (0);
		cub->map[i][cub->map_size_x] = '\0';
		ft_memset(cub->map[i], ' ', cub->map_size_x);
		ft_memmove(cub->map[i], head->content, ft_strlen(head->content));
		head = head->next;
		++i;
	}
	cub->map[i] = NULL;
	ft_lstclear(&lst, free);
	return (1);
}

static void	fill_lst(t_cub *cub, t_list **lst, char *ret)
{
	t_list			*tmp_lst;
	const size_t	ret_len = ft_strlen(ret);

	if (!(tmp_lst = ft_lstnew(ret)))
	{
		free(ret);
		ft_lstclear(lst, free);
		ft_error("Malloc error in map parsing", cub, __FILE__, __LINE__);
	}
	ft_lstadd_back(lst, tmp_lst);
	++cub->map_size_y;
	if (cub->map_size_x < ret_len)
		cub->map_size_x = ret_len;
}

static int	check_line(char *line, int *map_started, int check)
{
	size_t len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (*map_started == 0 && len == 0 && check == 1)
	{
		free(line);
		return (0);
	}
	if (check == 1 && (len == 0 || charset_in_line(line, MAP_CHARSET) == 0))
		return (-1);
	else
		*map_started += 1;
	return (1);
}

void		map_parser(int fd, t_cub *cub)
{
	t_list	*lst;
	char	*ret;
	int		check;
	int		map_started;
	int		tst;

	map_started = 0;
	lst = NULL;
	while ((check = get_next_line(fd, &ret)) >= 0)
	{
		if ((tst = check_line(ret, &map_started, check)) == 1)
		{
			fill_lst(cub, &lst, ret);
			if (check == 0 && convert_map(lst, cub))
				break ;
		}
		else if (tst == -1)
		{
			free(ret);
			ft_lstclear(&lst, free);
			ft_error("Invalid map", cub, __FILE__, __LINE__);
		}
	}
	if (check == -1)
		ft_error("No map found !", cub, __FILE__, __LINE__);
}
