/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:10:08 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 18:12:47 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** Clean characters the first `n' chars from `charset' found in `s'
** by modifying it.
**
** ex:
** ft_strclean(";bonjour >to<i", ";<>", 1);
**   => "bonjour >to<i"
*/
char	*ft_strnclean(char *s, const char *charset, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s || !charset)
		return (s);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (i >= n || 0 == ft_incharset(charset, s[i]))
			s[j++] = s[i];
		++i;
	}
	ft_bzero(s + j, ft_strlen(s + j));
	return (s);
}
