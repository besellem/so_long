/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:45:35 by besellem          #+#    #+#             */
/*   Updated: 2021/02/14 21:38:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strs_size(char **strs)
{
	int i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		++i;
	return (i);
}

/*
** Replace ternary operation (because of norm v3)
*/

void	*ft_ternary(int condition, void *if_true, void *if_false)
{
	if (condition != 0)
		return (if_true);
	else
		return (if_false);
}
