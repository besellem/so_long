/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:45:53 by besellem          #+#    #+#             */
/*   Updated: 2021/03/08 00:28:38 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if each characters of the string are alphanumeric
*/

int	ft_strisalnum(char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}
