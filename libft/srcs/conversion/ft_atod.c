/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:15:12 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:15:59 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double				nb;
	double				p;
	unsigned long long	div;
	int					min;

	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	min = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			min = -1;
	nb = 0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - 48;
	p = 0.;
	if (*str && *str == '.' && ++str)
	{
		div = 1;
		while (*str && *str >= '0' && *str <= '9')
			p = p + ((double)(*str++ - 48) / (div *= 10));
	}
	return ((nb + p) * min);
}
