/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:02:24 by besellem          #+#    #+#             */
/*   Updated: 2021/01/12 22:54:39 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alpha_check(char c, char cmp)
{
	if (c == cmp ||
		(ft_isalpha(c) && ft_isalpha(cmp) && ft_tolower(c) == ft_tolower(cmp)))
		return (1);
	return (0);
}

static int	in_base(int base, char c)
{
	char	*b;
	int		i;

	b = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = -1;
	while (b[++i] && i < base)
		if (alpha_check(b[i], c))
			return (i);
	return (-1);
}

static int	special_cases(const char *str, int *base)
{
	if ((*base == 0 || *base == 16) && *str && *str == '0' && *(str + 1) &&
		(*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		*base = 16;
		return (2);
	}
	else if (*base == 0 && *str && *str == '0')
	{
		*base = 8;
		return (1);
	}
	else if (*base == 0)
		*base = 10;
	return (0);
}

static int	get_head(const char *str, int *base, int *min)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		++i;
	*min = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*min = -1;
	return (i + special_cases(str, base));
}

long		ft_strtol(const char *str, char **endptr, int base)
{
	long	nb;
	int		min;
	int		i;
	int		j;

	if (base != 0 && (base < 2 || base > 36))
		return (0);
	i = get_head(str, &base, &min);
	j = 0;
	nb = 0;
	while (str[i + j] && in_base(base, str[i + j]) != -1)
	{
		nb = nb * base + in_base(base, str[i + j++]);
		if (nb < 0 && min == 1)
			return (LONG_MAX);
		else if (nb < 0)
			return (LONG_MIN);
	}
	if (endptr && j)
		*endptr = (char *)(&str[i + j]);
	else if (endptr)
		*endptr = (char *)(str);
	return (nb * min);
}
