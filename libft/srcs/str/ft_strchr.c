/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 02:29:31 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:17:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (!(char)c)
		return ((char *)(s + ft_strlen(s)));
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
