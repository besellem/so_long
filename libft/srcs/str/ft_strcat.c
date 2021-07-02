/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:54:22 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:17:05 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len;
	size_t i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[len + i] = s2[i];
		++i;
	}
	s1[len + i] = '\0';
	return (s1);
}
