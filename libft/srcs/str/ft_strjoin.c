/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 21:49:32 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:17:14 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if ((!s1 && !s2) || !(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	*str = '\0';
	i = -1;
	while (s1[++i] && s1)
		str[i] = s1[i];
	j = -1;
	while (s2[++j] && s2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
