/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:08:04 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 15:10:17 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the number of occurences of a character in a string
*/

size_t	ft_stroc(const char *haystack, char c)
{
	size_t i;
	size_t oc;

	if (!haystack)
		return (0);
	oc = 0;
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == c)
			++oc;
		++i;
	}
	return (oc);
}
