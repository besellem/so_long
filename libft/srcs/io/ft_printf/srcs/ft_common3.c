/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:16:14 by besellem          #+#    #+#             */
/*   Updated: 2020/11/27 14:53:09 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_internal.h"

char	*space_padding(char *data, int padding)
{
	char	*spaces;
	int		data_len;
	int		len;

	if (padding <= 0)
		return (NULL);
	data_len = data ? ft_strlen(data) : 0;
	len = data_len > padding ? 0 : padding - data_len;
	spaces = ft_malloc_c((len < 0 ? 0 : len), ' ');
	return (spaces);
}

int		ft_signbit_f(long double x)
{
	return ((1.0 / x) != (1.0 / (x < 0 ? 1 : 0)));
}

char	*convert_to_float(long long n, int sign)
{
	char		*data;
	long long	div;
	int			i;
	int			len;

	len = ft_len_base(n, 10) + 1;
	if (!(data = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = -1;
	if (sign == 1)
		n = -n;
	div = 1;
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		data[++i] = (n / div) % 10 + 48;
		div /= 10;
	}
	data[++i] = '\0';
	return (data);
}
