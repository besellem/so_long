/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:08:49 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 18:14:28 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** Clean characters from `charset' found in `s' by modifying it.
**
** ex:
** ft_strclean(";bonjour >to<i", ";<>");
**   => "bonjour toi"
*/
char	*ft_strclean(char *s, const char *charset)
{
	size_t	i;
	size_t	j;

	if (!s || !charset)
		return (s);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (0 == ft_incharset(charset, s[i]))
			s[j++] = s[i];
		++i;
	}
	ft_bzero(s + j, ft_strlen(s + j));
	return (s);
}
