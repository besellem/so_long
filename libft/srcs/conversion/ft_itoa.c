/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:27:52 by besellem          #+#    #+#             */
/*   Updated: 2021/01/12 22:41:42 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nblen(unsigned int nb)
{
	int len;

	len = 1;
	while (nb / 10 > 0)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

static size_t	power(unsigned int nb)
{
	size_t pow;

	pow = 1;
	while (nb / pow >= 10)
		pow *= 10;
	return (pow);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				len;
	int				div;
	int				i;

	if (n < 0)
		len = nblen(-n) + 1;
	else
		len = nblen(n);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	if (n < 0 && (nb = (unsigned int)(-n)))
		s[++i] = '-';
	else
		nb = (unsigned int)n;
	div = power(nb);
	while (div > 0)
	{
		s[++i] = nb / div % 10 + 48;
		div /= 10;
	}
	s[i + 1] = '\0';
	return (s);
}
