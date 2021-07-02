/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:04:36 by besellem          #+#    #+#             */
/*   Updated: 2021/01/12 22:37:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen_base(long long n, int base)
{
	int len;

	if (n < 0)
		n = -n;
	len = 1;
	while (n / base > 0)
	{
		n /= base;
		++len;
	}
	return (len);
}
