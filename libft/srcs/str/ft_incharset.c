/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incharset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:48:38 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 21:48:44 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Like strtchr, but returns a boolean
** Check if a character is in a string
** `c` is converted in char for the comparison
*/

int	ft_incharset(const char *charset, int c)
{
	size_t i;

	if (!charset)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (charset[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}
