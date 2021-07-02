/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 02:29:24 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:16:44 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			s1[i] = s2[i];
			++i;
		}
	}
	return (dst);
}
