/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:02:15 by besellem          #+#    #+#             */
/*   Updated: 2021/01/13 14:16:12 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int f;

	if (ft_is_prime(nb))
		return (nb);
	f = nb + 1;
	while (!ft_is_prime(f))
		++f;
	return (f);
}
