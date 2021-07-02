/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:11:34 by besellem          #+#    #+#             */
/*   Updated: 2020/11/27 14:53:04 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_internal.h"

char	*ft_mcat(char *dst, char *src)
{
	char	*new;
	size_t	len;

	len = (dst ? ft_strlen(dst) : 0) + (src ? ft_strlen(src) : 0);
	if (!(new = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (dst)
		ft_strcat(new, dst);
	if (src)
		ft_strcat(new, src);
	ft_free(2, dst, src);
	return (new);
}

int		ft_len_base(long long n, int base)
{
	long long	i;
	int			len;

	n = n < 0 ? -n : n;
	len = 1;
	i = base;
	while (n / i > 0)
	{
		i *= base;
		++len;
	}
	return (len);
}

int		ft_ulen_base(unsigned long long n, int base)
{
	int len;

	len = 1;
	while (n / base > 0)
	{
		n /= base;
		++len;
	}
	return (len);
}

char	*convert_base(long long n, char *base)
{
	char		*data;
	long long	div;
	int			i;
	int			len;

	len = ft_len_base(n, ft_strlen(base)) + (n < 0 ? 1 : 0) + 1;
	if (!(data = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	len = ft_strlen(base);
	i = -1;
	if (n < 0 && (n = -n))
		data[++i] = '-';
	div = 1;
	while (n / div >= len)
		div *= len;
	while (div > 0)
	{
		data[++i] = base[n / div % len];
		div /= len;
	}
	data[++i] = '\0';
	return (data);
}

char	*convert_base_u(t_ull n, char *base)
{
	char	*data;
	t_ull	div;
	t_ull	len;
	int		i;

	len = ft_ulen_base(n, ft_strlen(base));
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = ft_strlen(base);
	div = 1;
	while (n / div >= len)
		div *= len;
	i = -1;
	while (div > 0)
	{
		data[++i] = base[n / div % len];
		div /= len;
	}
	data[++i] = '\0';
	return (data);
}
