/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:57:27 by besellem          #+#    #+#             */
/*   Updated: 2021/03/08 00:28:43 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Use a function to check each characters of a string
** usage:
** ft_strisall("012345", ft_isdigit) == 1
*/

int	ft_strisall(char *str, int (*f)(int))
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((*f)(str[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}
